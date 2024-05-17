/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:23:10 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/28 17:26:24 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat jugwak("jugwak", 5);
		ShrubberyCreationForm Shrubbery("Shrubbery");

		std::cout << jugwak << std::endl << Shrubbery << std::endl;
		jugwak.signForm(Shrubbery);
		jugwak.signForm(Shrubbery);
		jugwak.executeForm(Shrubbery);
		jugwak.executeForm(Shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat jugwak("jugwak", 1);
		PresidentialPardonForm Presidential("Presidential");

		std::cout << jugwak << std::endl << Presidential << std::endl;
		jugwak.signForm(Presidential);
		jugwak.executeForm(Presidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat jugwak("jugwak", 1);
		RobotomyRequestForm Robotomy("Robotomy");

		std::cout << jugwak << std::endl << Robotomy << std::endl;
		jugwak.signForm(Robotomy);
		jugwak.executeForm(Robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}