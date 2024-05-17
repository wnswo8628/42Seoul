/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:06:26 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/12 21:42:38 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	output_perror(char *str)
{
	perror(str);
	exit(127);
}

void	output_error(char *tav, char *error)
{
	ft_putstr_fd(tav, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	exit(127);
}

int	run_execve(t_token *token, int idx, char **cnvp)
{
	return (execve(token[idx].cmd, token[idx].tav, cnvp));
}

void	execute_execve(t_token *token, int idx, char **cnvp)
{
	int	tmp;

	tmp = path_cmd(token, cnvp, idx);
	if (!tmp)
	{
		g_status = 1;
		output_error(token[idx].tav[0], "command not found\n");
		return ;
	}
	else if (tmp > 1)
		return ;
	else if (run_execve(token, idx, cnvp) < 0)
		perror(token[idx].cmd);
}
