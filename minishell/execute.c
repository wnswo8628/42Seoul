/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:55:36 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/13 21:56:22 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cmd(t_token *token, char **cnvp, int cmd)
{
	if (cmd == CD)
		cd_execute(token[0], cnvp);
	if (cmd == EC)
		echo_output(token[0]);
	if (cmd == ENV)
		env_output(cnvp);
	if (cmd == EXIT)
		exit_output(token[0]);
	if (cmd == EXPORT)
		export_execute(token[0], cnvp, 0);
	if (cmd == PWD)
		pwd_output();
	if (cmd == UNSET)
		unset_output(token[0], cnvp);
}

void	match_cmd(t_token *token, int *cmd)
{
	if (!ft_strcmp("cd", token[0].tav[0]))
		*cmd = CD;
	if (!ft_strcmp("echo", token[0].tav[0]))
		*cmd = EC;
	if (!ft_strcmp("env", token[0].tav[0]))
		*cmd = ENV;
	if (!ft_strcmp("exit", token[0].tav[0]))
		*cmd = EXIT;
	if (!ft_strcmp("export", token[0].tav[0]))
		*cmd = EXPORT;
	if (!ft_strcmp("pwd", token[0].tav[0]))
		*cmd = PWD;
	if (!ft_strcmp("unset", token[0].tav[0]))
		*cmd = UNSET;
}

int	one_inbuilt(t_token *token, char **cnvp)
{
	int	cmd;
	int	pfd;
	int	fd;

	cmd = 0;
	match_cmd(token, &cmd);
	if (!cmd)
		return (0);
	pfd = dup(STDOUT_FILENO);
	fd = open_outfile(token, 0);
	if (fd > 0)
		dup_stdout(fd);
	execute_cmd(token, cnvp, cmd);
	dup2(pfd, STDOUT_FILENO);
	return (1);
}

void	execute(t_token *token, char **cnvp, char *begin, int tcnt)
{
	if (tcnt == 1 && one_inbuilt(token, cnvp))
		;
	else
		and_more(token, cnvp, tcnt);
	free_token(token, begin, tcnt);
}
