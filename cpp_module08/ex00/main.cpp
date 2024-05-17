/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:38:52 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/04 18:17:34 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	std::deque<int> deq;
	std::list<int> lst;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		deq.push_back(i);
		lst.push_back(i);
	}

	std::cout << "<Vector>" << std::endl;
	try
	{
		std::cout << "Easyfind : " << *(easyfind(vec, 5)) << std::endl; 
		std:: cout << "distance : " <<
			std::distance(vec.begin(), easyfind(vec, 5)) <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << "<Deque>" << std::endl;
	try
	{
		std::cout << "Easyfind : " << *(easyfind(deq, 0)) << std::endl; 
		std:: cout << "distance : " <<
			std::distance(deq.begin(), easyfind(deq, 0)) <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << "<List>" << std::endl;
	try
	{
		std::cout << "Easyfind : " << *(easyfind(lst, 10)) << std::endl; 
		std:: cout << "distance : " <<
			std::distance(lst.begin(), easyfind(lst, 10)) <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}