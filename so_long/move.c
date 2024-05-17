/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:59:51 by jugwak            #+#    #+#             */
/*   Updated: 2023/02/23 20:53:14 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	printwalk(t_gameinfo *gameinfo)
{
	char	*result;

	result = ft_itoa(gameinfo->c_walk);
	write (1, "walk : ", 7);
	write (1, result, ft_strlen(result));
	write (1, "\n", 1);
	free(result);
}

void	move_w(t_gameinfo *gameinfo)
{
	int		x;
	int		y;

	correntplayer(gameinfo);
	x = gameinfo->player_x;
	y = gameinfo->player_y;
	if (gameinfo->map[x - 1][y] == 'C')
		gameinfo->countcollect++;
	if (gameinfo->map[x - 1][y] == 'E')
	{
		if (gameinfo->countcollect == gameinfo->c_collect)
		{
			write (1, "Game clear!\n", 12);
			exit(0);
		}
	}
	if (gameinfo->map[x - 1][y] != '1' && gameinfo->map[x - 1][y] != 'E')
	{
		gameinfo->map[x][y] = '0';
		gameinfo->map[x - 1][y] = 'P';
		gameinfo->c_walk++;
		printwalk(gameinfo);
		create_image(gameinfo);
	}
}

void	move_a(t_gameinfo *gameinfo)
{
	int		x;
	int		y;

	correntplayer(gameinfo);
	x = gameinfo->player_x;
	y = gameinfo->player_y;
	if (gameinfo->map[x][y - 1] == 'C')
		gameinfo->countcollect++;
	if (gameinfo->map[x][y - 1] == 'E')
	{
		if (gameinfo->countcollect == gameinfo->c_collect)
		{
			write (1, "Game clear!\n", 12);
			exit(0);
		}
	}
	if (gameinfo->map[x][y - 1] != '1' && gameinfo->map[x][y - 1] != 'E')
	{
		gameinfo->map[x][y] = '0';
		gameinfo->map[x][y - 1] = 'P';
		gameinfo->c_walk++;
		printwalk(gameinfo);
		create_image(gameinfo);
	}
}

void	move_s(t_gameinfo *gameinfo)
{
	int		x;
	int		y;

	correntplayer(gameinfo);
	x = gameinfo->player_x;
	y = gameinfo->player_y;
	if (gameinfo->map[x + 1][y] == 'C')
		gameinfo->countcollect++;
	if (gameinfo->map[x + 1][y] == 'E')
	{
		if (gameinfo->countcollect == gameinfo->c_collect)
		{
			write (1, "Game clear!\n", 12);
			exit(0);
		}
	}
	if (gameinfo->map[x + 1][y] != '1' && gameinfo->map[x + 1][y] != 'E')
	{
		gameinfo->map[x][y] = '0';
		gameinfo->map[x + 1][y] = 'P';
		gameinfo->c_walk++;
		printwalk(gameinfo);
		create_image(gameinfo);
	}
}

void	move_d(t_gameinfo *gameinfo)
{
	int		x;
	int		y;

	correntplayer(gameinfo);
	x = gameinfo->player_x;
	y = gameinfo->player_y;
	if (gameinfo->map[x][y + 1] == 'C')
		gameinfo->countcollect++;
	if (gameinfo->map[x][y + 1] == 'E')
	{
		if (gameinfo->countcollect == gameinfo->c_collect)
		{
			write (1, "Game clear!\n", 12);
			exit(0);
		}
	}
	if (gameinfo->map[x][y + 1] != '1' && gameinfo->map[x][y + 1] != 'E')
	{
		gameinfo->map[x][y] = '0';
		gameinfo->map[x][y + 1] = 'P';
		gameinfo->c_walk++;
		printwalk(gameinfo);
		create_image(gameinfo);
	}
}
