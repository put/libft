/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memcpy.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/07 17:49:14 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/23 13:25:39 by mschippe		 ###   ########.fr	   */
/*																			*/
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
