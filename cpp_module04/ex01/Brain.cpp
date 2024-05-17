/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:41:54 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/24 02:26:21 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain :: Brain()
{
	std::cout << "Brain default constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "mind!";
}

Brain :: Brain(const Brain &temp)
{
	std::cout << "Brain Copy constructor" << std::endl;
	*this = temp;
}

Brain& Brain :: operator=(const Brain &temp)
{
	Brain *a = new Brain();
	for (int i = 0; i < 100; i++)
		a->ideas[i] = temp.ideas[i] + " copy";
	return (*a);
}

std::string	Brain :: getIdeas(int n) const
{
	return (this->ideas[n]);
}

Brain :: ~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}