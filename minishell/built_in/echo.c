/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:20:52 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/11 21:56:48 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	output_echo(t_token token, int *i)
{
	if (token.tav[2] == NULL)
		return (1);
	else
	{
		*i = 2;
		while (token.tav[(*i) + 1])
			printf("%s ", token.tav[(*i)++]);
		printf("%s", token.tav[*i]);
		return (1);
	}
	return (0);
}

int	exist_tav(t_token token)
{
	int	i;

	i = 1;
	if (ft_strncmp(token.tav[1], "-", 1) != 0)
		return (1);
	while (token.tav[1][i] != '\0')
	{
		if (token.tav[1][i++] != 'n')
			return (1);
	}
	return (0);
}

int	echo_output(t_token token)
{
	int	i;

	g_status = 0;
	if (token.tav[1] == NULL)
		return (printf("\n"));
	else if (!exist_tav(token))
	{
		if (output_echo(token, &i) == 1)
			return (1);
	}
	else
	{
		i = 1;
		while (token.tav[i + 1])
			printf("%s ", token.tav[i++]);
		printf("%s", token.tav[i]);
		printf("\n");
		return (1);
	}
	return (0);
}
