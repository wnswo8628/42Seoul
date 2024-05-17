/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:03:10 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 16:41:26 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub.h"

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
