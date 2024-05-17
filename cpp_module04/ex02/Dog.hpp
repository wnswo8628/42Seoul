/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:33:12 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/24 01:12:16 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain* br;
	public:
		Dog();
		Dog(const Dog& temp);
		virtual ~Dog();
		Dog& operator=(const Dog& temp);
		virtual void	makeSound(void) const;
		std::string	getType(void) const;
		Brain* getBrain(void) const;
};

#endif