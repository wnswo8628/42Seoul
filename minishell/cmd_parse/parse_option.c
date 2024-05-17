/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:58:35 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/11 23:18:55 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	doubleq_join(t_token *token, int i, int j)
{
	char	*temp;

	temp = token[i].tav[j];
	token[i].tav[j] = ft_strjoin(temp, "\"");
	free(temp);
}

void	free2(void *temp, void *str)
{
	free(temp);
	free(str);
}

void	doubleq_p(char **arr, char **env)
{
	char	**str;
	char	*temp;
	int		i;
	int		j;

	i = -1;
	while (arr[++i])
	{
		str = dollar_split(arr[i], '$');
		j = 0;
		if (is_dohome(arr[i]))
			str[0] = get_env(env, str[0]);
		while (str[++j])
			str[j] = get_env(env, str[j]);
		free(arr[i]);
		arr[i] = ft_strdup("");
		j = -1;
		while (str[++j])
		{
			temp = arr[i];
			arr[i] = ft_strjoin(temp, str[j]);
			free2(temp, str[j]);
		}
		free(str);
	}
}

void	parse_option(t_token *token, int i, int j, char **env)
{
	char	**arr;
	char	*temp;
	char	*temp2;
	int		k;

	arr = dq_split(token[i].tav[j], '\"');
	doubleq_p(arr, env);
	temp2 = ft_strdup(token[i].tav[j]);
	free(token[i].tav[j]);
	token[i].tav[j] = ft_strdup("");
	k = -1;
	while (arr[++k])
	{
		if (k > 0 || (k == 0 && temp2[0] == '\"' && temp2[1] != '\"'))
			doubleq_join(token, i, j);
		temp = token[i].tav[j];
		token[i].tav[j] = ft_strjoin(temp, arr[k]);
		free2(temp, arr[k]);
	}
	if (ft_strlen(temp2) >= 2 \
	&& token[i].tav[j][ft_strlen(token[i].tav[j]) - 1] != '\"' \
	&& temp2[ft_strlen(temp2) - 1] == '\"' \
	&& temp2[ft_strlen(temp2) - 2] != '\"')
		doubleq_join(token, i, j);
	free2(temp2, arr);
}
