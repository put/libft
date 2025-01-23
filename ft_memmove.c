/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memmove.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/07 18:20:29 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/23 13:26:23 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*srccpy;
	unsigned char	*destcpy;

	if (dest == NULL && src == NULL)
		return (NULL);
	srccpy = (unsigned char *)src;
	destcpy = (unsigned char *)dest;
	if (srccpy < destcpy && destcpy < srccpy + n)
	{
		srccpy += n;
		destcpy += n;
		while (n-- > 0)
			*--destcpy = *--srccpy;
	}
	else
		while (n-- > 0)
			*destcpy++ = *srccpy++;
	return (dest);
}
