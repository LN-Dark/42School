/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_print_pointer.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pbranco- <pbranco-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/29 10:01:05 by pbranco-		  #+#	#+#			 */
/*   Updated: 2024/10/29 13:49:34 by pbranco-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

int	ft_print_pointer(unsigned long pointer)
{
	int	lenght;

	lenght = 0;
	if (!pointer)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		lenght += ft_printstr("0x");
		lenght += ft_put_hex(pointer, 'x');
	}
	return (lenght);
}
