/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:43:31 by mschippe          #+#    #+#             */
/*   Updated: 2024/11/05 00:53:49 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	long	sig;
	long	res;

	res = 0;
	sig = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == ' ')
		sig = (*nptr++ || res == 0);
	if (*nptr == 43 || *nptr == 45)
		sig = (*nptr++ - 44) * -1;
	while (*nptr >= '0' && *nptr <= '9')
		res = res * 10 + (*nptr++ - 48);
	return ((int)(sig * res));
}
