/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:52:22 by jugwak            #+#    #+#             */
/*   Updated: 2023/08/18 15:15:04 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error : argument" << std::endl;
		return (1);
	}
	
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::string file_name(av[1]);
	std::string line;
	int s1_len;
	int s2_len;

	s1_len = s1.length();
	s2_len = s2.length();
	std::ifstream in(file_name.c_str());
	if (!in.is_open())
	{
		std::cout << "Error : file open" << std::endl;
		return (1);
	}
	std::string name = file_name + ".replace";
	std::ofstream out_file(name.c_str());
	while (in)
	{
		std::getline(in, line);
		int pos = 0;
		while (true)
		{
			pos = line.find(s1, pos);
			if (pos == (int)std::string::npos)
				break ;
			line.erase(pos, s1_len);
			line.insert(pos, s2);
			pos += s2_len;
		}
		out_file << line;
		if (in.eof())
			break;
		out_file << std::endl;
	}
	in.close();
	out_file.close();
	return (0);
}