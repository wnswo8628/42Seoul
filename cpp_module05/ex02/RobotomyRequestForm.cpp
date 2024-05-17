/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:15:53 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/19 19:33:01 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm :: RobotomyRequestForm() : AForm("Robotomy", 72, 45), target("")
{
	
}

RobotomyRequestForm :: RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), target(target)
{

}

RobotomyRequestForm :: RobotomyRequestForm(const RobotomyRequestForm &temp) : AForm(temp)
{
	*this = temp;
}

RobotomyRequestForm&	RobotomyRequestForm :: operator=(const RobotomyRequestForm &temp)
{
	if (this != &temp)
	{
		target = temp.target;
	}
	return (*this);
}

std::string	RobotomyRequestForm :: getTarget() const
{
	return (this->target);
}

void	RobotomyRequestForm :: execute(const Bureaucrat &executer) const
{
	if (executer.getgrade() > getExGrade())
		throw GradeTooLowException();
	else if (getSign() == false)
		throw CheckSignedException();
	srand(static_cast<unsigned int>(time(NULL)));
	std::cout << "drill say : drrrrrrrrrr....!" << std::endl;
	if (rand() % 2 == 1)
		std::cout << target << " has been robotomized success !!" << std::endl;
	else
		std::cout << target << " robotomization fail...." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm &temp)
{
	os << temp.getName() << std::boolalpha << ", RobotomyRequestForm signed is "
		<< temp.getSign() << ", Grade for Sign : " << temp.getSignGrade()
		<< ", Grade for execute : " << temp.getExGrade();
	return (os);
}

RobotomyRequestForm :: ~RobotomyRequestForm()
{
	
}
