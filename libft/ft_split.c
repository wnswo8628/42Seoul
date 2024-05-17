/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:15:40 by jugwak            #+#    #+#             */
/*   Updated: 2022/07/15 17:16:39 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char s, char c)
{
	if (s == c)
		return (1);
	else
		return (0);
}

static void	free_array(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array[0]);
}

static char	**div_word(char const *str, char **array, int cnt_word, char c)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	i = 0;
	while (str[start] != '\0' && check(str[start], c))
		start++;
	while (i < cnt_word)
	{
		end = start;
		while (str[end] != '\0' && !check(str[end], c))
			end++;
		array[i++] = ft_substr(str, start, end - start);
		if (!array[i - 1])
		{
			free_array(array, i);
			return (NULL);
		}
		start = end;
		while (str[start] != '\0' && check(str[start], c))
			start++;
	}
	array[i] = 0;
	return (array);
}

static int	cnt_size(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0' && check(str[i], c))
		i++;
	while (str[i] != '\0')
	{
		cnt++;
		while (str[i] != '\0' && !check(str[i], c))
			i++;
		while (str[i] != '\0' && check(str[i], c))
			i++;
	}
	return (cnt);
}

char	**ft_split(char const *str, char c)
{
	int		cnt_word;
	char	**array;

	cnt_word = cnt_size(str, c);
	array = malloc((sizeof(char *)) * (cnt_word + 1));
	if (!array)
		return (0);
	array = div_word(str, array, cnt_word, c);
	return (array);
}
