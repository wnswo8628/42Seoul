/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:10:01 by jugwak            #+#    #+#             */
/*   Updated: 2022/07/15 18:10:02 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(const void *dest, const void *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(src);
	if (!dest || !src)
		return (0);
	while (i < n && i + 1 < size)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	if (size > 0)
		((unsigned char *)dest)[i] = '\0';
	return (n);
}
