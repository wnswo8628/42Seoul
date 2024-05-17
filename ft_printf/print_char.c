/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:42:08 by jugwak            #+#    #+#             */
/*   Updated: 2022/08/06 20:34:43 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_c(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_s(char *str)
{
	int	len;

	if (!str)
	{
		len = write (1, "(null)", 6);
		return (len);
	}
	len = write(1, str, ft_strlen(str));
	return (len);
}
