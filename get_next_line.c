/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alen <alen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:46:00 by alen              #+#    #+#             */
/*   Updated: 2025/02/07 17:10:41 by alen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = ft_strlen(src) + 1;
	dup = (char *)malloc(len * sizeof(char));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}

char *get_line(int fd, char *line)
{
	char	*buf;
	int		read_size;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_size = 1;
	while (!ft_strchr(line, '\n') && read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_size] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char *ft_clean_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		++i;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		++i;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
char *new_get_next_line(char *line)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(line);
	while(line[i] && line[i] != '\n')
		++i;
	str = (char *)malloc(len - i);
	if (!str)
	{
		free(line);
		return (NULL);
	}
	len = i + 1;
	i = 0;
	while(line[len + i])
	{
		str[i] = line[len + i];
		++i;
	}
	str[i] = '\0';
	free(line);
	return (str);
}
char *get_next_line(int fd)
{
	char		*clean_line;
	static char	*line;

	line = get_line(fd, line);
	if (!line)
		return (NULL);
	clean_line = ft_clean_line(line);
	line = new_get_next_line(line);
	return (clean_line);
}
