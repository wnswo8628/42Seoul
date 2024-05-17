/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:34:44 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/20 19:11:45 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie zombie1("jugwak");
	Zombie *zombi = newZombie("jugwak2");

	randomChump("random");
	zombie1.announce();
	zombi->announce();
	delete zombi;

	return (0);
}