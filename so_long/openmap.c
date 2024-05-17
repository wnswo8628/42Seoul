/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:59:56 by jugwak            #+#    #+#             */
/*   Updated: 2023/02/23 20:52:05 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	find_ber(char *mapfile, char *find)
{
	int	i;

	i = 0;
	while (find[i])
	{
		if (mapfile[i] != find[i])
			return (0);
		i++;
	}
	if (mapfile[i] == '\0')
		return (1);
	return (0);
}

int	checkfilename(char *mapfile)
{
	int	i;

	i = 0;
	while (mapfile[i])
	{
		if (mapfile[i] == '.')
		{
			if (find_ber(&mapfile[i], ".ber"))
				return (1);
		}
		i++;
	}
	return (0);
}

void	insertmap(int fd2, t_gameinfo *gameinfo)
{
	int		i;
	char	*line;

	i = 1;
	gameinfo->map = (char **)malloc(sizeof(char *) * (gameinfo->height + 1));
	line = get_next_line(fd2);
	if (line == NULL)
		printerror("Map error");
	gameinfo->width = ft_strlen(line) - 1;
	gameinfo->map[0] = ft_strdup(line);
	while (1)
	{
		free(line);
		line = get_next_line(fd2);
		if (line == NULL)
			break ;
		gameinfo->map[i] = ft_strdup(line);
		i++;
	}
	free(line);
	gameinfo->map[i] = NULL;
}

void	openmap(char *mapfile, t_gameinfo *gameinfo)
{
	char	*map;
	int		fd1;
	int		fd2;

	map = NULL;
	if (checkfilename(mapfile))
	{
		fd1 = open(mapfile, O_RDONLY);
		fd2 = open(mapfile, O_RDONLY);
		if (fd1 < 0)
			errormessage("Open");
		while (1)
		{
			if (map)
				free(map);
			map = get_next_line(fd1);
			if (map == NULL)
				break ;
			gameinfo->height++;
		}
		free(map);
		insertmap(fd2, gameinfo);
	}
	else
		errormessage("File name");
}
