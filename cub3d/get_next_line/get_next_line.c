/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:05:17 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 20:05:31 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	result = (char *)malloc(sizeof(char) * (ft_strlen2(files) - len + 1));
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

char	*remove_newline(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	if (line == NULL)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	temp = ft_substr2(line, 0, i);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*sentense;
	char		*line;
	char		*result;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	sentense = read_file(fd, sentense);
	if (!sentense)
		return (NULL);
	line = line_read(sentense, i);
	sentense = left_file(sentense);
	result = remove_newline(line);
	free(line);
	return (result);
}
