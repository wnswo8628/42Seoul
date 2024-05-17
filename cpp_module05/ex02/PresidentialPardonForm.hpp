/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:17:49 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/19 17:54:42 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &temp);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm &temp);
	virtual ~PresidentialPardonForm();
	std::string getTarget() const;
	virtual void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& pre);

#endif