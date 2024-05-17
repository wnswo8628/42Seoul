/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:49:46 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 18:42:05 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_check(t_map *map, char *line, t_player *player)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W')
			print_error("Error: map\n");
		else if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			if (player->player_status != -1)
				print_error("Error: Player count\n");
			player->player_status = get_playerstatus(line[i]);
		}
		i++;
	}
	if (map->width < i)
		map->width = i;
	if (map->map_index == 0)
		map->map_index = map->line_cnt;
}

char	*check_path(char *line)
{
	int		fd;
	char	*result;

	line += 2;
	while (ft_isspace(*line))
		line++;
	fd = open(line, O_RDONLY);
	if (fd < 0)
		print_error("Error: texture\n");
	close(fd);
	result = ft_strdup(line);
	return (result);
}

void	get_texture(char *line, t_map *map)
{
	char	*temp;

	if (!ft_strncmp(line, "NO ", 3))
	{
		temp = check_path(line);
		map->no_path = temp;
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		temp = check_path(line);
		map->so_path = temp;
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		temp = check_path(line);
		map->we_path = temp;
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		temp = check_path(line);
		map->ea_path = temp;
	}
}

int	filename_check(char *filename)
{
	int		i;
	char	*temp;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
			temp = ft_substr(filename, i, ft_strlen(filename) - i);
		i++;
	}
	if (ft_strcmp(temp, ".cub") != 0)
	{
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}

void	line_check(char *line, t_map *map, t_player *player)
{
	int	i;

	i = 0;
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		get_texture(line, map);
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		get_rgb(line, map);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '0' || line[i] == '1')
	{
		if (!map->no_path || !map->so_path || !map->we_path || !map->ea_path
			|| map->f_rgb == -1 || map->c_rgb == -1)
			print_error("Error: no component\n");
		map_check(map, line, player);
	}
}
