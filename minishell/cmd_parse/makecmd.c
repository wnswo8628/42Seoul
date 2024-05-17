/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makecmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:51:29 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/15 16:02:25 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**splitjoin(t_token *token, int i, char *sep)
{
	char	**result;
	char	*temp;

	result = q_split(token[i].str, sep[0]);
	temp = join_temp(result);
	result = q_split(temp, sep[1]);
	free(temp);
	temp = NULL;
	temp = join_temp(result);
	result = q_split(temp, sep[2]);
	free(temp);
	temp = NULL;
	return (result);
}

int	check_exist(t_token *token, char *str, t_lenpos index)
{
	int	j;

	j = -1;
	while (token[index.i].infile && token[index.i].infile[++j])
		if (!ft_strncmp(token[index.i].infile[j], str, ft_strlen(str)))
			return (1);
	j = -1;
	while (token[index.i].outfile && token[index.i].outfile[++j])
		if (!ft_strncmp(token[index.i].outfile[j], str, ft_strlen(str)))
			return (1);
	j = -1;
	while (token[index.i].here_doc && token[index.i].here_doc[++j])
		if (!ft_strncmp(token[index.i].here_doc[j], str, ft_strlen(str)))
			return (1);
	return (0);
}

void	make_cmd(t_token *token, char *str, t_lenpos index)
{
	char	*temp;

	if (index.j > 0)
	{
		temp = token[index.i].cmd;
		token[index.i].cmd = ft_strjoin(temp, " ");
		free(temp);
	}
	temp = token[index.i].cmd;
	token[index.i].cmd = ft_strjoin(temp, str);
	ft_free(temp);
}
