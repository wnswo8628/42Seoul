/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:43:31 by jugwak            #+#    #+#             */
/*   Updated: 2022/08/06 17:08:33 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	number_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
		while (n != 0)
		{
			n = n / 10;
			len++;
		}
	}
	else
	{
		while (n != 0)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

char	*result_num(char *result, int len, long num, int i)
{
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	if (num < 0)
	{
		result[0] = '-';
		num *= -1;
		while (num != 0)
		{
			result[i--] = num % 10 + '0';
			num = num / 10;
		}
	}
	else
	{
		while (num != 0)
		{
			result[i--] = num % 10 + '0';
			num = num / 10;
		}
	}
	result[len] = '\0';
	return (result);
}

int	print_num(long num)
{
	int		len;
	char	*result;
	int		i;
	int		res;

	result = 0;
	if (num == 0)
		return (res = write(1, "0", 1));
	len = number_len(num);
	i = len - 1;
	result = result_num(result, len, num, i);
	res = write(1, result, len);
	free(result);
	return (res);
}

int	ft_print_di(int num)
{
	int		len;
	long	n;

	n = (long)num;
	len = 0;
	len = print_num(n);
	return (len);
}

int	ft_print_u(unsigned int num)
{
	int		len;
	long	n;

	n = (long)num;
	len = 0;
	len = print_num(n);
	return (len);
}
