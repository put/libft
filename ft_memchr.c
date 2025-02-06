/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:08:53 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 02:08:56 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			ctr;
	unsigned char	*cpy;

	ctr = 0;
	cpy = (unsigned char *)s;
	while (ctr < n)
	{
		if (cpy[ctr] == (unsigned char)c)
			return ((void *)&cpy[ctr]);
		ctr++;
	}
	return (NULL);
}
