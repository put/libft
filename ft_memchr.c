/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memchr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/11 15:30:46 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/18 16:15:38 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <aio.h>
#include <stdio.h>

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
