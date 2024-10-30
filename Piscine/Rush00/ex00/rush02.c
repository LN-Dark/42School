/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:07:50 by tiagalex          #+#    #+#             */
/*   Updated: 2024/09/08 13:23:08 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_lines(int x, int begin, int middle, int end)
{
	int	columns;

	columns = 1;
	while (columns <= x)
	{
		if (columns == 1)
		{
			ft_putchar(begin);
		}
		else if (columns == x)
		{
			ft_putchar(end);
		}
		else
		{
			ft_putchar(middle);
		}
		columns++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	lines;

	if (x >= 1 && y >= 1 && x <= 2147483637 && y <= 2147483637)
	{
		lines = 1;
		while (lines <= y)
		{
			if (lines == 1)
			{
				print_lines(x, 'A', 'B', 'A');
			}
			else if (lines == y)
			{
				print_lines(x, 'C', 'B', 'C');
			}
			else
			{
				print_lines(x, 'B', ' ', 'B');
			}
			lines++;
		}
	}
	else
		write(1, "Invalid Value!", 14);
}
