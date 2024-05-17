/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:13:08 by jugwak            #+#    #+#             */
/*   Updated: 2022/07/15 18:13:10 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	int			i;
	int			len;

	len = ft_strlen(s);
	i = len;
	while (i >= 0)
	{
		if (s[i] == (char)ch)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
