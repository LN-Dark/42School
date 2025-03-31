/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_print_unsigned.c								:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pbranco- <pbranco-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/29 12:48:03 by pbranco-		  #+#	#+#			 */
/*   Updated: 2024/10/29 12:52:14 by pbranco-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int n)
{
	char	*nb;
	int		lenght;

	lenght = 0;
	nb = ft_uitoa(n);
	lenght = ft_printstr(nb);
	free(nb);
	return (lenght);
}
