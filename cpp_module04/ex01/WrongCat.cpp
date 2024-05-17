/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:40:16 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/23 19:45:15 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat :: WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat :: WrongCat(const WrongCat &temp)
{
	this->type = temp.type;
	std::cout << "WrongCat Copy constructor" << std::endl;
}

WrongCat& WrongCat :: operator=(const WrongCat &temp)
{
	if (this != &temp)
	{
		this->type = temp.type;
	}
	return (*this);
}

void	WrongCat :: makeSound(void) const
{
	std::cout << "Meow~" << std::endl;
}

std::string WrongCat :: getType(void) const
{
	return (this->type);
}

WrongCat :: ~WrongCat()
{
	std::cout << "WrongCat desconstructor" << std::endl;
}