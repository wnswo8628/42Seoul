/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:23:18 by jugwak            #+#    #+#             */
/*   Updated: 2023/02/23 20:52:13 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	checkmap(t_gameinfo *gameinfo)
{
	t_check	check;
	int		i;

	i = 0;
	checkwall(gameinfo);
	elementcount(gameinfo);
	if (gameinfo->c_player != 1 || gameinfo->c_exit != 1
		|| gameinfo->c_collect < 1)
		printerror("Element count error");
	check_rectangle(gameinfo);
	makecheck(&check, gameinfo);
	dfs(&check, gameinfo, check.x, check.y);
	while (i < gameinfo->height)
	{
		free(check.tempmap[i]);
		i++;
	}
	free(check.tempmap);
	if (check.way == 0 || check.check_collect != gameinfo->c_collect)
		printerror("Map way error");
}

void	structinit(t_gameinfo *gameinfo)
{
	gameinfo->height = 0;
	gameinfo->width = 0;
	gameinfo->c_collect = 0;
	gameinfo->c_exit = 0;
	gameinfo->c_player = 0;
	gameinfo->countcollect = 0;
	gameinfo->c_walk = 0;
}

int	keyesc(t_gameinfo *gameinfo)
{
	mlx_destroy_window(gameinfo->mlx_ptr, gameinfo->win_ptr);
	exit(0);
}

int	keypress(int keycode, t_gameinfo *gameinfo)
{
	if (keycode == KEY_W)
		move_w(gameinfo);
	else if (keycode == KEY_A)
		move_a(gameinfo);
	else if (keycode == KEY_S)
		move_s(gameinfo);
	else if (keycode == KEY_D)
		move_d(gameinfo);
	else if (keycode == KEY_ESC)
		keyesc(gameinfo);
	return (0);
}

int	main(int ac, char **av)
{
	t_gameinfo	gameinfo;

	if (ac != 2)
		printerror("Usage : ./so_long [map File]\n");
	structinit(&gameinfo);
	openmap(av[1], &gameinfo);
	checkmap(&gameinfo);
	gameinfo.mlx_ptr = mlx_init();
	gameinfo.win_ptr = mlx_new_window(gameinfo.mlx_ptr, 64 * gameinfo.width,
			64 * gameinfo.height, "so_long");
	create_image(&gameinfo);
	mlx_key_hook(gameinfo.win_ptr, keypress, &gameinfo);
	mlx_hook(gameinfo.win_ptr, X_EVENT_KEY_EXIT, 0, &keyesc, &gameinfo);
	mlx_loop(gameinfo.mlx_ptr);
	return (0);
}
