/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstclear.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/24 15:28:24 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/24 15:29:12 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmplst;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmplst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmplst;
	}
	*lst = NULL;
}
