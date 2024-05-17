/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:12:08 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/30 18:49:41 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer :: Serializer()
{

}

Serializer :: Serializer(const Serializer &temp)
{
	*this = temp;
}

Serializer :: ~Serializer()
{

}

Serializer& Serializer :: operator=(const Serializer &temp)
{
	(void)temp;
	return (*this);
}

uintptr_t	Serializer :: serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer :: deserialize(uintptr_t uniptr)
{
	return reinterpret_cast<Data *>(uniptr);
}