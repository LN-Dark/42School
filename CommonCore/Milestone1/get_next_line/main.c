/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:05:25 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/04 15:05:35 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv) {
    int fd;
    char *line;

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <caminho_do_arquivo>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while ((line = ft_get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line); // Libere a memória alocada para a linha
    }

    close(fd);
    return 0;
}
