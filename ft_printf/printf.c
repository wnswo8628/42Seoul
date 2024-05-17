/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:24:02 by jugwak            #+#    #+#             */
/*   Updated: 2022/08/06 17:08:34 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_check(char c)
{
	int		i;
	char	*type;

	type = "cspdiuxX%%";
	i = 0;
	while (type[i] != '\0')
	{
		if (c == type[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_typeset(va_list ap, char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = ft_print_c((char)va_arg(ap, int));
	else if (type == 's')
		len = ft_print_s(va_arg(ap, char *));
	else if (type == 'p')
		len = ft_print_p(va_arg(ap, unsigned long long int));
	else if (type == 'd' || type == 'i')
		len = ft_print_di(va_arg(ap, int));
	else if (type == 'u')
		len = ft_print_u(va_arg(ap, unsigned int));
	else if (type == 'x' || type == 'X')
		len = ft_print_xx(va_arg(ap, unsigned int), type);
	else if (type == '%')
		len = write (1, "%%", 1);
	return (len);
}

int	ft_symbols(const char *string, va_list ap)
{
	int		len;
	char	type;

	len = 0;
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			if (*string == '\0' || !type_check(*string))
				return (-1);
			type = *string;
			len += ft_typeset(ap, type);
		}
		else
			len += write(1, string, 1);
		string++;
	}
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, string);
	len = ft_symbols(string, ap);
	va_end(ap);
	return (len);
}
