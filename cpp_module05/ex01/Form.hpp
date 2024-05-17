/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:53:01 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/20 15:22:13 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

// class Bureaucrat;

class	Form
{
	private:
		const std::string name;
		bool sign;
		const	int signGrade;
		const	int exGrade;
	public:
		Form();
		Form(const std::string name, const int signGrade, const int exGrade);
		Form(const Form &temp);
		Form&	operator=(const Form &temp);
		~Form();
		const	std::string	getName() const;
		bool	getSign() const;
		int	getSignGrade() const;
		int	getExGrade() const;
		void	beSigned(Bureaucrat &bu);
		class	GradeTooHighException : public std::exception
		{
			public:
				const	char * what(void) const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const	char * what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream &os, const Form &temp);

#endif