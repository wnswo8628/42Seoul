/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:48:22 by jugwak            #+#    #+#             */
/*   Updated: 2022/08/06 20:34:59 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

int		print_num(long num);
int		ft_toupper(int c);
int		ft_print_p(unsigned long long int address);
int		ft_print_c(char c);
int		ft_print_s(char *str);
int		hex_len(unsigned long long int address);
int		ft_print_xx(unsigned int num, char type);
int		ft_print_di(int num);
int		ft_print_u(unsigned int num);
int		ft_typeset(va_list ap, char type);
int		ft_symbols(const char *string, va_list ap);
char	*ch_hex(unsigned int num, char type, char *result, int result_len);
int		ft_printf(const char *string, ...);
int		ft_strlen(const char *str);

#endif
