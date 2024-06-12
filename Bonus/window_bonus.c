/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 04:28:29 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/25 10:56:26 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_img **read)
{
	int	i;
	int	j;

	i = 0;
	while ((*read)->str[i])
	{
		j = 0;
		while ((*read)->str[i][j])
		{
			if ((*read)->str[i][j] == 'P')
			{
				(*read)->x_player = j;
				(*read)->y_player = i;
			}
			j++;
		}
		i++;
	}
}

void	full_str(t_img **read_m, char *argv)
{
	char	*line;
	int		k;
	int		fd;

	k = 0;
	fd = open((const char *)argv, O_RDONLY);
	line = get_next_line(fd);
	if (line != NULL)
	{
		(*read_m)->str = ft_split(line, '\n');
		(*read_m)->str_copy = ft_split(line, '\n');
		(*read_m)->count = count_words(line, '\n');
		(*read_m)->len = ft_strlen((*read_m)->str[0]);
		(*read_m)->count_coll = ft_strchr_int((*read_m)->str, 'C',
				(*read_m)->count);
		(*read_m)->count_moves = 0;
		free(line);
		find_player(read_m);
		(*read_m)->x_pxl = 0;
		(*read_m)->y_pxl = 0;
		(*read_m)->x_sp = 0;
		(*read_m)->z = 0;
		(*read_m)->i = 0;
	}
	close(fd);
}

void	put_image(t_img **img, int i, int j)
{
	if ((*img)->str[i][j] == '1')
		mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win, (*img)->img_wall,
			(*img)->y_pxl, (*img)->x_pxl);
	else if ((*img)->str[i][j] == 'P')
	{
		(*img)->y_player = (*img)->y_pxl;
		(*img)->x_player = (*img)->x_pxl;
	}
	else if ((*img)->str[i][j] == 'C')
	{
		mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win, (*img)->img_coll,
			(*img)->y_pxl, (*img)->x_pxl);
	}
	else if ((*img)->str[i][j] == 'N')
	{
		(*img)->y_enemy = (*img)->y_pxl;
		(*img)->x_enemy = (*img)->x_pxl;
		if ((*img)->str[i][j + 1] != '0' && (*img)->str[i][j + 1] != 'P')
			(*img)->z = 1;
		else if ((*img)->str[i][j - 1] != '0' && (*img)->str[i][j - 1] != 'P')
			(*img)->z = 0;
		animation(img);
	}
	else if ((*img)->str[i][j] == 'E')
		animation_exit(*img);
}

int	print_window(t_img **img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(*img)->x_pxl = 0;
	while (i < (*img)->count)
	{
		j = 0;
		(*img)->y_pxl = 0;
		while (j < (*img)->len)
		{
			mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win,
				(*img)->img_empty, (*img)->y_pxl, (*img)->x_pxl);
			put_image(img, i, j);
			j++;
			(*img)->y_pxl += 50;
		}
		i++;
		(*img)->x_pxl += 50;
	}
	mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win,
		(*img)->img_player[(*img)->x_sp], (*img)->y_player, (*img)->x_player);
	print_moves(*img);
	return (0);
}
