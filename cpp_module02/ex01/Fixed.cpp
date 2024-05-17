/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:29:43 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/18 19:43:46 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->f_value = 0;
}

Fixed :: Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->f_value = value << this->bit;
}

Fixed :: Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->f_value = roundf(value * (1 << this->bit));
}

Fixed :: Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed& Fixed :: operator=(const Fixed& fix)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
		this->f_value = fix.getRawBits();
	return (*this);
}
float	Fixed :: toFloat(void) const
{
	return ((float)this->f_value / (1 << this->bit));
}

int	Fixed :: toInt(void) const
{
	return (this->f_value >> this->bit);
}

void	Fixed :: setRawBits(const int raw)
{
	this->f_value = raw;
}

int	Fixed :: getRawBits(void) const
{
	return (this->f_value);
}

Fixed :: ~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &s, const Fixed &fixed)
{
	s << fixed.toFloat();
	return (s);
}