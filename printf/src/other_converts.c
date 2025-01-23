/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_converts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:37:00 by mschippe          #+#    #+#             */
/*   Updated: 2025/01/11 20:08:45 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*percentstr(void)
{
	return (ft_strdup("%"));
}

char	*charstr(int c)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*strtostr(char *s, t_format *format)
{
	if (!s)
	{
		format->wasnull = 1;
		return (ft_strdup("(null)"));
	}
	return (ft_strdup(s));
}
