/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:58:06 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/17 10:40:04 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void print_split_result(char **result)
{
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("Word %d: %s\n", i, result[i]);
        free(result[i]);  // Libera a memória alocada para cada palavra
    }
    free(result);  // Libera a memória alocada para o array de ponteiros
}

int main(void)
{
	char *s[3];
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

}