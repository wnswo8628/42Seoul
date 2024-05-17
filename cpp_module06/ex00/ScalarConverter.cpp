/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:35:44 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/02 17:28:23 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const std::string Scalarconverter :: value = "";
double	Scalarconverter :: point = 0.0;

Scalarconverter :: Scalarconverter()
{
	
}

Scalarconverter :: Scalarconverter(std::string c_value)
{
	try
	{
		const_cast<std::string&>(value) = c_value;
		if (soloChar(value))
			point = static_cast<double>(value[0]);
		else
			point = std::strtod(value.c_str(), NULL);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : casting because " << e.what() << '\n';
	}
}

Scalarconverter :: Scalarconverter(const Scalarconverter &temp)
{
	const_cast<std::string&>(value) = temp.value;
	*this = value;
}

Scalarconverter :: ~Scalarconverter()
{

}

Scalarconverter& Scalarconverter :: operator=(const Scalarconverter &temp)
{
	if (this != &temp)
	{
		const_cast<std::string&>(value) = temp.value;
		point = temp.point;
	}
	return *this;
}

bool	Scalarconverter :: soloChar(const std::string value)
{
	if (value.size() == 1 && !std::isdigit(value[0]))
		return (true);
	return (false);
}

void	Scalarconverter :: checkChar()
{
	char c = static_cast<char>(point);
	int i = static_cast<int>(point);

	if (point != point)
		std::cout << "char : impossible" << std::endl;
	else if (std::isprint(i))
		std::cout << "char : " << "'" << c << "'" << std::endl;
	else if (c >= std::numeric_limits<char>::min() && c <= std::numeric_limits<char>::max())
		std::cout << "char : non displayable" << std::endl;
	else
		std::cout << "char : impossible" << std::endl;
}

void	Scalarconverter :: checkInt()
{
	int i = static_cast<int>(point);

	if (point != point)
		std::cout << "int : impossible" << std::endl;
	else if (point >= std::numeric_limits<int>::min() && point <= std::numeric_limits<int>::max())
		std::cout << "int : " << i << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
}

void	Scalarconverter :: checkFloat()
{
	float f = static_cast<float>(point);

	if (point != point)
		std::cout << "float : nanf" << std::endl;
	else if (point == std::numeric_limits<float>::infinity())
		std::cout << "float : inff" << std::endl;
	else if (point == -std::numeric_limits<float>::infinity())
		std::cout << "float : -inff" << std::endl;
	else if (point < -std::numeric_limits<float>::max() && point > std::numeric_limits<float>::max())
		std::cout << "float : impossible" << std::endl;
	else
		std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void	Scalarconverter :: checkDouble()
{
	double f = static_cast<double>(point);

	if (point != point)
		std::cout << "double : nan" << std::endl;
	else if (point == std::numeric_limits<double>::infinity())
		std::cout << "double : inf" << std::endl;
	else if (point == -std::numeric_limits<double>::infinity())
		std::cout << "double : -inf" << std::endl;
	else if (point < -std::numeric_limits<double>::max() && point > std::numeric_limits<float>::max())
		std::cout << "double : impossible" << std::endl;
	else
		std::cout << "double : " << std::fixed << std::setprecision(1) << f << std::endl;
}