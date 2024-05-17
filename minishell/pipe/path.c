/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:02:21 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/12 19:06:24 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**match_path(char **cnvp)
{
	int		i;
	char	**path;

	i = 0;
	while (cnvp[i])
	{
		if (!ft_strncmp(cnvp[i], "PATH=", 5))
			break ;
		i++;
	}
	if (!cnvp[i])
		return (NULL);
	path = ft_split(cnvp[i] + 5, ':');
	if (!path)
		return (NULL);
	return (path);
}

int	full_path_cmd(t_token *token, int idx, char **cnvp)
{
	int		i;
	char	**path;
	char	*tmp;
	char	*full_path;

	i = 0;
	path = match_path(cnvp);
	if (!path)
		return (1);
	tmp = ft_strjoin("/", token[idx].tav[0]);
	while (path[i])
	{
		full_path = ft_strjoin(path[i], tmp);
		if (open(full_path, O_RDONLY) > 0)
		{
			free_var(tmp, path, token, idx);
			token[idx].cmd = full_path;
			return (1);
		}
		free(full_path);
		full_path = NULL;
		i++;
	}
	return (free_return(tmp, path));
}

int	tav_cmd(t_token *token, int idx)
{
	char	*tmp;

	tmp = token[idx].cmd;
	if (tmp)
	{
		token[idx].cmd = ft_strdup(token[idx].tav[0]);
		free(tmp);
		tmp = NULL;
	}
	return (1);
}

int	path_cmd(t_token *token, char **cnvp, int idx)
{
	if (token[idx].tav[0][0] == '\0')
	{
		printf("");
		exit(0);
	}
	if (!ft_strcmp("..", token[idx].tav[0]))
		return (0);
	if (!ft_strcmp(".", token[idx].tav[0]))
	{
		token[idx].cmd = ".";
		return (1);
	}
	if (!ft_strncmp(token[idx].tav[0], "./", 2) \
		|| !ft_strncmp(token[idx].tav[0], "/", 1) \
		|| token[idx].tav[0][ft_strlen(token[idx].tav[0]) - 1] == '/')
	{
		if (opendir(token[idx].tav[0]) != NULL)
			return (printf("%s: is a directory\n", token[idx].tav[0]));
		else
			return (tav_cmd(token, idx));
	}
	return (full_path_cmd(token, idx, cnvp));
}

int	execute_more_cmd(t_token *token, char **cnvp, int idx)
{
	if (!ft_strcmp("cd", token[idx].tav[0]))
		return (cd_execute(token[idx], cnvp));
	if (!ft_strcmp("echo", token[idx].tav[0]))
		return (echo_output(token[idx]));
	if (!ft_strcmp("env", token[idx].tav[0]))
		return (env_output(cnvp));
	if (!ft_strcmp("exit", token[idx].tav[0]))
		return (exit_output(token[idx]));
	if (!ft_strcmp("export", token[idx].tav[0]))
		return (export_execute(token[idx], cnvp, 0));
	if (!ft_strcmp("pwd", token[idx].tav[0]))
		return (pwd_output());
	if (!ft_strcmp("unset", token[idx].tav[0]))
		return (unset_output(token[idx], cnvp));
	return (0);
}
