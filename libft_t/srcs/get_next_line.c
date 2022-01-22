/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:30:51 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/11 16:34:10 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	newline(char *save)
{
	while (*save)
	{
		if (*save == '\n')
			return (1);
	save++;
	}
	return (0);
}

size_t	linelengh(char **save)
{
	size_t	i;

	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	return (i);
}

char	*cutsave(char **save)
{
	char	*line;
	char	*tmp_rest;
	size_t	linlen;

	line = NULL;
	tmp_rest = NULL;
	linlen = linelengh(&(*save));
	if ((*save)[linlen] == '\n')
	{
		line = ft_substr(*save, 0, (linlen + 1));
		tmp_rest = ft_strdup(&(*save)[linlen + 1]);
	}
	if ((*save)[linlen] == '\0')
		line = ft_strdup(*save);
	free(*save);
	*save = tmp_rest;
	if (*line == '\0')
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char	*read_fd(int fd, char **buf)
{
	static char	*save[10496];
	char		*tmp;
	size_t		bytes;

	bytes = 1;
	if (!save[fd])
		save[fd] = ft_strdup("");
	while (!newline(save[fd]) && bytes)
	{
		bytes = read(fd, *buf, BUFFER_SIZE);
		(*buf)[bytes] = '\0';
		tmp = save[fd];
		save[fd] = ft_strjoin(tmp, *buf);
		free(tmp);
	}
	free(*buf);
	return (cutsave(&save[fd]));
}

char	*get_next_line(int fd)
{
	char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		return (NULL);
	}
	return (read_fd(fd, &buf));
}
