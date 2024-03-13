/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:46:25 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/13 17:24:42 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	delete_window(void *param)
{
	exit(0);
}

int	close_win(int keycode, t_img *var)
{
	if (keycode == 53)
	{
		exit(1);
	}
	return (0);
}
