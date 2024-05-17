/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:23:24 by jugwak            #+#    #+#             */
/*   Updated: 2023/02/22 19:41:30 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_width(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	return (i);
}

void	correntplayer(t_gameinfo *gameinfo)
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
	gameinfo->player_x = i;
	gameinfo->player_y = j;
}

void	printerror(char *message)
{
	write (2, message, ft_strlen(message));
	exit(1);
}

void	errormessage(char *message)
{
	perror(message);
	exit(1);
}
