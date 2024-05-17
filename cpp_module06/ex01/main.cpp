/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:01:35 by jugwak            #+#    #+#             */
/*   Updated: 2023/09/30 18:50:30 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Bad argument" << std::endl;
		return (-1);
	}

	Data data;
	data.value = av[1];
	data.num = 42;
	data.letter = 'd';

	uintptr_t ptr;
	ptr = Serializer :: serialize(&data);

	Data *p_data;
	p_data = Serializer :: deserialize(ptr);

	if (&data == p_data)
	{
		std::cout << "Serialization and Deserialization success!!" << std::endl;
		std::cout << &data << std::endl;
		std::cout << p_data << std::endl;
	}
	else
	{
		std::cout << "Serialization and Deserialization fail..." << std::endl;
		std::cout << &data << std::endl;
		std::cout << p_data << std::endl;
	}

	std::cout << "data value : " << data.value << std::endl;
	std::cout << "p_data value : " << p_data->value << std::endl;
	std::cout << "data num : " << data.num << std::endl;
	std::cout << "p_data num : " << p_data->num << std::endl;
	std::cout << "data letter : " << data.letter << std::endl;
	std::cout << "p_data letter : " << p_data->letter << std::endl;

	return (0);
}