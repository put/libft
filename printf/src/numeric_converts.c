/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_converts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:12:33 by mschippe          #+#    #+#             */
/*   Updated: 2025/01/13 22:05:47 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexstrlen(uintptr_t n)
{
	size_t	len;

	len = 1;
	while (n / 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*utohexa(unsigned int n, int upper)
{
	char	*hex;
	size_t	len;

	len = hexstrlen(n);
	hex = malloc(len + 1);
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	while (len--)
	{
		if (n % 16 > 9)
		{
			if (upper)
				hex[len] = (n % 16) + 'A' - 10;
			else
				hex[len] = (n % 16) + 'a' - 10;
		}
		else
			hex[len] = (n % 16) + '0';
		n /= 16;
	}
	return (hex);
}

char	*ft_utoa(unsigned int n)
{
	size_t			intlen;
	char			*res;
	unsigned int	num;

	intlen = 2;
	num = n;
	while (num > 9)
		num /= 10 + (intlen++ && 0);
	res = malloc(intlen * sizeof(char));
	if (!res)
		return (NULL);
	res[intlen - 1] = '\0';
	intlen -= 2;
	num = n;
	while (num > 9)
	{
		res[intlen] = (num % 10) + 48;
		num /= 10 + ((int)--intlen < -1);
	}
	res[intlen] = num + 48;
	return (res);
}

char	*ft_ptoa(uintptr_t n)
{
	char	*hex;
	size_t	len;

	len = hexstrlen(n);
	if (n == 0)
		return (ft_strdup("(nil)"));
	hex = malloc(len + 1);
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	while (len--)
	{
		if (n % 16 > 9)
			hex[len] = (n % 16) + 'a' - 10;
		else
			hex[len] = (n % 16) + '0';
		n /= 16;
	}
	return (hex);
}
