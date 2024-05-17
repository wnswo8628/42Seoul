/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:47:10 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/22 17:22:19 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap :: ClapTrap()
{
	this->name = "default";
	this->Hitpoints = 10;
	this->Energypoints = 10;
	this->Attackdamage = 0;

	std::cout << "ClapTrap Call Default Constructor" << std::endl;
}

ClapTrap :: ClapTrap(std::string name)
{
	this->name = name;
	this->Hitpoints = 10;
	this->Energypoints = 10;
	this->Attackdamage = 0;

	std::cout << "Call " << name << " Constructor" << std::endl;
}

ClapTrap :: ClapTrap(ClapTrap &clap)
{
	this->name = clap.name;
	this->Hitpoints = clap.Hitpoints;
	this->Energypoints = clap.Energypoints;
	this->Attackdamage = clap.Attackdamage;

	std::cout << "Call " << this->name << " Constructor" << std::endl;
}

ClapTrap& ClapTrap :: operator=(const ClapTrap& trap)
{
	this->name = trap.name;
	this->Hitpoints = trap.Hitpoints;
	this->Energypoints = trap.Energypoints;
	this->Attackdamage = trap.Attackdamage;

	return (*this);
}

void	ClapTrap :: attack(const std::string& target)
{
	if (!this->Energypoints || !this->Hitpoints)
		std::cout << "ClapTrap " << this->name << " can not move.." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "
			<< this->Attackdamage << " points of damage!" << std::endl;
	}
	this->Energypoints--;
}

void 	ClapTrap :: takeDamage(unsigned int amount)
{
	if (amount >= this->Hitpoints)
		this->Hitpoints = 0;
	else
		this->Hitpoints -= amount;
	std::cout << "ClapTrap " << this->name << " is taken " << amount 
		<< " damage.." << std::endl;
	if (this->Hitpoints == 0)
		std::cout << "ClapTrap " << this->name << " is died..." << std::endl;
}

void	ClapTrap :: beRepaired(unsigned int amount)
{
	std::cout << this->Hitpoints << std::endl;
	if (!this->Energypoints || !this->Hitpoints)
		std::cout << "ClapTrap " << this->name << " can not move.." << std::endl;
	else
	{
		this->Hitpoints += amount;
		this->Energypoints--;
		std::cout << "ClapTrap " << this->name << " is repaired " << amount << " points"
			<< " It has " << this->Hitpoints << " points" << std::endl;
	}
}

ClapTrap :: ~ClapTrap()
{
	std::cout << "ClapTrap Call Disconsturctor" << std::endl;
}