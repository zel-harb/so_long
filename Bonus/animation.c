/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:55:43 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/29 09:50:59 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_enemy(t_img **img)
{
	int	width;
	int	height;

	(*img)->enemy[0] = mlx_xpm_file_to_image((*img)->mlx, "textures/enmy00.xpm",
			&width, &height);
	(*img)->enemy[1] = mlx_xpm_file_to_image((*img)->mlx, "textures/enmy01.xpm",
			&width, &height);
	(*img)->enemy[2] = mlx_xpm_file_to_image((*img)->mlx, "textures/enmy02.xpm",
			&width, &height);
	(*img)->enemy[3] = mlx_xpm_file_to_image((*img)->mlx, "textures/enmy03.xpm",
			&width, &height);
	(*img)->enemy[4] = mlx_xpm_file_to_image((*img)->mlx, "textures/enmy04.xpm",
			&width, &height);
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
	put_img_enemy(img);
	check_img(*img);
}

void	animation(t_img **img)
{
	(*img)->i++;
	if ((*img)->i < 20)
		mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win, (*img)->enemy[0],
			(*img)->y_enemy, (*img)->x_enemy);
	else if ((*img)->i < 40)
		mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win, (*img)->enemy[1],
			(*img)->y_enemy, (*img)->x_enemy);
	else if ((*img)->i < 60)
		mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win, (*img)->enemy[2],
			(*img)->y_enemy, (*img)->x_enemy);
	else if ((*img)->i < 80)
		mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win, (*img)->enemy[3],
			(*img)->y_enemy, (*img)->x_enemy);
	else if ((*img)->i < 100)
	{
		mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win, (*img)->enemy[4],
			(*img)->y_pxl, (*img)->x_pxl);
	}
	(*img)->i++;
	animation_move(img);
}

void	animation_exit(t_img *img)
{
	if (img->count_coll == 0)
		mlx_put_image_to_window((img)->mlx, (img)->mlx_win, img->img_exit[1],
			img->y_pxl, img->x_pxl);
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img_exit[0],
			img->y_pxl, img->x_pxl);
}

void	print_moves(t_img *img)
{
	char	*str;
	char	*reslut;

	str = ft_itoa(img->count_moves);
	reslut = ft_strjoin2("MOVE : ", str);
	mlx_string_put(img->mlx, img->mlx_win, 15, 6, 0xFFFFFF, reslut);
	free(str);
	free(reslut);
}
