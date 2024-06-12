/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:26:09 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/21 17:07:10 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_t_img(t_img *img)
{
	int	i;

	if (img == NULL)
		return ;
	if (img->str != NULL)
	{
		i = 0;
		while (img->str[i])
		{
			free(img->str[i]);
			i++;
		}
		free(img->str);
	}
}

void	free_t_img_copy(t_img *img)
{
	int	i;

	if (img == NULL)
		return ;
	if (img->str != NULL)
	{
		i = 0;
		while (img->str_copy[i])
		{
			free(img->str_copy[i]);
			i++;
		}
		free(img->str_copy);
	}
}

void	double_free(t_img *img)
{
	free_t_img_copy(img);
	free_t_img(img);
}

void	free_window_exit(t_img *img, int i)
{
	free_t_img(img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit(i);
}
