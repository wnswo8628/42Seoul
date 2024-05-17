/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:59:30 by jugwak            #+#    #+#             */
/*   Updated: 2023/02/19 19:20:09 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	number_len(long n)
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

static char	*result_num(char *result, int len, long num, int i)
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

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*result;
	int		i;

	result = 0;
	num = (long)n;
	if (num == 0)
		return (result = ft_strdup("0"));
	len = number_len(num);
	i = len - 1;
	result = result_num(result, len, num, i);
	return (result);
}
