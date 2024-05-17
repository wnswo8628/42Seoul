/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:19:05 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/13 21:56:00 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_add(char *tav, char **cnvp)
{
	int		i;
	char	*add;

	i = 0;
	add = ft_strdup(tav);
	while (cnvp[i])
		i++;
	cnvp[i + 1] = NULL;
	while (i > 0)
	{
		cnvp[i] = cnvp[i - 1];
		i--;
	}
	cnvp[i] = add;
}

int	match_cnvp(char *tav, char **cnvp)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(tav);
	while (tmp[i] && tmp[i] != '=')
		i++;
	tmp[i] = '\0';
	i = -1;
	while (cnvp[++i])
	{
		if (!ft_strncmp(tmp, cnvp[i], ft_strlen(tmp)))
		{
			free(tmp);
			tmp = NULL;
			tmp = cnvp[i];
			cnvp[i] = ft_strdup(tav);
			free(tmp);
			tmp = NULL;
			return (1);
		}
	}
	free(tmp);
	tmp = NULL;
	return (0);
}

void	is_equal(char **env, int i, int j, int flg)
{
	while (env[i][j] != '\0')
	{
		if (env[i][j] != '=')
		{
			printf("%c", env[i][j]);
			j++;
		}
		else if (env[i][j] == '=')
		{
			flg = 1;
			printf("%c\"", env[i][j]);
			j++;
		}
		if (env[i][j] == '\0' && flg == 1)
			printf("\"\n");
	}
}

int	not_equal(char *env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i] == '=')
			return (0);
		i++;
	}
	printf("%s\n", env);
	return (1);
}
