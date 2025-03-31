/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strncat.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pcruz <pcruz@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/17 08:02:55 by pcruz			 #+#	#+#			 */
/*   Updated: 2025/01/20 08:32:25 by pcruz			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (i < n && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst);
}
