/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:57:20 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/20 15:23:02 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("a", 1);
	Form aa("aa", 5, 5);

	try
	{
		std::cout << a << std::endl;
		std::cout << aa << std::endl;

		a.signForm(aa);

		a.signForm(aa);

		// a.increaseGrade();
		for (int i = 0; i < 5; i++)
			a.decreaseGrade();
		std::cout << a << std::endl;
		a.signForm(aa);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}