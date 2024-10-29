/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:27:43 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/29 14:34:36 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

char	*ft_uitoa(unsigned int n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
int		ft_printf(const char *format, ...);
int		ft_printc(int c);
int		ft_printstr(char *str);
int		ft_put_hex(unsigned long nb, const char form);
int		ft_print_pointer(unsigned long pointer);
int		ft_printnbr(int nb);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int nb, const char form);
int		ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
