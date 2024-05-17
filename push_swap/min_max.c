/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:37:46 by jugwak            #+#    #+#             */
/*   Updated: 2023/03/11 17:09:44 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int n, int m)
{
	if (n > m)
		return (n);
	else
		return (m);
}

int	ft_min(int n, int m)
{
	if (n < m)
		return (n);
	else
		return (m);
}
