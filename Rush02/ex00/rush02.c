/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontesi <pmontesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:12:30 by jasancho          #+#    #+#             */
/*   Updated: 2021/12/12 13:06:18 by pmontesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

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

int	main(int argc, char **argv)
{
	char	**tab_num;
	char	**tab_desc;
	int		*tab_len;
	char	*tab;
	int		i;

	if (argc == 2 && argv[1] != '\0')
	{
		if (argv[1][0] == '0')
			write(1, "zero", 4);
		tab = malloc(sizeof(*tab) * fd_size("numbers.dict"));
		tab = fd_copy("numbers.dict", tab);
		tab_num = malloc(sizeof(*tab_num) * 50);
		tab_desc = malloc(sizeof(*tab_desc) * 50);
		tab_len = malloc(sizeof(*tab_desc) * 50);
		parse_dict(tab, tab_num, tab_desc);
		i = 0;
		while (tab_num[i] != 0)
		{
			tab_len[i] = str_len(tab_num[i]);
			i++;
		}
		match(argv[1], tab_num, tab_desc, tab_len);
	}
	return (0);
}

void	match(char *num, char **tab_num, char **tab_desc, int *tab_len)
{
	int	i;
	int	len_num;
	int	len_1;
	int	found;

	i = 0;
	found = 0;
	while (num[i] != 0)
		i++;
	len_num = i;
	while (len_num > 0)
	{
		if (*num == '0')
			num++;
		len_1 = len_num % 3;
		if (len_1 == 0)
			len_1 = 1;
		i = 0;
		found = print_num(&num, tab_num, tab_desc, len_1);
		if (found == 0)
			print_num2(&num, tab_num, tab_desc, len_1);
		if (len_num / 3 > 0)
			print_dec(tab_desc, tab_len, (len_num - len_1 + 1));
		len_num = len_num - len_1;
	}
}

int	print_num(char **num_ref, char **tab_num, char **tab_desc, int len)
{
	int		found;
	int		i;
	char	*num;

	found = 0;
	i = 0;
	num = *num_ref;
	while (tab_num[i] != 0)
	{
		if (tab_num[i][0] == *num && tab_num[i][1] == *(num + 1) && len == 2)
		{
			found = 1;
			ft_putstr(tab_desc[i]);
			num++;
			num++;
		}
		i++;
	}
	*num_ref = num;
	return (found);
}

void	print_num2(char **num_ref, char **tab_num, char **tab_desc, int len)
{
	int		i;
	char	*num;

	i = 0;
	num = *num_ref;
	while (tab_num[i] != 0)
	{
		if (tab_num[i][0] == *num && tab_num[i][1] == '0' && len == 2)
		{
			ft_putstr(tab_desc[i]);
			num++;
			len--;
			i = 0;
		}
		if (tab_num[i][0] == *num && len == 1)
		{
			ft_putstr(tab_desc[i]);
			num++;
		}
		i++;
	}
	*num_ref = num;
}

void	print_dec(char **tab_desc, int *tab_len, int len)
{
	int	found;
	int	i;

	found = 0;
	i = 0;
	while (tab_len[i] != 0 && found == 0)
	{
		if (tab_len[i] == len)
		{
			ft_putstr(tab_desc[i]);
			found = 1;
		}
		i++;
	}
}
