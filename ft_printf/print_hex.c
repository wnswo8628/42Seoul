/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:42:21 by jugwak            #+#    #+#             */
/*   Updated: 2022/08/06 17:08:22 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	hex_len(unsigned long long int address)
{
	int	hex_len;

	hex_len = 0;
	while (address != 0)
	{
		address = address / 16;
		hex_len++;
	}
	return (hex_len);
}

int	ft_print_p(unsigned long long int address)
{
	int		i;
	char	*hex;
	char	*mem;
	int		mem_len;
	int		len;

	if (address == 0)
		return (len = write(1, "0x0", 3));
	hex = "0123456789abcdef";
	i = 0;
	mem_len = hex_len(address);
	mem = (char *)malloc(sizeof(char) * mem_len);
	if (!mem)
		return (0);
	while (i < mem_len)
	{
		mem[mem_len - i++ - 1] = hex[address % 16];
		address = address / 16;
	}
	write(1, "0x", 2);
	len = write(1, mem, mem_len) + 2;
	free(mem);
	return (len);
}

char	*ch_hex(unsigned int num, char type, char *result, int result_len)
{
	char	*hex;
	int		i;

	i = 2;
	hex = "0123456789abcdef";
	while (result_len > i - 1)
	{
		if (type == 'x')
		{
			result[result_len - i] = hex[num % 16];
			num = num / 16;
		}
		else if (type == 'X')
		{
			result[result_len - i] = ft_toupper(hex[num % 16]);
			num = num / 16;
		}
		i++;
	}
	result[result_len - 1] = '\0';
	return (result);
}

int	ft_print_xx(unsigned int num, char type)
{
	char					*result;
	int						len;
	unsigned long long int	n;
	int						result_len;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	n = (unsigned long long int)num;
	result_len = hex_len(n) + 1;
	result = (char *)malloc(sizeof(char) * (result_len));
	if (!result)
		return (0);
	result = ch_hex(num, type, result, result_len);
	len = write (1, result, result_len - 1);
	free(result);
	return (len);
}
