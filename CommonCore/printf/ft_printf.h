/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:27:43 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/29 12:58:05 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_printc(int c);
int		ft_printstr(char *str);
int 	ft_put_hex(unsigned long nb, const char form);
int		ft_print_ptr(unsigned long pointer);
int		ft_printnbr(int nb);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int nb, const char form);


#endif