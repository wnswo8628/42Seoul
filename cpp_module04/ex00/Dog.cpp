/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:04:19 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/24 00:47:45 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog :: Dog()
{
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
		this->type = temp.type;
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

Dog :: ~Dog()
{
	std::cout << "Dog desconstructor" << std::endl;
}