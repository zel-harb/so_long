/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:21:45 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/09 18:34:53 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int delete_window(void *param)
{
    exit(0);
}

// void full_str(t_data **read_m,int fd)
// {
//     char *line;
//     int k;
    
//     k = 0;
//     line =get_next_line(fd);
//    if (line != NULL) {
//        (*read_m)->str = ft_split(line, '\n');
//        (*read_m)->count= count_words(line, '\n');
//         free(line);
//     }

// }
void put_img(t_data *map,char *str, void *mlx,void *mlx_win)
{ 
    void    *img1;
    void    *img;
    void    *img2;
    int     width;
    int     height;
    int     i;
    int     j;
     int     i1;
    int     j1;
    i =0;
    j = 0;
    i1 =0;
    j1= 0;
    img1 = mlx_xpm_file_to_image(mlx, str, &width, &height);
    img = mlx_xpm_file_to_image(mlx, "_2_.xpm", &width, &height);
    img2 = mlx_xpm_file_to_image(mlx, "16.xpm", &width, &height);
    
    while(i  < map->count )
    {
        j = 0;
        j1=0;
        while(j <map->len)
        {
            mlx_put_image_to_window(mlx, mlx_win, img2,j1, i1);
            if(map->str[i][j]=='1')
             mlx_put_image_to_window(mlx, mlx_win, img1,j1, i1);
            if(map->str[i][j]=='P')
            mlx_put_image_to_window(mlx, mlx_win, img,j1, i1);
            j++;
            j1+=50;
        }
       i++;
       i1+=50;
       
    }

}
void back(t_data *map,void *mlx,void *mlx_win)
{

}

int main (int argc,char **argv)
{

    if(check_ber(argv[1],argc)==0)
    {
        write(2,"Erorr\n",6);
        return 0;
    }
    int fd;
    fd = open((const char *)argv[1],O_RDONLY);
    t_data *read_map;
    read_map = (t_data *)malloc(sizeof(t_data));
    full_str(&read_map,fd);
    if(check_map(read_map) == 0)
    {
      write(2,"Erorr\n",6);
        return 0;
    }
	void	*mlx;
	void	*mlx_win;
    void    *img;
    void    *img1;
    int     width;
    int     height;
    //  char *line;
    //  line=get_next_line(fd);
    //  printf("line is %s",line);
	mlx = mlx_init();
    if(mlx== NULL)
        return 1;
	mlx_win = mlx_new_window(mlx, read_map->len * 50 ,read_map->count * 50, "so_long!");
    //mlx_win = mlx_new_window(mlx, height, width, "so_long!");
    // if(mlx_win == NULL)
    //     return 1;
        

    // // mlx_string_put(mlx, mlx_win, 900 / 2, 500 / 2.32 32, 0x0000FF00, "so_long");
    //img = mlx_xpm_file_to_image(mlx, "_2_.xpm", &width, &height);
    //img1 = mlx_xpm_file_to_image(mlx, "Brick_Wall.xpm", &width, &height);
    put_img(read_map,"11.xpm",mlx,mlx_win);
    //  if (img == NULL)
    //     return 1;
//    mlx_put_image_to_window(mlx, mlx_win, img1,0, 0);
//     mlx_put_image_to_window(mlx, mlx_win, img1, 44, 0);
    // mlx_put_image_to_window(mlx, mlx_win, img, 88, 0);
	mlx_hook(mlx_win, 17, 0, delete_window, NULL);
    mlx_loop(mlx);

    return 0;
}
 