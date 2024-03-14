/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:26:05 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/14 01:43:31 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr_int(char **s, char c, int size)
{
	int	ds;
	int	i;
	int	j;

	i = 0;
	ds = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < ft_strlen(s[i]))
		{
			if (s[i][j] == c)
				ds++;
			j++;
		}
		i++;
	}
	return (ds);
}

int	check_first_last(char *line)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_mid(char *line)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (0);
	if (line[ft_strlen(line) - 1] != '1')
		return (0);
	return (1);
}

int	check_line(char *argv)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	close(fd);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (line[i + 1] == '\n')
			{
				write(2, "Error\n", 6);
				free(line);
				return (0);
			}
		}
		i++;
	}
	free(line);
	return (1);
}
