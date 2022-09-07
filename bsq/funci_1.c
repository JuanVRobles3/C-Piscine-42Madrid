/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funci_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:53:41 by jrobles-          #+#    #+#             */
/*   Updated: 2021/12/16 01:53:43 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_square    *max_square(char **grid, t_info *info, int x, int y)
{
    t_square    *sq;
    int            max_edge;
    int            i;

    sq = malloc(sizeof(t_square));
    max_edge = 0;
    sq->edge = 0;
    i = 0;
    sq->init_x = x;
    sq->init_y = y;
    while ((x + max_edge < info->columns) && (grid[y][x + max_edge] == info->empty))
        max_edge++;
    while ((y + i < info->rows) && (grid[y + i][x] == info->empty))
        i++;
    if (i < max_edge)
        max_edge = i;
    i = max_edge;
    while (i > 0)
    {
        sq->edge = i;
        if (is_valid_square(grid, sq, info))
            break ;
        i--;
    }
    //printf("%i %i %i\n", sq->init_x, sq->init_y, sq->edge);
    return (sq);
}
t_square    *ft_calculate_solution(char **grid, t_info *info)
{
    int            i;
    int            j;
    t_square    *sq;
    int            max;
    max = 0;
    j = 0;
    while (j < info->rows)
    {
        i = 0;
        while (i < info->columns)
        {
            if (max_square(grid, info, i, j)->edge > max)
            {
                if (max > 0)
                    free(sq);
                sq = max_square(grid, info, i, j);
                max = sq->edge;
            }
            i++;
        }
        j++;
    }
    return (sq);
}
void    *free_ob_ret(char **buff, char ***grid, t_info *info)
{
    int    i;
    i = 0;
    free(*buff);
    while ((*grid)[i] != NULL)
    {
        free((*grid)[i]);
        i++;
    }
    free(*grid);
    return (info);
}
int    is_valid_line(char    *buff, t_info *info)
{
    while (*buff != 0 && *buff != '\n')
    {
        if ((*buff != info->empty) && (*buff != info->obstacle))
            return (0);
        buff++;
    }
    return (1);
}
