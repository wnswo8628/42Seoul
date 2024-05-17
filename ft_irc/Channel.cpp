/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:18:41 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/05 16:03:34 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

std::string&	Channel::getName()	{return(_name);}
std::string&	Channel::getTopic() {return(_topic);}
std::string&	Channel::getMode()	{return (_mode);}
std::string&	Channel::getChannelPassword() {return(_channel_password);}
std::string&	Channel::getChannelTime(){ return (_channel_time);}
int&			Channel::getLimit() {return(_limit);}
std::map<std::string, Client>&	Channel::getClientList() {return(_clientList);}
std::vector<std::string>		Channel::getBanUsers() {return(_ban_users);}
std::vector<std::string>		Channel::getVoiceUser() {return(_voice_user);}
std::vector<std::string>		Channel::getOperators() {return(_operator);}
std::vector<std::string>		Channel::getInviteUsers() {return(_inviteUsers);}

Channel::Channel(std::string name) : _name(name), _limit(-1), _channel_time(saveTime())
{
	_ban_users.clear();
	_clientList.clear();
	_topic.clear();
}

Channel::~Channel(){}

void	Channel::addInviteUser(std::string nickname)
{
	_inviteUsers.push_back(nickname);
}

void	Channel::setTopic(std::string topic)
{
	_topic = topic;
}

void	Channel::setChannelPassword(std::string password)
{
	_channel_password = password;
}

void	Channel::removeInviteUser(std::string nickname)
{
	std::vector<std::string>::iterator it = _inviteUsers.begin();
	while (it != _inviteUsers.end())
	{
		if (*it == nickname)
		{
			_inviteUsers.erase(it);
			if (_inviteUsers.empty())
				break;
		}
		else
			it++;
	}
}

std::string	Channel::saveTime()
{
	long long	ltime = static_cast<long long>(time(NULL));
	std::string stime = "";
	char	c;

	while (ltime / 10)
	{
		c = '0' + ltime % 10;
		stime.insert(0, 1, c);
		ltime /= 10;
	}
	c = '0' + ltime % 10;
	stime.insert(0, 1 ,c);
	return stime;
}

void	Channel::setChannelTime(std::string &time)
{
	_channel_time = time;
}

void	Channel::setLimit(int limit)
{
	_limit = limit;
}

bool	Channel::checkClientExist(std::string &name)
{
	if (_clientList.size() == 0)
		return (false);
	
	std::map<std::string, Client>::iterator it = _clientList.find(name);
	if (it == _clientList.end())
		return (false);
	return(true);
}

void	Channel::addClientChannel(Client &client)
{
	_clientList.insert(std::pair<std::string, Client>(client.getNickname(), client));
}

void	Channel::removeClientChannel(std::string &name)
{
	std::map<std::string, Client>::iterator it = _clientList.find(name);
	if (it != _clientList.end())
		_clientList.erase(it);

	removeOperator(name);
}

void	Channel::addFirstOperator(std::string operatorname)
{
	if (_operator.empty())
		_operator.push_back(operatorname);
}

void Channel::addOper(std::string name)
{
	_operator.push_back(name);
}

void	Channel::removeOperator(std::string operatorname)
{
	std::vector<std::string>::iterator it = _operator.begin();

	while (it != _operator.end())
	{
		if (*it == operatorname)
			_operator.erase(it);
		else
			it++;
	}
}

bool	Channel::isOperator(std::string &operatorname)
{
	std::vector<std::string>::iterator it;
	if (_operator.empty())
		return (false);
	for (it = _operator.begin(); it != _operator.end(); it++)
	{
		if (*it == operatorname)
			return (true);
	}
	return (false);
}

void	Channel::addToBanUsers(std::string &banname)
{
	std::vector<std::string>::iterator it;
	for (it = _ban_users.begin(); it != _ban_users.end(); it++)
	{
		if (*it == banname)
		{
			std::cout << banname << " is already banned " << getName() << " is Channel" << std::endl;
			return ;
		}
	}
	_ban_users.push_back(banname);
	std::cout << banname << " is banned form the " << getName() << " Channel" << std::endl;
}

void	Channel::removeBanUser(std::string &banname)
{
	std::vector<std::string>::iterator it;
	for (it = _ban_users.begin(); it != _ban_users.end(); it++)
	{
		if (*it == banname)
		{
			_ban_users.erase(it);
			std::cout << banname << " is not banned this " << getName() << " Channel" << std::endl;
			return ;
		}
	}
	std::cout << banname << " already is not banned this " << getName() << " Channel" << std::endl; 
}
 
bool	Channel::isBanUser(std::string &banname)
{
	std::vector<std::string>::iterator it;
	if (_ban_users.empty())
		return (false);
	for (it = _ban_users.begin(); it != _ban_users.end(); it++)
	{
		if (*it == banname)
			return (true);
	}
	return (false);
}

void	Channel::addToVoiceUsers(std::string &voicename)
{
	std::vector<std::string>::iterator it;
	for (it = _voice_user.begin(); it != _voice_user.end(); it++)
	{
		if (*it == voicename)
		{
			std::cout << voicename << " is already voiced from the " << getName() << " Channel" << std::endl;
			return ;
		}
	}
	_voice_user.push_back(voicename);
	std::cout << voicename << " is now voiced from the " << getName() << " Channel" << std::endl;
}

void	Channel::removeVoiceUser(std::string &voicename)
{
	std::vector<std::string>::iterator it;
	for (it = _voice_user.begin(); it != _voice_user.end(); it++)
	{
		if (*it == voicename)
		{
			_voice_user.erase(it);
			std::cout << voicename << " is not now voiced from the " << getName() << " Channel" << std::endl;
			return ;
		}
	}
	std::cout << voicename << " has ever been voiecd from the " << getName() << " Channel" << std::endl;
}

bool	Channel::isInviteUser(std::string nickname)
{
	std::vector<std::string>::iterator it;
	for (it = _inviteUsers.begin(); it != _inviteUsers.end(); it++)
	{
		if (*it == nickname)
			return (true);
	}
	return (false);
}

bool	Channel::isVoiceUser(std::string &voicename)
{
	std::vector<std::string>::iterator it;

	if (_voice_user.empty())
		return (false);
	for (it = _voice_user.begin(); it != _voice_user.end(); it++)
	{
		if (*it == voicename)
			return (true);
	}
	return (false);
}

void	Channel::addMode(std::string mode)
{
	if (_mode.empty())
		_mode = "+" + mode;
	else
		_mode += mode;
}

void	Channel::removeMode(std::string mode)
{
	size_t pos = _mode.find(mode);
	_mode.erase(pos, 1);
}

void	Channel::removeChannelPassword()
{
	_channel_password.clear();
}