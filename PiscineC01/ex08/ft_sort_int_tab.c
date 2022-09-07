/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:56:32 by jrobles-          #+#    #+#             */
/*   Updated: 2021/12/06 20:21:54 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while(i<size)
	{
		j = i+1;
		while (j<size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i]=tab[j];
				tab[j]=temp;
			}
			j++;
		}
		i++;	
	}
}

int main (void)
{
	int tab[5] ={4, 2, 5, 1, 3};
		int size;

	size = 5;
	ft_sort_int_tab(tab, size);
	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]);
	printf("%d\n", tab[4]);
}
