/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:12:17 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 02:12:19 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while (*s1 == *s2 && counter < n)
	{
		if (!*s1)
			return (0);
		s1++;
		s2++;
		counter++;
	}
	if (counter == n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
