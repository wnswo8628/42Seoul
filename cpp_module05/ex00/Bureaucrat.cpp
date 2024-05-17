/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:20:37 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/30 15:18:13 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

const	char * Bureaucrat :: GradeTooHighException :: what(void) const throw()
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

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bu)
{
	os << bu.getName() << ", bureaucrat grade " << bu.getgrade();
	return (os);
}