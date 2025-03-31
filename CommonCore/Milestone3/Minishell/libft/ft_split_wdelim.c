/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split_wdelim.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pcruz <pcruz@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/03 09:27:49 by pcruz			 #+#	#+#			 */
/*   Updated: 2025/02/05 08:51:03 by pcruz			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char *seps)
{
	int	i;

	i = 0;
	while (seps[i])
	{
		if (c == seps[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_wcount_wdelim(char *str, char *seps)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_sep(str[i], seps))
		{
			counter++;
			i++;
		}
		else
		{
			counter++;
			while (str[i] != '\0' && !is_sep(str[i], seps))
				i++;
		}
	}
	return (counter);
}

static int	process_word(t_split *data)
{
	int	start;

	start = data->i;
	while (data->str[data->i] != '\0'
		&& !is_sep(data->str[data->i], data->seps))
		(data->i)++;
	if (data->i > start)
	{
		data->strs[data->j] = (char *)ft_calloc(data->i - start + 1,
				sizeof(char));
		if (!data->strs[data->j])
			return (0);
		ft_strlcpy(data->strs[data->j], data->str + start, data->i - start + 1);
		(data->j)++;
	}
	return (1);
}

static int	process_delim(t_split *data)
{
	data->strs[data->j] = (char *)ft_calloc(2, sizeof(char));
	if (!data->strs[data->j])
		return (0);
	data->strs[data->j][0] = data->str[data->i];
	(data->j)++;
	(data->i)++;
	return (1);
}

char	**ft_split_wdelim(char *str, char *seps)
{
	t_split	data;

	data.str = str;
	data.seps = seps;
	data.i = 0;
	data.j = 0;
	data.wcounter = ft_wcount_wdelim(str, seps);
	data.strs = (char **)ft_calloc(data.wcounter + 1, sizeof(char *));
	if (!data.strs)
		return (NULL);
	while (data.str[data.i] != '\0' && data.j < data.wcounter)
	{
		if (!process_word(&data))
			return (ft_free(data.strs), NULL);
		if (is_sep(data.str[data.i], data.seps))
		{
			if (!process_delim(&data))
				return (ft_free(data.strs), NULL);
		}
	}
	data.strs[data.j] = NULL;
	return (data.strs);
}
