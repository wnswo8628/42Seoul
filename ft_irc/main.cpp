/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:38:46 by jonseo            #+#    #+#             */
/*   Updated: 2023/11/23 18:16:48 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cerr << "Error: Not enough arguments." << '\n';
		return 1;
	}

	int casting_port_number;
	std::istringstream(av[1]) >> casting_port_number;
	Server server(casting_port_number, av[2]);
	server.Execute();
	
	return 0;
}