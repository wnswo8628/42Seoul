/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:56:32 by jugwak            #+#    #+#             */
/*   Updated: 2022/07/15 17:56:34 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp;
	const char	*s;
	size_t		i;

	temp = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		i = -1;
		while (++i < n)
			temp[i] = s[i];
	}
	else
	{
		i = n;
		while (i)
		{
			temp[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dest);
}
