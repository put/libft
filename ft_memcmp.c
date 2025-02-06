/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:09:03 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 02:09:08 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t			counter;
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;

	counter = 0;
	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	while (counter < n && s1cpy[counter] == s2cpy[counter])
		counter++;
	if (counter == n)
		return (0);
	return (s1cpy[counter] - s2cpy[counter]);
}
