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
    int num = 42;
    unsigned int unum = 12345;
    char *str = "Hello, World!";
    void *ptr = (void*)&num;

    ft_printf("Decimal: %d\n", num);
    ft_printf("Integer: %i\n", num);
    ft_printf("Unsigned: %u\n", unum);
    ft_printf("String: %s\n", str);
    ft_printf("Pointer: %p\n", ptr);
    ft_printf("Hexadecimal: %x\n", num);
    ft_printf("Hexadecimal Uppercase: %X\n", num);

    return 0;
}
