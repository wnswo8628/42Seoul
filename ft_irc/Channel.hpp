/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:27:13 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/05 15:50:24 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include "Client.hpp"
#include "Server.hpp"
#include <vector>

class	Client;

class Channel
{
	private :
		std::map<std::string, Client> _clientList;
		std::vector<std::string>	_ban_users;
		std::vector<std::string>	_operator;
		std::vector<std::string>	_voice_user;
		std::string					_name;
		std::string					_operatorPass;
		std::string					_topic;
		std::string					_mode;
		std::string					_channel_password;
		int							_limit;
		std::string					_channel_time;
		std::vector<std::string>	_inviteUsers;
	public:
		Channel(std::string name);
		~Channel();

		std::string&	getName();	
		std::string&	getTopic();
		std::string&	getMode();
		std::string&	getChannelPassword();
		int&			getLimit();
		std::string&	getChannelTime();
		std::string		saveTime();
		std::map<std::string, Client>&	getClientList();
		std::vector<std::string>		getBanUsers();
		std::vector<std::string>		getVoiceUser();
		std::vector<std::string>		getOperators();
		std::vector<std::string>		getInviteUsers();

		void	removeInviteUser(std::string nickname);
		void	setTopic(std::string topic);
		void	addInviteUser(std::string nickname);
		void	setChannelPassword(std::string password);
		void	setLimit(int limit);
		bool	checkClientExist(std::string &name);
		void	setChannelTime(std::string &time);
		void	addOperator(std::string name);
		bool	isInviteUser(std::string nickname);

		void	addClientChannel(Client &client);
		void	removeClientChannel(std::string &name);
		void 	addOper(std::string name);

		void	addFirstOperator(std::string operatorname);
		void	removeOperator(std::string operatorname);
		bool	isOperator(std::string &operatorname);

		void	addToBanUsers(std::string &banname);
		void	removeBanUser(std::string &banname);
		bool	isBanUser(std::string &banname);
		void	addToVoiceUsers(std::string &voicename);
		void	removeVoiceUser(std::string &voicename);
		bool	isVoiceUser(std::string &voicename);
		void	addMode(std::string mode);
		void	removeMode(std::string mode);
		void	removeChannelPassword();
};

#endif