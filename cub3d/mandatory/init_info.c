/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:49:24 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 16:46:11 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_tex(int **texture, int x, int y, int value)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			texture[i][j] = value;
			j++;
		}
		i++;
	}
}

void	init_key_value(t_info *info)
{
	info->move_speed = 0.03;
	info->rot_speed = 0.03;
	info->re_buf = 0;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_ar_l = 0;
	info->key_ar_r = 0;
	info->key_esc = 0;
}

void	vec_init(t_info *info, int dir, int plane)
{
	if (info->player.player_status == N
		|| info->player.player_status == S)
	{
		info->dir_x = 1.0 * dir;
		info->dir_y = 0.0 * dir;
		info->plane_x = 0.0 * plane;
		info->plane_y = 0.66 * plane;
	}
	else if (info->player.player_status == E
		|| info->player.player_status == W)
	{
		info->dir_x = 0.0 * dir;
		info->dir_y = 1.0 * dir;
		info->plane_x = 0.66 * plane;
		info->plane_y = 0.0 * plane;
	}
}

void	pos_value_init(t_info *info)
{
	int	dir;
	int	plane;

	info->pos_x = info->player.player_x;
	info->pos_y = info->player.player_y;
	dir = 1;
	plane = 1;
	if (info->player.player_status == N)
		dir = -1;
	else if (info->player.player_status == S)
		plane = -1;
	else if (info->player.player_status == W)
	{
		dir = -1;
		plane = -1;
	}
	vec_init(info, dir, plane);
}

void	all_init(t_info *info)
{
	int	i;

	i = 0;
	info->texture = (int **)malloc(sizeof(int *) * 4);
	if (!info->texture)
		print_error("Error: malloc\n");
	while (i < 4)
	{
		info->texture[i] = malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
		if (!info->texture[i])
		{
			while (--i > 0)
				free(info->texture[i]);
			print_error("Error: malloc\n");
		}
		i++;
	}
	init_tex(info->texture, 4, TEXHEIGHT * TEXWIDTH, 0);
	init_key_value(info);
	pos_value_init(info);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "cub3d");
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp,
			&info->img.size_line, &info->img.endian);
}
