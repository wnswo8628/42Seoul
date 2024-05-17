/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:35:08 by jugwak            #+#    #+#             */
/*   Updated: 2023/02/19 19:40:08 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	connect_image(t_gameinfo *gameinfo, t_image *image)
{
	image->player = mlx_xpm_file_to_image(gameinfo->mlx_ptr,
			"./image_xpm/player.xpm", &image->img_width, &image->img_height);
	image->collect = mlx_xpm_file_to_image(gameinfo->mlx_ptr,
			"./image_xpm/col.xpm", &image->img_width, &image->img_height);
	image->exit = mlx_xpm_file_to_image(gameinfo->mlx_ptr,
			"./image_xpm/exit2.xpm", &image->img_width, &image->img_height);
	image->tile = mlx_xpm_file_to_image(gameinfo->mlx_ptr,
			"./image_xpm/land.xpm", &image->img_width, &image->img_height);
	image->wall = mlx_xpm_file_to_image(gameinfo->mlx_ptr,
			"./image_xpm/tree.xpm", &image->img_width, &image->img_height);
}

void	put_image_pe(t_gameinfo *gameinfo, int hei, int wid, t_image *image)
{
	if (gameinfo->map[hei][wid] == 'P')
	{
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->win_ptr,
			image->tile, wid * 64, hei * 64);
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->win_ptr,
			image->player, wid * 64, hei * 64);
	}
	else if (gameinfo->map[hei][wid] == 'E')
	{
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->win_ptr,
			image->exit, wid * 64, hei * 64);
	}
	else
	{
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->win_ptr,
			image->tile, wid * 64, hei * 64);
	}
}

void	put_image(t_gameinfo *gameinfo, int hei, int wid, t_image *image)
{
	if (gameinfo->map[hei][wid] == '1')
	{
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->win_ptr,
			image->tile, wid * 64, hei * 64);
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->win_ptr,
			image->wall, wid * 64, hei * 64);
	}
	else if (gameinfo->map[hei][wid] == 'C')
	{
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->win_ptr,
			image->tile, wid * 64, hei * 64);
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->win_ptr,
			image->collect, wid * 64, hei * 64);
	}
	else
	{
		put_image_pe(gameinfo, hei, wid, image);
	}
}

void	setting_image(t_gameinfo *gameinfo, t_image *image)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < gameinfo->height)
	{
		wid = 0;
		while (wid < gameinfo->width)
		{
			put_image(gameinfo, hei, wid, image);
			wid++;
		}
		hei++;
	}
}

void	create_image(t_gameinfo *gameinfo)
{
	t_image	image;

	connect_image(gameinfo, &image);
	setting_image(gameinfo, &image);
}
