/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:00:21 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 18:46:28 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	init_map(t_map *map, t_player *player)
{
	map->full_map = NULL;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->line_cnt = 0;
	player->player_status = -1;
	map->width = 0;
	map->height = 0;
	map->map_index = 0;
	map->f_rgb = -1;
	map->c_rgb = -1;
}

int	file_parsing(char *filename, t_map *map, t_player *player)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	init_map(map, player);
	line = get_next_line(fd);
	if (line == NULL)
		return (1);
	while (line)
	{
		map->line_cnt++;
		line_check(line, map, player);
		free(line);
		line = get_next_line(fd);
	}
	if (player->player_status == -1)
		print_error("Error: no player\n");
	close(fd);
	map_parse(filename, map, player);
	return (0);
}

void	set_color(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < (int)HEIGHT / 2)
				info->buf[i][j] = info->map.c_rgb;
			else
				info->buf[i][j] = info->map.f_rgb;
			j++;
		}
		i++;
	}
}

int	main_loop(t_info *info)
{
	raycasting(info);
	draw_buffer(info);
	check_key(info);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		print_error("Error: argument\n");
	if (filename_check(av[1]))
		print_error("Error: filename\n");
	if (file_parsing(av[1], &info.map, &info.player))
		print_error("Error: file\n");
	all_init(&info);
	set_color(&info);
	set_image(&info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, end_program, &info);
	mlx_loop(info.mlx);
	return (0);
}
