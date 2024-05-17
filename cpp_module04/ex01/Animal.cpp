/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:00:49 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/24 02:31:01 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "";
	std::cout << "Animal Default constructor" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	this->type = obj.type;
	std::cout << "Animal Copy constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal desconstructor" << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return (*this);
}

std::string	Animal :: getType(void) const
{
	return (this->type);
}

void	Animal :: makeSound(void) const
{
	std::cout << "default type animal can't make sound!" << std::endl;
}