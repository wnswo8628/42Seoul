/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:20:16 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 16:53:28 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	draw_buffer(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	press_ws(t_info *info, double dir)
{
	double	direct;

	direct = dir * info->move_speed;
	if (info->map.full_map[(int)(info->pos_x + info->dir_x * direct)]
		[(int)info->pos_y] != '1')
		info->pos_x += info->dir_x * direct;
	if (info->map.full_map[(int)info->pos_x]
		[(int)(info->pos_y + info->dir_y * direct)] != '1')
		info->pos_y += info->dir_y * direct;
}

void	press_ad(t_info *info, double dir)
{
	double	direct;

	direct = dir * info->move_speed;
	if (info->map.full_map[(int)(info->pos_x + info->plane_x * direct)]
		[(int)info->pos_y] != '1')
		info->pos_x += info->plane_x * direct;
	if (info->map.full_map[(int)info->pos_x]
		[(int)(info->pos_y + info->plane_y * direct)] != '1')
		info->pos_y += info->plane_y * direct;
}

void	change_sight(t_info *info, double dir)
{
	double	olddirx;
	double	oldplanex;
	double	rot_dir;

	rot_dir = info->rot_speed * dir;
	olddirx = info->dir_x;
	info->dir_x = info->dir_x * cos(rot_dir) - info->dir_y * sin(rot_dir);
	info->dir_y = olddirx * sin(rot_dir) + info->dir_y * cos(rot_dir);
	oldplanex = info->plane_x;
	info->plane_x = info->plane_x * cos(rot_dir) - info->plane_y * sin(rot_dir);
	info->plane_y = oldplanex * sin(rot_dir) + info->plane_y * cos(rot_dir);
}

void	check_key(t_info *info)
{
	if (info->key_w)
		press_ws(info, 1.0);
	if (info->key_s)
		press_ws(info, -1.0);
	if (info->key_a)
		press_ad(info, -1.0);
	if (info->key_d)
		press_ad(info, 1.0);
	if (info->key_ar_l)
		change_sight(info, 1.0);
	if (info->key_ar_r)
		change_sight(info, -1.0);
	if (info->key_esc)
		end_program(info);
}
