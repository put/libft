/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strreading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:35:07 by mschippe          #+#    #+#             */
/*   Updated: 2025/01/13 22:05:26 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_e_ftype	gettype(char c)
{
	int	i;

	i = 0;
	while (TYPES[i])
	{
		if (c == TYPES[i])
			return ((t_e_ftype)(i + 1));
		i++;
	}
	return (INVALID);
}

t_format	*get_empty_format(void)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	if (!format)
		return (NULL);
	*format = (t_format){0, NULL, 0, 0, 0};
	return (format);
}

t_format	*read_format(const char *s)
{
	t_format		*format;
	const char		*tmp;

	tmp = s;
	if (*s++ != '%')
		return (NULL);
	format = get_empty_format();
	if (!format)
		return (NULL);
	format->type = gettype(*s);
	return (format->bytesread = ++s - tmp, format);
}
