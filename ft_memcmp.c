/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memcmp.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/11 14:48:01 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/18 15:33:02 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <aio.h>

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
