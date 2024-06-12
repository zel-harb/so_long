/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:21:37 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/29 09:48:05 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_img
{
	int		count;
	int		len;
	char	**str;
	char	**str_copy;
	int		x_pxl;
	int		y_pxl;
	void	*mlx;
	void	*mlx_win;
	void	*img_wall;
	void	*img_player[2];
	void	*img_empty;
	void	*img_coll;
	void	*img_exit[2];
	int		count_coll;
	int		x_pos;
	int		y_pos;
	int		x_player;
	int		y_player;
	int		x_enemy;
	int		y_enemy;
	int		count_moves;
	int		x_sp;
	void	*enemy[5];
	int		z;
	int		i;

}			t_img;

int			ft_strchr_int(char **s, char c, int size);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *src);
char		*ft_strjoin2(char *s1, char *s2);
char		*ft_itoa(int nbr);
size_t		ft_strlen(char *str);
char		*get_next_line(int fd);
int			ft_strchr_int(char **s, char c, int size);
int			check_ber(char *argv, int argc);
int			check_map(t_img **read);
char		**ft_split(char const *s, char c);
int			count_words(char const *s, char c);
void		full_str(t_img **read_m, char *argv);
int			check_character(char **str);
int			print_window(t_img **img);
int			check_first_last(char *line);
int			check_mid(char *line);
void		ft_moves(t_img **img);
int			close_win(int keycode, t_img *var);
int			delete_window(void *param);
void		check_line(char *argv);
void		find_player(t_img **read);
void		animation(t_img **img);
void		animation_exit(t_img *img);
void		put_img(t_img **img);
void		print_moves(t_img *img);
void		check_img(t_img *img);
void		write_exit(char *line);
void		free_t_img(t_img *img);
void		free_t_img_copy(t_img *img);
void		double_free(t_img *img);
void		free_window_exit(t_img *img, int i);
void		animation_move(t_img **img);

#endif