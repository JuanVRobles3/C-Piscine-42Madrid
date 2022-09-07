/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:48:05 by jrobles-          #+#    #+#             */
/*   Updated: 2021/12/07 18:56:01 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	a;
	
	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] < 32 || str [a] > 126)
			return (0);
		a++;
	}
	return (1);
}