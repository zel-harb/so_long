/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:21:45 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/29 10:18:35 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_p(int keycode, t_img **game)
{
	if (keycode == 0)
		(*game)->x_pos = -1;
	else if (keycode == 13)
		(*game)->y_pos = -1;
	else if (keycode == 2)
		(*game)->x_pos = 1;
	else if (keycode == 1)
		(*game)->y_pos = 1;
	else if (keycode == 53)
		exit(0);
	ft_moves(game);
	mlx_clear_window((*game)->mlx, (*game)->mlx_win);
	print_window(game);
	(*game)->x_pos = 0;
	(*game)->y_pos = 0;
	return (1);
}

int	check_ber_line(char *argv, int argc)
{
	if (argc > 2)
	{
		write(2, "Error\nMore file name\n", 22);
		return (1);
	}
	if (check_ber(argv, argc) == 0)
	{
		ft_printf("Error\nInvalid name file\n");
		return (1);
	}
	check_line(argv);
	return (0);
}

void	window(t_img *img)
{
	put_img(&img);
	mlx_loop_hook(img->mlx, print_window, &img);
	mlx_hook(img->mlx_win, 2, 0L, key_p, &img);
	mlx_hook(img->mlx_win, 17, 0, delete_window, NULL);
	mlx_loop(img->mlx);
}

void	check_space(t_img *img)
{
	if (img->len > 52 || img->count > 27)
	{
		write(2, "Error\nInvalid size window\n", 27);
		double_free(img);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_img	*img;

	if (check_ber_line(argv[1], argc) == 1)
		return (1);
	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		return (1);
	full_str(&img, argv[1]);
	check_space(img);
	if (check_map(&img) == 1)
	{
		double_free(img);
		return (1);
	}
	free_t_img_copy(img);
	img->mlx = mlx_init();
	if (img->mlx == NULL)
	{
		free_t_img(img);
		return (1);
	}
	img->mlx_win = mlx_new_window(img->mlx, img->len * 50, img->count * 50,
			"so_long!");
	window(img);
	return (0);
}
