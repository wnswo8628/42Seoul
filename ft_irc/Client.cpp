/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:28:31 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/04 02:32:15 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"
#include "Channel.hpp"

Client::Client(int fd) : _client_fd(fd), _to_deconnect(false), _connexion_password(false), \
	_registrationDone(false), _welcomeSent(false), _hasAllInfo(false), _nbInfo(0), flag(0), _isinvited(false)
{

}

Client::~Client(){}

int				Client::getClientFd() const { return (_client_fd); }
std::string&	Client::getSendBuffer()  	{ return (_sendbuf); }
std::string&	Client::getReadBuffer()  	{ return (_readbuf); }
std::string&	Client::getNickname()  		{ return (_nickname); }
std::string&	Client::getOldNickname()  	{ return (_old_nickname); }
std::string 	Client::getUsername() const { return (_username); }
std::string		Client::getRealname() const { return (_realname); }
std::string&	Client::getMode()			{ return (_mode); }
std::string&	Client::getIp()				{ return (_ip); }
std::vector<std::string> Client::getJoinChannel() {return (_joinChannel);}

bool&			Client::getisInvited()			{ return (_isinvited);}
bool&			Client::getConnexionPassword()	{ return (_connexion_password); }
bool&			Client::isRegistrationDone() 	{ return (_registrationDone); }
bool&			Client::isWelcomeSent()			{ return (_welcomeSent); }
bool&			Client::hasAllInfo() 			{ return (_hasAllInfo); }
bool&			Client::getDeconnexionStatus()	{ return (_to_deconnect); }
int				Client::getNbInfo() const 		{ return (_nbInfo); }
bool&			Client::getFlag()				{ return (flag);}

void	Client::setIp(std::string ip)
{
	_ip = ip;
}

void	Client::setisInvited(bool boolean)
{
	_isinvited = boolean;
}

void	Client::setFlag(bool boolean)
{
	flag = boolean;
}

void	Client::setReadBuffer(std::string const &buf)
{
	_readbuf += buf;
}

void	Client::resetReadBuffer(std::string const &str)
{
	_readbuf.clear();
	_readbuf = str;
}

void	Client::setSendBuffer(std::string const &buf)
{
	_sendbuf += buf;
}

void	Client::setDeconnexionStatus(bool status)
{
	_to_deconnect = status;
}

void	Client::setNickname(std::string const &nickname)
{
	_nickname = (_nickname.size() > 9) ? nickname.substr(0, 9) : nickname;
}

void	Client::setOldNickname(std::string const &nickname)
{
	_old_nickname = nickname;
}

void	Client::setUsername(std::string const &username)
{
	_username = username;
}

void	Client::setRealname(std::string const &realname)
{
	_realname = realname;
}

void	Client::addMode(std::string const mode)
{
	if (_mode.empty() == true)
		_mode = "+" + mode;
	else 
		_mode += mode;
}

void	Client::removeMode(std::string const mode)
{
	size_t pos = _mode.find(mode);
	_mode.erase(pos, 1);
}

void	Client::setConnexionPassword(bool boolean)
{
	_connexion_password = boolean;
}

void	Client::setRegistrationDone(bool boolean)
{
	_registrationDone = boolean;
}

void	Client::setWelcomeSent(bool boolean)
{
	_welcomeSent = boolean;
}

void	Client::sethasAllInfo(bool boolean)
{
	_hasAllInfo = boolean;
}

void	Client::setNbInfo(int n)
{
	_nbInfo += n;
	if (_nbInfo <= 0)
		_nbInfo = 0;
}

int	Client::is_valid() const
{
	if (_username.empty())
		return (0);
	if (_nickname.empty())
		return (0);
	if (_realname.empty())
		return (0);
	if (_connexion_password == false)
		return (0);
	if (this->getNbInfo() < 3)
		return (0);
	return (1);
}