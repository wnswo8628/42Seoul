/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:19:47 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/12 21:08:08 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dup_stdin(t_token *token, int idx, int fd)
{
	dup2(fd, STDIN_FILENO);
	close(fd);
	if (token[idx].last_doc != NULL)
		unlink(token[idx].last_doc);
}

void	dup_stdout(int fd)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	begin_pipe(int *fd)
{
	dup2(fd[1], 1);
	close(fd[0]);
}

void	end_pipe(int *fd)
{
	dup2(fd[0], 0);
	close(fd[1]);
}
