/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:18:13 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/20 15:18:33 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
 private:
	const std::string name;
	int	grade;
 public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat();
	const std::string getName() const;
	int	getgrade() const;
	void	increaseGrade();
	void	decreaseGrade();
	Bureaucrat& operator=(const Bureaucrat& obj);
	class	GradeTooHighException : public std::exception
	{
		public :
			const	char *	what(void) const throw();

	};
	class	GradeTooLowException : public std::exception
	{
		public :
			const	char * what(void) const throw();
		
	};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bu);

#endif