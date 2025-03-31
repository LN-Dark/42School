/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pbranco- <pbranco-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/16 10:10:44 by pbranco-		  #+#	#+#			 */
/*   Updated: 2024/12/16 08:21:40 by pbranco-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	ft_wcount(char *str, char sep)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0')
		{
			counter++;
			while (str[i] != sep && str[i] != '\0')
				i++;
		}
	}
	return (counter);
}

int	ft_alphacount(char *str, char sep, int word)
{
	int	i;
	int	h;
	int	count;

	i = 0;
	h = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0')
		{
			if (h == word)
			{
				count = 0;
				while (str[i + count] != sep && str[i + count] != '\0')
					count++;
				return (count);
			}
			h++;
			while (str[i] != sep && str[i] != '\0')
				i++;
		}
	}
	return (0);
}

int	ft_alphacountbegin(char *str, char sep, int word)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0')
		{
			if (h == word)
				return (i);
			h++;
			while (str[i] != sep && str[i] != '\0')
				i++;
		}
	}
	return (i);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		wcounter;
	int		length;

	if (!str)
		return (NULL);
	wcounter = ft_wcount((char *)str, c);
	strs = (char **)ft_calloc(wcounter + 1, sizeof(char *));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (i < wcounter)
	{
		length = ft_alphacount((char *)str, c, i);
		strs[i] = (char *)ft_calloc(length + 1, sizeof(char));
		if (strs[i] == NULL)
			return (ft_free(strs), NULL);
		ft_strlcpy(strs[i],
			str + ft_alphacountbegin((char *)str, c, i), length + 1);
		i++;
	}
	strs[wcounter] = NULL;
	return (strs);
}
