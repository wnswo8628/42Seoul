/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:47:40 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/05 15:01:51 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

void	addToBufferMessage(Server *server, int const fd, std::string message)
{
	Client &client = retrieveClient(server, fd);

	client.setSendBuffer(message);
	send(fd, client.getSendBuffer().c_str(), client.getSendBuffer().size(), 0);
	client.getSendBuffer().clear();
}

Client& retrieveClient(Server *server, int const fd)
{
	std::map<const int, Client>&	client_list = server->getClients();
	std::map<const int, Client>::iterator it = client_list.find(fd);

	Client &client = it->second;
	return (client);
}

std::string retrieveNickname(std::string message)
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

bool	isFobidden(char c)
{
	if (c == ' ' || c == ',' || c == '*' || c == '?' || c == '!'
		|| c == '@' || c == '.')
		return (true);
	else
		return (false);
}

bool	containFobiddenCharacters(std::string nickname)
{
	if (nickname[0] == '$' || nickname[0] == ':' || nickname[0] == '#')
		return (true);
	for (size_t i = 0; i < nickname.size(); i++)
		if (isFobidden(nickname[i]) == true)
			return(true);
	return (false);
}

bool	checkAlreadyUsedNickname(Server *server, int fd, std::string nickname)
{

	std::map<const int, Client>&	client_list = server->getClients();
	std::map<const int, Client>::iterator it = client_list.begin();

	while (it != client_list.end())
	{
		if (it->second.getClientFd() != fd && it->second.getNickname() == nickname)
			return (true);
		it++;
	}
	return (false);
}

void	nick(Server *server, int fd, cmd_struct cmd_info)
{
	std::string nickname = retrieveNickname(cmd_info.message);
	Client& find_client = retrieveClient(server, fd);

	if (find_client.isRegistrationDone() == false)
	{
		find_client.setNickname(nickname);
		find_client.setOldNickname(nickname);
		find_client.setNbInfo(+1);
	}

	if (nickname.empty())
	{
		addToBufferMessage(server, fd, ":irc.local 432 " + find_client.getNickname() + " " + nickname + "\r\n");
		if (find_client.isRegistrationDone() == false)
			find_client.setNbInfo(-1);
	}
	else if (containFobiddenCharacters(nickname))
	{
		addToBufferMessage(server, fd, ":irc.local 432 " + find_client.getNickname() + " " + nickname + "\r\n");
		if (find_client.isRegistrationDone() == false)
			find_client.setNbInfo(-1);
	}
	else if (checkAlreadyUsedNickname(server, fd, nickname) == true)
	{
		addToBufferMessage(server, fd, ":irc.local 433 " + find_client.getNickname() + " " + nickname + " already in use.\r\n");
		if (find_client.isRegistrationDone() == false)
			find_client.setNbInfo(-1);
	}
	else
	{
		if (find_client.isRegistrationDone() == true)
		{
			find_client.setOldNickname(find_client.getNickname());
			std::cout << "[Server] Nickname change registered. Old nickname is now : " << find_client.getOldNickname() << std::endl;
			addToBufferMessage(server, fd, ":" + find_client.getNickname() + "!" + find_client.getUsername() + "@" + find_client.getIp() + " NICK :" + nickname + "\r\n");
			find_client.setNickname(nickname);
		}
	}
}
