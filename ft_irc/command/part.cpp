/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:16:45 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/05 17:56:34 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

static std::string	getReason(std::string message)
{
	std::string reason;
	reason.clear();

	if (message.find(":") != message.npos)
		reason.append(message, message.find(":") + 1, std::string::npos);
	return (reason);
}

bool	containsLeastAlpha(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]))
			return (true);
	}
	return (false);
}

static void	broadCastChannel(Server *server, Channel &channel, std::string user, std::string nickname, std::string reason)
{
	std::map<std::string, Client>::iterator it = channel.getClientList().begin();

	while (it != channel.getClientList().end())
	{
		addToBufferMessage(server, it->second.getClientFd(), ":" + nickname + "!" + user + "@" + it->second.getIp() + " PART #" + channel.getName() + " " + (reason.empty() ? "." : reason) + "\r\n");
		it++;
	}
}

void	exitChannel(Client &client, std::string channel)
{
	std::vector<std::string> joinchannel = client.getJoinChannel();
	for (std::vector<std::string>::iterator it = joinchannel.begin(); it != joinchannel.end(); it++)
	{
		if ((*it) == channel)
		{
			if (joinchannel.size() == 1)
			{
				joinchannel.erase(it);
				joinchannel = std::vector<std::string>();
			}
			else
				joinchannel.erase(it);
			return ;
		}
	}
}

void	delOperuser(Channel &channel, std::string nickname)
{
	std::vector<std::string> opers = channel.getOperators();
	std::vector<std::string>::iterator it = opers.begin();

	while (it != opers.end())
	{
		if ((*it) == nickname)
		{
			opers.erase(it);
			break ;
		}
		it++;
	}
}

void	delUser(Channel &channel, std::string nickname)
{
	std::map<std::string, Client> clients = channel.getClientList();
	std::map<std::string, Client>::iterator it = clients.begin();

	while (it != clients.end())
	{
		if (it->second.getNickname() == nickname)
		{
			clients.erase(it);
			break ;
		}
		it++;
	}
}

void	part(Server *server, int fd, cmd_struct cmd_info)
{
	Client client = retrieveClient(server, fd);
	std::string nickname = client.getNickname();
	std::string channel;

	std::string reason = getReason(cmd_info.message);
	if (cmd_info.message.empty() == true)
	{
		addToBufferMessage(server, fd, ":irc.local 461 " + nickname + " " + cmd_info.name + " :Not enough parameters.\r\n");
		return ;
	}
	cmd_info.message.erase(cmd_info.message.find(reason), reason.length());

	channel.clear();
	channel = getChannelName(cmd_info.message);
	cmd_info.message.erase(cmd_info.message.find(channel), channel.length());

	std::map<std::string, Channel>& channels = server->getChannels();
	std::map<std::string, Channel>::iterator it = channels.find(channel);
	if (it == channels.end())
	{
		addToBufferMessage(server, fd, ":irc.local 403 " + nickname + " #" + channel + " :No such channel\r\n");
		return ;
	}
	else if (it != channels.end() && it->second.checkClientExist(nickname) == false)
	{
		addToBufferMessage(server, fd, ":irc.local 442 " + nickname + " #" + channel + " :The user is not on this channel\r\n");
		return ;
	}
	else
	{
		it->second.getClientList().erase(nickname);
		it->second.removeOperator(nickname);
		it->second.removeInviteUser(nickname);
		exitChannel(client, channel);
		if (it->second.getClientList().size() == 0)
			server->getChannels().erase(it);
		addToBufferMessage(server, fd, ":" + nickname + "!" + client.getUsername() + "@" + client.getIp() + " PART :#" + channel + (reason.empty() ? "" : ":" + reason ) + "\r\n");
		broadCastChannel(server, it->second, client.getUsername(), nickname, reason);
	}
}