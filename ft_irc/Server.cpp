/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:57:54 by jonseo            #+#    #+#             */
/*   Updated: 2023/12/05 15:39:22 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(int _port_number, std::string _password) : port_number(_port_number), _password(_password)
{
	server_socket_fd = 0;
	if ((std::memset(&server_socket_addr, 0, sizeof(server_socket_addr))) == NULL)
	{
		std::cerr << "Error: Server Constructor, memset()" << '\n';
		exit(1);
	}

	client_socket_fd = 0;
	if ((std::memset(&client_socket_addr, 0, sizeof(client_socket_addr))) == NULL)
	{
		std::cerr << "Error: Server Constructor, memset()" << '\n';
		exit(1);
	}

	kq = 0;
	_Quit = false;
}

void Server::Execute()
{
	try
	{
		Socket();
		Bind();
		Listen();
		Kqueue();
		Kevent();
		Close();
	}
	catch(const char *e)
	{
		std::cerr << e << '\n';
		close(server_socket_fd);
	}
}

void Server::Socket()
{
	if ((server_socket_fd = socket(PF_INET, SOCK_STREAM, 0)) == -1) // socket()함수를 호출할 때 프로토콜 패밀리로 PF_INET을 지정하면, IPv4를 사용하는 소켓을 생성하게 됩니다.
		throw "Error: Server socket()";

	server_socket_addr.sin_family = AF_INET;
	server_socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_socket_addr.sin_port = htons(port_number);
}

void Server::Bind()
{
	if ((bind(server_socket_fd, reinterpret_cast<struct sockaddr *>(&server_socket_addr), sizeof(server_socket_addr))) == -1)
		throw "Error: Server bind()";
	
	if ((fcntl(server_socket_fd, F_SETFL, O_NONBLOCK)) == -1)
		throw "Error: Server fcntl()";
}

void Server::Listen()
{
	if ((listen(server_socket_fd, 8)) == -1)
		throw "Error: Server listen()";
}

void Server::Accept()
{
	socklen_t client_socket_addr_size = sizeof(client_socket_addr);
	if ((client_socket_fd = accept(server_socket_fd, reinterpret_cast<struct sockaddr *>(&client_socket_addr), &client_socket_addr_size)) == -1)
	{
		std::cerr << "Error: accept()" << '\n';
		Close();
	}

	if ((fcntl(client_socket_fd, F_SETFL, O_NONBLOCK)) == -1)
	{
		std::cerr << "Error: Server fcntl()" << '\n';
		Close();
	}
}

void Server::Kqueue()
{
	kq = kqueue(); // kernel에 event queue를 위한 공간을 만들고 fd 반환
	if (kq == -1)
		throw "Error: Server kqueue()";

	EVSET(inactive_eventlist, server_socket_fd, EVFILT_READ, EV_ENABLE | EV_ADD, 0, 0, NULL);
}

void Server::Kevent()
{
	int new_event_count;
	struct timespec timeout = {1, 0};

	while (42)
	{
		new_event_count = kevent(kq, &inactive_eventlist[0], inactive_eventlist.size(), active_eventlist, 8, &timeout);
		if  (new_event_count == -1)
		{
			for_Disconnect();
			close(kq);
			throw "Error: kevent()";
		}

		inactive_eventlist.clear();

		for (int i = 0 ; i < new_event_count ; i++)
		{
			struct kevent *check_event = &active_eventlist[i];
			if (check_event->filter == EVFILT_READ)
			{
				if (check_event->ident == static_cast<uintptr_t>(server_socket_fd))
				{
					Accept();
					EVSET(inactive_eventlist, client_socket_fd, EVFILT_READ, EV_ENABLE | EV_ADD, 0, 0, NULL);
					Clientlist_add(client_socket_fd);
					client[client_socket_fd] = "";
				}
				else if (client.find(check_event->ident) != client.end())
				{
					char	buffer[BUFFER_SIZE];
					int		byte;

					if ((byte = recv(check_event->ident, buffer, sizeof(buffer), 0)) > 0)
						client[check_event->ident] = std::string(buffer, byte);
                    else if (byte <= 0)
                    {
                        std::cerr << "Error: read(), Client socket fd = " << check_event->ident << '\n';
                        EV_SET(check_event, check_event->ident, EVFILT_READ, EV_DISABLE | EV_DELETE, 0, 0, NULL);
                        Disconnect(0, check_event->ident);
						Clientlist_del(check_event->ident);
                    }
					
					parsecommand(check_event->ident, client[check_event->ident]);
				}
				if (_Quit == true)
				{
					std::cout << "Quit : Disconnect FD = " << check_event->ident << '\n';
					_Quit = false;
					
					EV_SET(check_event, check_event->ident, EVFILT_READ, EV_DISABLE | EV_DELETE, 0, 0, NULL);
					
					std::map<std::string, Channel>::iterator it =  _channel_list.begin();
					while (it != _channel_list.end())
					{		
						if (it->second.getClientList().size() == 0)
						{
							_channel_list.erase(it);
							if (_channel_list.size() == 0)
								break ;
						}
						else
							it++;
					}
					Disconnect(0, check_event->ident);
					Clientlist_del(check_event->ident);
				}
			}
		}
	}
}

void Server::Close()
{
	for_Disconnect();
	Disconnect(server_socket_fd, 0);
	close(kq);
	exit(1);
}

void Server::Disconnect(int server_fd, int client_fd)
{
	if (server_fd != 0)
		close(server_fd);

	if (client_fd != 0)
		close(client_fd);
}

void Server::for_Disconnect()
{
	for (std::map<const int, Client>::iterator it = _client_list.begin() ; it != _client_list.end() ; it++)
		Disconnect(0, it->second.getClientFd());
	
	std::cout << "Disconnect is complete" << '\n';
}

void Server::Clientlist_add(int fd)
{
	Client newClient(fd);

	_client_list.insert(std::pair<const int, Client>(fd, newClient));
    std::cout << "[Server] Add client #" << fd << " Successfully " << '\n';
}

void Server::Clientlist_del(int fd)
{
	_client_list.erase(fd);
}

void Server::for_Clientlist_del()
{
	for (std::map<const int, Client>::iterator it = _client_list.begin() ; it != _client_list.end() ; it++)
		Clientlist_del(it->second.getClientFd());
}

void Server::EVSET(std::vector<struct kevent> &inactive_eventlist, uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void *udata)
{
	struct kevent new_event;

	EV_SET(&new_event, ident, filter, flags, fflags, data, udata);
	
	inactive_eventlist.push_back(new_event);
}

void Server::setQuit()
{
	_Quit = true;
}

std::map<const int, Client>& Server::getClients()
{
	return (_client_list);
}

std::string	Server::getPasword()
{
	return (_password);
}

std::map<std::string, Channel>& Server::getChannels()
{
	return(_channel_list);
}

std::vector<server_op>& Server::getServerop()
{
	return(opers);
}