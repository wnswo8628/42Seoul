/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limitMode.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:19:01 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/03 18:21:54 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

void	limitMode(Server *server, std::string data[4], int fd)
{
	std::map<std::string, Channel>::iterator it;
	Client &client = retrieveClient(server, fd);
	it = server->getChannels().find(data[1]);
	if (it == server->getChannels().end())
	{
		addToBufferMessage(server, fd, ":irc.local 403 " + data[0] + " #" + data[1] + " :No such channel\r\n");
		return ;
	}
	if (data[3].empty() && data[2][0] == '+')
	{
		addToBufferMessage(server, fd, ":irc.local 696 " + client.getNickname() + " " + it->second.getName() + " l * :You must specify a parameter for the limit mode. Syntax: <limit>.\r\n");
		return ;
	}
	int limit = atoi(data[3].c_str());
	if (data[2][0] == '+')
	{
		if (limit < 0 || (int)it->second.getClientList().size() > limit)
		{	
			addToBufferMessage(server, fd, ":irc.local 696 " + client.getNickname() + " " + it->second.getName() + " l " + data[3] + " :Invalid limit mode parameter. Syntax: <limit>.\r\n");
			return ;
		}
		it->second.setLimit(limit);
		size_t pos = it->second.getMode().find("l");
		if (pos != std::string::npos)
			return ;
		it->second.addMode("l");
		std::ostringstream ss;
		ss << limit;
		broadCastMode(server, it->second,  ":" + client.getNickname() + "!" + client.getUsername() + "@" + client.getIp() + " MODE " + "#" + it->second.getName() + " +l " + ":" + data[3] + "\r\n");
	}
	else if (data[2][0] == '-')
	{
		limit = -1;
		it->second.setLimit(limit);
		size_t pos = it->second.getMode().find("l");
		if (pos == std::string::npos)
			return ;
		it->second.removeMode("l");
		broadCastMode(server, it->second, ":" + client.getNickname() + "!" + client.getUsername() + "@" + client.getIp() + " MODE " + "#" + it->second.getName() + " -l" + "\r\n");
	}
}