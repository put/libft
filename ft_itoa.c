/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 01:55:15 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 01:56:48 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	long long	intlen;
	char		*res;
	long		num;

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
