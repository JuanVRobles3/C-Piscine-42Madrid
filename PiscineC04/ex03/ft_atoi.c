/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:15:13 by jrobles-          #+#    #+#             */
/*   Updated: 2021/12/12 00:15:15 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define SPACIOS " \t\n\v\f\r"

int has_any(char c, char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (c == str[i])
        {
            return (1);
        }
    }
    return (0);
}

int ft_atoi(char *str)
{
    int	c;
    int s;
    int res;

	c = 0;
    s = 1;
    res = 0;
    /*while (has_any(str[c], SPACIOS))
        c++;*/
     while(str[c] == '\t' ||str[c] == '\n' ||str[c] == '\v' ||str[c] == '\f' ||str[c] == '\r' || str[c] == ' ')
     {
         c++;
     }
    while (str[c] == '+' || str [c] == '-')
    {
        if (str[c] == '-')
        {
            s *= -1;
        }
        c++;
    }
    while(str[c] >= '0' && str[c] <= '9')
    {
        res = (str[c] - '0') + (res *10);
        c++;
    }	
    return (res * s);
}

int main()
{
    printf("%d\n", ft_atoi(" \t--+--+1234ab567"));
}