/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_tolower.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/09 21:27:38 by mschippe		  #+#	#+#			 */
/*   Updated: 2024/10/17 19:29:55 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (!(c >= 'A' && c <= 'Z'))
		return (c);
	return (c + 32);
}
