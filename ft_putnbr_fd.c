/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:10:25 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 02:10:26 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	newn;

	newn = (long)n;
	if (newn < 0)
	{
		ft_putchar_fd('-', fd);
		newn = -newn;
	}
	if (newn > 9)
	{
		ft_putnbr_fd((int)(newn / 10), fd);
		ft_putnbr_fd((int)(newn % 10), fd);
	}
	else
		ft_putchar_fd((int)(newn + 48), fd);
}
