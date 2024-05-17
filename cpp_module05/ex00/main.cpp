/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:57:20 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/28 17:22:42 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		try
		{
			Bureaucrat temp("temp", 200);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		Bureaucrat a("jugwak", 150);
		Bureaucrat b("b", 1);

		// a.decreaseGrade();
		// b.increaseGrade();
		
		a.increaseGrade();
		b.decreaseGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}