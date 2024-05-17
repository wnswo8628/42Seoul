/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:53:19 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/24 02:25:54 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat :: Cat()
{
	br = new Brain();
	this->type = "Cat";
	std::cout << "Cat default constructor" << std::endl;
}

Cat :: Cat(const Cat &temp)
{
	std::cout << "Cat Copy constructor" << std::endl;
	*this = temp;
}

Cat&	Cat :: operator=(const Cat &temp)
{
	if (this != &temp)
	{
		this->type = temp.getType();
		delete this->br;
		*(this->br) = *(temp.getBrain());
	}
	return (*this);
}

void	Cat :: makeSound(void) const
{
	std::cout << "Meow~" << std::endl;
}

std::string	Cat :: getType(void) const
{
	return (this->type);
}

Brain* Cat :: getBrain(void) const
{
	return (br);
}

Cat :: ~Cat()
{
	delete br;
	std::cout << "Cat desconstructor" <<std::endl;
}