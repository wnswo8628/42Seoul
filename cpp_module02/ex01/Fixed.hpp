/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:29:53 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/03 17:30:49 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	f_value;
		static const int bit = 8;
	public:
		Fixed(const Fixed& copy);
		Fixed(const float value);
		Fixed(const int value);
		Fixed();
		Fixed &operator=(const Fixed &fix);
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		~Fixed();
};

std::ostream	&operator<<(std::ostream &s, const Fixed &fixed);

#endif