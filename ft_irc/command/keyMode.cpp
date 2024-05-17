/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyMode.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:17:23 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/05 17:31:09 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

bool	isAlpha(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]) && !isdigit(str[i]))
			return (false);
	}
	return (true);
}

void	keyMode(Server *server, mod_struct mod_info, int fd, std::string str)
{
	std::map<const int, Client>::iterator it_client = server->getClients().find(fd);
	std::map<std::string, Channel>::iterator it_channel = server->getChannels().find(mod_info.target);

	size_t pos = it_channel->second.getMode().find("k");
	if (mod_info.parameters.empty())
		return ;
	if (str[0] == '+')
	{
		if (pos != std::string::npos)
			return ;
		if (isAlpha(mod_info.parameters) == false)
		{
			addToBufferMessage(server, fd, ":irc.local 686 " + it_client->second.getNickname() + " #" + mod_info.target + " +k " + mod_info.parameters + " :password must only contained alpha and digit\r\n");
			return ;
		}
		it_channel->second.addMode("k");
		it_channel->second.setChannelPassword(mod_info.parameters);
		broadCastMode(server, it_channel->second, ":" + it_client->second.getNickname() + "!" + it_client->second.getUsername() + "@" + it_client->second.getIp() + " MODE #" + it_channel->second.getName() + ' ' + ":" + mod_info.mode + "\r\n");
	}
	else
	{
		if (pos == std::string::npos)
			return ;
		it_channel->second.removeMode("k");
		it_channel->second.removeChannelPassword();
		broadCastMode(server, it_channel->second, ":" + it_client->second.getNickname() + "!" + it_client->second.getUsername() + "@" + it_client->second.getIp() + " MODE #" + it_channel->second.getName() + ' ' + ":" + mod_info.mode + "\r\n");
	}
}