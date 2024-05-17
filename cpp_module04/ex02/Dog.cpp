/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:04:19 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/24 02:24:13 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog :: Dog()
{
	br = new Brain();
	this->type = "Dog";
	std::cout << "Dog default constructor" << std::endl;
}

Dog :: Dog(const Dog &temp)
{
	std::cout << "Dog Copy constructor" << std::endl;
	*this = temp;
}

Dog&	Dog :: operator=(const Dog &temp)
{
	if (this != &temp)
	{
		this->type = temp.getType();
		delete this->br;
		*(this->br) = *(temp.getBrain());
	}
	return (*this);
}

std::string	Dog :: getType(void) const
{
	return (this->type);
}

void	Dog :: makeSound(void) const
{
	std::cout << "Bark! BarK!" << std::endl;
}

Brain* Dog :: getBrain(void) const
{
	return (br);
}

Dog :: ~Dog()
{
	delete this->br;
	std::cout << "Dog desconstructor" << std::endl;
}