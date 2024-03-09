/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:21:37 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/09 02:24:51 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LONG_h
#define S_LONG_h

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include  <fcntl.h>
#include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct	s_dat {
	int count;
    int len;
    char **str;
}				t_data;
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
int check_ber(char *argv,int argc);
int check_map(t_data *read);
char	**ft_split(char const *s, char c);
int	count_words(char const *s, char c);
void   full_str(t_data **read_m,int fd);

#endif