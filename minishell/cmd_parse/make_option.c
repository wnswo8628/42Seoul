/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:56:22 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/15 16:08:00 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	join_arr(t_token *token, int i, int j, char **arr)
{
	int		k;
	char	*temp;
	int		l;

	k = -1;
	l = 0;
	if (l == 0)
	{
		ft_free(token[i].tav[j]);
		token[i].tav[j] = ft_strdup("");
	}
	while (arr[++k])
	{
		if (l > 0)
		{
			temp = token[i].tav[j];
			token[i].tav[j] = ft_strjoin(temp, " ");
			free(temp);
		}
		temp = token[i].tav[j];
		token[i].tav[j] = ft_strjoin(temp, arr[k]);
		ft_free(temp);
		ft_free(arr[k]);
	}
	ft_free(arr);
}

char	*get_env(char **env, char *str)
{
	char	*temp;

	if (!ft_strncmp(str, "$", 2))
		return (str);
	else if (!ft_strncmp(str, "$?", 2) || !ft_strncmp(str, "?", 1))
	{
		temp = dollar_ques(str);
		return (temp);
	}
	else if (!ft_strncmp(str, "~", 2))
	{
		ft_free(str);
		str = ft_strdup("HOME");
	}
	else if (!ft_strncmp(str, "\"", 1))
		return (str);
	else if (!ft_strncmp(str, "\'", 1))
		return (str);
	if ((int)ft_strlen(str) > option_len(str))
		temp = space_env_parse(env, str);
	else
		temp = env_parse(env, str);
	temp = dollar_last(str, temp);
	ft_free(str);
	return (temp);
}

int	is_dohome(char *str)
{
	if (!ft_strncmp(str, "$", 1))
		return (1);
	else if (!ft_strncmp(str, "~", 2))
		return (1);
	return (0);
}

char	**dollar_split(char *str, char c)
{
	char	**arr;

	if (!ft_strncmp(str, "$", 2))
	{
		arr = ft_malloc(sizeof(char *) * 2);
		arr[0] = ft_strdup("$");
		arr[1] = NULL;
	}
	else if (!ft_strncmp(str, "$?", 3))
	{
		arr = ft_malloc(sizeof(char *) * 2);
		arr[0] = ft_strdup("$?");
		arr[1] = NULL;
	}
	else
		arr = last_dollar(str, c);
	return (arr);
}

void	make_option(t_token *token, int i, char	**env)
{
	int		j;
	int		k;
	char	**arr;

	if (!token[i].cmd)
	{
		token[i].tav = malloc(sizeof(char *) * 2);
		token[i].tav[0] = ft_strdup("");
		token[i].tav[1] = NULL;
		return ;
	}
	token[i].tav = q_split(token[i].cmd, ' ');
	j = -1;
	while (token[i].tav[++j])
	{
		arr = dollar_split(token[i].tav[j], '$');
		k = 0;
		if (is_dohome(token[i].tav[j]))
			arr[0] = get_env(env, arr[0]);
		while (arr[++k])
			arr[k] = get_env(env, arr[k]);
		join_arr(token, i, j, arr);
		parse_option(token, i, j, env);
		delete_q(token, i, j);
	}
}
