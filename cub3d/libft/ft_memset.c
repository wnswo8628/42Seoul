/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:36:48 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 16:41:29 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*dest;

	dest = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		dest[i++] = (unsigned char)value;
	}
	return (dest);
}
