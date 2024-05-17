/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:57:34 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/19 20:08:00 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern :: Intern()
{

}

Intern :: Intern(const Intern &temp)
{
	*this = temp;
}

Intern&	Intern :: operator=(const Intern &temp)
{
	(void)temp;
	return *this;
}

AForm*	Intern :: makeForm(std::string type, std::string name)
{
	int i;
	std::string types[3] = {"Shrubbery", "Robotomy", "Presidential"};

	for (i = 0; i < 3; i++)
	{
		if (type == types[i])
		{
			std::cout << "Intern creates " << type << std::endl;
			break;
		}
	}
	switch(i)
	{
		case 0:
			return (new ShrubberyCreationForm(name));
		case 1:
			return (new RobotomyRequestForm(name));
		case 2:
			return (new PresidentialPardonForm(name));
		default:
			std::cout << "Doesn't find form......" << std::endl;
	}
	std::cout << std::endl;
	return (NULL);
}

Intern :: ~Intern()
{
	
}