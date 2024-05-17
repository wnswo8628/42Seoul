/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:43:55 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/12 19:05:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_oldpwd(char *oldpwd, char **cnvp, char *path)
{
	t_token	token;
	char	*tmp;

	if (!oldpwd)
		return ;
	tmp = ft_strjoin("OLDPWD=", path);
	token.tav = (char **)malloc(sizeof(char *) * 3);
	token.tav[0] = ft_strdup("export");
	token.tav[1] = tmp;
	token.tav[2] = NULL;
	export_execute(token, cnvp, 0);
	free(token.tav[1]);
	free(token.tav[0]);
	free(token.tav);
	token.tav[1] = NULL;
	token.tav[0] = NULL;
	token.tav = NULL;
}

void	change_pwd(char *pwd, char **cnvp)
{
	t_token	token;
	char	*path;
	char	*tmp;

	if (!pwd)
		return ;
	path = getcwd(NULL, 0);
	tmp = ft_strjoin("PWD=", path);
	token.tav = (char **)malloc(sizeof(char *) * 3);
	token.tav[0] = ft_strdup("export");
	token.tav[1] = tmp;
	token.tav[2] = NULL;
	export_execute(token, cnvp, 0);
	free(token.tav[1]);
	free(token.tav[0]);
	free(token.tav);
	token.tav[1] = NULL;
	token.tav[0] = NULL;
	token.tav = NULL;
}

int	chdir_other(t_token token)
{
	if (chdir(token.tav[1]) < 0)
	{
		perror(token.tav[1]);
		g_status = 1;
		return (1);
	}
	else
	{
		g_status = 0;
		return (0);
	}
}

int	chdir_home(char *home)
{
	if (!home)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		g_status = 1;
		return (1);
	}
	else
	{
		chdir(home);
		g_status = 0;
		return (0);
	}
}
