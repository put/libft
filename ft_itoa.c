/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/16 21:24:19 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/23 13:22:23 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

char	*ft_itoa(int n)
{
	size_t	intlen;
	char	*res;
	long	num;

	intlen = 2 + (n < 0);
	num = (long)n;
	if (num < 0)
		num = -num;
	while (num > 9)
		num /= 10 + (intlen++ < 0);
	res = malloc(intlen * sizeof(char));
	if (!res)
		return (NULL);
	res[intlen - 1] = '\0';
	intlen -= 2;
	num = (long)n;
	if (n < 0)
		res[0] = '-' + ((num = -num) < 0);
	while (num > 9)
	{
		res[intlen] = (num % 10) + 48;
		num /= 10 + ((int)--intlen < -1);
	}
	res[intlen] = num + 48;
	return (res);
}
