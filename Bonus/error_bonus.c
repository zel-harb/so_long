/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:35:34 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/29 10:20:16 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *argv, int argc)
{
	int		i;
	char	*s;
	int		j;

	i = ft_strlen(argv);
	s = ".ber";
	if (i <= 4)
		return (0);
	j = 4;
	while (i != -1 && j != -1)
	{
		if (argv[0] == '.' || (argv[i] == '.' && argv[i - 1] == '/' && i != 0))
			return (0);
		if (argv[i] != s[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

int	check_error(t_img *read)
{
	int	i;
	int	count;

	i = 0;
	count = ft_strlen(read->str[0]);
	if (check_first_last(read->str[0]) == 0
		|| check_first_last(read->str[(read->count) - 1]) == 0)
	{
		write(2, "Error\nInvalid args\n", 20);
		return (0);
	}
	i++;
	while (read->str[i] && i < read->count)
	{
		if (check_mid(read->str[i]) == 0)
			return (0);
		if (count != ft_strlen(read->str[i]))
		{
			write(2, "Error\nInvalid size\n", 20);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_arg(t_img *read)
{
	char	tab[4];

	tab[0] = 'P';
	tab[1] = 'E';
	tab[2] = 'C';
	tab[3] = 'N';
	if (ft_strchr_int(read->str, tab[0], read->count) != 1
		|| ft_strchr_int(read->str, tab[1], read->count) != 1)
		return (0);
	if (!ft_strchr_int(read->str, tab[2], read->count)
		|| ft_strchr_int(read->str, tab[3], read->count) > 1)
		return (0);
	return (1);
}

void	flood_fill(t_img **map, int x, int y)
{
	if ((*map)->str_copy[y][x] == 'E' || (*map)->str_copy[y][x] == 'N')
		(*map)->str_copy[y][x] = '1';
	if (x < 0 || y < 0 || x >= (*map)->len || y >= (*map)->count
		|| ((*map)->str_copy[y][x] != '0' && (*map)->str_copy[y][x] != 'C'
			&& (*map)->str_copy[y][x] != 'P' && (*map)->str_copy[y][x] != 'E'
			&& (*map)->str_copy[y][x] != 'N'))
		return ;
	(*map)->str_copy[y][x] = 'X';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

int	check_map(t_img **read)
{
	if ((*read)->str == NULL)
	{
		write(2, "Error\nEmpty map\n", 19);
		return (1);
	}
	if (check_error(*read) == 0)
		return (1);
	if (check_arg(*read) == 0 || check_character((*read)->str) == 1)
	{
		write(2, "Error\nInvalid character\n", 25);
		return (1);
	}
	flood_fill(read, (*read)->x_player, (*read)->y_player);
	if (ft_strchr_int((*read)->str_copy, 'C', (*read)->count) != 0
		|| ft_strchr_int((*read)->str_copy, 'E', (*read)->count) != 0)
	{
		write(2, "Error\nInvalid path\n", 20);
		return (1);
	}
	return (0);
}
