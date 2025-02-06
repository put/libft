/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:12:09 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 02:16:40 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	size_t			slen;
	char			*res;

	index = 0;
	slen = ft_strlen(s);
	res = malloc((slen + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (*s)
		*res++ = f(index++, *s++);
	*res = '\0';
	return (res - index);
}
