/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:36:15 by jrobles-          #+#    #+#             */
/*   Updated: 2021/12/08 14:03:25 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
char    *ft_strcpy(char *dest, char *src);
int main(void)
{
    char    *dest;
    char    *src;
    src = "hola ";
    printf("src: %s\n", src);
    ft_strcpy(dest, src);
    printf("dest: %s\n", dest);
    return (0);
}
