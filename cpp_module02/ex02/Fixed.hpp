/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:49:44 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/04 17:43:07 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int		f_value;
		static	const int bit = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& fix);
		
		Fixed &operator=(const Fixed &fix);
		bool operator>(Fixed fix) const;
		bool operator<(Fixed fix) const;
		bool operator>=(Fixed fix) const;
		bool operator<=(Fixed fix) const;
		bool operator==(Fixed fix) const;
		bool operator!=(Fixed fix) const;

		Fixed operator+(Fixed fix) const;
		Fixed operator-(Fixed fix) const;
		Fixed operator*(Fixed fix) const;
		Fixed operator/(Fixed fix) const;

		Fixed &operator++(void); //전위 연산자
		const Fixed operator++(int); //후위 연산자
		Fixed &operator--(void);
		const Fixed operator--(int);
		
		static	Fixed	&min(Fixed &ref1, Fixed &ref2);
		static	const	Fixed	&min(Fixed const &ref1, Fixed const &ref2);
		static	Fixed	&max(Fixed &ref1, Fixed &ref2);
		static	const	Fixed	&max(Fixed const &ref1, Fixed const &ref2);
		
		int	getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &s, const Fixed &fixed);

#endif