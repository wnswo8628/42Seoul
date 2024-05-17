/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:54:07 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/23 17:43:58 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "bad argument" << std::endl;
		return -1;
	}
	Scalarconverter sc(av[1]);
	sc.checkChar();
	sc.checkInt();
	sc.checkFloat();
	sc.checkDouble();

	return (0);
}