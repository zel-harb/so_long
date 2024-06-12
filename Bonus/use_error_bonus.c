/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:26:05 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/04 11:39:50 by zel-harb         ###   ########.fr       */
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
	{
		write(2, "Error\nInvalid size\n", 20);
		return (0);
	}
	if (line[ft_strlen(line) - 1] != '1')
	{
		write(2, "Error\nInvalid size\n", 20);
		return (0);
	}
	return (1);
}

void	check_line(char *argv)
{
	int		i;
	char	*line;

	line = get_next_line(open(argv, O_RDONLY));
	if (line == NULL)
	{
		write(2, "Error\nEmpty map\n", 17);
		exit(1);
	}
	close(open(argv, O_RDONLY));
	i = 0;
	if (line[i] == '\n')
		write_exit(line);
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (line[i + 1] == '\n')
				write_exit(line);
		}
		else if (line[i + 1] && line[i] == '\n')
			write_exit(line);
		i++;
	}
	free(line);
}

int	check_character(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P' || str[i][j] == 'E' || str[i][j] == '0')
				j++;
			else if (str[i][j] == '1' || str[i][j] == 'C' || str[i][j] == 'N')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
