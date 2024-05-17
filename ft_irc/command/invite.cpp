/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:39:11 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/04 04:38:36 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

std::string findNickname(std::string message)
{
	std::string nickname;
	nickname.clear();

	if (message.empty() == true)
		return (nickname);
	
	char *temp = const_cast<char *>(message.data());
	nickname = strtok(temp, " ");

	if (nickname.empty() || nickname.find("#") != nickname.npos)
		nickname.clear();
	return (nickname);
}

std::string findChannel(std::string message)
{
	std::string channel;

	if (message.empty() || message.find("#") == message.npos)
		channel.clear();
	else
		channel.append(message, message.find("#") + 1, std::string::npos);
	return (channel);
}

void	invite(Server *server, int fd, cmd_struct cmd_info)
{
	Client& client = retrieveClient(server, fd);
	std::string clientNickname = client.getNickname();
	std::string channel_name = findChannel(cmd_info.message);
	std::string new_client = findNickname(cmd_info.message);

	if (clientNickname.empty() || channel_name.empty())
	{
		addToBufferMessage(server, fd, ":localhost 461 " + clientNickname + " " + cmd_info.name + " :Not enough parameters.\r\n");
		return ;
	}
	
	std::map<std::string, Channel>&	channels = server->getChannels();
	std::map<std::string, Channel>::iterator it = channels.find(channel_name);
	if (it == channels.end())
	{
		addToBufferMessage(server, fd, ":localhost 403 " + clientNickname + " #" + channel_name + " :No such channel\r\n");
		return ;
	}
	if (it->second.checkClientExist(clientNickname) == false)
	{
		addToBufferMessage(server, fd, ":localhost 442 " + clientNickname + " #" + channel_name + " :The user is no on this channel.\r\n");
		return ;
	}
	if (it->second.checkClientExist(new_client) == true)
	{
		addToBufferMessage(server, fd, ":localhost 443 " + clientNickname + " " + new_client + " #" + channel_name + " :Is already on channel.\r\b");
		return ;
	}

	addToBufferMessage(server, fd, ":irc.local 341" + client.getNickname() + " " + new_client + " :#" + channel_name + "\r\n");
	std::map<const int, Client>&	clients = server->getClients();

	std::map<const int, Client>::iterator it2;
	for (it2 = clients.begin(); it2 != clients.end(); it2++)
	{
		if (it2->second.getNickname() == new_client)
		{
			it2->second.setisInvited(true);
			it->second.addInviteUser(it2->second.getNickname());
			addToBufferMessage(server, it2->second.getClientFd(),":" + client.getNickname() + "!" + client.getUsername() + "@" + client.getIp() + " INVITE " + new_client + " :#" + channel_name + "\r\n");
			break;
		}
	}
}