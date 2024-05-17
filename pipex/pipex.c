/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:40:01 by jugwak            #+#    #+#             */
/*   Updated: 2023/01/31 18:37:22 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_infile(int *pipeid, int *fd, char **av, char **env)
{
	pid_t	pid;
	char	**cmd;

	pid = fork();
	if (pid < 0)
		printerror("Fork Error.\n");
	if (pid == 0)
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] < 0)
			printerror("File open Error.\n");
		cmd = ft_split(av[2], ' ');
		close(pipeid[0]);
		dup2(fd[0], 0);
		dup2(pipeid[1], 1);
		if (cmd[0] && get_path(cmd[0], env))
		{
			execve(get_path(cmd[0], env), cmd, env);
			free_split(cmd);
		}
		else
			printerror("Commond not found error.\n");
	}
}

void	fork_outfile(int *pipeid, int *fd, char **av, char **env)
{
	char	**cmd;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		printerror("Fork Error.\n");
	if (pid == 0)
	{
		fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			printerror("File open Error.\n");
		cmd = ft_split(av[3], ' ');
		close(pipeid[1]);
		dup2(fd[1], 1);
		dup2(pipeid[0], 0);
		if (cmd[0] && get_path(cmd[0], env))
		{
			execve(get_path(cmd[0], env), cmd, env);
			free_split(cmd);
		}
		else
			printerror("Command not found error.\n");
	}
}

int	main(int ac, char **av, char **env)
{
	int	pipeid[2];
	int	fd[2];
	int	status;

	if (ac != 5)
		printerror("Invaild argument number.\n");
	if (pipe(pipeid) < 0)
		printerror("Pipe error.\n");
	fork_infile(pipeid, fd, av, env);
	fork_outfile(pipeid, fd, av, env);
	close(pipeid[0]);
	close(pipeid[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}
