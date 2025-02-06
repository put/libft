/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:11:29 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 02:15:57 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1l;
	size_t	s2l;
	char	*res;
	char	*resstart;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	res = malloc((s1l + s2l + 1) * sizeof(char));
	if (!res)
		return (NULL);
	resstart = res;
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	return (resstart);
}
