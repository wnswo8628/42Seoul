/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:17:14 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/03 22:18:16 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

static std::string getReason(std::string message)
{
	std::string reason;

	reason.clear();
	
	if (message.find(":") != message.npos)
		reason.append(message, message.find(":") + 1, std::string::npos);
	return (reason);
}

static void	broadcastChannel(Server *server, Channel &channel, int fd, std::string nickname, std::string username, std::string reason)
{
	std::map<std::string, Client>::iterator it = channel.getClientList().begin();

	(void) fd;
	while (it != channel.getClientList().end())
	{
		if (it->second.getClientFd() != fd)
		{
			addToBufferMessage(server, it->second.getClientFd(), ":" + nickname + "!" + username + "@localhost" + " QUIT :Quit " + reason + "\r\n");
		}
		it++;
	}
}

void	removeServer(Server *server, std::string nickname)
{
	std::map<std::string, Channel>&	channels = server->getChannels();
	std::map<std::string, Channel>::iterator it;

	for (it = channels.begin(); it != channels.end(); it++)
	{
		if (it->second.checkClientExist(nickname))
		{
			it->second.getClientList().erase(nickname);
		}
	}
}

void	quit(Server *server, int fd, cmd_struct cmd_info)
{
	Client &client = retrieveClient(server, fd);
	std::string reason = getReason(cmd_info.message);
	std::map<std::string, Channel>&	channels = server->getChannels();
	std::map<std::string, Channel>::iterator it = channels.begin();

	addToBufferMessage(server, fd, ":" + client.getNickname() + "!" + client.getUsername() + "@localhost" + " QUIT :Quit: " + reason + "\r\n");
	for (; it != channels.end(); it++)
	{
		std::map<std::string, Client>& members = it->second.getClientList();
		std::map<std::string, Client>::iterator it2 = members.begin();
		for (; it2 != members.end(); it2++)
		{
			if (it2->second.getClientFd() == fd)
			{
				members.erase(client.getNickname());
				broadcastChannel(server, it->second, fd, client.getNickname(), client.getUsername(), reason);
				break;
			}
		}
	}
	client.setDeconnexionStatus(true);
	server->setQuit();
}