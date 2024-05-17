/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:07:57 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/18 19:51:29 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed()
{
	this->f_value = 0;
}

Fixed :: Fixed(const int value)
{
	this->f_value = value << this->bit;
}

Fixed :: Fixed(const float value)
{
	this->f_value = roundf(value * (1 << this->bit));
}

Fixed :: Fixed(const Fixed& fix)
{
	*this = fix;
}

Fixed& Fixed :: operator=(const Fixed &fix)
{
	if (this != &fix)
		this->f_value = fix.getRawBits();
	return (*this);
}

bool	Fixed :: operator>(Fixed fix) const
{
	return (this->getRawBits() > fix.getRawBits());
}

bool	Fixed :: operator<(Fixed fix) const
{
	return (this->getRawBits() < fix.getRawBits());
}

bool	Fixed :: operator>=(Fixed fix) const
{
	return (this->getRawBits() >= fix.getRawBits());
}

bool	Fixed :: operator<=(Fixed fix) const
{
	return (this->getRawBits() <= fix.getRawBits());
}

bool	Fixed :: operator==(Fixed fix) const
{
	return (this->getRawBits() == fix.getRawBits());
}

bool	Fixed :: operator!=(Fixed fix) const
{
	return (this->getRawBits() != fix.getRawBits());
}

Fixed	Fixed :: operator+(Fixed fix) const
{
	Fixed temp(this->toFloat() + fix.toFloat());
	return (temp);
}

Fixed	Fixed :: operator-(Fixed fix) const
{
	Fixed temp(this->toFloat() - fix.toFloat());
	return (temp);
}

Fixed	Fixed :: operator*(Fixed fix) const
{
	Fixed temp(this->toFloat() * fix.toFloat());
	return (temp);
}

Fixed	Fixed :: operator/(Fixed fix) const
{
	Fixed temp(this->toFloat() / fix.toFloat());
	return (temp);
}

Fixed&	Fixed :: operator++(void)
{
	this->f_value++;
	return (*this);
}

const	Fixed	Fixed :: operator++(int)
{
	const	Fixed temp(*this);

	this->f_value++;
	return (temp);
}

Fixed&	Fixed :: operator--(void)
{
	this->f_value--;
	return (*this);
}

const	Fixed	Fixed :: operator--(int)
{
	const Fixed temp(*this);

	this->f_value--;
	return (temp);
}

Fixed&	Fixed :: min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 <= ref2)
		return(ref1);
	else
		return(ref2);
}

const	Fixed&	Fixed :: min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 <= ref2)
		return (ref1);
	else
		return (ref2);
}

Fixed&	Fixed :: max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 >= ref2)
		return(ref1);
	else
		return(ref2);
}

const	Fixed&	Fixed :: max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 >= ref2)
		return (ref1);
	else
		return (ref2);
}

float	Fixed :: toFloat(void) const
{
	return ((float)this->f_value / (1 << this->bit));
}

int		Fixed :: toInt(void) const
{
	return (this->f_value >> this->bit);
}

int	Fixed :: getRawBits(void) const
{
	return (this->f_value);
}

void	Fixed :: setRawBits(const int raw)
{
	this->f_value = raw;
}

Fixed :: ~Fixed()
{
	
}

std::ostream& operator<<(std::ostream &s, const Fixed &fixed)
{
	s << fixed.toFloat();
	return (s);
}