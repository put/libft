/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstiter.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/24 15:29:53 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/24 15:29:55 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
