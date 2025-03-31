/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strstr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hfilipe- <hfilipe-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/20 07:54:58 by pcruz			 #+#	#+#			 */
/*   Updated: 2025/01/21 15:24:36 by hfilipe-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		h = haystack;
		n = needle;
		while (*h && *n && *h == *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
