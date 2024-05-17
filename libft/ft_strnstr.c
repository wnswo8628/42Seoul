/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:16:48 by jugwak            #+#    #+#             */
/*   Updated: 2022/07/15 17:33:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
