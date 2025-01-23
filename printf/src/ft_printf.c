/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:17:18 by mschippe          #+#    #+#             */
/*   Updated: 2025/01/13 22:19:28 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_formats_logic(t_format *format)
{
	int	len;

	len = 0;
	if (format->res)
	{
		len = ft_strlen(format->res);
		if (format->termchar == 2)
		{
			write(1, "\0", 1);
			write(1, format->res, len);
		}
		else if (format->termchar == 1)
			write(1, format->res, len + 1);
		else
			write(1, format->res, len);
		return (len + (!!format->termchar));
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}

int	print_formats(t_list *list)
{
	t_format	*format;
	int			totalwrote;

	totalwrote = 0;
	while (list)
	{
		format = list->content;
		if (format->type == INVALID)
			return (-1);
		totalwrote += print_formats_logic(format);
		list = list->next;
	}
	return (totalwrote);
}

int	ft_printf(const char *s, ...)
{
	t_list		*list;
	va_list		args;
	int			bytesprinted;

	list = get_formats(s);
	if (!list)
		return (-1);
	va_start(args, s);
	process_formats(list, args);
	finish_strings(list);
	bytesprinted = print_formats(list);
	va_end(args);
	free_all(list);
	return (bytesprinted);
}
