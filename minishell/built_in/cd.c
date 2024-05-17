/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:02:29 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/11 21:38:58 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	change_dir(t_token token, char *home)
{
	if (!token.tav[1] || !token.tav[1][0])
		return (chdir_home(home));
	else
		return (chdir_other(token));
}

char	*match_home(char **cnvp)
{
	int	i;

	i = 0;
	while (cnvp[i])
	{
		if (!ft_strncmp(cnvp[i], "HOME", 4))
			return (cnvp[i] + 5);
		i++;
	}
	return (NULL);
}

void	match_pwd(char **cnvp, char *pwd, char *oldpwd)
{
	int	i;

	i = 0;
	while (cnvp[i])
	{
		if (!ft_strncmp(cnvp[i], "PWD", 3))
			pwd = cnvp[i];
		if (!ft_strncmp(cnvp[i], "OLDPWD", 6))
			oldpwd = cnvp[i];
		i++;
	}
}

int	cd_execute(t_token token, char **cnvp)
{
	char	*cwd;
	char	*pwd;
	char	*oldpwd;

	cwd = getcwd(NULL, 0);
	pwd = NULL;
	oldpwd = NULL;
	match_pwd(cnvp, pwd, oldpwd);
	if (change_dir(token, match_home(cnvp)))
	{
		free(cwd);
		cwd = NULL;
		return (1);
	}
	change_pwd(pwd, cnvp);
	change_oldpwd(oldpwd, cnvp, cwd);
	free(cwd);
	cwd = NULL;
	return (1);
}
