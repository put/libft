/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcat.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/09 19:17:57 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/17 19:28:42 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <aio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstsize;
	size_t	srcsize;
	size_t	available_space;
	size_t	count;

	dstsize = 0;
	srcsize = 0;
	available_space = 0;
	count = 0;
	while (dst[dstsize] && dstsize < size)
		dstsize++;
	while (src[srcsize])
		srcsize++;
	if (dstsize == size)
		return (size + srcsize);
	available_space = size - dstsize - 1;
	while (src[count] && count < available_space)
	{
		dst[dstsize + count] = src[count];
		count++;
	}
	dst[dstsize + count] = '\0';
	return (dstsize + srcsize);
}
