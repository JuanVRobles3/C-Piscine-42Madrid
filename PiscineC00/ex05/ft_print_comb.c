/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:59:08 by jrobles-          #+#    #+#             */
/*   Updated: 2021/11/30 13:27:07 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_imprime(char a, char b, char c, bool cond)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (cond)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;
	bool	cond;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				cond = !(a == '7' && b == '8' && c == '9');
				ft_imprime(a, b, c, cond);
				c ++;
			}
			b ++;
		}
		a ++;
	}
}
