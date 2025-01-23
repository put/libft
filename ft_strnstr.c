/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strnstr.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/09 22:23:41 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/10 17:18:17 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <aio.h>
#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	lilindex;

	index = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[index] && index < len)
	{
		lilindex = 0;
		while (little[lilindex] == big[index + lilindex]
			&& index + lilindex < len)
		{
			if (little[++lilindex] == '\0')
				return ((char *)&big[index]);
		}
		index++;
	}
	return (NULL);
}
