/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:24:05 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/28 19:35:31 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class	Harl
{
	private:
		std::string level;
		void	debug(void);
		void	info(void);
		void	warining(void);
		void	error(void);
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif