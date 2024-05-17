/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:00:18 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/03 22:20:13 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

#include "Server.hpp"
#include "Channel.hpp"
#include "Client.hpp"

class Server;
class Client;
class Channel;

struct cmd_struct
{
	std::string prefix;
	std::string name;
	std::string message;
};

struct mod_struct
{
	std::string target;
	std::string mode;
	std::string parameters;
};

void	invite(Server *server, int fd, cmd_struct cmd_info);
void	join(Server *server, int fd, cmd_struct cmd_info);
void	kick(Server *server, int fd, cmd_struct cmd_info);
void	mode(Server *server, int fd, cmd_struct cmd_info);
void	nick(Server *server, int fd, cmd_struct cmd_info);
int		pass(Server *server, int fd, cmd_struct cmd_info);
int		ping(Server *server, int fd, cmd_struct &cmd_info);
void	privmsg(Server *server, int fd, cmd_struct cmd_info);
void	quit(Server *server, int fd, cmd_struct cmd_info);
void	topic(Server *server, int fd, cmd_struct cmd_info);
void	user(Server *server, int fd, cmd_struct cmd_info);
void	part(Server *server, int fd, cmd_struct cmd_info);
void	who(Server *server, int fd, cmd_struct cmd_info);

Client& retrieveClient(Server *server, int const fd);
void	addToBufferMessage(Server *server, int const fd, std::string message);
std::string	getChannelName(std::string message);
std::string getSymbol(Channel &channel);
std::string	getListMembers(std::string nickname, Channel &channel);

//mode
void	inviteOnlyMode(Server *server, mod_struct mod_info, int fd, std::string str);
void	topicMode(Server *server, mod_struct mod_info, int fd, std::string str);
void	keyMode(Server *server, mod_struct mod_info, int fd, std::string str);
void	operatorMode(Server *server, mod_struct mod_info, int fd, std::string str);
void	limitMode(Server *server, std::string data[4], int fd);
void	broadCastMode(Server *server, Channel &channel, std::string message);

#endif