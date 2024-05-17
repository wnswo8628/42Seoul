/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:12:59 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/11 22:48:30 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_status(int status, t_token *token, \
	t_heredoc *hdoc, int token_cnt)
{
	if (status)
		unlink_file(token, hdoc, token_cnt);
}

void	set_token_cnt(t_token *token, int token_cnt)
{
	int	i;
	int	j;

	j = 0;
	while (j < token_cnt)
	{
		token[j].in_quotes = 0;
		i = 0;
		token[j].inre_cnt = 0;
		token[j].outre_cnt = 0;
		token[j].heredoc_cnt = 0;
		token[j].append_cnt = 0;
		while (token[j].str[i])
		{
			match_redirect(token, &j, &i);
			i++;
		}
		j++;
	}
}

char	**ft_errorhandler(void)
{
	char	**arr;

	arr = (char **)ft_malloc(sizeof(char *));
	if (!arr)
		return (NULL);
	arr[0] = NULL;
	return (arr);
}

void	init_split(t_split *sp)
{
	sp->cnt = 0;
	sp->i = -1;
	sp->inquotes = 0;
	sp->inword = 0;
	sp->issep = 0;
}

int	ft_checkleak2(char **arr, int i)
{
	if (!arr[i])
	{
		while (--i >= 0)
			free(arr[i]);
		free(arr);
		return (0);
	}
	return (1);
}
