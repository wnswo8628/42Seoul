/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatorMode.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:18:16 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/04 00:50:38 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

void	operatorMode(Server *server, mod_struct mod_info, int fd, std::string str)
{
	std::map<const int, Client>::iterator it_client = server->getClients().find(fd);
	std::map<std::string, Channel>::iterator it_channel = server->getChannels().find(mod_info.target);

	if (mod_info.parameters.empty())
		return ;
	
	std::map<const int, Client>::iterator it = server->getClients().begin();
	while (it != server->getClients().end())
	{
		if (it->second.getNickname() == mod_info.parameters)
			break ;
		it++;
	}
	if (it == server->getClients().end())
	{
		addToBufferMessage(server, fd, "401 " + it_client->second.getNickname() + " " + mod_info.parameters + " :No such nick.\r\n");
		addToBufferMessage(server, fd, "441 " + it_client->second.getNickname() + " " + mod_info.parameters + " #" + mod_info.target = " :They aren't on channel\r\n");
		return ;
	}

	std::vector<std::string>::iterator it2;
	for (it2 = it_channel->second.getOperators().begin(); it2 != it_channel->second.getOperators().end(); it2++)
	{
		if (*it2 == mod_info.parameters)
			break;
	}
	if (str[0] == '+')
	{
		if (it2 != it_channel->second.getOperators().end())
			return ;
		
		it_channel->second.addOper(mod_info.parameters);
		broadCastMode(server, it_channel->second, ":" + it_client->second.getNickname() + "!" + it_client->second.getUsername() + "@" + it_client->second.getIp() + " MODE #" + it_channel->second.getName() + ' ' + mod_info.mode + " :" + mod_info.parameters + "\r\n");
	}
	else if (str[0] == '-')
	{
		if (it2 == it_channel->second.getOperators().end())
			return ;
		it_channel->second.removeOperator(mod_info.parameters);
		broadCastMode(server, it_channel->second, ":" + it_client->second.getNickname() + "!" + it_client->second.getUsername() + "@" + it_client->second.getIp() + " MODE #" + it_channel->second.getName() + ' ' + mod_info.mode + " :" + mod_info.parameters + "\r\n");
	}
}