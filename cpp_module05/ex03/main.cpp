/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:08:11 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/19 20:24:36 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat jugwak("jugwak", 1);
		Intern	intern;
		AForm *form = intern.makeForm("Shrubbery", "AAAAA");

		if (!form)
			return (-1);
		std::cout << jugwak << std::endl << *form << std::endl;
		jugwak.signForm(*form);
		jugwak.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;

	try
	{
		Bureaucrat jugwak("jugwak", 1);
		Intern intern;
		AForm *form = intern.makeForm("Presidential", "BBBBBB");

		if (!form)
			return (-1);
		std::cout << jugwak << std::endl << *form << std::endl;
		jugwak.signForm(*form);
		jugwak.signForm(*form);
		jugwak.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;

	try
	{
		Bureaucrat jugwak("jugwak", 1);
		Intern intern;
		AForm *form = intern.makeForm("Robotomy", "CCCCCCC");

		if (!form)
			return (-1);
		std::cout << jugwak << std::endl << *form << std::endl;
		jugwak.signForm(*form);
		jugwak.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}