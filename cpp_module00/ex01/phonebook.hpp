/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:20:10 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/14 20:14:59 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

class Contact
{
	private :
		std::string	first_name;
		std::string	last_name;
		std::string nickname;
		std::string phone_number;
		std::string	secret;
	public:
		void	init(void);
		int		add_info_contact(void);
		void	print_component(std::string str);
		void	print_info_contact(int out_index);
};

class Phonebook
{
	private:
		int	index;
		Contact	contact[8];
	public:
		int		add_info(int index);
		void	print_info(int index);
		void	print_index_info(int index);
};

#endif