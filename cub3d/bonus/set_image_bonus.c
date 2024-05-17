/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:48:10 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 16:53:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	get_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	i;
	int	j;

	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_line, &img->endian);
	j = 0;
	while (j < img->img_height)
	{
		i = 0;
		while (i < img->img_width)
		{
			texture[img->img_width * j + i] = img->data[img->img_width * j + i];
			i++;
		}
		j++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	set_image(t_info *info)
{
	t_img	img;

	get_image(info, info->texture[0], info->map.no_path, &img);
	get_image(info, info->texture[1], info->map.we_path, &img);
	get_image(info, info->texture[2], info->map.so_path, &img);
	get_image(info, info->texture[3], info->map.ea_path, &img);
}
