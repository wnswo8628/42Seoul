/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:08:25 by jugwak            #+#    #+#             */
/*   Updated: 2022/07/15 18:08:26 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (destsize <= dest_len)
		return (src_len + destsize);
	while (dest_len + i + 1 < destsize && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (i < destsize)
		dest[i + dest_len] = '\0';
	return (src_len + dest_len);
}
