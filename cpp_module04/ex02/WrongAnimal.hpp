/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:24:34 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/23 19:54:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class	WrongAnimal
{
	protected:
		std::string type;
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal &temp);
		WrongAnimal& operator=(const WrongAnimal &temp);
		virtual ~WrongAnimal();
		void	makeSound() const;
		std::string getType() const;
};

#endif