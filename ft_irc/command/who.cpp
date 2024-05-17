/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:55:59 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/03 01:43:16 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

static std::string	getNickname(std::string message)
{
	std::string nickname;

	nickname.clear();
	if (message.empty())
		return (nickname);
	if (message.empty() == false && message[0] == ' ')
		message.erase(0, 1);
	if (message.empty() == false && message.find(' '))
	{
		char *temp  = const_cast<char *>(message.data());
		nickname = strtok(temp, " ");
	}
	if (nickname.empty())
		nickname.clear();
	return (nickname);
}

std::map<const int, Client>::iterator	findClient(Server *server, int fd, std::string nickname)
{
	std::map<const int, Client>&	client_list = server->getClients();
	std::map<const int, Client>::iterator it = client_list.begin();

	while (it != client_list.end())
	{
		if (it->second.getClientFd() != fd && it->second.getNickname() == nickname)
			return (it);
		it++;
	}
	return (it);
}

std::string	getLastJoinChannel(Client &client)
{
	if (client.getJoinChannel().empty())
		return ("");
	return (client.getJoinChannel()[client.getJoinChannel().size() - 1]);
}

void	who(Server *server, int fd, cmd_struct cmd_info)
{
	Client	&client = retrieveClient(server, fd);
	std::string channelName = getChannelName(cmd_info.message);
	std::string nickname = getNickname(cmd_info.message);
	std::map<std::string, Channel>::iterator it_channel = server->getChannels().find(channelName);
	std::map<const int, Client>::iterator it = server->getClients().begin();
	std::string status;

	if (it_channel == server->getChannels().end())
	{
		it = findClient(server, fd, nickname);
		if (it == server->getClients().end())
			addToBufferMessage(server, fd, ":irc.local 315 " + client.getNickname() + " " + nickname = " :End of /WHO list.\r\n");
		else
		{
			std::string lastjoinChannel;
			if (it->second.isRegistrationDone() == true)
				status = "H";
			lastjoinChannel = getLastJoinChannel(client);
			if (lastjoinChannel == "")
				lastjoinChannel = "*";
			else
			{
				std::map<std::string, Channel>::iterator it2 = server->getChannels().find(lastjoinChannel);
				if (it2->second.isOperator(it->second.getNickname()))
					status += "@";
			}

			addToBufferMessage(server, fd, ":irc.local 352 " + client.getNickname() + " #" + lastjoinChannel \
				+ " " + it->second.getUsername() + " " + it->second.getIp() + " irc.loacl " \
				+ it->second.getNickname() + " " + status + " :0 " + it->second.getRealname() + "\r\n");
			addToBufferMessage(server, fd, ":irc.local 315 " + client.getNickname() + " " \
				+ it->second.getNickname() + " :End of /WHO list.\r\n");
		}
	}
	else
	{
		if (it_channel->second.getClientList().find(client.getNickname()) == it_channel->second.getClientList().end())
		{
			addToBufferMessage(server, fd, ":irc.local 315 " + client.getNickname() + " #" + it_channel->second.getName() + " :End of /WHO list.\r\n");
		}
		else
		{
			std::map<std::string, Client>::iterator iter = it_channel->second.getClientList().begin();
			while (iter != it_channel->second.getClientList().end())
			{
				if (iter->second.isRegistrationDone() == true)
					status = "H";
				if (it_channel->second.isOperator(iter->second.getNickname()))
					status += "@";
				addToBufferMessage(server, fd, ":irc.local 352 " + client.getNickname() + " #" + it_channel->second.getName() \
					+ " " + iter->second.getUsername() + " " + iter->second.getIp() + " irc.local " \
					+ iter->second.getNickname() + " " + status + " :0" + iter->second.getRealname() + "\r\n");
				iter++;
			}
			addToBufferMessage(server, fd, ":irc.local 315 " + client.getNickname() + " #" + it_channel->second.getName() + " :End of /WHO list.\r\n");
		}
	}
}