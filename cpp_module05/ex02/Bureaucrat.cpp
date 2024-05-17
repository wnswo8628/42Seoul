/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:20:37 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/28 20:19:32 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

void	Bureaucrat :: increaseGrade()
{
	this->grade--;
	if (this->grade < 1)
		throw	Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw	Bureaucrat::GradeTooLowException();
}

void	Bureaucrat :: decreaseGrade()
{
	this->grade++;
	if (this->grade < 1)
		throw	Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw	Bureaucrat::GradeTooLowException();
}

const std::string Bureaucrat :: getName() const
{
	return (this->name);
}

int Bureaucrat :: getgrade() const
{
	return (this->grade);
}

const	char * Bureaucrat :: GradeTooLowException :: what(void) const throw()
{
	return ("Grade too Low...");
}

const char * Bureaucrat :: GradeTooHighException :: what(void) const throw()
{
	return ("Grade too high...");
}

Bureaucrat::Bureaucrat() : name(""), grade(150)
{
	
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	this->grade = grade;
	if (this->grade < 1)
		throw	Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw	Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name)
{
	*this = obj;
}

void Bureaucrat :: signForm(AForm &fo)
{
	try
	{
		fo.beSigned(*this);
		std::cout << this->getName() << " signed " << fo.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << fo.getName() << " because " << e.what() << std::endl;
	}
	catch(const char *s)
	{
		std::cout << s << '\n';
	}
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
	{
		const_cast<std::string&>(name) = obj.name;
		this->grade = obj.grade;
	}
	return (*this);
}

void	Bureaucrat :: executeForm(const AForm& af)
{
	try
	{
		af.execute(*this);
		std::cout << this->getName() << " executed " << af.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << af.getName() << " because " << e.what() << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bu)
{
	os << bu.getName() << ", bureaucrat grade " << bu.getgrade();
	return (os);
}