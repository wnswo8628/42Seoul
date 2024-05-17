/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:41:59 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/15 17:22:37 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	find_infile(t_token *token, t_lenpos *lp, int *k)
{
	lp->len = 0;
	lp->pos = 0;
	if (!is_quotes(token, token[lp->j].str[lp->i], lp->j))
	{
		if (!ft_strncmp(&(token[lp->j].str[lp->i]), "<<", 2))
			lp->i += 2;
		if (token[lp->j].str[lp->i] == '<')
		{
			while (token[lp->j].str[++lp->i] == ' ')
				;
			lp->pos = lp->i;
			while (token[lp->j].str[lp->i] != ' ' \
				&& token[lp->j].str[lp->i] && token[lp->j].str[lp->i] != '<' \
				&& token[lp->j].str[lp->i] != '>')
			{
				lp->len++;
				lp->i++;
			}
			token[lp->j].infile[(*k)++] \
				= ft_substr(token[lp->j].str, lp->pos, lp->len);
			lp->i--;
		}
	}
}

void	inredirect_parse(t_token *token, int token_cnt)
{
	t_lenpos	lp;
	int			k;

	lp.j = -1;
	while (++lp.j < token_cnt)
	{
		k = 0;
		lp.i = -1;
		if (token[lp.j].inre_cnt <= 0)
			continue ;
		token[lp.j].infile = \
			(char **)ft_malloc(sizeof(char *) * (token[lp.j].inre_cnt + 1));
		token[lp.j].infile[token[lp.j].inre_cnt] = NULL;
		while (token[lp.j].str[++lp.i])
			find_infile(token, &lp, &k);
		lp.j++;
	}
}

int	is_quotes(t_token *token, char c, int i)
{
	if (c == '\'' && token[i].in_quotes == 0)
		token[i].in_quotes = 1;
	else if (c == '\"' && token[i].in_quotes == 0)
		token[i].in_quotes = 2;
	else if (c == '\'' && token[i].in_quotes == 1)
		token[i].in_quotes = 0;
	else if (c == '\"' && token[i].in_quotes == 2)
		token[i].in_quotes = 0;
	return (token[i].in_quotes);
}

void	match_redirect(t_token *token, int *j, int *i)
{
	if (!is_quotes(token, token[*j].str[*i], *j))
	{
		if (!ft_strncmp(&(token[*j].str[*i]), "<<", 2))
		{
			token[*j].heredoc_cnt++;
			(*i)++;
		}
		else if (!ft_strncmp(&(token[*j].str[*i]), ">>", 2))
		{
			token[*j].append_cnt++;
			(*i)++;
		}
		else if (token[*j].str[*i] == '<')
			token[*j].inre_cnt++;
		else if (token[*j].str[*i] == '>')
			token[*j].outre_cnt++;
	}
}

int	parse_token(t_token *token, int token_cnt, char *str, char **env)
{
	int	status;

	set_token_cnt(token, token_cnt);
	inredirect_parse(token, token_cnt);
	outredirect_parse(token, token_cnt);
	status = heredoc_parse(token, token_cnt);
	cmd_parse(token, token_cnt, env);
	if (status)
		free_token(token, str, token_cnt);
	return (status);
}
