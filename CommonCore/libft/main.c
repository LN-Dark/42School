/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:58:06 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/17 14:45:13 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void print_split_result(char **result)
{
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("Word %d: %s\n", i, result[i]);
        free(result[i]);
    }
    free(result);
}

void print_char_with_index(unsigned int index, char *c)
{
    printf("Index: %u, Character: %c\n", index, *c);
}

char to_upper(unsigned int index, char c)
{
    (void)index;
    return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

int main(void)
{
	char *s[3];
	char *result2;
	printf("%d %s\n", ft_atoi("-1254hagh"), "-> ft_atoi");
	printf("%s %s\n", ft_itoa(-125478), "-> ft_itoa");
	printf("%d %s\n", ft_isalnum(-125478), "-> ft_isalnum");
	printf("%d %s\n", ft_isalpha(127), "-> ft_isalpha");
	printf("%d %s\n", ft_isascii(128), "-> ft_isascii");
	printf("%d %s\n", ft_isdigit(95), "-> ft_isdigit");
	printf("%d %s\n", ft_isprint(45), "-> ft_isprint");
	ft_putchar_fd('a', 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-15478, 1);
	ft_putstr_fd("\nft_putstr_fd\n", 1);
	printf("%s %s\n", ft_strchr("Ola", 97), "-> ft_strchr");
	printf("%s %s\n", ft_strjoin("Ola", "Mundo"), "-> ft_strjoin");
	printf("%zu %s\n", ft_strlcat("ola", "Mundo", 3), "-> ft_strlcat");
	printf("%zu %s %s\n", ft_strlcpy(*s, "Mundo", 5), *s, "-> ft_strlcpy");
	printf("%d %s\n", ft_strlen("teste"), "-> ft_strlen");
	printf("%d %s\n", ft_strncmp("teste", "zeste", 5), "-> ft_strncmp");
	printf("%d %s\n", ft_tolower(87), "-> ft_tolower");
	printf("%d %s\n", ft_toupper(119), "-> ft_toupper");
	const char *str = "Este é um exemplo de string";
    char sep = ' ';
    char **result = ft_split(str, sep);

    if (result != NULL)
    {
        print_split_result(result);
    }
    else
    {
        printf("Erro ao dividir a string.\n");
    }
	printf("%s %s\n", ft_strrchr("Olaaab", 97), "-> ft_strrchr");
	printf("%s %s\n", ft_strnstr("Olaaab", "a", 3), "-> ft_strnstr");
	printf("%s %s\n", ft_substr("Olaaab", 2, 3), "-> ft_substr");
	char str2[] = "Hello, World!";
    ft_striteri(str2, print_char_with_index);
    printf("%s %s\n", ft_strtrim("OlaaabO", "O"), "-> ft_strtrim");

    result2 = ft_strmapi("hello world", to_upper);
    if (result2)
    {
        printf("Mapped string: '%s'\n", result2);
        free(result2);
    }
    else
    {
        printf("Error allocating memory!\n");
    }

    char src3[] = "Hello, World!";
    char dest3[20];
    ft_memcpy(dest3, src3, 13);
    dest3[13] = '\0';
    printf("Destination: '%s'\n", dest3);

}