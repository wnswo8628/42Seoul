/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outredirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:17:36 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/11 22:55:02 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_append(t_token *token, t_lenpos *lp, int *k)
{
	lp->i++;
	while (token[lp->j].str[++lp->i] == ' ')
		;
	lp->pos = lp->i;
	while (token[lp->j].str[lp->i] != ' ' && token[lp->j].str[lp->i] \
		&& token[lp->j].str[lp->i] != '<' && token[lp->j].str[lp->i] != '>')
	{
		lp->len++;
		lp->i++;
	}
	token[lp->j].append_flg[*k] = 1;
	token[lp->j].outfile[(*k)++] \
		= ft_substr(token[lp->j].str, lp->pos, lp->len);
	lp->i--;
}

void	parse_outfile(t_token *token, t_lenpos *lp, int *k)
{
	while (token[lp->j].str[++lp->i] == ' ')
		;
	lp->pos = lp->i;
	while (token[lp->j].str[lp->i] != ' ' && token[lp->j].str[lp->i] \
		&& token[lp->j].str[lp->i] != '<' && token[lp->j].str[lp->i] != '>')
	{
		lp->len++;
		lp->i++;
	}
	token[lp->j].append_flg[*k] = 0;
	token[lp->j].outfile[(*k)++] \
		= ft_substr(token[lp->j].str, lp->pos, lp->len);
	lp->i--;
}

int	malloc_outre(t_token *token, t_lenpos *lp)
{
	if (token[lp->j].outre_cnt + token[lp->j].append_cnt <= 0)
		return (0);
	token[lp->j].outfile = (char **)ft_malloc(sizeof(char *) \
		* (token[lp->j].outre_cnt + token[lp->j].append_cnt + 1));
	token[lp->j].outfile[token[lp->j].outre_cnt \
		+ token[lp->j].append_cnt] = NULL;
	token[lp->j].append_flg = ft_malloc(sizeof(int) * \
		(token[lp->j].outre_cnt + token[lp->j].append_cnt + 1));
	return (1);
}

void	outredirect_parse(t_token *token, int token_cnt)
{
	t_lenpos	lp;
	int			k;

	lp.j = -1;
	while (++lp.j < token_cnt)
	{
		k = 0;
		lp.i = -1;
		if (!malloc_outre(token, &lp))
			continue ;
		while (token[lp.j].str[++lp.i])
		{
			lp.len = 0;
			lp.pos = 0;
			if (!is_quotes(token, token[lp.j].str[lp.i], lp.j))
			{
				if (!ft_strncmp(&(token[lp.j].str[lp.i]), ">>", 2))
					parse_append(token, &lp, &k);
				else if (token[lp.j].str[lp.i] == '>')
					parse_outfile(token, &lp, &k);
			}
		}
	}
}
