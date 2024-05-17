/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:31:47 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/13 21:59:19 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_free(char **env, int flg)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		env[i] = NULL;
		i++;
	}
	free(env);
	env = NULL;
	if (flg != 0)
		exit(0);
	return (1);
}

void	export_output(char **env)
{
	int	i;
	int	j;
	int	flg;

	i = 0;
	flg = 0;
	while (env[i])
	{
		printf("declare -x ");
		if (not_equal(env[i]))
			;
		else
		{
			j = 0;
			is_equal(env, i, j, flg);
		}
		i++;
	}
	g_status = 0;
}

void	env_sort(char **env)
{
	int		i;
	int		j;
	int		cnt;
	char	*swap;

	cnt = 0;
	while (env[cnt])
		cnt++;
	i = -1;
	j = 0;
	while (++i < cnt)
	{
		j = 1;
		while (j < cnt)
		{
			if (ft_strcmp(env[j - 1], env[j]) > 0)
			{
				swap = env[j - 1];
				env[j - 1] = env[j];
				env[j] = swap;
			}
			j++;
		}
	}
	export_output(env);
}

char	**env_dup(char **cnvp)
{
	char	**env;
	int		i;
	int		cnt;

	i = 0;
	while (cnvp[i])
		i++;
	cnt = i;
	env = (char **)malloc(sizeof(char *) * (cnt + 100));
	i = 0;
	while (cnvp[i])
	{
		env[i] = (char *)malloc(sizeof(char) * (ft_strlen(cnvp[i]) + 1));
		ft_strcpy(env[i], cnvp[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

int	export_execute(t_token token, char **cnvp, int flg)
{
	int		i;
	char	**env;

	i = 1;
	env = env_dup(cnvp);
	if (token.tav[1] == NULL)
	{
		export_output(env);
		return (env_free(env, flg));
	}
	while (token.tav[i])
	{
		if (match_cnvp(token.tav[i], cnvp))
			;
		else
			env_add(token.tav[i], cnvp);
		i++;
	}
	g_status = 0;
	return (env_free(env, flg));
}
