/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/27 18:22:08 by mschippe		  #+#	#+#			 */
/*   Updated: 2025/01/06 19:01:59 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>

char	*nl_strchr(char *s, int c);
char	*nl_substr(char *source, size_t start, size_t length);
size_t	nl_strlen(char *s);
size_t	nl_strlcat(char *dst, char *src, size_t size);
void	*nl_realloc(void *ptr, size_t new_size, size_t old_size);
#endif