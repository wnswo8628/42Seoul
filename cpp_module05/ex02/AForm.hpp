/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:53:01 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/20 15:24:28 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

// class Bureaucrat;

class	AForm
{
	private:
		const std::string name;
		bool sign;
		const	int signGrade;
		const	int exGrade;
	public:
		AForm();
		AForm(const std::string name, const int signGrade, const int exGrade);
		AForm(const AForm &temp);
		AForm&	operator=(const AForm &temp);
		virtual ~AForm();
		const	std::string	getName() const;
		bool	getSign() const;
		int	getSignGrade() const;
		int	getExGrade() const;
		void	beSigned(Bureaucrat &bu);
		virtual void	execute(Bureaucrat const &executer) const = 0;
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
		class	CheckSignedException : public std::exception
		{
			public :
				const	char *what(void) const throw();
		};
		class	AlreadySignedException : public std::exception
		{
			public :
				const	char *what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream &os, const AForm &temp);

#endif