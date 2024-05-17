/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:41:58 by jonseo            #+#    #+#             */
/*   Updated: 2023/05/12 17:53:33 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	in_last(t_token *token, int idx, int last_fd)
{
	int	fd;

	if (!token[idx].last_doc)
		return (last_fd);
	fd = open(token[idx].last_doc, O_RDONLY);
	close(last_fd);
	if (!token[idx].tav[0])
	{
		close(fd);
		unlink(token[idx].last_doc);
		open_outfile(token, idx);
		exit(0);
	}
	return (fd);
}

int	cnt_file(char **file)
{
	int	i;

	i = 0;
	if (!file)
		return (0);
	while (file[i])
		i++;
	return (i);
}

void	free_close(t_token *token, int *fd, int idx)
{
	int	i;

	i = 0;
	if (!token[idx].infile)
	{
		free(fd);
		fd = NULL;
		return ;
	}
	while (fd[i] < cnt_file(token[idx].infile) - 1)
		close(fd[i++]);
	free(fd);
	fd = NULL;
}

int	open_infile(t_token *token, int idx)
{
	int	i;
	int	*fd;

	i = -1;
	if (!token[idx].infile && !token[idx].last_doc)
		return (-1);
	fd = (int *)malloc(sizeof(int) * cnt_file(token[idx].infile));
	while (token[idx].infile && token[idx].infile[++i])
	{
		fd[i] = open(token[idx].infile[i], O_RDONLY);
		if (fd[i] < 0)
		{
			perror(token[idx].infile[i]);
			while (--i >= 0)
				close(fd[i]);
			free(fd);
			fd = NULL;
			return (0);
		}
	}
	if (token[idx].infile)
		i = fd[cnt_file(token[idx].infile) - 1];
	free_close(token, fd, idx);
	return (in_last(token, idx, i));
}

int	open_outfile(t_token *token, int idx)
{
	int	i;
	int	len;
	int	fd;

	i = 0;
	len = 0;
	if (!token[idx].outfile)
		return (-1);
	while (token[idx].outfile[len])
		len++;
	while (i < len)
	{
		if (token[idx].append_flg[i] == 1)
			fd = open(token[idx].outfile[i], \
			O_RDWR | O_CREAT | O_APPEND, 0664);
		else
			fd = open(token[idx].outfile[i], \
			O_RDWR | O_CREAT | O_TRUNC, 0644);
		i++;
	}
	return (fd);
}
