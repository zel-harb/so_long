/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:38:27 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/17 21:16:50 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*to_read(int fd, char *str)
{
	char	*buf;
	int		i;

	i = 1;
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[i] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*show_line(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i])
		i++;
	s = malloc(i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*new_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = to_read(fd, str);
	if (!str)
		return (NULL);
	s_str = show_line(str);
	str = new_line(str);
	return (s_str);
}
