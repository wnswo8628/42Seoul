/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:19:51 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/11 22:12:52 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**error_handle(void)
{
	char	**arr;

	arr = (char **)ft_malloc(sizeof(char *));
	if (!arr)
		return (NULL);
	arr[0] = NULL;
	return (arr);
}

int	token_len(t_token *token)
{
	int	i;

	i = 0;
	while (token[i].str)
		i++;
	return (i);
}

void	ctrl_d(void)
{
	printf("exit\n");
	exit(0);
}

void	*ft_malloc(size_t size)
{
	void	*temp;

	temp = (void *)malloc(size);
	if (!temp)
	{
		g_status = 1;
		exit(1);
	}
	return (temp);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*pb;
	size_t			allocate;

	ptr = (void *)ft_malloc(count * size);
	if (!ptr)
		return (NULL);
	pb = ptr;
	allocate = count * size;
	while (allocate-- > 0)
		*pb++ = 0;
	return (ptr);
}
