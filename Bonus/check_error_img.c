/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:26 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/29 09:51:40 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_img(t_img *img)
{
	if (!img->img_wall || !img->img_player[0] || !img->img_player[1])
	{
		ft_printf("Error\nInvalid images\n");
		free_window_exit(img, 1);
	}
	else if (!img->img_empty || !img->img_exit[0] || !img->img_exit[1]
		|| !img->img_coll)
	{
		ft_printf("Error\nInvalid images\n");
		free_window_exit(img, 1);
	}
	else if (!img->enemy[0] || !img->enemy[1] || !img->enemy[2])
	{
		ft_printf("Error\nInvalid images\n");
		free_window_exit(img, 1);
	}
	else if (!img->enemy[3] || !img->enemy[4])
	{
		ft_printf("Error\nInvalid images\n");
		free_window_exit(img, 1);
	}
}

void	write_exit(char *line)
{
	free(line);
	write(2, "Error\nMap with an empty line\n", 30);
	exit(1);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
