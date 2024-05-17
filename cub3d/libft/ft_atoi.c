/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:03:16 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 16:40:38 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub.h"

int	ft_atoi(const char *str)
{
	long	sign;
	int		i;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		result = (result * 10) + str[i++] - '0';
	return (result * sign);
}
