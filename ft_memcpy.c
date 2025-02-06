/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:09:29 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 02:09:33 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*start;

	start = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
		*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (start);
}
