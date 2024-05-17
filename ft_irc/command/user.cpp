/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:04:38 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/05 18:25:58 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Command.hpp"
#include "../Server.hpp"
#include "../Client.hpp"

std::string	findUser(std::string message)
{
	std::string user;
	user.clear();

	if (message.empty() == false && message[0] == ' ')
		message.erase(0, 1);
	if (message.empty() == false)
	{
		if (message.find_first_of(' ') != std::string::npos)
			user.insert(0, message, 0, message.find(' '));
		else
			user.insert(0, message, 0, std::string::npos);
	}
	return (user);
}

std::string findReal(std::string message)
{
	std::string real;
	real.clear();

	if (message.empty() == false && message[0] == ' ')
		message.erase(0, 1);
	if (message.empty())
		return (real);
	
	int count = 0;
	int begin = 0;
	for (size_t i = 0; i < message.size(); i++)
	{
		if (message[i] == ' ')
			count++;
		if (count == 3)
		{
			begin = i;
			break;
		}
	}
	if (count >= 3)
		real.insert(0, message, begin + 1, std::string::npos);
	if (real[0] == ':')
		real.erase(0, 1);
	return (real);
}

std::string	getIp(std::string message)
{
	std::string ip;
	ip.clear();

	if (message.empty() == false && message[0] == ' ')
		message.erase(0, 1);
	if (message.empty())
		return ip;
	int count = 0;
	int begin = 0;

	for (size_t i = 0; i < message.size(); i++)
	{
		if (message[i] == ' ')
			count++;
		if (count == 2)
		{
			begin = i;
			break ;
		}
	}

	int pos = 0;
	if (count >= 2)
		ip.insert(0, message, begin + 1, std::string::npos);
	for (size_t i = 0; i < ip.size(); i++)
	{
		if (ip[i] == ' ')
		{
			pos = i;
			break;
		}
	}
	
	ip.erase(pos, ip.size() - 1);
	return ip;
}

void	user(Server *server, int fd, cmd_struct cmd_info)
{
	Client&		client = retrieveClient(server, fd);
	std::string username = findUser(cmd_info.message);
	std::string realname = findReal(cmd_info.message);
	std::string ip = getIp(cmd_info.message);

	if (username.empty() || realname.empty())
		addToBufferMessage(server, fd, "Username or realname is empty!\r\n");
	else
	{
		client.setIp(ip);
		client.setUsername(username);
		client.setRealname(realname);
		client.setNbInfo(+1);
	}
}