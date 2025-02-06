/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:10:44 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/06 02:16:27 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_count(char const *s, char c)
{
	size_t	cnt;
	int		wordflag;

	cnt = 0;
	wordflag = 0;
	while (*s)
	{
		if (*s != c && !wordflag)
		{
			wordflag = 1;
			cnt++;
		}
		else if (*s == c)
			wordflag = 0;
		s++;
	}
	return (cnt);
}

static size_t	get_str_size(char const *ptr, char sep)
{
	size_t	cnt;

	cnt = 0;
	while (*ptr != sep && *ptr)
	{
		cnt++;
		ptr++;
	}
	return (cnt);
}

static char	**free_str_arr(char **arr, int index)
{
	while (index > -1)
		free(arr[index--]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	strcnt;
	char	**res;
	int		resind;

	if (!s)
		return (NULL);
	strcnt = get_str_count(s, c);
	res = malloc((strcnt + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	resind = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		res[resind] = ft_substr(s, 0, get_str_size(s, c));
		if (!res[resind])
			return (free_str_arr(res, resind - 1));
		s += get_str_size(s, c) + (++resind < 0);
	}
	res[resind] = NULL;
	return (res);
}
