/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funci_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:55:49 by jrobles-          #+#    #+#             */
/*   Updated: 2021/12/16 01:55:50 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_null(void *a)
{
    if (a  ==  NULL)
    {
        write(1, "map error\n", 10);
        return (1);
    }
    return (0);
}
