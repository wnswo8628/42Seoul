/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:52:47 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/30 15:15:02 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	Form :: getSignGrade() const
{
	return (this->signGrade);
}

int	Form :: getExGrade() const
{
	return (this->exGrade);
}

const std::string Form :: getName() const
{
	return (this->name);
}

bool	Form :: getSign() const
{
	return (this->sign);
}

const	char * Form :: GradeTooHighException :: what(void) const throw()
{
	return ("Grade Too High....;");
}

const	char * Form :: GradeTooLowException :: what(void) const throw()
{
	return ("Grade Too Low...;");
}

Form :: Form() : name(""), signGrade(150), exGrade(150)
{
	this->sign = false;
}

Form :: Form(const std::string name, const int signGrade, const int exGrade) 
	: name(name), signGrade(signGrade), exGrade(exGrade)
{
	if (this->getSignGrade() > 150 || this->getExGrade() > 150)
		throw Form :: GradeTooLowException();
	else if (this->getSignGrade() < 1 || this->getExGrade() < 1)
		throw Form :: GradeTooHighException();
	this->sign = false;
}

Form :: Form(const Form &temp) 
	: name(temp.name), signGrade(temp.signGrade), exGrade(temp.exGrade)
{
	*this = temp;
}

Form&	Form :: operator=(const Form &temp)
{
	if (this != &temp)
	{
		const_cast<std::string&>(name) = temp.name;
		this->sign = temp.sign;
		const_cast<int&>(signGrade) = temp.signGrade;
		const_cast<int&>(exGrade) =  temp.exGrade;
	}
	return (*this);
}

void	Form :: beSigned(Bureaucrat &bu)
{
	if (this->signGrade < bu.getgrade())
		throw Form :: GradeTooLowException();
	else if (this->sign == true)
		throw "Already signed";
	this->sign = true;
}

Form :: ~Form()
{
	
}

std::ostream& operator<<(std::ostream &os, const Form &fo)
{
	os << fo.getName() << std::boolalpha << ", sign : " << fo.getSign()
		<< ", signGrade : " << fo.getSignGrade()
		<< ", exGrade : " << fo.getExGrade();
	return (os);
}