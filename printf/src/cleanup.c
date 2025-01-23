/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:39:09 by mschippe          #+#    #+#             */
/*   Updated: 2025/01/11 19:55:55 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	free_format(t_format *format)
{
	if (format)
	{
		if (format->res)
			free(format->res);
		free(format);
	}
	return (1);
}

void	free_all(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free_format(tmp->content);
		free(tmp);
	}
}
