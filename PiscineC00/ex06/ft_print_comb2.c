/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:27:50 by jrobles-          #+#    #+#             */
/*   Updated: 2021/11/30 13:45:49 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_imprime(int a, int b, bool cond)
{
	ft_putchar(48 + a / 10);
	ft_putchar(48 + a % 10);
	ft_putchar (' ');
	ft_putchar(48 + b / 10);
	ft_putchar(48 + b % 10);
	if (cond)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	bool	cond;
	int		a;
	int		b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			cond = !(a == 98 && b == 99);
			ft_imprime (a, b, cond);
			b++;
		}
		a ++;
	}
}
