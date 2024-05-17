/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:07:26 by jugwak            #+#    #+#             */
/*   Updated: 2022/07/15 18:07:27 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
