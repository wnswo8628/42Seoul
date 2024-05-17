/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:06:19 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/05 16:41:45 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int array[4] = {1, 2, 3, 4};
	char c_array[4] = {'a', 'b', 'c', 'd'};
	const char cc_array[4] = {'a', 'b', 'c', 'd'};
	const int	ci_array[4] = {1, 2, 3, 4};

	::iter(array, 4, ::plus);
	for (int i = 0; i < 4; i++)
		::print(array[i]);
	::iter(c_array, 4, ::plus);
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		::print(c_array[i]);

	std::cout << std::endl;
	std::cout << "Const test" << std::endl;
	::iter(cc_array, 4, ::print);
	std::cout << std::endl;
	::iter(ci_array, 4, ::print);

	return (0);
}