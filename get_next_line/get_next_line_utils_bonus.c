/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:37:55 by jugwak            #+#    #+#             */
/*   Updated: 2022/08/26 20:18:13 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!n || dest == src)
		return (dest);
	if (dest == NULL || src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int ch)
{
	int		i;
	char	temp;

	if (!str)
		return (0);
	i = 0;
	temp = (char)ch;
	while (str[i] != temp)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		len;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len + len2 + 1));
	if (!result)
		return (0);
	ft_memcpy(result, s1, len);
	ft_memcpy(result + len, s2, len2);
	result[len + len2] = 0;
	free(s1);
	return (result);
}
