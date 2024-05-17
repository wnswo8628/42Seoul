/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:40:25 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/05 15:01:23 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

std::string getSymbol(Channel &channel, std::string nickname)
{
	std::string symbol;
	std::vector<std::string> oper = channel.getOperators();
	std::vector<std::string>::iterator it = oper.begin();
	symbol.clear();

	while (it != oper.end())
	{
		if (*it == nickname)
			symbol += "@";
		it++;
	}
	return (symbol);
}

std::string	getListMembers(std::string nickname, Channel &channel)
{
	std::map<std::string, Client>&	client_list = channel.getClientList();
	std::map<std::string, Client>::iterator it;
	std::string	nick;
	std::string	members;

	for (it = client_list.begin(); it != client_list.end(); it++)
	{
		nick.clear();
		nick = it->second.getNickname();
		if (it->second.getMode().find("i") != std::string::npos && channel.checkClientExist(nickname) == false)
			continue;
		if (channel.isOperator(nick) == true)
			members += "@";
		members += nick;
		members += " ";
	}
	if (members.size() >= 1 && members[members.size() - 1] == ' ')
		members.erase(members.end() - 1);
	return (members);
}

void	sendInfos(Server *server, Channel &channel, std::string channelName, Client &client)
{
	std::string nickname = client.getNickname();
	std::string username = client.getUsername();

	std::map<std::string, Client>::iterator it = channel.getClientList().begin();

	while (it != channel.getClientList().end())
	{
		addToBufferMessage(server, it->second.getClientFd(), ":" + client.getNickname() + "!" + client.getUsername() + "@" + client.getIp() + " JOIN :#" + channel.getName() + "\r\n");
		it++;
	}
	if (channel.getTopic().empty() == false)
			addToBufferMessage(server, it->second.getClientFd(), ":irc.local 332 " + nickname + " #" + channel.getName() + " " + channel.getTopic() + "\r\n");

	std::string members = getListMembers(nickname, channel);
	std::string symbol = getSymbol(channel, nickname);

	addToBufferMessage(server, client.getClientFd(), ":irc.local 353 " + client.getNickname() + " = " + "#" + channelName + " :" + members + "\r\n");
	addToBufferMessage(server, client.getClientFd(), ":irc.local 366 " + client.getNickname() + " #" + channelName + " :End of /NAMES list.\r\n");
}

void	addClientChannel(Server *server, std::string &channelName, Client &client)
{
	std::map<std::string, Channel>::iterator it;
	it = server->getChannels().find(channelName);
	std::string clientName = client.getNickname();
	if (it->second.checkClientExist(clientName) == false)
	{
		it->second.getClientList().insert(std::pair<std::string, Client>(client.getNickname(), client));
		client.getJoinChannel().push_back(it->second.getName());
	}
	else
		std::cout << client.getNickname() << "already exist!" << std::endl;
}

std::string retrieveKey(std::string message)
{
	std::string key;
	key.clear();

	message = message.substr(message.find_first_of(" "), message.npos);
	if (message[0] == ' ')
		message.erase(0, 1);
	
	int pos = (message.find(",") == 0) ? message.find(",") + 1 : 0;

	while (message[pos] != ',' && message[pos])
	{
		if (message[pos] == '_' || message[pos] == '-' || isalpha(message[pos]) || isdigit(message[pos]))
			key += message[pos];
		pos++;
	}
	return (key);
}

std::string	getChannelName(std::string message)
{
	std::string name;
	size_t i = 0;
	while (message[i] && message[i] != '#')
		i++;
	if (message[i] == '#')
		i++;
	while (message[i] && (message[i] != ' '))
		name += message[i++];
	return (name);
}

bool	checkLeastAlpha(std::string message)
{
	if (message[0] == ' ')
		message.erase(0, 1);
	if (message.find(" ") != message.npos)
		message = message.substr(0, message.find(" "));
	for (size_t i = 0; i < message.size(); i++)
	{
		if (isalpha(message[i]) || isdigit(message[i]))
			return (true);
	}
	return (false);
}

void	addChannel(Server *server, std::string channelName)
{
	std::map<std::string, Channel>::iterator it = server->getChannels().find(channelName);
	if (it != server->getChannels().end())
	{
		std::cout << "Channel already exist!!" << std::endl;
		return ;
	}
	Channel channel(channelName);
	server->getChannels().insert(std::pair<std::string, Channel>(channelName, channel));
}

void	join(Server *server, int fd, cmd_struct cmd_info)
{
	Client	&client = retrieveClient(server, fd);
	std::string nickname = client.getNickname();
	std::string channelName;


	channelName.clear();
	channelName = getChannelName(cmd_info.message);
	cmd_info.message.erase(cmd_info.message.find(channelName), channelName.length());

	std::map<std::string, Channel>&	channel_list = server->getChannels();
	std::map<std::string, Channel>::iterator it = channel_list.find(channelName);

	if (it == channel_list.end())
	{
		addChannel(server, channelName);
	}
	else if (it->second.getMode().find('i') != std::string::npos)
	{
		if (it->second.isInviteUser(client.getNickname()) == false)
		{
			addToBufferMessage(server, fd, "475 " + nickname + " #" + channelName + " :Cannot join channel (+i)\r\n");
			return ;
		}
	}
	else if (it->second.getMode().find('k') != std::string::npos)
	{
		std::string key = retrieveKey(cmd_info.message);
		cmd_info.message.erase(cmd_info.message.find(key), key.length());
		if (key != it->second.getChannelPassword())
		{
			addToBufferMessage(server, fd, "475 " + nickname + " #" + channelName + " :Cannot join channel (+k)\r\n");
			return ;
		}
	}
	std::map<std::string, Channel>::iterator it2 = server->getChannels().find(channelName);
	if (it2->second.getLimit() != -1 && (int)it2->second.getClientList().size() == it2->second.getLimit() && it->second.getMode().find('i') == std::string::npos)
	{
		addToBufferMessage(server, fd, "474 " + client.getNickname() + " #" + channelName + " :Cannot join channel (Channel is full)\r\n");
	}
	else
	{
		addClientChannel(server, channelName, client);
		if (it2->second.getOperators().empty() && it2->second.getClientList().size() == 1)
			it2->second.addFirstOperator(client.getNickname());	
		sendInfos(server, it2->second, channelName, client);
	}
}