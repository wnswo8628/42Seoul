/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:30:58 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/23 19:20:22 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
	public :
		Cat();
		Cat(const Cat& temp);
		virtual ~Cat();
		Cat& operator=(const Cat& temp);
		virtual void	makeSound(void) const;
		std::string	getType(void) const;
};

#endif
