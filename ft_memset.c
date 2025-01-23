/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memset.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/07 17:34:26 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/22 15:27:23 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <aio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	void	*start;

	start = s;
	while (n-- > 0)
		*((unsigned char *)s++) = (unsigned char)c;
	return (start);
}
