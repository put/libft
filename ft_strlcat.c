/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:11:41 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 02:11:45 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstsize;
	size_t	srcsize;
	size_t	available_space;
	size_t	count;

	dstsize = 0;
	srcsize = 0;
	available_space = 0;
	count = 0;
	while (dst[dstsize] && dstsize < size)
		dstsize++;
	while (src[srcsize])
		srcsize++;
	if (dstsize == size)
		return (size + srcsize);
	available_space = size - dstsize - 1;
	while (src[count] && count < available_space)
	{
		dst[dstsize + count] = src[count];
		count++;
	}
	dst[dstsize + count] = '\0';
	return (dstsize + srcsize);
}
