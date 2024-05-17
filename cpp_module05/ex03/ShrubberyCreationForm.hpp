/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:40:26 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/19 19:32:33 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &temp);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &temp);
		std::string getTarget() const;
		virtual void execute(const Bureaucrat& executor) const;
		virtual ~ShrubberyCreationForm();
		class	CanNotOpenFileException : public std::exception
		{
			public :
				const	char * what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &temp);

#endif