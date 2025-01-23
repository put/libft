/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strmapi.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/17 13:45:15 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/23 13:23:56 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>
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
