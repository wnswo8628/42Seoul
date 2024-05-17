/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:13:34 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/15 18:48:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_fork(void)
{
	int	status;

	status = 0;
	while (wait(&status) != -1)
		;
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
		{
			printf("^C\n");
			g_status = WTERMSIG(status) + 128;
		}
		else if (WTERMSIG(status) == SIGQUIT)
		{
			printf("^\\Quit: 3\n");
			g_status = WTERMSIG(status) + 128;
		}
	}
}

void	sig_wait(void)
{
	ctl_signal(1, 1);
	wait_fork();
	ctl_signal(0, 1);
}
