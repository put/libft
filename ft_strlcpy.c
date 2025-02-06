/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:11:51 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 02:11:53 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srcsize;
	size_t	ctr;

	srcsize = 0;
	ctr = 0;
	while (src[srcsize])
		srcsize++;
	if (size > 0)
	{
		while (*src && ctr < size - 1)
		{
			*(dst++) = *(src++);
			ctr++;
		}
		*dst = '\0';
	}
	return (srcsize);
}
