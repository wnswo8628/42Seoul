/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:10:56 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/19 18:15:48 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib> //srand()
# include <ctime> //time()

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &temp);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &temp);
		std::string getTarget() const;
		virtual void execute(const Bureaucrat& executor) const;
		virtual ~RobotomyRequestForm();
};

std::ostream&	operator<<(std::ostream &os, const RobotomyRequestForm &temp);

#endif