/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:22:19 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/13 17:30:21 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_here_doc(t_token *token, int idx)
{
	int	i;

	i = 0;
	if (!token[idx].here_doc)
		return ;
	if (token[idx].here_doc[0])
	{
		while (token[idx].here_doc[i])
		{
			free(token[idx].here_doc[i]);
			token[idx].here_doc[i] = NULL;
			i++;
		}
	}
	free(token[idx].here_doc);
	token[idx].here_doc = NULL;
}

void	free_tav(t_token *token, int idx)
{
	int	i;

	i = 0;
	if (!token[idx].tav[0])
	{
		free(token[idx].tav);
		return ;
	}
	while (token[idx].tav[i])
	{
		free(token[idx].tav[i]);
		token[idx].tav[i] = NULL;
		i++;
	}
	free(token[idx].tav);
	token[idx].tav = NULL;
}

void	free_arr(t_token *token, int idx)
{
	int	i;

	i = 0;
	if (!token[idx].arr)
		return ;
	if (token[idx].arr[0])
	{
		while (token[idx].arr[i])
		{
			free(token[idx].arr[i]);
			token[idx].arr[i] = NULL;
			i++;
		}
	}
	free(token[idx].arr);
	token[idx].arr = NULL;
}

void	free_outfile(t_token *token, int idx)
{
	int	i;

	i = 0;
	if (!token[idx].outfile)
		return ;
	if (token[idx].outfile[0])
	{
		while (token[idx].outfile[i])
		{
			free(token[idx].outfile[i]);
			token[idx].outfile[i] = NULL;
			i++;
		}
	}
	free(token[idx].outfile);
	token[idx].outfile = NULL;
}

void	free_infile(t_token *token, int idx)
{
	int	i;

	i = 0;
	if (!token[idx].infile)
		return ;
	if (token[idx].infile[0])
	{
		while (token[idx].infile[i])
		{
			free(token[idx].infile[i]);
			token[idx].infile[i] = NULL;
			i++;
		}
	}
	free(token[idx].infile);
	token[idx].infile = NULL;
}
