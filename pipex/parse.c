/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:39:57 by jugwak            #+#    #+#             */
/*   Updated: 2023/01/31 18:36:59 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	printerror(char *message)
{
	write (2, message, ft_strlen(message));
	exit(1);
}

void	free_split(char **str)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	while (i < size)
		free(str[i++]);
	free(str);
}

char	**get_pathline(char **env)
{
	int		i;
	char	**result;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 6) == env[i])
			break ;
		i++;
	}
	result = ft_split(env[i] + 5, ':');
	return (result);
}

char	*get_path(char *cmd, char **env)
{
	char	**path;
	char	*cmdpath;
	char	*slash;
	int		i;

	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	path = get_pathline(env);
	i = 0;
	while (path[i])
	{
		slash = ft_strjoin(path[i], "/");
		cmdpath = ft_strjoin(slash, cmd);
		free(slash);
		if (access(cmdpath, F_OK) == 0)
		{
			free_split(path);
			return (cmdpath);
		}
		free(cmdpath);
		i++;
	}
	free_split(path);
	return (0);
}
