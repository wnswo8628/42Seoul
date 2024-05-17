/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:52:47 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/28 20:20:10 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

int	AForm :: getSignGrade() const
{
	return (this->signGrade);
}

int	AForm :: getExGrade() const
{
	return (this->exGrade);
}

const std::string AForm :: getName() const
{
	return (this->name);
}

bool	AForm :: getSign() const
{
	return (this->sign);
}

const	char * AForm :: GradeTooHighException :: what(void) const throw()
{
	return ("Grade Too High....;");
}

const	char * AForm :: GradeTooLowException :: what(void) const throw()
{
	return ("Grade Too Low...;");
}

const	char * AForm :: CheckSignedException :: what(void) const throw()
{
	return ("Not sign...");
}

const	char * AForm :: AlreadySignedException :: what(void) const throw()
{
	return ("Already signed...");
}

AForm :: AForm() : name(""), signGrade(150), exGrade(150)
{
	this->sign = false;
}

AForm :: AForm(const std::string name, const int signGrade, const int exGrade) 
	: name(name), signGrade(signGrade), exGrade(exGrade)
{
	if (this->getSignGrade() > 150 || this->getExGrade() > 150)
		throw AForm :: GradeTooLowException();
	else if (this->getSignGrade() < 1 || this->getExGrade() < 1)
		throw AForm :: GradeTooHighException();
	this->sign = false;
}

AForm :: AForm(const AForm &temp) 
	: name(temp.name), signGrade(temp.signGrade), exGrade(temp.exGrade)
{
	*this = temp;
}

AForm&	AForm :: operator=(const AForm &temp)
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

void	AForm :: beSigned(Bureaucrat &bu)
{
	if (this->signGrade < bu.getgrade())
		throw AForm :: GradeTooLowException();
	else if (this->sign == true)
		throw AForm :: AlreadySignedException();
	this->sign = true;
}

AForm :: ~AForm()
{
	
}

std::ostream& operator<<(std::ostream &os, const AForm &fo)
{
	os << fo.getName() << std::boolalpha << ", sign : " << fo.getSign()
		<< ", signGrade : " << fo.getSignGrade()
		<< ", exGrade : " << fo.getExGrade();
	return (os);
}