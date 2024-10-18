/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:58:06 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/18 09:36:40 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

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



    const char *str5 = "Hello, World!";
    char ch = 'W';
    size_t n = strlen(str5);

    // Usando a função original memchr para comparação
    void *result_original = memchr(str5, ch, n);
    void *result_ft = ft_memchr(str5, ch, n);

    // Verificar se os resultados são iguais
    if (result_original == result_ft) {
        printf("Test passed: Found character '%c' at the same location.\n", ch);
    } else {
        printf("Test failed: Different results.\n");
        printf("Original memchr result: %s\n", (char *)result_original);
        printf("Custom ft_memchr result: %s\n", (char *)result_ft);
    }

    // Testar com um caractere que não existe
    ch = 'x';
    result_original = memchr(str5, ch, n);
    result_ft = ft_memchr(str5, ch, n);

    if (result_original == result_ft) {
        printf("Test passed: Character '%c' not found as expected.\n", ch);
    } else {
        printf("Test failed: Unexpected results when character not found.\n");
    }


    const char *st1 = "Hello, World!";
    const char *st2 = "Hello, World!";
    const char *st3 = "Hello, world!";
    const char *st4 = "Hello, Worlx!";

    // Teste com strings iguais
    if (ft_memcmp(st1, st2, 13) == 0) {
        printf("Test passed: Strings are equal.\n");
    } else {
        printf("Test failed: Strings should be equal.\n");
    }

    // Teste com strings diferentes (case-sensitive)
    if (ft_memcmp(st1, st3, 13) < 0) {
        printf("Test passed: First string is less than second (case-sensitive).\n");
    } else {
        printf("Test failed: Comparison result unexpected.\n");
    }

    // Teste com strings diferentes (em um caractere específico)
    if (ft_memcmp(st1, st4, 13) != 0) {
        printf("Test passed: Strings are different.\n");
    } else {
        printf("Test failed: Strings should be different.\n");
    }

	char stsr1[50] = "Hello, World!";
    char stsr2[50] = "Goodbye, World!";
    
    // Teste 1: Cópia normal
    printf("Before memmove: dest = '%s', src = '%s'\n", stsr1, stsr2);
    ft_memmove(stsr1, stsr2, strlen(stsr2) + 1); // +1 para copiar o '\0'
    printf("After memmove: dest = '%s'\n", stsr1);

    // Teste 2: Cópia com sobreposição
    char overlap[50] = "Hello, World!";
    printf("Before overlapping memmove: %s\n", overlap);
    ft_memmove(overlap + 7, overlap, 6); // Move "Hello" para " World"
    printf("After overlapping memmove: %s\n", overlap);


    char strst[50] = "Hello, World!";
    
    printf("Before ft_memset: '%s'\n", strst);
    ft_memset(strst, '*', 5); // Define os primeiros 5 caracteres como '*'
    printf("After ft_memset: '%s'\n", strst);

}