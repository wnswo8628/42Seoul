/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:51:05 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/25 19:59:55 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon :: ~Weapon()
{

}

Weapon :: Weapon(std::string weapon)
{
	this->weapon = weapon;
}

void Weapon :: setType(std::string weapon)
{
	this->weapon = weapon;
}

const	std::string &Weapon::getType()
{
	return this->weapon;
}