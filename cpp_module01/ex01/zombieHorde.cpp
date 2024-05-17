/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:19:36 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/20 20:20:50 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *p = new Zombie[N];
	std::stringstream stream;

	for (int i = 0; i < N; i++)
	{
		stream.str("");
		stream << i;
		p[i].setName(name + stream.str());
	}
	return (p);
}