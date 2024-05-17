/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:25:45 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/14 20:18:20 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Contact::print_component(std::string str)
{
	if (str.length() <= 10)
		std::cout << std::right << std::setw(10) << str;
	else
	{
		str = str.substr(0,9) + ".";
		std::cout << std::right << std::setw(10) << str;
	}
}

void	Contact::print_info_contact(int out_index)
{
	std::cout << std::right << std::setw(10) << out_index;
	std::cout << "| ";
	print_component(first_name);
	std::cout << "| ";
	print_component(last_name);
	std::cout << "| ";
	print_component(nickname);
	std::cout << "| ";
	print_component(phone_number);
	std::cout << "| ";
	print_component(secret);
	std::cout << "| " << std::endl;
}

void	Phonebook::print_info(int out_index)
{
	this->contact[out_index].print_info_contact(out_index);
}

void	print_frame(void)
{
	std::cout << std::right << std::setw(10) << "Index";
	std::cout << "| ";
	std::cout << std::right << std::setw(10) << "First name";
	std::cout << "| ";
	std::cout << std::right << std::setw(10) << "Last name";
	std::cout << "| ";
	std::cout << std::right << std::setw(10) << "Nickname";
	std::cout << "| ";
	std::cout << std::right << std::setw(10) << "Phone num";
	std::cout << "| ";
	std::cout << std::right << std::setw(10) << "Secret";
	std::cout << "|" << std::endl;
}

void	Contact::init(void)
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->secret = "";
}

int	Contact::add_info_contact(void)
{
	std::cout << "First name : ";
	std::getline(std::cin, first_name);
	if (first_name.empty())
	{
		std::cout << "Please insert First name" << std::endl;
		init();
		return (1);
	}
	std::cout << "Last name : ";
	std::getline(std::cin, last_name);
	if (last_name.empty())
	{
		std::cout << "Please insert Last name" << std::endl;
		init();
		return (1);
	}
	std::cout << "Nickname : ";
	std::getline(std::cin, nickname);
	if (nickname.empty())
	{
		std::cout << "Please insert Nickname" << std::endl;
		init();
		return (1);
	}
	std::cout << "Phone number : ";
	std::getline(std::cin, phone_number);
	if (phone_number.empty())
	{
		std::cout << "Please insert Phone number" << std::endl;
		init();
		return (1);
	}
	std::cout << "Darkest secret : ";
	std::getline(std::cin, secret);
	if (secret.empty())
	{
		std::cout << "Please insert Darkest secret" << std::endl;
		init();
		return (1);
	}
	return (0);
}

int	Phonebook::add_info(int out_index)
{
	int	empty_check;

	index = out_index;
	empty_check = this->contact[index].add_info_contact();
	return (empty_check);
}

void	Phonebook::print_index_info(int	index)
{
	print_frame();
	print_info(index);
}

void	select_index(Phonebook pbook)
{
	std::string			s_index;
	std::stringstream	ss;
	int					i_index;

	std::cout << "Select index : ";
	std::getline(std::cin, s_index);
	ss << s_index;
	ss >> i_index;
	
	if (i_index >= 0 && i_index <= 7 && ss.fail() == false)
		pbook.print_index_info(i_index);
	else
		std::cout << "Index select fail!" << std::endl;
}

int main(void)
{
	std::string	cmd;
	Phonebook	pbook;
	int			index = 0;

	while (!std::cin.eof())
	{
		std::cout << "Please enter command : ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			return (0);
		else if (cmd == "ADD")
		{
			index = index % 8;
			if (!pbook.add_info(index))
				index++;
		}
		else if (cmd == "SEARCH")
		{
			print_frame();
			for (int i = 0; i < 8; i++)
			{
				pbook.print_info(i);
			}
			select_index(pbook);
		}
		else
			std::cout << "Command not found!" << std::endl;
	}
	return (0);
}