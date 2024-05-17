/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:33:06 by jugwak            #+#    #+#             */
/*   Updated: 2023/03/11 18:31:56 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **snum)
{
	int	i;

	i = 0;
	while (snum[i])
	{
		free(snum[i]);
		i++;
	}
	free(snum);
}

void	check_double(int *num, int n, int size, int i)
{
	i--;
	while (i >= 0)
	{
		if (n == num[i])
			print_error(1);
		i--;
	}
}

void	check_sort(int *num, int size)
{
	int	i;
	int	checker;

	checker = 0;
	i = 0;
	while (i < size)
	{
		if (num[i] > num[i + 1] && i + 1 < size)
			checker++;
		check_double(num, num[i], size, i);
		if (num[i] > 2147483647 || num[i] < -2147483648)
			print_error(1);
		i++;
	}
	if (checker == 0)
		print_error(-1);
}

int	*get_num_array(int ac, char **av, int size)
{
	int		*result;
	char	**split_av;
	int		i;
	int		j;
	int		index;

	result = (int *)malloc(sizeof(int) * size);
	if (!result)
		print_error(1);
	i = 0;
	index = 0;
	while (++i < ac)
	{
		j = 0;
		split_av = ft_split(av[i], ' ');
		while (split_av[j])
		{
			result[index] = ft_atoi(split_av[j]);
			index++;
			j++;
		}
		free_str(split_av);
	}
	return (result);
}
