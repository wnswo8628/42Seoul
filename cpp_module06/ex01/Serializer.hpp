/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:02:01 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/23 18:19:48 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

struct Data
{
	std::string value;
	char letter;
	int num;
};

class	Serializer
{
	private:
		Serializer();
	public:
		Serializer(const Serializer &temp);
		~Serializer();
		Serializer& operator=(const Serializer &temp);
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t uniptr);
};

#endif