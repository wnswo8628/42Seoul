/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:04:59 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/11 21:31:41 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_cnvp(char **cnvp, int flg)
{
	int	i;

	i = 0;
	while (cnvp[i])
	{
		free(cnvp[i]);
		cnvp[i] = NULL;
		i++;
	}
	free(cnvp);
	cnvp = NULL;
	if (flg != 0)
		exit(0);
}

void	free_double(t_token *token, int idx)
{
	free_infile(token, idx);
	free_outfile(token, idx);
	free_arr(token, idx);
	free_tav(token, idx);
	free_here_doc(token, idx);
}

void	free_single(t_token *token, int idx)
{
	if (token[idx].str)
	{
		free(token[idx].str);
		token[idx].str = NULL;
	}
	if (token[idx].cmd)
	{
		free(token[idx].cmd);
		token[idx].cmd = NULL;
	}
	if (token[idx].last_doc)
	{
		free(token[idx].last_doc);
		token[idx].last_doc = NULL;
	}
	if (token[idx].append_flg)
	{
		free(token[idx].append_flg);
		token[idx].append_flg = NULL;
	}
}

void	free_token(t_token *token, char *begin, int tcnt)
{
	int	i;

	i = 0;
	while (i < tcnt)
	{
		free_single(token, i);
		free_double(token, i);
		i++;
	}
	free(token);
	token = NULL;
	free(begin);
	begin = NULL;
}
