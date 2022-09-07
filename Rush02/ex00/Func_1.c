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

int		parse_dict(char *aux, char **tab_num, char **tab_desc);
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

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_atoi(char *str)
{
	int		i;
	int		j;
	int		count;
	char	*ret;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	count = len_str(str + i);
	ret = malloc(sizeof(char) * count + 1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*ft_string(char *str)
{
	char	*ret;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] >= 32 && str[i] <= 126)
	{
		i++;
		count++;
	}
	i = i - count;
	ret = malloc(sizeof(char) * count + 1);
	while (str[i] >= 32 && str[i] <= 126)
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
