/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:03:56 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/16 17:46:27 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB :: HumanB(std::string name)
{
	this->name = name;
	this->club = NULL;
}

void	HumanB :: setWeapon(Weapon &club)
{
	this->club = &club;
}

void	HumanB :: attack(void)
{
	if (!club)
		std::cout << this->name << " No weapon" << std::endl;
	else
		std::cout << this->name << "attacks with " << this->club->getType() << std::endl;
}

HumanB :: ~HumanB()
{
	
}