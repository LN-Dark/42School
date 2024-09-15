/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:02:45 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/14 19:02:46 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

#define N 4

void	ft_putchar(char c);
void	initialize_grid(int grid[N][N]);
void	print_grid(int grid[N][N]);
int		is_valid_digit(char *str);
int		parse_input(int argc, char **argv, int top[N], int bottom[N], int left[N], int right[N]);
int		is_safe(int grid[N][N], int row, int col, int num);
int		check_row_left(int grid[N][N], int left[N], int row);
int		check_row_right(int grid[N][N], int right[N], int row);
int		check_col_up(int grid[N][N], int top[N], int col);
int		check_col_down(int grid[N][N], int bottom[N], int col);
int		solve(int grid[N][N], int top[N], int bottom[N], int left[N], int right[N], int row, int col);

int	main(int argc, char **argv)
{
	int grid[N][N];
	int top[N], bottom[N], left[N], right[N];

	if (argc != (N * 4) + 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!parse_input(argc, argv, top, bottom, left, right))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	initialize_grid(grid);
	if (solve(grid, top, bottom, left, right, 0, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	initialize_grid(int grid[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_grid(int grid[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			ft_putchar(grid[i][j] + '0');
			if (j < N - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	is_valid_digit(char *str)
{
	if (str[0] >= '1' && str[0] <= '0' + N && str[1] == '\0')
		return (1);
	return (0);
}

int	parse_input(int argc, char **argv, int top[N], int bottom[N], int left[N], int right[N])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_digit(argv[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < N)
	{
		top[i] = argv[1 + i][0] - '0';
		bottom[i] = argv[1 + N + i][0] - '0';
		left[i] = argv[1 + 2 * N + i][0] - '0';
		right[i] = argv[1 + 3 * N + i][0] - '0';
		i++;
	}
	return (1);
}

int	is_safe(int grid[N][N], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_row_left(int grid[N][N], int left[N], int row)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < N)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			count++;
		}
		i++;
	}
	if (left[row] != 0 && count != left[row])
		return (0);
	return (1);
}

int	check_row_right(int grid[N][N], int right[N], int row)
{
	int	i;
	int	max;
	int	count;

	i = N - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			count++;
		}
		i--;
	}
	if (right[row] != 0 && count != right[row])
		return (0);
	return (1);
}

int	check_col_up(int grid[N][N], int top[N], int col)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < N)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
		i++;
	}
	if (top[col] != 0 && count != top[col])
		return (0);
	return (1);
}

int	check_col_down(int grid[N][N], int bottom[N], int col)
{
	int	i;
	int	max;
	int	count;

	i = N - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
		i--;
	}
	if (bottom[col] != 0 && count != bottom[col])
		return (0);
	return (1);
}

int	solve(int grid[N][N], int top[N], int bottom[N], int left[N], int right[N], int row, int col)
{
	int	num;

	if (row == N)
		return (1);
	if (grid[row][col] != 0)
	{
		if (col == N - 1)
		{
			if (solve(grid, top, bottom, left, right, row + 1, 0))
				return (1);
		}
		else
		{
			if (solve(grid, top, bottom, left, right, row, col + 1))
				return (1);
		}
		return (0);
	}
	num = 1;
	while (num <= N)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (col == N - 1)
			{
				if (check_row_left(grid, left, row) && check_row_right(grid, right, row))
				{
					if (solve(grid, top, bottom, left, right, row + 1, 0))
						return (1);
				}
			}
			else if (row == N - 1 && col < N - 1)
			{
				if (check_col_up(grid, top, col) && check_col_down(grid, bottom, col))
				{
					if (solve(grid, top, bottom, left, right, row, col + 1))
						return (1);
				}
			}
			else
			{
				if (solve(grid, top, bottom, left, right, row, col + 1))
					return (1);
			}
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

