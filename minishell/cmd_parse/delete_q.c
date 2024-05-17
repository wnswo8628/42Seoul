/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_q.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:02:23 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/11 22:23:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	shift_q(t_token *token, int i, int j, t_delq *delq)
{
	while (delq->pos + 1 != delq->index)
	{
		token[i].tav[j][delq->pos] = token[i].tav[j][delq->pos + 1];
		delq->pos++;
	}
	while (token[i].tav[j][delq->pos + 2])
	{
		token[i].tav[j][delq->pos] = token[i].tav[j][delq->pos + 2];
		delq->pos++;
	}
	token[i].tav[j][delq->pos] = '\0';
	delq->index -= 2;
}

void	delete_q(t_token *token, int i, int j)
{
	t_delq	delq;

	delq.oneq_cnt = 0;
	delq.twoq_cnt = 0;
	delq.index = -1;
	while (token[i].tav[j][++delq.index])
	{
		if (token[i].tav[j][delq.index] == '\'' && delq.twoq_cnt % 2 == 0)
		{
			delq.oneq_cnt++;
			if (delq.oneq_cnt % 2 == 0)
				shift_q(token, i, j, &delq);
			delq.pos = delq.index;
		}
		else if (token[i].tav[j][delq.index] == '\"' && delq.oneq_cnt % 2 == 0)
		{
			delq.twoq_cnt++;
			if (delq.twoq_cnt % 2 == 0)
				shift_q(token, i, j, &delq);
			delq.pos = delq.index;
		}
	}
}
