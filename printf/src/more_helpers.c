/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:08:07 by mschippe          #+#    #+#             */
/*   Updated: 2025/01/13 21:51:51 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_hex_prefix(t_format *format)
{
	char	*tmp;

	if (format->type == POINTER)
	{
		if (ishexzero(format->res))
			return ;
		tmp = ft_strjoin("0x", format->res);
		free(format->res);
		format->res = tmp;
	}
}

int	ishexzero(char *s)
{
	if (ft_strncmp(s, "(nil)", 5) == 0)
		return (1);
	while (*s)
	{
		if (*s != '0')
			return (0);
		s++;
	}
	return (1);
}

void	set_termchar(t_format *format)
{
	format->termchar = ft_strlen(format->res) == 0 && format->type == CHAR;
}
