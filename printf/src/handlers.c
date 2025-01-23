/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:43:15 by mschippe          #+#    #+#             */
/*   Updated: 2025/01/13 21:56:33 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char *s, t_list **list)
{
	t_format	*format;

	format = read_format(s);
	if (!format)
		return (-1);
	if (!*list)
	{
		*list = ft_lstnew(format);
		if (!*list)
			return (-1);
	}
	else
		ft_lstadd_back(&(*list), ft_lstnew(format));
	return (format->bytesread);
}

static int	handle_plain(const char *s, t_list **list)
{
	int			count;
	t_format	*format;

	count = 0;
	format = get_empty_format();
	if (!format)
		return (-1);
	while (*s && *s != '%')
		count += 1 + (s++ && 0);
	s -= count;
	format->res = ft_substr(s, 0, count);
	if (!format->res)
		return (-1);
	ft_lstadd_back(list, ft_lstnew(format));
	return (count);
}

t_list	*get_formats(const char *s)
{
	int			bytesread;
	t_list		*list;

	list = NULL;
	while (*s)
	{
		if (*s == '%')
		{
			bytesread = handle_format(s, &list);
			if (bytesread == -1)
				return (NULL);
			s += bytesread;
		}
		else
		{
			bytesread = handle_plain(s, &list);
			if (bytesread == -1)
				return (NULL);
			s += bytesread;
		}
	}
	return (list);
}

void	process_formats(t_list *list, va_list args)
{
	t_format	*format;

	while (list)
	{
		format = list->content;
		if (format->type == CHAR)
			format->res = charstr(va_arg(args, int));
		else if (format->type == STRING)
			format->res = strtostr(va_arg(args, char *), format);
		else if (format->type == POINTER)
			format->res = ft_ptoa(va_arg(args, uintptr_t));
		else if (format->type == SIG_DEC || format->type == SIG_INT)
			format->res = ft_itoa(va_arg(args, int));
		else if (format->type == UNS_DEC)
			format->res = ft_utoa(va_arg(args, unsigned int));
		else if (format->type == HEX_LOW)
			format->res = utohexa(va_arg(args, unsigned int), 0);
		else if (format->type == HEX_UP)
			format->res = utohexa(va_arg(args, unsigned int), 1);
		else if (format->type == PERCENT)
			format->res = percentstr();
		else if (format->type == INVALID)
			return ;
		list = list->next;
	}
}

void	finish_strings(t_list *list)
{
	t_format	*format;

	while (list)
	{
		format = list->content;
		if (format->type == INVALID)
			return ;
		if (format->type == PERCENT)
		{
			list = list->next;
			continue ;
		}
		apply_hex_prefix(list->content);
		set_termchar(list->content);
		list = list->next;
	}
}
