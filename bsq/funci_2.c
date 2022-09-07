/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funci_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:55:12 by jrobles-          #+#    #+#             */
/*   Updated: 2021/12/16 01:55:13 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_squarespace(t_info *info)
{
    char    *buff;
    char    **grid;
    int        i;
    int        readed_chars;
    char    c;
    i = 0;
    c = 0;
    grid = malloc((info->rows + 1) * sizeof(char *));
    buff = malloc((info->columns + 1) * sizeof(char));
    while (i < info->rows)
    {
        if (i == 0)
            grid[i] = info->first_line;
        else
        {
            readed_chars = read(info->fd, buff, info->columns + 1);
            if (buff[info->columns] != '\n')
                //return (free_ob_ret(&buff, &grid, NULL));
                return (NULL);
            buff[info->columns] = 0;
            if (!is_valid_line(buff, info))
                return (NULL);
            grid[i] = ft_strdup(buff);
        }
        i++;
    }
    write(1, "\n", 1);
    ft_print_solution(ft_calculate_solution(grid, info), grid, info);
    //return (free_ob_ret(&buff, &grid, info));
    return (info);
}
int read_first_line(t_info *info)
{
    char    c;
    char    buff[1024];
    int        i;
    i = 0;
    c = 0;
    while (c != '\n')
    {
        read(info->fd, &c, 1);
        buff[i] = c;
        i++;
    }
    buff[i] = 0;
    if (!is_valid_line(buff, info))
        return (-1);
    info->first_line = ft_strdup(buff);
    return (ft_strlen(buff));
}
t_info    *get_dimensions_and_chars(int fd)
{
    char    c;
    t_info    *info;
    int        i;
    int        cont;
    char    buff[1024];
    cont = 1;
    info = malloc(sizeof(t_info));
    info->rows = 0;
    i = 0;
    read(fd, &c, 1);
    while (c != '\n')
    {
        buff[i] = c;
        read(fd, &c, 1);
        i++;
    }
    if (i < 3)
        return (NULL);
    info->full = buff[i - 1];
    info->obstacle = buff[i - 2];
    info->empty = buff[i - 3];
    i = i - 4;
    while  (i >= 0)
    {
        if (buff[i] > '9' || buff[i] < '0')
            return (NULL);
        info->rows += (buff[i] - '0') * cont;
        i--;
        cont *= 10;
    }
    info->fd = fd;
    if (c != '\n' || ((info->empty == info->full)
    || (info->full == info->obstacle) || (info->empty == info->obstacle)
    || info->empty < 32 || info->obstacle < 32 || info->full < 32))
        return (NULL);
    info->columns = read_first_line(info);
    if (info->columns == -1)
        return (NULL);
    return (info);
}
