/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:26:49 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/14 14:26:53 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display(char *filename)
{
	char	character;
	int		file;

	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		write(2, "Cannot read file.\n", 19);
		return ;
	}
	while (read(file, &character, 1) > 0)
		write(1, &character, 1);
	close(file);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		display(argv[1]);
	return (0);
}
