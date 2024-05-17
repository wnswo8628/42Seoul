/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:21:55 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/16 18:02:29 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str : " << str << std::endl;
	std::cout << "strPTR : " << *stringPTR << std::endl;
	std::cout << "strREF : " << stringREF << std::endl;

	std::cout << "str address : " << &str << std::endl;
	std::cout << "strPTR address : " << stringPTR << std::endl;
	std::cout << "strREF address : " << &stringREF << std::endl;
}