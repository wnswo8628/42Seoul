/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:05:18 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/11 21:31:50 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	free_return(char *tmp, char **path)
{
	free(tmp);
	tmp = NULL;
	free_path(path);
	return (0);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}
	free(path);
	path = NULL;
}

void	free_var(char *tmp, char **path, t_token *token, int idx)
{
	free(tmp);
	tmp = NULL;
	free_path(path);
	free(token[idx].cmd);
	token[idx].cmd = NULL;
}
