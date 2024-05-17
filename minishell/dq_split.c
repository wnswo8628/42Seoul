/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:46:39 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/11 22:54:24 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cnt(char const *s, char c, t_split *p, size_t *pos)
{
	if (s[*pos] != c)
	{
		p->inword = 1;
		p->cnt++;
	}
	if (s[*pos] == c && s[(*pos) + 1] == c && p->inquotes == 0)
	{
		p->inword = 1;
		p->cnt += 2;
		(*pos)++;
	}
	if (s[*pos] == c && (p->inquotes == 1 || p->inquotes == 2))
		p->cnt++;
}

void	get_cwinfo(char const *str, char c, t_split *sp)
{
	if (str[sp->i] == '\'' && sp->inquotes == 0)
		sp->inquotes = 1;
	else if (str[sp->i] == '\'' && sp->inquotes == 1)
		sp->inquotes = 0;
	if (str[sp->i] == c && sp->inquotes == 0)
		sp->issep = 1;
	else
		sp->issep = 0;
	if (str[sp->i + 1] == c && sp->issep == 1)
	{
		sp->issep = 0;
		sp->i++;
	}
}

size_t	ft_countspell2(char const *s, char c, size_t *pos)
{
	t_split	p;

	init_split(&p);
	while (s[*pos])
	{
		if (s[*pos] == '\'' && p.inquotes == 0)
			p.inquotes = 1;
		else if (s[*pos] == '\'' && p.inquotes == 1)
			p.inquotes = 0;
		if (p.inword == 1 && \
			(s[*pos] == c && s[(*pos) + 1] != c) && p.inquotes == 0)
			break ;
		get_cnt(s, c, &p, pos);
		(*pos)++;
	}
	return (p.cnt);
}

size_t	ft_countword2(char const *str, char c)
{
	t_split	sp;

	init_split(&sp);
	while (str[++sp.i])
	{
		get_cwinfo(str, c, &sp);
		if (sp.inword == 1 && sp.issep == 1)
			sp.inword = 0;
		if ((sp.inword == 0 && sp.issep == 0))
		{
			sp.inword = 1;
			sp.cnt++;
		}
	}
	return (sp.cnt);
}

char	**dq_split(char const *str, char c)
{
	char	**arr;
	size_t	i;
	size_t	pos;
	size_t	spellcnt;
	size_t	j;

	i = -1;
	pos = 0;
	if (!str || *str == '\0')
		return (error_handle());
	arr = (char **)ft_calloc((ft_countword2(str, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	while (++i < ft_countword2(str, c))
	{
		spellcnt = ft_countspell2(str, c, &pos);
		arr[i] = (char *)ft_calloc((spellcnt + 1), sizeof(char));
		if (ft_checkleak2(arr, i) == 0)
			return (NULL);
		j = 1;
		while (spellcnt > 0)
			arr[i][(spellcnt--) - 1] = str[pos - (j++)];
	}
	return (arr);
}
