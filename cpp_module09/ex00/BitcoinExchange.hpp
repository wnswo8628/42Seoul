/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:12:17 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/12 17:41:33 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <cstring>
# include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, float> bitcoindata;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &temp);
	BitcoinExchange& operator=(const BitcoinExchange &temp);
	
	void	checkCsv(void);
	bool	validDate(std::string data);
	bool	validValue(std::string data);
	void	checkInputFile(char *file);
	bool	checkInputDate(const std::string &date);
	bool	checkInputValue(const std::string &value);
	void	chcekInputInfo(std::string line);
	void	excute(char *file);
	void	checkInputLine(char *file);
	void	printBit(std::string date, float value);
	
	class FileErrorException : public std::exception
	{
		const	char * what(void) const throw();
	};
};

#endif