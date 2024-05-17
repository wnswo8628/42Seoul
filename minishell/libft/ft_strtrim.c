/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:13:50 by jugwak            #+#    #+#             */
/*   Updated: 2022/07/15 18:13:51 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	if (*set == '\0')
		return (ft_strdup(s1));
	while (s1[start] != '\0' && is_set(s1[start], set))
		start++;
	while (is_set(s1[end - 1], set))
	{
		if (end - 1 < 1)
			break ;
		end--;
	}
	if (start > end)
		return (ft_strdup(""));
	result = ft_substr(s1, start, end - start);
	return (result);
}
