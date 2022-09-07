/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funciones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:27:47 by jrobles-          #+#    #+#             */
/*   Updated: 2021/12/12 21:27:52 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define CHUNK 1024

void	parse_dict(char *aux, char **tab_num, char **tab_desc);
char	*ft_atoi(char *str);
char	*ft_string(char *str);
int		str_len(char *str);
void	match(char *num, char **tab_num, char **tab_desc, int *tab_len);
void	print_dec(char **tab_desc, int *tab_len, int len);
void	ft_putstr(char *str);
int		fd_size(char *name);
char	*fd_copy(char *name, char *tab);
int		print_num(char **num, char **tab_num, char **tab_desc, int len);
void	print_num2(char **num, char **tab_num, char **tab_desc, int len);

void	parse_dict(char *aux, char **tab_num, char **tab_desc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*aux != '\0')
	{
		tab_num[i] = ft_atoi(aux);
		i++;
		while (*aux != ' ' || (*aux >= '0' && *aux <= '9'))
			aux++;
		aux++;
		while (*aux == ' ')
			aux++;
		tab_desc[j] = ft_string(aux);
		j++;
		while (*aux != '\n' && *aux != '0')
			aux++;
		if (*aux == '\n')
		{
			*aux = '\0';
			aux++;
		}
	}
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		str++;
	}
	write(1, " ", 1);
}

int	get_size(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	fd_size(char *name)
{
	char	buffer[1];
	int		count;
	int		fd;

	count = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	while ((read(fd, buffer, sizeof(char))) > 0)
		count++;
	close(fd);
	return (count);
}

char	*fd_copy(char *name, char *tab)
{
	char	buffer[1];
	int		i;
	int		fd;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	while ((read(fd, buffer, sizeof(char))) > 0)
	{
		tab[i] = buffer[0];
		i++;
	}
	close(fd);
	return (tab);
}
