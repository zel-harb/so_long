/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_pxl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:56:17 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/21 15:34:04 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_img(t_img *img)
{
	if (!img->img_wall || !img->img_player[0] || !img->img_player[1])
	{
		write(2, "Error\nInvalid images\n", 22);
		free_window_exit(img, 1);
	}
	else if (!img->img_empty || !img->img_exit[0] || !img->img_exit[1]
		|| !img->img_coll)
	{
		write(2, "Error\nInvalid images\n", 22);
		free_window_exit(img, 1);
	}
}

void	put_img(t_img **img)
{
	int	width;
	int	height;

	(*img)->img_wall = mlx_xpm_file_to_image((*img)->mlx, "textures/wall.xpm",
			&width, &height);
	(*img)->img_player[0] = mlx_xpm_file_to_image((*img)->mlx,
			"textures/player.xpm", &width, &height);
	(*img)->img_player[1] = mlx_xpm_file_to_image((*img)->mlx,
			"textures/player_s.xpm", &width, &height);
	(*img)->img_empty = mlx_xpm_file_to_image((*img)->mlx, "textures/empty.xpm",
			&width, &height);
	(*img)->img_coll = mlx_xpm_file_to_image((*img)->mlx,
			"textures/collectible.xpm", &width, &height);
	(*img)->img_exit[0] = mlx_xpm_file_to_image((*img)->mlx,
			"textures/exit.xpm", &width, &height);
	(*img)->img_exit[1] = mlx_xpm_file_to_image((*img)->mlx,
			"textures/exit00.xpm", &width, &height);
	check_img(*img);
}

void	put_image(t_img **img, int i, int j)
{
	if ((*img)->str[i][j] == '1')
		mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win, (*img)->img_wall,
			(*img)->y_pxl, (*img)->x_pxl);
	if ((*img)->str[i][j] == 'P')
	{
		(*img)->y_player = (*img)->y_pxl;
		(*img)->x_player = (*img)->x_pxl;
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

void	write_exit(char *line)
{
	free(line);
	write(2, "Error\nMap with an empty line\n", 30);
	exit(1);
}
