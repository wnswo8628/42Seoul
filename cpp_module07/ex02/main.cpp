/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:52:11 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/05 17:10:33 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int>	array(10);
	Array<int>	array3(10);

	try
	{
		for (unsigned int i = 0; i < array.size(); i++)
			array[i] = i * 10;
		
		array3 = array;
		std::cout << "Copy operator" << std::endl;
		for (unsigned int i = 0; i < array3.size(); i++)
			std::cout << array3[i] << " ";
		std::cout << std::endl;
		std::cout << "Array elements" << std::endl;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;

		std::cout << "const Array elements" << std::endl;
		const Array<int> array2(5);
		for (unsigned int i = 0;  i < array2.size(); i++)
			std::cout << array2[i] << " ";
		std::cout << std::endl;

		int	invaildindex = array.size() + 1;
		array[invaildindex] = 100;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Array<char>	c_array(5);

	std::cout << std::endl;
	std::cout << "Char Array test" << std::endl;
	try
	{
		for (unsigned int i = 0; i < c_array.size(); i++)
			c_array[i] = 'a' + i;
		
		for (unsigned int i = 0; i < c_array.size(); i++)
			std::cout << c_array[i] << " ";
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}