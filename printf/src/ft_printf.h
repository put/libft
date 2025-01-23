/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:57:22 by mschippe          #+#    #+#             */
/*   Updated: 2025/01/23 22:30:23 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# define FT_PRINTF_H
# define FLAGS "-0# +"
# define FLAGS_W
# define TYPES "cspdiuxX%"

typedef enum t_e_ftype
{
	NONE_T,
	CHAR,
	STRING,
	POINTER,
	SIG_DEC,
	SIG_INT,
	UNS_DEC,
	HEX_LOW,
	HEX_UP,
	PERCENT,
	INVALID
}	t_e_ftype;

typedef struct t_format
{
	t_e_ftype					type;
	char						*res;
	unsigned int				bytesread;
	int							termchar;
	int							wasnull;
}	t_format;

t_format	*read_format(const char *s);
t_format	*get_empty_format(void);
t_list		*get_formats(const char *s);
char		*charstr(int c);
char		*percentstr(void);
char		*strtostr(char *s, t_format *format);
char		*ft_ptoa(uintptr_t ptr);
char		*ft_utoa(unsigned int n);
char		*utohexa(unsigned int n, int upper);
void		process_formats(t_list *list, va_list args);
void		free_all(t_list *list);
void		finish_strings(t_list *list);
void		apply_hex_prefix(t_format *format);
void		set_termchar(t_format *format);
int			ishexzero(char *s);
#endif