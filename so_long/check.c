/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:00:10 by jugwak            #+#    #+#             */
/*   Updated: 2023/02/23 20:57:36 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	checkwall(t_gameinfo *gameinfo)
{
	int	i;
	int	j;

	i = 0;
	while (i < gameinfo->height)
	{
		j = 0;
		while (j < gameinfo->width)
		{
			if (i == 0 && gameinfo->map[i][j] != '1')
				printerror("Map error");
			else if (i == gameinfo->height - 1 && gameinfo->map[i][j] != '1')
				printerror("Map error");
			else if (j == 0 && gameinfo->map[i][j] != '1')
				printerror("Map error");
			else if (j == gameinfo->width - 1 && gameinfo->map[i][j] != '1')
				printerror("Map error");
			j++;
		}
		i++;
	}
}

void	elementcount(t_gameinfo *gameinfo)
{
	int	i;
	int	j;

	i = 0;
	while (i < gameinfo->height)
	{
		j = 0;
		while (j < gameinfo->width)
		{
			if (gameinfo->map[i][j] != 'P' && gameinfo->map[i][j] != 'E'
				&& gameinfo->map[i][j] != 'C' && gameinfo->map[i][j] != '0'
				&& gameinfo->map[i][j] != '1')
				printerror("Map error");
			if (gameinfo->map[i][j] == 'P')
				gameinfo->c_player++;
			else if (gameinfo->map[i][j] == 'E')
				gameinfo->c_exit++;
			else if (gameinfo->map[i][j] == 'C')
				gameinfo->c_collect++;
			j++;
		}
		i++;
	}
}

void	check_rectangle(t_gameinfo *gameinfo)
{
	int	i;

	i = 0;
	while (gameinfo->map[i])
	{
		if (check_width(gameinfo->map[i]) != gameinfo->width)
			printerror("Map is not Rectangle");
		i++;
	}
	if (gameinfo->width == gameinfo->height)
		printerror("Map is not Rectangle");
}

void	findplayer(t_check *check, t_gameinfo *gameinfo)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (i < gameinfo->height)
	{
		j = 0;
		while (j < gameinfo->width)
		{
			if (gameinfo->map[i][j] == 'P')
			{
				flag = 1;
				break ;
			}				
			j++;
		}
		if (flag == 1)
			break ;
		i++;
	}
	check->x = i;
	check->y = j;
}

void	makecheck(t_check *check, t_gameinfo *gameinfo)
{
	int	i;
	int	j;

	i = 0;
	findplayer(check, gameinfo);
	check->tempmap = (char **)malloc(sizeof(char *) * (gameinfo->height));
	while (i < gameinfo->height)
	{
		check->tempmap[i] = (char *)malloc(sizeof(char) * gameinfo->width);
		i++;
	}
	i = 0;
	while (i < gameinfo->height)
	{
		j = 0;
		while (j < gameinfo->width)
		{
			check->tempmap[i][j] = 0;
			j++;
		}
		i++;
	}
	check->check_collect = 0;
	check->way = 0;
}
