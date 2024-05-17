/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:21:24 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/22 16:54:49 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap :: FragTrap()
{
	this->Hitpoints = 100;
	this->Energypoints = 100;
	this->Attackdamage = 30;

	std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap :: FragTrap(std::string name)
{
	this->name = name;
	this->Hitpoints = 100;
	this->Energypoints = 100;
	this->Attackdamage = 30;

	std::cout << "FragTrap "  << this->name << " constructor" << std::endl;
}

FragTrap :: FragTrap(const FragTrap &temp)
{
	this->name = temp.name;
	this->Hitpoints = temp.Hitpoints;
	this->Energypoints = temp.Energypoints;
	this->Attackdamage = temp.Attackdamage;

	std::cout << "FragTrap " << this->name << " Copy constructor" << std::endl;
}

FragTrap& FragTrap :: operator=(const FragTrap &temp)
{
	this->name = temp.name;
	this->Hitpoints = temp.Hitpoints;
	this->Energypoints = temp.Energypoints;
	this->Attackdamage = temp.Attackdamage;

	std::cout << "FragTrap " << this->name << " operator=" << std::endl;
	return (*this);
}

void	FragTrap :: highFivesGuys(void)
{
	if (!this->Hitpoints)
	{
		std::cout << "FragTrap " << this->name << " can't move.." << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->name << " doing HighFive!" << std::endl;
	}
}

FragTrap :: ~FragTrap()
{
	std::cout << "FragTrap desconstructor" << std::endl;
}