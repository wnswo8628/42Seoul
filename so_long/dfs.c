/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:00:06 by jugwak            #+#    #+#             */
/*   Updated: 2023/02/23 20:33:05 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	dfs(t_check *check, t_gameinfo *gameinfo, int x, int y)
{
	const int	dx[4] = {0, 0, -1, 1};
	const int	dy[4] = {-1, 1, 0, 0};
	int			i;
	int			mx;
	int			my;

	i = 0;
	check->tempmap[x][y] = 1;
	if (gameinfo->map[x][y] == 'C')
		check->check_collect++;
	if (gameinfo->map[x][y] == 'E')
	{
		check->way++;
		return ;
	}
	while (i < 4)
	{
		mx = x + dx[i];
		my = y + dy[i];
		if (gameinfo->map[mx][my] != '1' && !check->tempmap[mx][my])
			dfs(check, gameinfo, mx, my);
		i++;
	}
}
