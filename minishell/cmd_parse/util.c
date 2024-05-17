/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:07:08 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/15 16:20:23 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*env_parse(char **env, char *str)
{
	char	*temp;
	int		i;

	i = -1;
	while (env[++i])
	{
		if (str[ft_strlen(str) - 1] == '$')
		{
			if (!ft_strncmp(env[i], str, ft_strlen(str) - 1))
				break ;
		}
		else
			if (ft_strnstr(env[i], str, ft_strlen(str)) == env[i])
				break ;
	}
	if (env[i])
	{
		if (str[ft_strlen(str) - 1] == '$')
			temp = ft_strdup(&(env[i][ft_strlen(str)]));
		else
			temp = ft_strdup(&(env[i][ft_strlen(str) + 1]));
	}
	else
		temp = ft_strdup("");
	return (temp);
}

int	option_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (is_space(str[len]))
			break ;
		len++;
	}
	return (len);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

char	*space_env_parse(char **env, char *str)
{
	char	*temp;
	char	*temp2;
	char	*ch_env;
	char	*result;
	int		i;

	i = 0;
	while (str[i])
	{
		if (is_space(str[i]))
			break ;
		i++;
	}
	temp = ft_substr(str, 0, i);
	temp2 = ft_substr(str, i, ft_strlen(str));
	ch_env = env_parse(env, temp);
	result = ft_strjoin(ch_env, temp2);
	free(temp);
	free(temp2);
	free(ch_env);
	return (result);
}

char	*dollar_last(char *str, char *temp)
{
	char	*temp2;

	if (str[ft_strlen(str) - 1] == '$')
	{
		temp2 = temp;
		temp = ft_strjoin(temp, "$");
		ft_free(temp2);
	}
	return (temp);
}
