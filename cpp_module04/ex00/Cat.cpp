/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:53:19 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/24 00:47:38 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat :: Cat()
{
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
		this->type = temp.type;
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

Cat :: ~Cat()
{
	std::cout << "Cat desconstructor" <<std::endl;
}