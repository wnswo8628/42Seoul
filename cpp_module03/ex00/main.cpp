/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:13:28 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/21 20:22:07 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.attack("A");
	a.takeDamage(11);
	b.takeDamage(5);
	a.beRepaired(4);
	b.beRepaired(5);
}