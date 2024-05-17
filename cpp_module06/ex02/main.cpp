/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:45:26 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/02 17:33:09 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	identify(Base &ptr)
{
	try
	{
		A &a = dynamic_cast<A&>(ptr);
		std::cout << "generate make A class" << std::endl;
		static_cast<void>(a);
	}
	catch(const std::exception& e){
	}
	try
	{
		B &b = dynamic_cast<B&>(ptr);
		std::cout << "generate make B class" << std::endl;
		static_cast<void>(b);
	}
	catch(const std::exception& e){
	}
	try
	{
		C &c = dynamic_cast<C&>(ptr);
		std::cout << "generate make C class" << std::endl;
		static_cast<void>(c);
	}
	catch(const std::exception& e){
	}
}

void	identify(Base *ptr)
{
	if (dynamic_cast<A *>(ptr) != NULL)
		std::cout << "generate make A class." << std::endl;
	else if (dynamic_cast<B *>(ptr) != NULL)
		std::cout << "generate make B class." << std::endl;
	else if (dynamic_cast<C *>(ptr) != NULL)
		std::cout << "generate make C class." << std::endl;
	else
		std::cout << "Can not make any class from generate..." << std::endl;
}

Base* generate()
{
	int i = rand() % 3;
	switch(i)
	{
		case 0 :
			return new A();
		case 1 :
			return new B();
		case 2 :
			return new C();
		default :
			return NULL;
	}
}

int main()
{
	Base *ptr;

	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < 3; i++)
	{
		ptr = generate();
		identify(*ptr);
		identify(ptr);
		delete ptr;
	}
	return (0);
}