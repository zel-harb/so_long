/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:21:45 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/11 04:35:15 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int delete_window(void *param)
{
    exit(0);
}

int main (int argc,char **argv)
{
    if(check_ber(argv[1],argc)==0)
        return 0;
    t_data *read_map;
    read_map = (t_data *)malloc(sizeof(t_data));
    full_str(&read_map,argv[1]);
    if(check_map(read_map) == 0)
        return 0;
    t_img  *img;
    img = (t_img *)malloc(sizeof(t_img));
    if (img == NULL)
        return 1; 
	img->mlx = mlx_init();
    if(img->mlx== NULL)
        return 1;
	img->mlx_win = mlx_new_window(img->mlx, read_map->len * 50 ,read_map->count * 50, "so_long!");
    put_img(&img);
    print_window(read_map,img);
	mlx_hook(img->mlx_win, 17, 0, delete_window, NULL);
    mlx_loop(img->mlx);

    return 0;
} 