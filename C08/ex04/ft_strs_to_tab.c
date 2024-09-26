/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:23:22 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/25 10:23:24 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *str, int size)
{
	char	*ret;
	int		i;

	ret = NULL;
	ret = malloc(sizeof(char) * (size + 1));
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i += 1;
	}
	ret[i] = 0;
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int argc, char **argv)
{
	t_stock_str	*ret;
	int			i;

	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (argc + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		ret[i].size = ft_strlen(argv[i]);
		ret[i].str = argv[i];
		ret[i].copy = ft_strcpy(argv[i], ret[i].size);
		i += 1;
	}
	ret[i].size = 0;
	ret[i].str = 0;
	ret[i].copy = 0;
	return (ret);
}
