/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:44:29 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/02 17:54:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

int	ping(Server *server, int fd, cmd_struct &cmd_info)
{
	Client	&client = retrieveClient(server, fd);
	std::string nickname = client.getNickname();
	std::string username = client.getUsername();
	
	if (cmd_info.message[0] == ' ')
		cmd_info.message.erase(0, 1);
	cmd_info.message.insert(0, ":");
	addToBufferMessage(server, fd, ":irc.local PONG irc.local :irc.local\r\n");

	return (1);
}