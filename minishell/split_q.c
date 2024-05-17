/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_q.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:43:21 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/11 22:49:18 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_inquotes(char c, t_split *sp)
{
	if (c == '\'' && sp->inquotes == 0)
		sp->inquotes = 1;
	else if (c == '\"' && sp->inquotes == 0)
		sp->inquotes = 2;
	else if (c == '\'' && sp->inquotes == 1)
		sp->inquotes = 0;
	else if (c == '\"' && sp->inquotes == 2)
		sp->inquotes = 0;
}

int	error_free(char **result, int i)
{
	if (!result[i])
	{
		while (--i >= 0)
			free(result[i]);
		free(result);
		return (0);
	}
	return (1);
}

int	spell_count(char *str, char c, int *pos)
{
	t_split	sp;

	init_split(&sp);
	while (str[*pos])
	{
		get_inquotes(str[*pos], &sp);
		if (sp.inword == 1 && str[*pos] == c && sp.inquotes == 0)
			break ;
		if (str[*pos] != c)
		{
			sp.inword = 1;
			sp.cnt++;
		}
		if (str[*pos] == c && (sp.inquotes == 1 || sp.inquotes == 2))
			sp.cnt++;
		(*pos)++;
	}
	return (sp.cnt);
}

int	ft_countword(char *str, char c)
{
	t_split	sp;

	init_split(&sp);
	while (str[++sp.i])
	{
		get_inquotes(str[sp.i], &sp);
		if (str[sp.i] == c && sp.inquotes == 0)
			sp.issep = 1;
		else
			sp.issep = 0;
		if (sp.inword == 1 && sp.issep == 1)
			sp.inword = 0;
		if (sp.inword == 0 && sp.issep == 0)
		{
			sp.inword = 1;
			sp.cnt++;
		}
	}
	return (sp.cnt);
}

char	**q_split(char *str, char c)
{
	char	**result;
	int		i;
	int		spellcnt;
	int		pos;
	int		j;

	i = -1;
	pos = 0;
	if (!str || *str == '\0')
		return (ft_errorhandler());
	result = (char **)ft_calloc((ft_countword(str, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (++i < ft_countword(str, c))
	{
		spellcnt = spell_count(str, c, &pos);
		result[i] = (char *)ft_calloc((spellcnt + 1), sizeof(char));
		if (error_free(result, i) == 0)
			return (NULL);
		j = 1;
		while (spellcnt > 0)
			result[i][(spellcnt--) - 1] = str[pos - (j++)];
	}
	return (result);
}
