/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:36:08 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/24 02:31:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>


class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& temp);
		virtual ~Animal();
		Animal& operator=(const Animal& temp);
		virtual void	makeSound(void) const = 0;
		std::string	getType(void) const;
};

#endif