/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alen <alen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:46:00 by alen              #+#    #+#             */
/*   Updated: 2025/02/07 18:30:16 by alen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*get_line(int fd, char *line, int read_size)
{
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_size = 1;
	while (!ft_strchr(line, '\n') && read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == 0)
		{
			free(buf);
			return (line);
		}
		if (read_size < 0)
		{
			free(buf);
			free(line);
			return (NULL);
		}
		buf[read_size] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

static	char	*ft_clean_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		++i;
	if (line[i] == '\n')
		str = (char *)malloc(i + 2);
	else
		str = (char *)malloc(i + 1);
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

char	*new_get_next_line(char *line)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(line);
	while (line[i] && line[i] != '\n')
		++i;
	if (i == len || (line[i] == '\n' && line[i + 1] == '\0'))
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(len - i);
	if (!str)
	{
		free(line);
		return (NULL);
	}
	len = i + 1;
	i = 0;
	while (line[len + i])
		str[i++] = line[len + i];
	str[i] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*clean_line;
	int			read_size;
	static char	*line;

	read_size = 1;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	line = get_line(fd, line, read_size);
	if (!line)
		return (NULL);
	clean_line = ft_clean_line(line);
	line = new_get_next_line(line);
	return (clean_line);
}
