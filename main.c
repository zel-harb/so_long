/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:21:45 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/12 12:13:50 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int delete_window(void *param)
{
    exit(0);
}
void ft_moves(t_img **img)
{
    int x;
    int y;

    x=(*img)->x_player;
    y=(*img)->y_player;
   if((*img)->y_pos == 1)
   {
    if((*img)->str[y+1][x]!='1' &&( (*img)->count_coll ==0 || (*img)->str[y+1][x] != 'E') )
    {
        if((*img)->str[y+1][x]=='C' && (*img)->count_coll !=0 )
            (*img)->count_coll--;
        if((*img)->str[y+1][x]=='E' &&(*img)->count_coll ==0 )
        {
            write(1,"you win !",10);
            exit(0);
        }
        (*img)->str[y][x]='0';
        (*img)->str[y+1][x]='P';
        (*img)->count_moves++;
        // write(1,"moves",)
    }
   }
   else if ((*img)->y_pos == -1)
   {
    if((*img)->str[y-1][x]!='1' &&( (*img)->count_coll ==0 || (*img)->str[y-1][x] != 'E') )
    {
         if((*img)->str[y-1][x]=='C' && (*img)->count_coll !=0)
            (*img)->count_coll--;
         if((*img)->str[y-1][x]=='E' &&(*img)->count_coll ==0 )
        {
            write(1,"you win !",10);
            exit(0);
        }
        (*img)->str[y][x]='0';
        (*img)->str[y-1][x]='P';
        (*img)->count_moves++;
    }
   }
    else if ((*img)->x_pos == 1)
    {
    if((*img)->str[y][x+1]!='1' &&( (*img)->count_coll ==0 || (*img)->str[y][x+1] != 'E') )
    {
         if((*img)->str[y][x+1]=='C' && (*img)->count_coll !=0)
            (*img)->count_coll--;
        if((*img)->str[y][x+1]=='E' &&(*img)->count_coll ==0 )
        {
            write(1,"you win !\n",10);
            exit(0);
        }
        (*img)->str[y][x]='0';
        (*img)->str[y][x+1]='P';
        (*img)->count_moves++;
    }
    }
    else if ((*img)->x_pos == -1)
    {
    if((*img)->str[y][x-1]!='1' &&( (*img)->count_coll ==0 || (*img)->str[y][x-1] != 'E')) 
    {
        if((*img)->str[y][x-1]=='C' && (*img)->count_coll !=0 )
            (*img)->count_coll--;
         if((*img)->str[y][x-1]=='E' &&(*img)->count_coll ==0 )
        {
            write(1,"you win !",10);
            exit(0);
        }
        (*img)->str[y][x]='0';
        (*img)->str[y][x-1]='P';
        (*img)->count_moves++;
    } 
    }
}

int   close_win(int keycode, t_img *var)
{
    if(keycode == 53)
    {
        exit(1);
    }
    return 0;
}
int key_p(int keycode, t_img **game )
{
   
    if (keycode == 0) // A
    {
       (*game)->x_pos=-1;
       (*game)->y_pos = 0;
    }
    else if (keycode == 13) // W 
    {
        (*game)->x_pos =0 ;
        (*game)->y_pos = -1;
    } 
    else if (keycode == 2) // D
    {
        (*game)->x_pos=1;
        (*game)->y_pos = 0;
    }
    else if (keycode == 1) // S
    {
        (*game)->x_pos= 0;
        (*game)->y_pos= 1;
    }
    else if(keycode == 53)
    {
         exit(0);
    }
 ft_moves(game);
mlx_clear_window((*game)->mlx, (*game)->mlx_win);
 put_img(game);
 print_window(game);
 
 
    return (0);
}



int main (int argc,char **argv)
{
    if(check_ber(argv[1],argc)==0)
        return 0;
    t_img *img;
    img = (t_img *)malloc(sizeof(t_img));
       if (img == NULL)
        return 1; 
    full_str(&img,argv[1]);
    if(check_map(img) == 0)
        return 0;
	img->mlx = mlx_init();
    if(img->mlx== NULL)
        return 1;
	img->mlx_win = mlx_new_window(img->mlx, img->len * 50 ,img->count * 50, "so_long!");
    put_img(&img);
    print_window(&img);
    mlx_hook(img->mlx_win, 2, 0L,key_p, &img);
   
    mlx_hook(img->mlx_win, 17, 0, delete_window, NULL);
    mlx_loop(img->mlx);
    return 0;
} 
