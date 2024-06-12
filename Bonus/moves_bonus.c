/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:38:04 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/21 16:43:23 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	down(t_img **img, int x, int y)
{
	if ((*img)->str[y + 1][x] == 'N')
	{
		write(1, "LOSE !\n", 7);
		free_window_exit(*img, 0);
	}
	if ((*img)->str[y + 1][x] != '1' && ((*img)->count_coll == 0
			|| (*img)->str[y + 1][x] != 'E'))
	{
		if ((*img)->str[y + 1][x] == 'C' && (*img)->count_coll != 0)
			(*img)->count_coll--;
		if ((*img)->str[y + 1][x] == 'E' && (*img)->count_coll == 0)
		{
			write(1, "you win !", 10);
			free_window_exit(*img, 0);
		}
		(*img)->str[y][x] = '0';
		(*img)->str[y + 1][x] = 'P';
		(*img)->count_moves++;
	}
}

void	up(t_img **img, int x, int y)
{
	if ((*img)->str[y - 1][x] == 'N')
	{
		write(1, "LOSE !\n", 7);
		free_window_exit(*img, 0);
	}
	if ((*img)->str[y - 1][x] != '1' && ((*img)->count_coll == 0
			|| (*img)->str[y - 1][x] != 'E'))
	{
		if ((*img)->str[y - 1][x] == 'C' && (*img)->count_coll != 0)
			(*img)->count_coll--;
		if ((*img)->str[y - 1][x] == 'E' && (*img)->count_coll == 0)
		{
			write(1, "you win !", 10);
			free_window_exit(*img, 0);
		}
		(*img)->str[y][x] = '0';
		(*img)->str[y - 1][x] = 'P';
		(*img)->y_player = y - 1;
		(*img)->count_moves++;
	}
}

void	right(t_img **img, int x, int y)
{
	if ((*img)->str[y][x + 1] == 'N')
	{
		write(1, "LOSE !\n", 7);
		free_window_exit(*img, 0);
	}
	if ((*img)->str[y][x + 1] != '1' && ((*img)->count_coll == 0
			|| (*img)->str[y][x + 1] != 'E'))
	{
		if ((*img)->str[y][x + 1] == 'C' && (*img)->count_coll != 0)
			(*img)->count_coll--;
		if ((*img)->str[y][x + 1] == 'E' && (*img)->count_coll == 0)
		{
			write(1, "you win !\n", 10);
			free_window_exit(*img, 0);
		}
		(*img)->str[y][x] = '0';
		(*img)->str[y][x + 1] = 'P';
		(*img)->count_moves++;
		(*img)->x_sp = 0;
	}
}

void	left(t_img **img, int x, int y)
{
	if ((*img)->str[y][x - 1] == 'N')
	{
		write(1, "LOSE !\n", 7);
		free_window_exit(*img, 0);
	}
	if ((*img)->str[y][x - 1] != '1' && ((*img)->count_coll == 0
			|| (*img)->str[y][x - 1] != 'E'))
	{
		if ((*img)->str[y][x - 1] == 'C' && (*img)->count_coll != 0)
			(*img)->count_coll--;
		if ((*img)->str[y][x - 1] == 'E' && (*img)->count_coll == 0)
		{
			write(1, "you win !", 10);
			free_window_exit(*img, 0);
		}
		(*img)->str[y][x] = '0';
		(*img)->str[y][x - 1] = 'P';
		(*img)->count_moves++;
		(*img)->x_sp = 1;
	}
}

void	ft_moves(t_img **img)
{
	int	x;
	int	y;

	y = (*img)->x_player / 50;
	x = (*img)->y_player / 50;
	if ((*img)->y_pos == 1)
		down(img, x, y);
	else if ((*img)->y_pos == -1)
		up(img, x, y);
	else if ((*img)->x_pos == 1)
		right(img, x, y);
	else if ((*img)->x_pos == -1)
		left(img, x, y);
}
