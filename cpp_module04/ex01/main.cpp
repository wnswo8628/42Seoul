/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:35:06 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/24 02:28:56 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *animal[10];
	std::string str;

	for (int i = 0; i < 10; i++) 
	{
		if (i < 5)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		animal[i]->makeSound();
		std::cout << std::endl;
	}
	for (int i = 0; i < 10; i++) 
		delete animal[i];
	
	std::cout << "---------------" << std::endl;
	Cat *d = new Cat();
	Cat *d2 = new Cat();
	std::cout << "---------------" << std::endl;
	str = d->getBrain()->getIdeas(0);
	std::cout << "In brain : " << str << std::endl;

	*d2 = *d;
	str = d2->getBrain()->getIdeas(0);
	std::cout << "In copy Brain : " << str << std::endl;

	delete d;
	d = NULL;
	delete d2;
	d2 = NULL;
    system("leaks Brain");
    return 0; 
}