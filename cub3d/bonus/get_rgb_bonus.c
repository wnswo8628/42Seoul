/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:51:27 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 16:14:41 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	get_digit(char *line, int *i)
{
	int	result;

	result = ft_atoi(&line[*i]);
	while (line[*i])
	{
		if (line[*i] == ',' || line[*i] == '\0')
		{
			(*i)++;
			break ;
		}
		(*i)++;
	}
	return (result);
}

void	check_rgb(char *line)
{
	int	i;
	int	cm_cnt;

	cm_cnt = 0;
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	i = check_fc(line[i], i);
	while (ft_isspace(line[i]))
		i++;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
		{
			i++;
			cm_cnt++;
			while (ft_isspace(line[i]))
				i++;
		}
		if (!ft_isdigit(line[i]))
			print_error("Error: RGB1\n");
		i++;
	}
	if (cm_cnt != 2)
		print_error("Error: RGB2\n");
}

void	get_rgb(char *line, t_map *map)
{
	t_rgb	rgb;
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'F' || line[i] == 'C')
	{
		rgb.type = line[i];
		i++;
	}
	while (ft_isspace(line[i]))
		i++;
	check_rgb(line);
	rgb.r = get_digit(line, &i);
	rgb.g = get_digit(line, &i);
	rgb.b = get_digit(line, &i);
	if ((rgb.r < 0 || rgb.r > 255) || (rgb.g < 0 || rgb.g > 255)
		|| (rgb.b < 0 || rgb.b > 255))
		print_error("Error: RGB range\n");
	if (rgb.type == 'F')
		map->f_rgb = (rgb.r << 16 | rgb.g << 8 | rgb.b);
	else if (rgb.type == 'C')
		map->c_rgb = (rgb.r << 16 | rgb.g << 8 | rgb.b);
}
