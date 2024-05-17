/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:34:20 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/16 18:46:26 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	private :
		std::string name;
	public :
		Zombie(std::string name);
		void	announce(void);
		~Zombie();
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif