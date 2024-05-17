/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:32:09 by jugwak            #+#    #+#             */
/*   Updated: 2023/03/11 17:09:35 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_split_size(char **snum)
{
	int	result;

	result = 0;
	while (snum[result])
		result++;
	return (result);
}

int	get_str_size(int ac, char **av)
{
	int		i;
	int		check;
	int		size;
	char	**snum;

	size = 0;
	i = 0;
	while (++i < ac)
	{
		check = 0;
		while (av[i][check])
		{
			if (av[i][check] != ' ')
				break ;
			check++;
		}
		snum = ft_split(av[i], ' ');
		size += get_split_size(snum);
		free_str(snum);
	}
	return (size);
}
