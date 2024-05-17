/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:30:58 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/24 01:11:14 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain* br;
	public :
		Cat();
		Cat(const Cat& temp);
		virtual ~Cat();
		Cat& operator=(const Cat& temp);
		virtual void	makeSound(void) const;
		std::string	getType(void) const;
		Brain*	getBrain(void) const;
};

#endif
