/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcpy.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/08 13:15:36 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/09 19:17:31 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <aio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srcsize;
	size_t	ctr;

	srcsize = 0;
	ctr = 0;
	while (src[srcsize])
		srcsize++;
	if (size > 0)
	{
		while (*src && ctr < size - 1)
		{
			*(dst++) = *(src++);
			ctr++;
		}
		*dst = '\0';
	}
	return (srcsize);
}
