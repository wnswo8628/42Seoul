/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:04:20 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/12 17:40:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <cstring>
# include <cstdlib>

class RPN
{
	private:
		std::string	cmd;
		std::stack<std::string> cmd_split;
		std::stack<double> rpn;
		int	elements;
	public:
		RPN();
		RPN(char *av);
		RPN(const RPN &temp);
		RPN& operator=(const RPN &temp);
		~RPN();
		void	excute(void);
		void	cmdSplit(void);
		void	calculate(void);
		void	checkCmd(std::string str);
		bool	isOperator(std::string tmp);
		double	calculateNumber(double num1, double num2, char oper);
		class Error : public std::exception
		{
			const	char * what(void) const throw();
		};
};

#endif