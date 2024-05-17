/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:00:59 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/11 22:02:13 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exist_in_env(t_token token, char **cnvp, int idx)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(token.tav[idx]);
	while (cnvp[++i])
	{
		if (!ft_strncmp(token.tav[idx], cnvp[i], len))
			return (i);
	}
	return (-1);
}

int	unset_output(t_token token, char **cnvp)
{
	int	i;
	int	idx;

	i = 0;
	if (token.tav[1] == NULL)
		return (-1);
	while (token.tav[++i])
	{
		idx = exist_in_env(token, cnvp, i);
		if (idx != -1)
		{
			free(cnvp[idx]);
			cnvp[idx] = NULL;
			cnvp[idx] = cnvp[idx + 1];
			while (cnvp[++idx])
				cnvp[idx] = cnvp[idx + 1];
			cnvp[idx] = NULL;
		}
	}
	return (0);
}
