/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printnbr.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pbranco- <pbranco-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/29 11:11:19 by pbranco-		  #+#	#+#			 */
/*   Updated: 2024/10/29 11:13:12 by pbranco-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

int	ft_printnbr(int nb)
{
	char	*nbtostr;
	int		lenght;

	lenght = 0;
	nbtostr = ft_itoa(nb);
	lenght = ft_printstr(nbtostr);
	free(nbtostr);
	return (lenght);
}
