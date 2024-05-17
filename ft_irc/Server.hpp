/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:41:45 by jonseo            #+#    #+#             */
/*   Updated: 2023/12/03 21:43:21 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <string>
# include <map>
# include <vector>

# include <cstring>			// memset()
# include <cerrno>			// errno
# include <sstream>			// istringstream()
// # include <stdexcept>		// std::exception

# include <sys/socket.h>	// socket(), send(), recv() C++에는 socket 프로그래밍 관련 별도의 표준라이브러리가 포함되어 있지 않으므로 호환되는 C버전을 사용한다.
# include <netinet/in.h>	// struct sockaddr_in
# include <sys/event.h>		// kqueue()
# include <fcntl.h>			// fcntl()
# include <unistd.h>		// recv(), read(), write(), close()

#include "Client.hpp"
#include "Command.hpp"
#include "Channel.hpp"

class Client;
class Channel;

struct server_op
{
	std::string	name;
	std::string	host;
	std::string	password;
};

# define BUFFER_SIZE 1024

class Server
{
	private:
		int 						port_number;
		std::string					_password;

		int							server_socket_fd;
		struct sockaddr_in			server_socket_addr;

		std::map<int, std::string>	client;
		std::map<const int, Client>	_client_list;
		int							client_socket_fd;
		struct sockaddr_in			client_socket_addr;
		bool						_Quit;

		int							kq;
		std::vector<struct kevent>	inactive_eventlist;
		struct kevent				active_eventlist[8];

		std::vector<server_op>			opers;
		std::map<std::string, Channel>	_channel_list;

		Server();
	public:
		Server(int port_number, std::string connection_poassword);

		void	Execute();
		void	Socket();
		void	Bind();
		void	Listen();
		void	Accept();
		void	Kqueue();
		void	Kevent();
		void	Close();
		void	Disconnect(int server_fd, int client_fd);
		void	for_Disconnect();
		void	Clientlist_add(int fd);
		void	Clientlist_del(int fd);
		void	for_Clientlist_del();
		void	EVSET(std::vector<struct kevent> &inactive_eventlist, uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void *udata);
		void	setQuit();

		void							parsecommand(int fd, std::string message);
		void							fillClient(std::map<const int, Client> &client_list, int fd, std::string cmd);
		void							exeCommand(int fd, std::string cmd);
		std::map<const int, Client>&	getClients();
		std::string						getPasword();
		std::map<std::string, Channel>&	getChannels();
		std::vector<server_op>&			getServerop();
};

#endif