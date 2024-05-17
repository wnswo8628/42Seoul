/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:04:05 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/15 18:50:39 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	idx_middle(t_token *token, char **cnvp, int idx)
{
	int	infd;
	int	outfd;

	infd = open_infile(token, idx);
	if (infd < 0)
		end_pipe(token[idx - 1].fd);
	else if (infd >= 0)
	{
		close(token[idx - 1].fd[0]);
		close(token[idx - 1].fd[1]);
		dup_stdin(token, idx, infd);
		if (infd == 0)
			return ;
	}
	outfd = open_outfile(token, idx);
	begin_pipe(token[idx].fd);
	if (outfd > 0)
		dup_stdout(outfd);
	if (execute_more_cmd(token, cnvp, idx) == 1)
		return ;
	execute_execve(token, idx, cnvp);
}

void	idx_last(t_token *token, char **cnvp, int idx)
{
	int	infd;
	int	outfd;

	infd = open_infile(token, idx);
	if (infd < 0)
		end_pipe(token[idx - 1].fd);
	else if (infd >= 0)
	{
		close(token[idx - 1].fd[0]);
		close(token[idx - 1].fd[1]);
		dup_stdin(token, idx, infd);
		if (infd == 0)
			return ;
	}
	outfd = open_outfile(token, idx);
	if (outfd > 0)
		dup_stdout(outfd);
	if (execute_more_cmd(token, cnvp, idx) == 1)
		return ;
	execute_execve(token, idx, cnvp);
}

void	idx_first(t_token *token, char **cnvp, int idx)
{
	int	infd;
	int	outfd;

	infd = open_infile(token, idx);
	if (infd == 0)
		return ;
	if (infd > 0)
		dup_stdin(token, idx, infd);
	outfd = open_outfile(token, idx);
	if (outfd > 0)
		dup_stdout(outfd);
	else
		begin_pipe(token[idx].fd);
	if (execute_more_cmd(token, cnvp, idx) == 1)
		return ;
	infd = path_cmd(token, cnvp, idx);
	if (infd == 0)
		output_error(token[idx].tav[0], "command not found\n");
	else if (infd > 1)
		return ;
	else if (run_execve(token, idx, cnvp) < 0)
		output_perror(token[idx].cmd);
}

void	parallelism(t_token *token, char **cnvp, int idx, int last)
{
	if (idx == 0)
		idx_first(token, cnvp, idx);
	else if (idx == last)
		idx_last(token, cnvp, idx);
	else
		idx_middle(token, cnvp, idx);
}

void	and_more(t_token *token, char **cnvp, int tcnt)
{
	int		i;
	pid_t	pid;

	i = 0;
	ctl_signal(2, 2);
	while (i < tcnt)
	{
		if (i != tcnt - 1)
			pipe(token[i].fd);
		pid = fork();
		if (pid == 0)
		{
			parallelism(token, cnvp, i, tcnt - 1);
			exit(1);
		}
		if (i > 0)
		{
			close(token[i - 1].fd[0]);
			close(token[i - 1].fd[1]);
		}
		i++;
	}
	sig_wait();
}
