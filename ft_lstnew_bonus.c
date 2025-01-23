/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstnew.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/20 14:33:38 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/22 15:22:52 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	*new = (t_list){content, NULL};
	return (new);
}
