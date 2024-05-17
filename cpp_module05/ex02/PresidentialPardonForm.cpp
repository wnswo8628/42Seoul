/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:17:45 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/30 15:17:11 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm :: PresidentialPardonForm() : AForm("Presidential", 25, 5), target("")
{
	
}

PresidentialPardonForm :: PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), target(target)
{
	
}

PresidentialPardonForm :: PresidentialPardonForm(const PresidentialPardonForm &temp) : AForm(temp)
{
	*this = temp;
}

PresidentialPardonForm& PresidentialPardonForm :: operator=(const PresidentialPardonForm &temp)
{
	if (this != &temp)
		target = temp.target;
	return (*this);
}

std::string	PresidentialPardonForm :: getTarget() const
{
	return target;
}

void	PresidentialPardonForm :: execute(const Bureaucrat &executer) const
{
	if (executer.getgrade() > getExGrade())
		throw GradeTooLowException();
	else if (getSign() == false)
		throw CheckSignedException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream&	operator<<(std::ostream &os, const PresidentialPardonForm &temp)
{
	os << temp.getName() << std::boolalpha << ", PresidentialPardonForm signed is "
		<< temp.getSign() << ", Grade for Sign : " << temp.getSignGrade()
		<< ", Grade for Excute : " << temp.getExGrade();
	return (os);
}

PresidentialPardonForm :: ~PresidentialPardonForm()
{

}