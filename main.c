/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:21:45 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/14 01:40:53 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_p(int keycode, t_img **game)
{
	if (keycode == 0 || keycode == 123)
		(*game)->x_pos = -1;
	else if (keycode == 13 || keycode == 126)
		(*game)->y_pos = -1;
	else if (keycode == 2 || keycode == 124)
		(*game)->x_pos = 1;
	else if (keycode == 1 || keycode == 125)
		(*game)->y_pos = 1;
	else if (keycode == 53)
		exit(0);
	ft_moves(game);
	mlx_clear_window((*game)->mlx, (*game)->mlx_win);
	put_img(game);
	print_window(game);
	(*game)->x_pos = 0;
	(*game)->y_pos = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_img	*img;

	if (check_ber(argv[1], argc) == 0)
		return (0);
	if (check_line(argv[1]) == 0)
		return (0);
	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		return (1);
	full_str(&img, argv[1]);
	if (check_map(&img) == 0)
		return (0);
	img->mlx = mlx_init();
	if (img->mlx == NULL)
		return (1);
	img->mlx_win = mlx_new_window(img->mlx, img->len * 50, img->count * 50,
			"so_long!");
	put_img(&img);
	print_window(&img);
	mlx_hook(img->mlx_win, 2, 0L, key_p, &img);
	mlx_hook(img->mlx_win, 17, 0, delete_window, NULL);
	mlx_loop(img->mlx);
	return (0);
}
