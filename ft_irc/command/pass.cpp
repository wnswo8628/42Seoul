/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:09:35 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/03 22:17:59 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

std::string	retrievePass(std::string message)
{
	std::string pass;
	
	pass.erase();
	size_t i = 0;

	while (message[i] && message[i] == ' ')
		i++;
	while (message[i] && message[i] != ' ')
		pass += message[i++];
	return (pass);
}

int	pass(Server *server, int fd, cmd_struct cmd_info)
{
	Client	&client = retrieveClient(server, fd);
	std::string password = retrievePass(cmd_info.message);

	if (cmd_info.message.empty() == true || password.empty() == true)
	{
		addToBufferMessage(server, fd, "No Password!\r\n");
		return (0);
	}
	else if (server->getPasword() != password)
	{
		addToBufferMessage(server, fd, "Wrong password!\rn");
		if (client.isRegistrationDone() == false)
			client.setNbInfo(-1);
		return (0);
	}
	else
	{
		client.setNbInfo(+1);
		return (1);
	}
}