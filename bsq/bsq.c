/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasancho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:26:54 by jasancho          #+#    #+#             */
/*   Updated: 2021/12/16 01:53:23 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while ((str[i] != 0) && (str[i] != '\n'))
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		len;
	char	*p;
	int		i;

	i = 0;
	len = ft_strlen(str);
	p = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		*(p + i) = *(str + i);
		i++;
	}
	*(p + i) = 0;
	return (p);
}

int	print_cell_from_square(int i, int j, t_square *sq, t_info *info)
{
	if (i >= sq->init_x && i < sq->init_x + sq->edge
		&& j >= sq->init_y && j < sq->init_y + sq->edge)
	{
		write(1, &info->full, 1);
		return (1);
	}
	return (0);
}

void	ft_print_solution(t_square *sq, char **grid, t_info *info)
{
	int	i;
	int	j;

	j = 0;
	while (j < info->rows)
	{
		i = 0;
		while (i < info->columns)
		{
			if (!print_cell_from_square(i, j, sq, info))
				write(1, &grid[j][i], 1);
			i++;
		}
		j++;
		write(1, "\n", 1);
	}
}

int	is_valid_square(char **grid, t_square *sq, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sq->edge && sq->init_x + i < info->columns)
	{
		j = 0;
		while (j < sq->edge && sq->init_y + j < info->rows)
		{
			if (grid[sq->init_y + j][sq->init_x + i] != info->empty)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		fd;
	t_info	*info;
	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
			{
				write(1, "map error\n", 10);
				return (-1);
			}
			else
			{
				info = get_dimensions_and_chars(fd);
				if (!check_null(info))
					check_null(ft_squarespace(info));
			}
			i++;
		}
	}
	else
	{
		fd = 0;
		info = get_dimensions_and_chars(fd);
		if (!check_null(info))
			check_null(ft_squarespace(info));
	}
}
