/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:11:03 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/15 17:26:03 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error_output(char *tav)
{
	printf("exit\nexit: %s: numeric argument required\n", tav);
	g_status = 1;
	exit(-1);
}

int	check_num(char *tav)
{
	int	i;

	i = 0;
	while (tav[i])
	{
		if (!ft_isdigit(tav[i]))
			return (1);
		i++;
	}
	return (0);
}

int	exit_output(t_token token)
{
	int	num;

	num = 0;
	if (!token.tav[1])
	{
		printf("exit\n");
		exit(0);
	}
	if (check_num(token.tav[1]))
		error_output(token.tav[1]);
	if (!token.tav[2])
	{
		num = ft_atoi(token.tav[1]);
		if (ft_strcmp(token.tav[1], "0") == 0)
			exit(0);
		if (ft_strcmp(token.tav[1], "-1") == 0)
			exit(-1);
		if (num == 0 || num == -1)
			error_output(token.tav[1]);
		printf("exit\n");
		exit(ft_atoi(token.tav[1]) % 256);
	}
	printf("exit\nexit: too many arguments\n");
	g_status = 1;
	return (1);
}
