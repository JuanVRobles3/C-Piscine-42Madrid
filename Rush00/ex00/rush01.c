/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush011.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:32:32 by jrobles-          #+#    #+#             */
/*   Updated: 2021/12/05 13:13:01 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>

void	ft_putchar(char c);

int	error(void)
{
	write(1, "Up to you!\n", 11);
	return (-1);
}

// 92 ASCII *
void	comprobar(int fila, int columna, int maxFila, int maxColumna)
{
	if (fila == 0)
	{
		if (columna == 0)
			ft_putchar('/');
		else if (columna == maxColumna)
			ft_putchar(92);
		else
			ft_putchar('*');
	}
	else if (fila == maxFila)
	{
		if (columna == 0)
			ft_putchar(92);
		else if (columna == maxColumna)
			ft_putchar('/');
		else
			ft_putchar('*');
	}
	else
	{
		if (columna == 0 || columna == maxColumna)
			ft_putchar('*');
		else
			ft_putchar(' ');
	}	
}

void	rush(int x, int y)
{
	int	columna;
	int	fila;

	fila = 0;
	if (x <= 0 || y <= 0)
		error();
	while (fila < y)
	{
		columna = 0;
		while (columna < x)
		{
			comprobar(fila, columna, y - 1, x - 1);
			columna ++;
		}
		ft_putchar('\n');
		fila ++;
	}
}
