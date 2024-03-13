/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 04:28:29 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/13 17:24:01 by zel-harb         ###   ########.fr       */
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
	}
	close(fd);
}

void	put_img(t_img **img)
{
	int	width;
	int	height;

	(*img)->img_wall = mlx_xpm_file_to_image((*img)->mlx, "img/wall.xpm",
			&width, &height);
	(*img)->img_player = mlx_xpm_file_to_image((*img)->mlx, "img/plyaer.xpm",
			&width, &height);
	(*img)->img_empty = mlx_xpm_file_to_image((*img)->mlx, "img/empty.xpm",
			&width, &height);
	(*img)->img_coll = mlx_xpm_file_to_image((*img)->mlx, "img/collectible.xpm",
			&width, &height);
	(*img)->img_exit = malloc(2 * sizeof(void *));
	(*img)->img_exit[0] = mlx_xpm_file_to_image((*img)->mlx, "img/exit.xpm",
			&width, &height);
	(*img)->img_exit[1] = mlx_xpm_file_to_image((*img)->mlx, "img/51.xpm",
			&width, &height);
}

void	put_image(t_img **img, int i, int j)
{
	if ((*img)->str[i][j] == '1')
		mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win, (*img)->img_wall,
			(*img)->y_pxl, (*img)->x_pxl);
	if ((*img)->str[i][j] == 'P')
	{
		(*img)->x_player = j;
		(*img)->y_player = i;
		mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win,
			(*img)->img_player, (*img)->y_pxl, (*img)->x_pxl);
	}
	if ((*img)->str[i][j] == 'C')
	{
		mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win, (*img)->img_coll,
			(*img)->y_pxl, (*img)->x_pxl);
	}
	if ((*img)->str[i][j] == 'E')
	{
		if ((*img)->count_coll == 0)
			mlx_put_image_to_window(((*img))->mlx, (*img)->mlx_win,
				(*img)->img_exit[1], (*img)->y_pxl, (*img)->x_pxl);
		else
			mlx_put_image_to_window(((*img))->mlx, (*img)->mlx_win,
				(*img)->img_exit[0], (*img)->y_pxl, (*img)->x_pxl);
	}
}

void	print_window(t_img **img)
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
}
