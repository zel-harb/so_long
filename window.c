/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 04:28:29 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/11 04:29:16 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void full_str(t_data **read_m,char *argv)
{
    char *line;
    int k;
    int fd;
    
    k = 0;
    fd = open((const char *)argv,O_RDONLY);
    line = get_next_line(fd);
    if (line != NULL) {
       (*read_m)->str = ft_split(line, '\n');
       (*read_m)->count = count_words(line, '\n');
       (*read_m)->len = ft_strlen((*read_m)->str[0]);
        free(line);
    }
    close(fd);
    
}
void put_img(t_img **img)
{ 
    
    int     width;
    int     height;
    
    (*img)->img_wall = mlx_xpm_file_to_image((*img)->mlx, "img/wall.xpm", &width, &height);
    (*img)->img_player= mlx_xpm_file_to_image((*img)->mlx, "img/plyaer.xpm", &width, &height);
    (*img)->img_empty = mlx_xpm_file_to_image((*img)->mlx, "img/empty.xpm", &width, &height);
    (*img)->img_coll=mlx_xpm_file_to_image((*img)->mlx, "img/collectible.xpm", &width, &height);
    (*img)->img_exit=mlx_xpm_file_to_image((*img)->mlx, "img/exit.xpm", &width, &height);

}
void print_window(t_data *map,t_img *img)
{
    int i;
    int j;
    int i1;
    int j1;
    
    i = 0;
    j = 0;
    i1 = 0;
    j1 = 0;
    while(i  < map->count )
    {
        j = 0;
        j1=0;
        while(j < map->len )
        {
            mlx_put_image_to_window(img->mlx,img-> mlx_win,img->img_empty,j1, i1);
            if(map->str[i][j]=='1')
                mlx_put_image_to_window(img->mlx, img->mlx_win,img->img_wall,j1, i1);
            if(map->str[i][j]=='P')
                mlx_put_image_to_window(img->mlx, img->mlx_win,img->img_player,j1, i1);
            if(map->str[i][j]=='C')
                mlx_put_image_to_window(img->mlx,img->mlx_win,img->img_coll,j1, i1);
            if(map->str[i][j]=='E')
                mlx_put_image_to_window(img->mlx,img->mlx_win,img->img_exit,j1, i1);
            j++;
            j1+=50;
        }
       i++;
       i1+=50;
       
    }
}
