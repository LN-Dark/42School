/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:15:33 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/29 15:15:36 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main() {
    int num = 0;
    unsigned int unum = 12345;
    char *str = "Hello, World!";
    void *ptr = (void*)&num;
    char *str2;

    ft_printf("Decimal: %d\n", num);
    ft_printf("Decimal: %d\n", INT_MAX);
    ft_printf("Integer: %i\n", -2);
    ft_printf("Unsigned: %u\n", unum);
    ft_printf("String: %s\n", "");
    ft_printf("String: %s\n", NULL);
    ft_printf("Pointer: %p\n", NULL);
    ft_printf("Hexadecimal: %x\n", NULL);
    ft_printf("Hexadecimal Uppercase: %X\n", 16);

    return 0;
}
