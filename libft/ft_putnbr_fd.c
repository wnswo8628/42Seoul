/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:52 by jugwak            #+#    #+#             */
/*   Updated: 2022/07/15 18:02:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int	aa;
	int	bb;
	int	i;

	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nb < 0)
	{
		write(fd, "-", 1);
		i = nb * -1;
		ft_putnbr_fd(i, fd);
	}
	else if (nb >= 10)
	{
		aa = nb / 10;
		bb = nb % 10 + '0';
		ft_putnbr_fd(aa, fd);
		write(fd, &bb, 1);
	}
	else
	{
		nb = nb + '0';
		write(fd, &nb, 1);
	}
}
