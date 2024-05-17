/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:40:07 by jugwak            #+#    #+#             */
/*   Updated: 2023/01/31 18:36:36 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*result;

	len = ft_strlen(str);
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

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (result);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		i2 = 0;
		if (little[i2] == big[i + i2])
		{
			while (little[i2] && big[i + i2])
			{
				if (little[i2] != big[i + i2] || (i + i2) >= len)
					break ;
				i2++;
			}
			if (little[i2] == '\0')
				return (&((char *)big)[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start > (size_t)ft_strlen(s))
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
