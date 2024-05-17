/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonseo <jonseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:53:23 by jugwak            #+#    #+#             */
/*   Updated: 2023/12/04 05:37:31 by jonseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "Server.hpp"
#include "Channel.hpp"

class Client
{
	private: 
		int				_client_fd;
		std::string		_readbuf;
		std::string		_sendbuf;
		bool			_to_deconnect;
		std::string		_nickname;
		std::string		_old_nickname;
		std::string		_username;
		std::string		_realname;
		std::string		_mode;
		std::string		_ip;
		bool			_connexion_password;
		bool			_registrationDone;
		bool			_welcomeSent;
		bool			_hasAllInfo;
		int				_nbInfo;
		bool			flag;
		bool			_isinvited;
		std::vector<std::string> _joinChannel;
	public :
		Client(int fd);
		~Client();
		int				getClientFd()const;
		void			setNickname(std::string const &nickname);
		std::string&	getReadBuffer();
		void			setReadBuffer(std::string const &buf);
		void			resetReadBuffer(std::string const &str);
		std::string&	getSendBuffer();
		void			setSendBuffer(std::string const &buf);
		bool&			getDeconnexionStatus();
		void			setDeconnexionStatus(bool status);
		bool&			getFlag();
		bool&			getisInvited();
		std::vector<std::string> getJoinChannel();

		std::string&	getNickname();
		void			setOldNickname(std::string const &nickname);
		std::string&	getOldNickname();
		void			setUsername(std::string const &username);
		std::string		getUsername()const;
		void			setRealname(std::string const &realname);
		std::string		getRealname()const;
		bool&			getConnexionPassword();
		void			setConnexionPassword(bool boolean);
		void			setFlag(bool boolean);
		void			setisInvited(bool boolean);
		std::string&	getIp();

		std::string&	getMode();
		void			addMode(std::string const mode);
		void			removeMode(std::string const mode);

		bool&			isRegistrationDone();
		void			setRegistrationDone(bool boolean);
		bool&			isWelcomeSent();
		void			setWelcomeSent(bool boolean);
		bool&			hasAllInfo();
		void			sethasAllInfo(bool boolean);
		int				getNbInfo() const;
		void			setNbInfo(int n);
		int				is_valid()const;
		void			setIp(std::string ip);
		
};

#endif