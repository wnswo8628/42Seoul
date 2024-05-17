/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:45:14 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/11 21:59:59 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	existence_of_equal(char *cnvp)
{
	int	i;

	i = 0;
	while (cnvp[i])
	{
		if (cnvp[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	env_output(char **cnvp)
{
	int	i;

	g_status = 0;
	i = 0;
	while (cnvp[i])
	{
		if (existence_of_equal(cnvp[i]))
			printf("%s\n", cnvp[i]);
		i++;
	}
	return (1);
}
