/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:58:45 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/17 10:41:10 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_atoi(const char *str);
int	ft_tolower(int i);
int	ft_toupper(int i);
int	ft_isalnum(int i);
int	ft_isalpha(int i);
int	ft_isascii(int i);
int	ft_isdigit(int i);
int	ft_isprint(int i);
int	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int	ft_strncmp(const char *s1, char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int i);
char	**ft_split(char const *str, char c);

#endif
