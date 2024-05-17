/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topicMode.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:16:31 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/03 19:21:44 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

void	topicMode(Server *server, mod_struct mod_info, int fd, std::string str)
{
	std::map<const int, Client>::iterator it_client = server->getClients().find(fd);
	(void)it_client;
	std::map<std::string, Channel>::iterator it_channel = server->getChannels().find(mod_info.target);

	size_t pos = it_channel->second.getMode().find("t");
	if (str[0] == '+')
	{
		if (pos != std::string::npos)
			return;
		if (it_channel->second.getMode().find("t") != std::string::npos)
			return ;
		it_channel->second.addMode("t");
		broadCastMode(server, it_channel->second, ":" + it_client->second.getNickname() + "!" + it_client->second.getUsername() + "@" + it_client->second.getIp() + " MODE #" + it_channel->second.getName() + ' ' + ":" + mod_info.mode + "\r\n");
	}
	else
	{
		if (pos == std::string::npos)
			return ;
		if (it_channel->second.getMode().find("t") == std::string::npos)
			return ;
		it_channel->second.removeMode("t");
		broadCastMode(server, it_channel->second, ":" + it_client->second.getNickname() + "!" + it_client->second.getUsername() + "@" + it_client->second.getIp() + " MODE #" + it_channel->second.getName() + ' ' + ":" + mod_info.mode + "\r\n");
	}
}