/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printhex.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pbranco- <pbranco-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/29 12:54:18 by pbranco-		  #+#	#+#			 */
/*   Updated: 2024/10/29 13:01:07 by pbranco-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned int nb, const char form)
{
	if (nb == 0)
		return (ft_printc('0'));
	else
		return (ft_put_hex(nb, form));
	return (0);
}
