/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:25:33 by jrobles-          #+#    #+#             */
/*   Updated: 2021/11/28 20:53:38 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>

void	ft_putchar(char c);

void	error(void)
{
	write(1, "Up to you!\n", 11);
	exit (1);
}

void	comprobar(int fila, int columna, int maxFila, int maxColumna)
{
	if (fila == 0 || fila == maxFila)
	{
		if (columna == 0)
			ft_putchar('A');
		else if (columna == maxColumna)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (columna == 0 || columna == maxColumna)
			ft_putchar('B');
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
