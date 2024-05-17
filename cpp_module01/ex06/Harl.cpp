/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:46:33 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/28 19:38:36 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl :: Harl()
{

}

Harl :: ~Harl()
{

}

void	Harl :: debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl :: info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl :: warining(void)
{
	std::cout << "[ WARINING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl :: error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl :: complain(std::string level)
{
	std::string command[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	index;
	for (index = 0; index < 4; index++)
	{
		if (level.compare(command[index]) == 0)
			break ;
	}
	switch(index)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warining();
		case 3:
		{
			this->error();
			break;
		}
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}