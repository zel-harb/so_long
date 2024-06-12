/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:11:18 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/25 10:31:20 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves_right(t_img **img, int x, int y)
{
	(*img)->str[x][y] = '0';
	(*img)->str[x][y + 1] = 'N';
	(*img)->i = 0;
	if ((*img)->str[x][y + 2] != '0' && (*img)->str[x][y + 2] != 'P')
		(*img)->z = 1;
}

void	moves_left(t_img **img, int x, int y)
{
	(*img)->str[x][y] = '0';
	(*img)->str[x][y - 1] = 'N';
	(*img)->i = 0;
	if ((*img)->str[x][y - 2] != '0' && (*img)->str[x][y - 2] != 'P')
		(*img)->z = 0;
}

void	animation_move(t_img **img)
{
	int	x;
	int	y;

	x = (*img)->x_enemy / 50;
	y = (*img)->y_enemy / 50;
	if ((*img)->i == 100)
	{
		if (((*img)->str[x][y - 1] == 'P' && (*img)->z == 1)
			|| ((*img)->str[x][y + 1] == 'P' && (*img)->z == 0))
		{
			write(1, "LOSE !\n", 7);
			free_window_exit(*img, 0);
		}
		if (((*img)->str[x][y - 1] == '0' && (*img)->z == 1))
			moves_left(img, x, y);
		else if (((*img)->str[x][y + 1] == '0' && (*img)->z == 0))
			moves_right(img, x, y);
		(*img)->i = 0;
	}
}
