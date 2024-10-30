/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:26:49 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/16 16:26:56 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_display(char *string)
{
	int		file_ptr;
	char	c;

	file_ptr = open(string, O_RDONLY, 0);
	if (file_ptr == -1)
		ft_putstr("Cannot read file.\n");
	while (read(file_ptr, &c, 1) == 1)
		write(1, &c, 1);
	close(file_ptr);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("File name missing.\n");
	if (argc == 2)
		ft_display(argv[1]);
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	return (0);
}
