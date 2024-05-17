/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecommand.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:50:38 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/05 15:40:46 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Command.hpp"

void	splitCommand(std::vector<std::string> &cmd, std::string command)
{
	int pos = 0;
	std::string n = "\n";
	std::string substr;

	while ((pos = command.find(n)) != static_cast<int>(std::string::npos))
	{
		substr = command.substr(0, pos);
		cmd.push_back(substr);
		command.erase(0, pos + n.length());
	}

	std::vector<std::string>::iterator iter = cmd.begin();

	while (iter != cmd.end())
	{
		std::cout << *iter << std::endl;
		iter++;
	}
}

cmd_struct	parseCommands(std::string cmd, cmd_struct cmd_info)
{
	if (cmd.empty() == true)
		exit(1);

	std::string copy = cmd;
	if (cmd[0] == ':')
	{
		if (cmd.find_first_of(' ') != std::string::npos)
			copy.erase(0, copy.find_first_of(' ') + 1);
	}

	if (copy.find_first_of(' ') == std::string::npos)
	{
		cmd_info.name.insert(0, copy, 0, std::string::npos);
		if (cmd_info.name.find('\r') != std::string::npos)
			cmd_info.name.erase(cmd_info.name.find('\r'), 1);
	}
	else
		cmd_info.name.insert(0, copy, 0, copy.find_first_of(' '));
	
	size_t p_length = cmd.find(cmd_info.name, 0);
	cmd_info.prefix.assign(cmd, 0, p_length);

	size_t m_begin = cmd.find(cmd_info.name, 0) +  cmd_info.name.length();
	cmd_info.message = cmd.substr(m_begin, std::string::npos);
	if (cmd_info.message.find("\r") != std::string::npos)
		cmd_info.message.erase(cmd_info.message.find("\r"), 1);
	for (size_t i = 0; i < cmd_info.name.size(); i++)
		cmd_info.name[i] = std::toupper(cmd_info.name[i]);
	return (cmd_info);
}

void	Server::fillClient(std::map<const int, Client> &client_list, int fd, std::string cmd)
{
	std::map<const int, Client>::iterator it = client_list.find(fd);
	cmd_struct cmd_info;
	
	cmd_info = parseCommands(cmd, cmd_info);
	if (cmd.find("NICK") != std::string::npos)
		nick(this, fd, cmd_info);
	else if (cmd.find("USER") != std::string::npos)
		user(this, fd, cmd_info);
	else if (cmd.find("PASS") != std::string::npos)
	{
		if (pass(this, fd, cmd_info) == 1)
			it->second.setConnexionPassword(true);
		else
			it->second.setConnexionPassword(false);
	}
}

Client* getClient(Server *server, int fd)
{
	std::map<const int, Client>& clients = server->getClients();
	std::map<const int, Client>::iterator it = clients.find(fd);

	if (it == clients.end())
		return NULL;
	return (&it->second);
}

void	Server::exeCommand(int fd, std::string cmd)
{
	std::string cmd_list[13] =
	{
		"INVITE",
		"JOIN",
		"KICK",
		"MODE",
		"NICK",
		"PART",
		"PING",
		"PRIVMSG",
		"QUIT",
		"TOPIC",
		"USER",
		"WHO"
	};
	cmd_struct cmd_info;
	int index = 0;

	cmd_info = parseCommands(cmd, cmd_info);
	while (index < 12)
	{
		if (cmd_info.name == cmd_list[index])
			break;
		index++;
	}

	switch (index + 1)
	{
		case 1: invite(this, fd, cmd_info); break;
		case 2: join(this, fd, cmd_info); break;
		case 3: kick(this, fd, cmd_info); break;
		case 4: mode(this, fd, cmd_info); break;
		case 5: nick(this, fd, cmd_info); break;
		case 6: part(this, fd, cmd_info); break;
		case 7: ping(this, fd, cmd_info); break;
		case 8: privmsg(this, fd, cmd_info); break;
		case 9: quit(this, fd, cmd_info); break;
		case 10: topic(this, fd, cmd_info); break;
		case 11: user(this, fd, cmd_info); break;
		case 12: who(this, fd, cmd_info); break;
	}
}

void	sendClientWelcome(Server *server, int fd, std::map<const int, Client>::iterator &it)
{
	addToBufferMessage(server, fd, ":irc.local 001 " + it->second.getNickname() + " :Welcome to the Localnet IRC Network " + it->second.getNickname() + "!" + it->second.getUsername() + "@" + it->second.getIp() + "\r\n");
	it->second.getSendBuffer().clear();
}

void	Server::parsecommand(int const fd, std::string command)
{
	std::vector<std::string>	cmd;
	std::map<const int, Client>::iterator it = _client_list.find(fd);

	splitCommand(cmd, command);
	for (size_t i = 0; i != cmd.size(); i++)
	{
		if (it->second.isRegistrationDone() == false)
		{
			if (it->second.hasAllInfo() == false)
			{
				fillClient(_client_list, fd, cmd[i]);
				if (it->second.getNbInfo() == 3)
					it->second.hasAllInfo() = true;
			}
			if (it->second.hasAllInfo() == true && it->second.isWelcomeSent() == false)
			{
				if (it->second.is_valid() == 1)
				{
					sendClientWelcome(this,fd, it);
					it->second.isWelcomeSent() = true;
					it->second.isRegistrationDone() = true;
				}
				else
				{
					std::cout << "[Server] Invaild command Please in PASS USER NICK\n";
					exit(1);
				}
			}
		}
		else
			exeCommand(fd, cmd[i]);
	}
}