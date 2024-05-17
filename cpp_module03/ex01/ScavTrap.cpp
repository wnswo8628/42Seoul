/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:57:22 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/22 17:17:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap :: ScavTrap()
{
	this->Hitpoints = 100;
	this->Energypoints = 50;
	this->Attackdamage = 20;

	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap :: ScavTrap(std::string name)
{
	this->name = name;
	this->Hitpoints = 100;
	this->Energypoints = 50;
	this->Attackdamage = 20;

	std::cout << "ScavTrap " << this->name << " constructor" << std::endl;
}

ScavTrap :: ScavTrap(const ScavTrap &temp)
{
	this->name = temp.name;
	this->Hitpoints = temp.Hitpoints;
	this->Energypoints = temp.Energypoints;
	this->Attackdamage = temp.Attackdamage;

	std::cout << "ScavTrap " << this->name << " Copy constructor" << std::endl;
}

ScavTrap& ScavTrap :: operator=(const ScavTrap &temp)
{
	this->name = temp.name;
	this->Hitpoints = temp.Hitpoints;
	this->Energypoints = temp.Energypoints;
	this->Attackdamage = temp.Attackdamage;

	std::cout << "ScavTrap " << this->name << " operator=" << std::endl;
	return (*this);
}

void	ScavTrap :: attack(const std::string &target)
{
	if (!this->Hitpoints || !this->Energypoints)
	{
		std::cout << "ScavTrap " << this->name << "can't move..." << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << "attacks " << target << ", catusing "
			<< this->Attackdamage << " points of damage!" << std::endl;
		this->Energypoints--;
	}
}

void	ScavTrap :: guardGate(void)
{
	if (!this->Hitpoints || !this->Energypoints)
	{
		std::cout << "ScavTrap " << this->name << "cant't move..." << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " is guardGate mode!" << std::endl;
		this->Energypoints--;
	}
}

ScavTrap :: ~ScavTrap()
{
	std::cout << "ScavTrap desconstructor" << std::endl;
}