/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:05:48 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 20:06:00 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*result;

	len = ft_strlen2(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

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

size_t	ft_strlen2(const char *str)
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
	len = ft_strlen2(s1);
	len2 = ft_strlen2(s2);
	result = (char *)malloc(sizeof(char) * (len + len2 + 1));
	if (!result)
		return (0);
	ft_memcpy(result, s1, len);
	ft_memcpy(result + len, s2, len2);
	result[len + len2] = 0;
	free(s1);
	return (result);
}
