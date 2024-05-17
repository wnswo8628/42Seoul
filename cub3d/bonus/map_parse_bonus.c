/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:55:31 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 16:15:02 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	get_player_xy(char **str, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E' || str[i][j] == 'W'
				|| str[i][j] == 'S' || str[i][j] == 'N')
			{
				player->player_x = i + 0.5;
				player->player_y = j + 0.5;
			}
			j++;
		}
		i++;
	}
}

void	check_wall(t_map *map, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0' || str[i][j] == 'N' || str[i][j] == 'W'
				|| str[i][j] == 'E' || str[i][j] == 'S')
			{
				if (i == 0 || j == 0)
					print_error("Error: Wall\n");
				else if (i == map->height || !str[i][j + 1])
					print_error("Error: Wall\n");
				else if (str[i - 1][j] == ' ' || str[i + 1][j] == ' ')
					print_error("Error: Wall\n");
				else if (str[i][j - 1] == ' ' || str[i][j + 1] == ' ')
					print_error("Error: Wall\n");
			}
			j++;
		}
		i++;
	}
}

void	map_dup(int fd, t_map *map)
{
	char	*line;
	int		i;
	char	*str;

	i = 0;
	while (i < map->height + 1)
	{
		line = get_next_line(fd);
		str = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!str)
			print_error("Error: str malloc\n");
		ft_memset(str, ' ', map->width);
		str[map->width] = '\0';
		ft_strcpy(str, line);
		map->full_map[i] = str;
		free(line);
		line = NULL;
		i++;
	}
}

void	find_map(int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	while (i < map->map_index - 1)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
}

void	map_parse(char *filename, t_map *map, t_player *player)
{
	int		fd;

	map->height = map->line_cnt - map->map_index;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Error: open\n");
	find_map(fd, map);
	map->full_map = (char **)malloc(sizeof(char *) * (map->height + 2));
	map->full_map[map->height + 1] = 0;
	if (!map)
		print_error("Error: malloc\n");
	map_dup(fd, map);
	check_wall(map, map->full_map);
	get_player_xy(map->full_map, player);
	close(fd);
}
