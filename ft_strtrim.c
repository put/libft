/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:12:40 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 02:16:13 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*res;
	size_t			slen;
	unsigned int	soffset;
	unsigned int	eoffset;

	slen = ft_strlen(s1);
	soffset = 0;
	eoffset = slen;
	while (s1[soffset] && ft_strchr(set, s1[soffset]) != NULL)
		soffset++;
	while (eoffset > soffset && ft_strchr(set, s1[eoffset - 1]) != NULL)
		eoffset--;
	res = malloc((eoffset - soffset + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, &s1[soffset], eoffset - soffset);
	res[eoffset - soffset] = '\0';
	return (res);
}
