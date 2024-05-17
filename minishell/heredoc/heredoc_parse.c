/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:06:17 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/12 17:33:23 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unlink_file(t_token *token, t_heredoc *hdoc, int token_cnt)
{
	hdoc->i = -1;
	while (++hdoc->i < token_cnt)
		if (token[hdoc->i].last_doc)
			unlink(token[hdoc->i].last_doc);
}

void	wait_heredoc(t_heredoc *hdoc)
{
	int	status;

	status = 0;
	waitpid(-1, &status, 0);
	if (WIFSIGNALED(status))
	{
		printf("\n");
		g_status = 1;
		hdoc->status = 1;
	}
}

int	infile_hd(t_token *token, int i, int j)
{
	while (token[i].str[j])
	{
		if (!is_quotes(token, token[i].str[j], i))
		{
			if (token[i].str[j] == '<')
				return (1);
		}
		j++;
	}
	return (0);
}

void	heredoc_ps(t_token *token, t_heredoc *hdoc)
{
	if (!ft_strncmp(&(token[hdoc->i].str[hdoc->j]), "<<", 2))
	{
		hdoc->j++;
		while (token[hdoc->i].str[++hdoc->j] == ' ')
			;
		hdoc->pos = hdoc->j;
		while (token[hdoc->i].str[hdoc->j] \
			&& token[hdoc->i].str[hdoc->j] != ' ' \
			&& token[hdoc->i].str[hdoc->j] != '<' \
			&& token[hdoc->i].str[hdoc->j] != '>')
		{
			hdoc->len++;
			hdoc->j++;
		}
		hdoc->heredoc = ft_substr(token[hdoc->i].str, hdoc->pos, hdoc->len);
		token[hdoc->i].here_doc[hdoc->idx++] = ft_strdup(hdoc->heredoc);
		if (file_heredoc(token, hdoc->i, hdoc->j))
			input_heredoc(token, hdoc, 1);
		else
			input_heredoc(token, hdoc, 0);
		hdoc->j--;
		free(hdoc->heredoc);
		hdoc->heredoc = NULL;
		ctl_signal(0, 1);
	}
}

int	heredoc_parse(t_token *token, int token_cnt)
{
	t_heredoc	hdoc;

	hdoc.i = -1;
	hdoc.status = 0;
	hdoc.file_i = 0;
	while (++hdoc.i < token_cnt)
	{
		hdoc.idx = 0;
		hdoc.j = -1;
		if (token[hdoc.i].heredoc_cnt <= 0)
			continue ;
		token[hdoc.i].here_doc = \
			(char **)ft_malloc(sizeof(char *) * (token->heredoc_cnt + 1));
		token[hdoc.i].here_doc[token[hdoc.i].heredoc_cnt] = NULL;
		while (token[hdoc.i].str[++hdoc.j])
		{
			hdoc.len = 0;
			hdoc.pos = 0;
			if (!is_quotes(token, token[hdoc.i].str[hdoc.j], hdoc.j))
				heredoc_ps(token, &hdoc);
		}
	}
	check_status(hdoc.status, token, &hdoc, token_cnt);
	return (hdoc.status);
}
