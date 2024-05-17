/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:28:23 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/05 18:09:20 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

std::string findChannelName(std::string message)
{
	std::string channel_name;
	channel_name.clear();

	if (message.empty() || message.find("#") == message.npos)
		return (channel_name);
	else if (message.find(":") != message.npos)
	{
		char *str = const_cast<char *>(message.data());
		channel_name = strtok(str, " ");
		channel_name.erase(channel_name.find("#"), 1);
	}
	else
	{
		size_t i = 0;
		while (message[i] && (!isalpha(message[i]) && !isdigit(message[i]) && message[i] != '=' && message[i] != '_'))
			i++;
		while (message[i] && (!isalpha(message[i]) || message[i] == '-' || message[i] == '_' || isdigit(message[i])))
			channel_name += message[i++];
	}
	return (channel_name);
}

std::string findTopic(std::string message)
{
	std::string topic;

	if (message.empty() || message.find(":") == message.npos)
		topic.clear();
	else
		topic.append(message, message.find(":"), std::string::npos);
	return (topic);
}

static void	broadcastChannel(Server *server, Channel &channel, Client &client, std::string channelName, std::string topic)
{
	std::map<std::string, Client>::iterator it = channel.getClientList().begin();
	std::string	client_nickname = client.getNickname();

	while (it != channel.getClientList().end())
	{
		addToBufferMessage(server, it->second.getClientFd(), ":localhost 332 " + client_nickname + " #" + channelName + " " + topic + "\r\n");
		it++;
	}
}

void	topic(Server *server, int fd, cmd_struct cmd_info)
{
	std::string channelName;
	std::string topic;

	Client &client = retrieveClient(server, fd);
	std::string	clientNickname = client.getNickname();

	channelName = findChannelName(cmd_info.message);
	if (channelName.empty())
	{
		addToBufferMessage(server, fd, ":localhost 461 " + client.getNickname() + " #" + cmd_info.name + " :Not enough parameters.\r\n");
		return ;
	}
	
	std::map<std::string, Channel>&	channels = server->getChannels();
	std::map<std::string, Channel>::iterator it = channels.find(channelName);
	if (it == channels.end())
	{
		addToBufferMessage(server, fd, ":localhost 403 " + client.getNickname() + " #" + channelName + " :No such channel.\r\n");
		return ;
	}
	if (it->second.checkClientExist(clientNickname) == false)
	{
		addToBufferMessage(server, fd, ":localhost 442 " + client.getNickname() + " #" + channelName + " :The user is not on this channel.\r\n");
		return ;
	}

	topic = findTopic(cmd_info.message);
	if (topic.empty())
	{
		if (it->second.getTopic().empty() == false)
			addToBufferMessage(server, fd, ":localhost 332 " + clientNickname + " #" + channelName + " " + it->second.getTopic() + "\r\n");
		else
			addToBufferMessage(server, fd, ":localhost 331 " + clientNickname + " #" + channelName + " :No topic is setting.\r\n");
	}
	else
	{
		if (it->second.getMode().find('t') != std::string::npos && it->second.isOperator(clientNickname) == false)
			addToBufferMessage(server, fd, ":localhost 482 " + clientNickname + " #" + channelName + " :You are not channel operator\r\n");
		else
		{
			if (topic == ":")
				topic.clear();
			it->second.setTopic(topic);
			broadcastChannel(server, it->second, client, channelName, topic);
		}
	}
}