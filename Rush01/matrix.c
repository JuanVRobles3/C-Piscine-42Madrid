/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:08:08 by jrobles-          #+#    #+#             */
/*   Updated: 2021/12/05 15:39:06 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		error(void)
{
	write(1, "Up to you!\n!", 11);
	return (-1);
}

char	recorre(char arr_n[])
{
	char c;
	c = arr_n[0];
	return c;
}


void	print(int row, int column, int max_row, int max_column)
{
	temp[];
	char a;

	if (row == 0 || row == max_row)
	{
		if (column == 0)
			if(recorre(temp) == 4)
			ft_putchar('1');
			
			
		else
			if (column == max_column)
				ft_putchar(' ');
	}
	else
	{
		
	}
}

void	matrix(char *argv)
{
	int	row;
	int	column;
		
	row = 0;
	while (row <= 3)
	{
		column = 0;
		while (column <= 3)
		{
			print(row, column, 3, 3);
			column ++;	
		}
		ft_putchar('\n');
		row ++;
	}
}
	