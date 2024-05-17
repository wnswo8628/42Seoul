/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:36:55 by jugwak            #+#    #+#             */
/*   Updated: 2022/08/30 21:08:06 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_read(char *files, int i)
{
	char	*line;

	if (!files[i])
		return (NULL);
	while (files[i] != '\n' && files[i] != '\0')
		i++;
	if (files[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (files[i] != '\0' && files[i] != '\n')
	{
		line[i] = files[i];
		i++;
	}
	if (files[i] == '\n')
	{
		line[i] = files[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*left_file(char *files)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	len = 0;
	while (files[len] && files[len] != '\n')
		len++;
	if (!files[len])
	{
		free(files);
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(files) - len + 1));
	if (!result)
		return (NULL);
	if (files[len] == '\n')
		len++;
	while (files[len])
		result[i++] = files[len++];
	result[i] = '\0';
	free(files);
	files = NULL;
	return (result);
}

char	*read_file(int fd, char *files)
{
	char	buf[BUFFER_SIZE + 1];
	int		len;

	len = 1;
	while (!ft_strchr(files, '\n') && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		buf[len] = '\0';
		files = ft_strjoin(files, buf);
	}
	return (files);
}

char	*get_next_line(int fd)
{
	static char	*sentense[OPEN_MAX];
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	sentense[fd] = read_file(fd, sentense[fd]);
	if (!sentense[fd])
		return (NULL);
	line = line_read(sentense[fd], i);
	sentense[fd] = left_file(sentense[fd]);
	return (line);
}
