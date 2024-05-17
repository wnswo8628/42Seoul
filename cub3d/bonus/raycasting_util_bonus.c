/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:56:22 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 16:53:41 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	get_texnum(t_raycast *rc)
{
	if (rc->side == 1)
	{
		if (rc->raydir_y > 0)
			return (W);
		else
			return (E);
	}
	else
	{
		if (rc->raydir_x > 0)
			return (N);
		else
			return (S);
	}
}

void	draw_texture(t_info *info, t_raycast *rc, t_tex *tex, int x)
{
	int	y;

	y = rc->draw_start;
	while (y < rc->draw_end)
	{
		tex->tex_y = (int)tex->tex_pos & (TEXHEIGHT - 1);
		tex->tex_pos += tex->step;
		tex->color = \
			info->texture[tex->texnum][TEXHEIGHT * tex->tex_y + tex->tex_x];
		info->buf[y][x] = tex->color;
		info->re_buf = 1;
		y++;
	}
}
