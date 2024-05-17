/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:04:31 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/13 16:52:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN :: RPN() : cmd(NULL), elements(0)
{
	
}

RPN :: RPN(char *av) : elements(0)
{
	cmd = std::string(av);
}

RPN :: RPN(const RPN &temp)
{
	this->cmd = temp.cmd;
	this->elements = temp.elements;
	*this = temp;
}

RPN&	RPN :: operator=(const RPN &temp)
{
	if (this != &temp)
	{
		this->cmd = temp.cmd;
		this->elements = temp.elements;
	}
	return (*this);
}

RPN :: ~RPN()
{
	
}

void	RPN :: cmdSplit()
{
	std::istringstream	iss(this->cmd);
	std::string	temp;
	std::stack<std::string> stack_temp;

	while (std::getline(iss, temp, ' '))
	{
		if (temp.empty())
			continue ;
		checkCmd(temp);
		stack_temp.push(temp);
	}

	while (!stack_temp.empty())
	{
		this->cmd_split.push(stack_temp.top());
		stack_temp.pop();
	}

	if (this->elements * 2 - this->cmd_split.size() != 1)
		throw RPN :: Error();
}

void	RPN :: checkCmd(std::string str)
{
	if (str.length() == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*'))
		return ;
	char *ptr = NULL;
	double value = 0;
	value = std::strtod(str.c_str(), &ptr);
	if (value == 0.0 && !std::isdigit(str[0]))
		throw RPN :: Error();
	if (*ptr && std::strcmp(ptr, "f"))
		throw RPN :: Error();
	if (value >= 10 || value <= -10)
		throw RPN :: Error();
	++this->elements;
}

bool	RPN :: isOperator(std::string tmp)
{
	if (tmp.length() == 1 && (tmp[0] == '+' || tmp[0] == '-' || tmp[0] == '/' || tmp[0] == '*'))
		return (true);
	return (false);
}

double	RPN :: calculateNumber(double num1, double num2, char oper)
{
	if (oper == '+')
		return(num1 + num2);
	else if (oper == '-')
		return(num1 - num2);
	else if (oper == '/')
		return (num1 / num2);
	else if (oper == '*')
		return (num1 * num2);
	else
		throw	RPN :: Error();
}

void	RPN :: calculate()
{
	double	num1, num2;
	
	while (!this->cmd_split.empty())
	{
		std::string tmp = this->cmd_split.top();
		if (isOperator(tmp))
		{
			if (this->rpn.size() < 2)
				throw	RPN :: Error();
			num2 = rpn.top();
			rpn.pop();
			num1 = rpn.top();
			rpn.pop();
			rpn.push(calculateNumber(num1, num2, tmp[0]));
			this->cmd_split.pop();
		}
		else
		{
			double	num = std::strtod(this->cmd_split.top().c_str(), NULL);
			rpn.push(num);
			this->cmd_split.pop();
		}
	}
	std::cout << rpn.top() << std::endl;
}

void	RPN :: excute(void)
{
	try
	{
		cmdSplit();
		calculate();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

const	char * RPN :: Error :: what(void) const throw()
{
	return ("Error");
}