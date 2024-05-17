/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:57:26 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/04 03:58:28 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

void	broadCastMode(Server *server, Channel &channel, std::string message)
{
	std::map<std::string, Client>::iterator it = channel.getClientList().begin();

	while (it != channel.getClientList().end())
	{
		addToBufferMessage(server, it->second.getClientFd(), message);
		it++;
	}
}

void	fillModInfo(mod_struct &mod_info, std::string message)
{
	size_t	pos;

	//target
	pos = message.find(" ");
	if (pos == std::string::npos)
	{
		mod_info.target = message.substr(0);
		return ;
	}
	else
	{
		mod_info.target = message.substr(0, pos);
		message.erase(0, pos + 1);
	}

	//mode
	pos = message.find(" ");
	if (pos == std::string::npos)
	{
		mod_info.mode = message.substr(0);
		return ;
	}
	else
	{
		mod_info.mode = message.substr(0, pos);
		message.erase(0, pos + 1);
	}

	//parameters
	mod_info.parameters = message.substr(0);
}

void	changeMode(Server *server, mod_struct mod_info, int fd)
{
	std::map<const int, Client>::iterator it_client = server->getClients().find(fd);
	std::map<std::string, Channel>::iterator it_channel = server->getChannels().find(mod_info.target);

	(void)it_client;
	(void)it_channel;

	std::vector<std::string> modes;
	for (int i = 1; mod_info.mode[i] != '\0'; i++)
	{
		if (mod_info.mode[i] == '+' || mod_info.mode[i] == '-')
		{
			modes.push_back(mod_info.mode.substr(0, i));
			mod_info.mode.erase(0, 1);
			i = 0;
		}
	}
	modes.push_back(mod_info.mode.substr(0));

	for (std::vector<std::string>::iterator it = modes.begin(); it != modes.end(); it++)
	{
		std::string str = *it;
		std::string data[4];
		data[0] = it_client->second.getNickname();
		data[1] = mod_info.target;
		data[2] = str;
		data[3] = mod_info.parameters;

		if (str.find("i") != std::string::npos)
			inviteOnlyMode(server, mod_info, fd, str);
		if (str.find("t") != std::string::npos)
			topicMode(server, mod_info, fd, str);
		if (str.find("k") != std::string::npos)
			keyMode(server, mod_info, fd, str);
		if (str.find("o") != std::string::npos)
			operatorMode(server, mod_info, fd, str);
		if (str.find("l") != std::string::npos)
			limitMode(server, data, fd);
	}
}

void	modeChannel(Server *server, mod_struct mod_info, int fd)
{
	std::map<const int, Client>::iterator it = server->getClients().find(fd);
	
	mod_info.target.erase(0, 1);
	std::map<std::string, Channel>::iterator it_channel = server->getChannels().find(mod_info.target);
	if (it_channel == server->getChannels().end())
	{
		addToBufferMessage(server, fd, ":irc.local 403 " + it->second.getNickname() + " #" + mod_info.target + " :No such channel\r\n");
		return ;
	}
	if (mod_info.mode.empty())
	{
		addToBufferMessage(server, fd, ":irc.local 324 " + it->second.getNickname() + " #" + mod_info.target + " :+nt" + "\r\n");
		it_channel->second.addMode("nt");
		addToBufferMessage(server, fd, ":irc.local 329 " + it->second.getNickname() + " #" + mod_info.target + " :" + it_channel->second.getChannelTime() + "\r\n");
		return ;
	}
	if (mod_info.mode.find("b") != std::string::npos)
	{
		if (mod_info.mode[0] == '-')
			return ;
		addToBufferMessage(server, fd, ":irc.local 368 " + it->second.getNickname() + " #" + mod_info.target + " :End of channel ban list\r\n");
		return ;
	}

	std::vector<std::string>::iterator it2;
	for (it2 = it_channel->second.getOperators().begin(); it2 != it_channel->second.getOperators().end(); it2++)
	{
		if (*it2 == it->second.getNickname())
			break ;
	}
	if (it2 == it_channel->second.getOperators().end())
	{
		addToBufferMessage(server, fd, ":irc.local 482 " + it->second.getNickname() + " #" + mod_info.target + " :You're not channel operator\r\n");
		return ;
	}
	if (mod_info.mode[0] == '+' || mod_info.mode[0] == '-')
		changeMode(server, mod_info, fd);
}

void	modeUser(Server *server, mod_struct mod_info, int fd)
{
	std::map<const int, Client>::iterator it_client = server->getClients().find(fd);
	std::map<const int, Client>::iterator it = server->getClients().begin();
	while (it != server->getClients().end())
	{
		if (it->second.getNickname() == mod_info.target)
			break ;
		it++;
	}
	if (it == server->getClients().end())
	{
		addToBufferMessage(server, fd, "401 " + it_client->second.getNickname() + " " + mod_info.target + " :No such nickname.\r\n");
		return ;
	}
	if (it->second.getNickname() != it_client->second.getNickname())
	{
		addToBufferMessage(server, fd, "502 " + it_client->second.getNickname() + " :Cant change mode for other users\r\n");
		return ;
	}

	if (mod_info.mode.empty())
	{
		addToBufferMessage(server, fd, ":irc.local 221 " + it_client->second.getNickname() + " " + it_client->second.getMode() + "\r\n");
	}
	if (mod_info.mode[0] == '+' || mod_info.mode[0] == '-')
	{
		std::string::iterator pos = mod_info.mode.begin();
		while (pos != mod_info.mode.end())
		{
			if (*pos == '+')
			{
				pos++;
				while (*pos != '+' && *pos != '-' && pos != mod_info.mode.end())
				{
					if (*pos == 'i')
					{
						if (it->second.getMode().find("i") == std::string::npos)
						{
							it->second.addMode("i");
							addToBufferMessage(server, fd, ":" + it_client->second.getNickname() + " MODE " + it_client->second.getNickname() + " : +i\r\n");
						}
					}
					pos++;
				}
			}
			if (*pos == '-')
			{
				pos++;
				while (*pos != '+' && *pos != '-' && pos != mod_info.mode.end())
				{
					if (*pos == 'i')
					{
						if (it->second.getMode().find("i") != std::string::npos)
						{
							it->second.removeMode("i");
							addToBufferMessage(server, fd, ":" + it_client->second.getNickname() + " MODE " + it_client->second.getNickname() + " : -i \r\n");
						}
					}
					if (*pos == 'o')
					{
						if (it->second.getMode().find("o") != std::string::npos)
						{
							it->second.removeMode("o");
							addToBufferMessage(server, fd, ":" + it_client->second.getNickname() + " MODE " + it_client->second.getNickname() + " : -o \r\n");
						}
					}
					pos++;
				}
			}
		}
		if (mod_info.mode.find("O") != std::string::npos || mod_info.mode.find("r") != std::string::npos || mod_info.mode.find("w") != std::string::npos)
			addToBufferMessage(server, fd, ":irc.local 501 " + it_client->second.getNickname() + " :Unknown MODE flag\r\n");
	}
}

void	mode(Server *server, int fd, cmd_struct cmd_info)
{
	mod_struct mod_info;

	cmd_info.message.erase(0, 1);
	fillModInfo(mod_info, cmd_info.message);

	if (mod_info.target[0] == '#') //target이 채널일때
		modeChannel(server, mod_info, fd);
	else //target이 유저일때
		modeUser(server, mod_info, fd);

}