/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:53:52 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 16:15:18 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	end_program(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

void	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	get_playerstatus(char c)
{
	if (c == 'N')
		return (N);
	else if (c == 'S')
		return (S);
	else if (c == 'E')
		return (E);
	else if (c == 'W')
		return (W);
	return (0);
}

int	check_fc(char c, int i)
{
	if (c != 'F' && c != 'C')
		print_error("Error: RGB type\n");
	else
		i++;
	return (i);
}
