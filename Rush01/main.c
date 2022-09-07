/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:52:13 by jrobles-          #+#    #+#             */
/*   Updated: 2021/12/05 17:17:58 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	matrix(char *argv);

int main (int argc, char *argv[])
{
	/*if (argc != 2)
	{
		write(1, "Up to you!\n", 11);
	   return (-1);
	}*/
	printf ("Esto es argv:%s\n",argv[1]);
	//size(argv[1]);
	return (0);
}
