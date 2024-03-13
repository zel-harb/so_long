/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 04:28:29 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/13 02:07:39 by zel-harb         ###   ########.fr       */
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
	// printf("X  %d  Y  %d\n",(*read)->x_player,(*read)->y_player);
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
void	print_window(t_img **img)
{
	int	i;
	int	j;
	int	i1;
	int	j1;

	i = 0;
	j = 0;
	i1 = 0;
	j1 = 0;
	while (i < (*img)->count)
	{
		j = 0;
		j1 = 0;
		while (j < (*img)->len)
		{
			mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win,
				(*img)->img_empty, j1, i1);
			if ((*img)->str[i][j] == '1')
				mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win,
					(*img)->img_wall, j1, i1);
			if ((*img)->str[i][j] == 'P')
			{
				(*img)->x_player = j;
				(*img)->y_player = i;
				mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win,
					(*img)->img_player, j1, i1);
			}
			if ((*img)->str[i][j] == 'C')
			{
				mlx_put_image_to_window((*img)->mlx, (*img)->mlx_win,
					(*img)->img_coll, j1, i1);
			}
			if ((*img)->str[i][j] == 'E')
			{
				if ((*img)->count_coll == 0)
					mlx_put_image_to_window(((*img))->mlx, (*img)->mlx_win,
						(*img)->img_exit[1], j1, i1);
				else
					mlx_put_image_to_window(((*img))->mlx, (*img)->mlx_win,
						(*img)->img_exit[0], j1, i1);
			}
			j++;
			j1 += 50;
		}
		i++;
		i1 += 50;
	}
}
