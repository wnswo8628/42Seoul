/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:06:25 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/15 16:01:13 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**last_dollar(char *str, char c)
{
	char	**arr;
	char	*temp;
	int		i;

	arr = q_split(str, c);
	if (str[ft_strlen(str) - 1] == '$')
	{
		i = -1;
		while (arr[(++i) + 1])
			;
		temp = arr[i];
		arr[i] = ft_strjoin(temp, "$");
		free(temp);
		temp = NULL;
	}
	return (arr);
}

char	*join_temp(char **result)
{
	char	*temp;
	char	*temp2;
	int		i;

	i = -1;
	temp2 = ft_strdup("");
	while (result[++i])
	{
		if (i > 0)
		{
			temp = temp2;
			temp2 = ft_strjoin(temp, " ");
			ft_free(temp);
		}
		temp = temp2;
		temp2 = ft_strjoin(temp, result[i]);
		ft_free(temp);
		ft_free(result[i]);
	}
	ft_free(result);
	return (temp2);
}

void	cmd_parse(t_token *token, int token_cnt, char **env)
{
	t_lenpos	index;
	char		**arr;

	index.i = -1;
	while (++index.i < token_cnt)
	{
		index.j = -1;
		token[index.i].cmd = ft_strdup("");
		arr = splitjoin(token, index.i, "<> ");
		while (arr[++index.j])
		{
			if (!check_exist(token, arr[index.j], index))
				make_cmd(token, arr[index.j], index);
			free(arr[index.j]);
		}
		free(arr);
		make_option(token, index.i, env);
	}
}
