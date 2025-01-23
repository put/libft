/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_calloc.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/14 19:25:00 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/18 16:29:35 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (size <= 0 || nmemb <= 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}
