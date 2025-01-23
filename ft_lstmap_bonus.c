/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstmap.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/24 15:30:50 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/24 15:31:30 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*make_item(void *content, void (*del)(void *))
{
	t_list	*res;

	res = ft_lstnew(content);
	if (!res)
	{
		del(content);
		return (NULL);
	}
	return (res);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*reslst;
	t_list	*tmplst;
	void	*content;

	if (!lst || !f)
		return (NULL);
	content = f(lst->content);
	reslst = make_item(content, del);
	if (!reslst)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		tmplst = make_item(content, del);
		if (!tmplst)
		{
			ft_lstclear(&reslst, del);
			return (NULL);
		}
		ft_lstadd_back(&reslst, tmplst);
		lst = lst->next;
	}
	return (reslst);
}
