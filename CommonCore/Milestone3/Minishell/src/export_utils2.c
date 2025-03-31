/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:45:14 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:45:15 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strstr_(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && *haystack != '=')
	{
		h = haystack;
		n = needle;
		while (*h && *n && *h == *n && *h != '=' && *n != '=' && *n != '+')
		{
			h++;
			n++;
		}
		if (*n == '=' || *n == '+' || (*n == '\0' && *h == '\0'))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

char	*ft_strstr_1(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && *haystack != '=')
	{
		h = haystack;
		n = needle;
		if (*h != *n)
			return (NULL);
		while (*h && *n && *h == *n && *h != '=' && *n != '=' && *n != '+')
		{
			h++;
			n++;
		}
		if (*n == '=' || *n == '+' || *n == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

void	swap(char **str1, char **str2)
{
	char	*temp;

	if (!str1 || !str2 || !*str1 || !*str2)
		return ;
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int	ft_strcmp_(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2 && *s1 != '=' )
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
