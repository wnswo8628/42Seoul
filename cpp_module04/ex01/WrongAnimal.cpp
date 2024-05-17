/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:28:19 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/23 19:32:28 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal :: WrongAnimal()
{
	this->type = "";
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal :: WrongAnimal(const WrongAnimal &temp)
{
	this->type = temp.type;
	std::cout << "WrongAnimal Copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal :: operator=(const WrongAnimal &temp)
{
	if (this != &temp)
	{
		this->type = temp.type;
	}
	return (*this);
}

void	WrongAnimal :: makeSound(void) const
{

}

std::string WrongAnimal :: getType(void) const
{
	return (this->type);
}

WrongAnimal :: ~WrongAnimal()
{
	std::cout << "WrongAnimal desconstructor" << std::endl;
}