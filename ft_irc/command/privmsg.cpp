/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:37:35 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/03 22:18:10 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

void	broadCastMessage(Server *server, int fd, std::map<const int, Client>::iterator it_client, std::map<std::string, Channel>::iterator it_channel, std::string target, std::string send_message)
{
	std::vector<std::string> ban_users = it_channel->second.getBanUsers();
	Client &client = retrieveClient(server, fd);
	for (std::vector<std::string>::iterator it = ban_users.begin(); it != ban_users.end(); it++)
	{
		if (*it == it_client->second.getNickname())
		{
			std::cout << "[Server] " << it_client->second.getNickname() << " is banned User!" << std::endl;
			return ;
		}
	}

	if (it_channel->second.getMode().find("m") != std::string::npos)
	{
		if (it_channel->second.isOperator(it_client->second.getNickname()) == false && it_channel->second.isVoiceUser(it_client->second.getNickname()) == false)
		{
			addToBufferMessage(server, fd, "404 " + it_client->second.getNickname() + " #" + it_channel->second.getName() + " :Cannot send to channel\r\n");
			return;
		}
	}

	std::map<std::string, Client>::iterator iter = it_channel->second.getClientList().begin();
	while (iter != it_channel->second.getClientList().end())
	{
		if (iter->second.getClientFd() != fd)
			addToBufferMessage(server, iter->second.getClientFd(), ":" + client.getNickname() + "!" + client.getUsername() + "@" + client.getIp() + " PRIVMSG " + target + " " + send_message + "\r\n");
		iter++;
	}
}

bool	checkUserInChannel(std::map<const int, Client>::iterator it_client, std::map<std::string, Channel>::iterator it_channel)
{
	if (it_channel->second.getClientList().find(it_client->second.getNickname()) != it_channel->second.getClientList().end())
		return (true);
	return (false);
}

void	privmsg(Server *server, int fd, cmd_struct cmd_info)
{
	std::map<const int, Client> clients = server->getClients();
	std::map<std::string, Channel> channels = server->getChannels();
	std::map<const int, Client>::iterator it = clients.find(fd);

	std::string target;
	std::string send_message;

	size_t	temp = cmd_info.message.rfind(":");
	target = cmd_info.message.substr(1, temp - 1);
	send_message = cmd_info.message.substr(temp);
	if (temp == std::string::npos)
	{
		addToBufferMessage(server, fd, "412 " + it->second.getNickname() + " :No text to send\r\n");
		return ;
	}
	if (target.empty())
	{
		addToBufferMessage(server, fd, "411 " + it->second.getNickname() + " : No target PRIVMSG\r\n");
		return ;
	}

	temp = target.find(" ");
	if (temp != std::string::npos)
		target.erase(temp);
	
	//target이 채널일떄
	if (target[0] == '#')
	{
		std::map<std::string, Channel>::iterator it2 = channels.find(target.substr(1));

		if (it2 == channels.end())
			addToBufferMessage(server, fd, "401 " + it->second.getNickname() + " " + target + " :No such nick/channel\r\n");
		else
			broadCastMessage(server, fd, it, it2, target, send_message);
	}
	//target이 유저일때
	else
	{
		std::map<std::string, Channel>::iterator it_channel = channels.find(target);

		std::map<const int, Client>::iterator it_target = clients.begin();
		while (it_target != clients.end())
		{
			if (it_target->second.getNickname() == target)
				break ;
			it_target++;
		}
		if (it_target == clients.end() && it_channel == channels.end())
			addToBufferMessage(server, fd, "401 " + it_target->second.getNickname() + " " + target + " :No suck target\r\n");
		else
		{
			if (it_target == clients.end())
			{
				if (checkUserInChannel(it, it_channel) == true)
				{
					target.insert(1, "#");
					broadCastMessage(server, fd, it, it_channel, target, send_message);
				}
				else
					addToBufferMessage(server, fd, "401 " + it->second.getNickname() + " " + target + " :No such nick/channel.\r\n");
			}
			else
				addToBufferMessage(server, it_target->first,  ":" + it->second.getNickname() + "!" + it->second.getUsername() + "@" + it->second.getIp() + " PRIVMSG " + target + " " + send_message + "\r\n");
		}
	}
}