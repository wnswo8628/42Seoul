/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:04:22 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/16 18:44:48 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA :: HumanA(std::string name, Weapon &club) : name(name), club(club)
{

}

HumanA :: ~HumanA()
{

}

void	HumanA :: attack()
{
	std::cout << this->name << " attacks with " << this->club.getType() << std::endl;
} 

