/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:03:01 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 16:46:21 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int key, t_info *info)
{
	if (key == K_ESC)
		end_program(info);
	else if (key == K_W)
		info->key_w = 1;
	else if (key == K_A)
		info->key_a = 1;
	else if (key == K_S)
		info->key_s = 1;
	else if (key == K_D)
		info->key_d = 1;
	else if (key == K_AR_L)
		info->key_ar_l = 1;
	else if (key == K_AR_R)
		info->key_ar_r = 1;
	return (0);
}

int	key_release(int key, t_info *info)
{
	if (key == K_ESC)
		end_program(info);
	else if (key == K_W)
		info->key_w = 0;
	else if (key == K_A)
		info->key_a = 0;
	else if (key == K_S)
		info->key_s = 0;
	else if (key == K_D)
		info->key_d = 0;
	else if (key == K_AR_L)
		info->key_ar_l = 0;
	else if (key == K_AR_R)
		info->key_ar_r = 0;
	return (0);
}
