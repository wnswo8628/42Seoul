/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:22:13 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/11 22:54:14 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(void *str)
{
	free(str);
	str = NULL;
}

int	check_qorp(char *str)
{
	int		i;
	int		twocnt;
	int		onecnt;
	char	*temp;

	i = -1;
	twocnt = 0;
	onecnt = 0;
	while (str[++i])
	{
		if (str[i] == '\"' && onecnt % 2 == 0)
			twocnt++;
		else if (str[i] == '\'' && twocnt % 2 == 0)
			onecnt++;
	}
	temp = ft_strtrim(str, " ");
	i = -1;
	if (twocnt % 2 != 0 || onecnt % 2 != 0 || temp[ft_strlen(temp) - 1] == '<' \
	|| temp[ft_strlen(temp) - 1] == '>' || temp[ft_strlen(temp) - 1] == '|')
	{
		ft_free(temp);
		return (1);
	}
	ft_free(temp);
	return (0);
}

int	find_pipe(char *str, int *i, int *pos)
{
	if (str[*i] == '|')
	{
		if (*pos != -1)
			return (1);
		*pos = (*i)++;
		while (str[*i] && str[*i] != '|')
			(*i)++;
		while (++(*pos) < *i)
		{
			if (str[*pos] != ' ')
				return (0);
		}
	}
	return (-1);
}

int	is_spacepipe(char *str)
{
	int	i;
	int	pos;
	int	flag;

	i = -1;
	pos = -1;
	while (str[++i])
	{
		flag = find_pipe(str, &i, &pos);
		if (flag == 1)
			return (1);
		else if (flag == 0 || i >= (int)ft_strlen(str))
			return (0);
	}
	if (pos == -1)
		return (0);
	return (1);
}

int	check_syntax(char *str)
{
	if (!*str)
		return (0);
	if (is_spacepipe(str))
	{
		g_status = 258;
		printf("systax error near unexpected token '|\'\n");
		add_history(str);
		ft_free(str);
		return (1);
	}
	if (check_qorp(str) || ft_strnstr(str, "$$", ft_strlen(str)))
	{
		g_status = 258;
		printf("systax error\n");
		add_history(str);
		ft_free(str);
		return (1);
	}
	return (0);
}
