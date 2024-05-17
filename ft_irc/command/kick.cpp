/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:49:47 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/03 22:13:36 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

std::string	getKickName(std::string message)
{
	std::string kick_name;

	if (message[0] == ' ')
		message.erase(0, 1);
	kick_name = message.substr(message.find(' ') + 1, (message.find(':') - 1 - (message.find(' ') + 1)));
	return (kick_name);
}

static std::string getReason(std::string message)
{
	std::string reason;

	reason.clear();

	if (message.find(":") != message.npos)
		reason.append(message, message.find(":") + 1, std::string::npos);
	return (reason);
}

static void	broadCastChannel(Server *server, Channel &channel, std::string clientName, std::string kick_name, std::string reason)
{
	std::map<std::string, Client>::iterator it = channel.getClientList().begin();

	while (it != channel.getClientList().end())
	{
		addToBufferMessage(server, it->second.getClientFd(), ":" + clientName + "!" + it->second.getUsername() + "@" + it->second.getIp() + 
			" KICK #" + channel.getName() + " " + kick_name + " " + reason + "\r\n");
		it++;
	}
}

void	kick(Server *server, int fd, cmd_struct cmd_info)
{
	Client&	client = retrieveClient(server, fd);
	std::string clientName = client.getNickname();
	std::string channel_name = getChannelName(cmd_info.message);
	std::string kick_name = getKickName(cmd_info.message);
	std::string reason = getReason(cmd_info.message);

	std::map<std::string, Channel>&	channels = server->getChannels();
	std::map<std::string, Channel>::iterator it = channels.find(channel_name);

	if (channel_name.empty() || kick_name.empty())
	{
		addToBufferMessage(server, fd, ":irc.local 461 " + clientName + " " + cmd_info.name + " :Not enouth parameter.\r\n");
		return ;
	}
	else if (it == channels.end())
	{
		addToBufferMessage(server, fd, ":irc.local " + clientName + " #" + channel_name + " :No such channel.\r\n");
		return ;
	}
	else if (it->second.checkClientExist(clientName) == false)
	{
		addToBufferMessage(server, fd, ":irc.local " + clientName + " #" + channel_name + " :The user is not on this channel.\r\n");
		return ;
	}
	else if (it->second.checkClientExist(kick_name) == false)
	{
		addToBufferMessage(server, fd, "441 " + clientName + " " + kick_name + " #" + channel_name + " :They aren't not on this channel.\r\n");
		return ;
	}
	else if (it->second.isOperator(clientName) == false)
	{
		addToBufferMessage(server, fd, ":irc.local 482 " + clientName + " #" + channel_name + " :You are not channel operator.\r\n");
		return ;
	}
	else
	{
		broadCastChannel(server, it->second, clientName, kick_name, reason);
		it->second.getClientList().erase(kick_name);
	}
}