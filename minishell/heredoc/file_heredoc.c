/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:11:05 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/12 21:38:02 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fork_heredoc(t_token *token, t_heredoc *hdoc, int *status)
{
	while (42)
	{
		hdoc->str = readline("> ");
		if (!hdoc->str)
			break ;
		if (!ft_strncmp(hdoc->str, hdoc->heredoc, ft_strlen(hdoc->heredoc)))
		{
			close(hdoc->fd);
			if (token[hdoc->i].last_doc == NULL)
				unlink(hdoc->filename);
			*status = 0;
			if (*status == 0)
				break ;
		}
		write (hdoc->fd, hdoc->str, ft_strlen(hdoc->str));
		write (hdoc->fd, "\n", 1);
		free(hdoc->str);
		hdoc->str = NULL;
	}
	exit(EXIT_SUCCESS);
}

void	input_heredoc(t_token *token, t_heredoc *hdoc, int status)
{
	char	*temp;

	ctl_signal(2, 1);
	temp = ft_itoa(hdoc->file_i++);
	hdoc->pid = fork();
	hdoc->filename = ft_strjoin(".temp", temp);
	free(temp);
	hdoc->fd = open(hdoc->filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (!status)
	{
		if (!infile_hd(token, hdoc->i, hdoc->j))
			token[hdoc->i].last_doc = ft_strdup(hdoc->filename);
	}
	if (hdoc->pid == 0)
		fork_heredoc(token, hdoc, &status);
	free(hdoc->filename);
	hdoc->filename = NULL;
	ctl_signal(1, 1);
	wait_heredoc(hdoc);
}

int	file_heredoc(t_token *token, int i, int j)
{
	while (token[i].str[j])
	{
		if (!is_quotes(token, token[i].str[j], i))
		{
			if (!ft_strncmp(&(token[i].str[j]), "<<", 2))
				return (1);
		}
		j++;
	}
	return (0);
}
