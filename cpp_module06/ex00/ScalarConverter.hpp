/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:35:00 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/23 17:42:19 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits> //numeric_limits<>
# include <cstdlib> //strtod();
# include <iomanip> // setpercision()

class	Scalarconverter
{
	private:
		static	const std::string value;
		static	double point;
		Scalarconverter();
	public:
		Scalarconverter(std::string c_value);
		Scalarconverter(const Scalarconverter &temp);
		Scalarconverter& operator=(const Scalarconverter &temp);
		~Scalarconverter();
		static	void	convert(const std::string value);
		static	bool	soloChar(const std::string value);
		static	void	checkChar();
		static	void	checkInt();
		static	void	checkFloat();
		static	void	checkDouble();
};

#endif