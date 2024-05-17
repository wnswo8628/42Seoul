/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:36:43 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/24 01:51:22 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class	Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &temp);
		Brain& operator=(const Brain &temp);
		~Brain();
		std::string getIdeas(int n) const;
};

#endif