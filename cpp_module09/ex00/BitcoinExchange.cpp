/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:36:34 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/12 23:34:13 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange :: BitcoinExchange(){	
}

BitcoinExchange :: BitcoinExchange(const BitcoinExchange &temp){
	*this = temp;	
}

BitcoinExchange&	BitcoinExchange :: operator=(const BitcoinExchange &temp)
{
	this->bitcoindata = temp.bitcoindata;
	return (*this);
}

BitcoinExchange :: ~BitcoinExchange(){
}

void	BitcoinExchange :: excute(char *file)
{
	try
	{
		checkCsv();
		checkInputFile(file);
	}
	catch(const std::exception& e)	{
	}
	checkInputLine(file);
}

void	BitcoinExchange :: checkCsv(void)
{
	std::ifstream	csv("data.csv");
	std::string	read;
	size_t	data_size;
	float	value;

	if (!csv)
	{
		std::cout << "Error: could not open file." << std::endl;
		throw BitcoinExchange :: FileErrorException();
	}

	if (std::getline(csv, read).eof())
	{
		std::cout << "Error: file empty or no data in." << std::endl;
		throw BitcoinExchange :: FileErrorException();
	}

	while (std::getline(csv, read))
	{
		if (read != "date,exchange_rate")
		{
			data_size = read.find(',');
			if (validDate(read.substr(0, data_size)) == false)
			{
				std::cout << "Error: include invalid date." << std::endl;
				throw	BitcoinExchange :: FileErrorException();
			}
			if (validValue(read.substr(data_size + 1, read.length())) == false)
			{
				std::cout << "Error: include invalid value." << std::endl;
				throw	BitcoinExchange :: FileErrorException();
			}
			std::istringstream(read.substr(data_size + 1, read.length())) >> value;
			bitcoindata[read.substr(0, data_size)] = value;
		}
	}
}

bool	BitcoinExchange :: validDate(std::string data)
{
	if (data.length() != 10)
		return (false);
	std::string	split;
	std::istringstream ss(data);
	int	year, month, day;
	int index = 0;

	while (std::getline(ss, split, '-'))
	{
		if (index == 0)
		{
			std::istringstream(split) >> year;
			if (year < 1000 || year > 9999)
				return (false);
		}
		else if (index == 1)
		{
			std::istringstream(split) >> month;
			if (month < 1 || month > 12)
				return (false);
		}
		else if (index == 2)
		{
			std::istringstream(split) >> day;
			if (day < 1 || day > 31)
				return (false);
			if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
				return (false);
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			{
				if (day > 29 && month == 2)
					return (false);
				else if (day > 28 && month == 2)
					return (false);
			}
		}
		index++;
	}

	if (index != 3)
		return (false);
	return (true);
}

bool	BitcoinExchange :: validValue(std::string data)
{
	char *c_ptr = NULL;
	double	value = std::strtod(data.c_str(), &c_ptr);
	if (value == 0.0 && !std::isdigit(data[0]))
		return (false);
	if (*c_ptr && std::strcmp(c_ptr, "f"))
		return (false);
	if (value < 0)
		return (false);
	return (true);
}

void	BitcoinExchange :: checkInputFile(char *file)
{
	std::fstream fs;
	std::string	line;

	fs.open(file, std::ifstream::in);
	if (!fs.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		throw	BitcoinExchange :: FileErrorException();
	}

	if (std::getline(fs, line).eof())
	{
		std::cout << "Error: File empty or no data in." << std::endl;
		throw	BitcoinExchange :: FileErrorException();
	}

	if (line.compare("date | value") != 0)
	{
		std::cout << "Error: File format error." << std::endl;
		throw	BitcoinExchange :: FileErrorException();
	}

	line.erase();
	fs.close();
}

void	BitcoinExchange :: checkInputLine(char *file)
{
	std::ifstream	openfile(file);

	std::string line;
	getline(openfile, line);
	while (getline(openfile, line))
		chcekInputInfo(line);
}

void	BitcoinExchange :: chcekInputInfo(std::string line)
{
	std::string date, str;
	std::istringstream ifs(line);
	float	value;
	int	index = 0;

	while (std::getline(ifs, str, ' '))
	{
		if (index == 0)
		{
			if (checkInputDate(str) == false)
				return ;
			date = str;
		}
		if (index == 1 && str != "|")
		{
			std::cout << "Error: invalid format => " << line << std::endl;
			return ;
		}
		if (index == 2)
		{
			if (checkInputValue(str) == false)
				return ;
			value = std::strtod(str.c_str(), NULL);
			if (value > 1000)
			{
				std::cout << "Error: too large a number =>" << line << std::endl;
				return ;
			}
		}
		index++;
	}

	if (index != 3)
	{
		std::cout << "Error: invalid format => " << line << std::endl;
		return ;
	}

	printBit(date, value);
}

bool	BitcoinExchange :: checkInputDate(const std::string &str)
{
	std::string	split;
	std::istringstream ss(str);
	int year, month, day;
	int index = 0;

	if (str.find('-', str.length() - 1) != std::string::npos)
	{
		std::cout << "Error: incorrect date formate =>" << str << std::endl;
		return (false);
	}
	while (std::getline(ss, split, '-'))
	{
		if (index == 0)
		{
			std::istringstream(split) >> year;
			if (year < 2009 || year > 2022)
			{
				std::cout << "Error: bad input => " << str << std::endl;
				return (false);
			}
		}
		if (index == 1)
		{
			std::istringstream(split) >> month;
			if (month < 1 || month > 12)
			{
				std::cout << "Error: bad input =>" << str << std::endl;
				return (false);
			}
		}
		if (index == 2)
		{
			std::istringstream(split) >> day;
			if (day < 1 || day > 31)
			{
				std::cout << "Error: bad input => " << str << std::endl;
				return (false);
			}
			if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
			{
				std::cout << "Error: incorrect days => " << str << std::endl;
				return (false);
			}
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			{
				if (day > 29 && month == 2)
				{
					std::cout << "Error: incorrect days => " << str << std::endl;
					return (false);
				}
				else if (day > 28 && month == 2)
				{
					std::cout << "Error: incorrect days => " << str << std::endl;
					return (false);
				}
			}
		}
		index++;
	}
	if (index != 3)
	{
		std::cout << "Error: incorrect format => " << str << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange :: checkInputValue(const std::string &value)
{
	char	*ptr = NULL;
	double	dval = std::strtod(value.c_str(), &ptr);

	if (value.find('.', 0) == 0 || value.find('.', value.length() - 1) != std::string::npos)
	{
		std::cout << "Error: not a number." << std::endl;
		return (false);
	}
	if (*ptr && std::strcmp(ptr, "f"))
	{
		std::cout << "Error: not a number." << std::endl;
		return (false);
	}
	if (dval == 0.0 && !std::isdigit(value[0]))
	{
		std::cout << "Error: not a number." << std::endl;
		return (false);
	}
	if (dval < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (value.length() > 10 || (value.length() == 10 && dval > 2147483647))
	{
		std::cout << "Error: too large number." << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange :: printBit(std::string date, float value)
{
	std::map<std::string, float>::const_iterator iter;
	float res;

	res = 0;
	iter = bitcoindata.find(date);
	if (iter != bitcoindata.end())
		res = (iter->second) * value;
	else
	{
		iter = bitcoindata.lower_bound(date);
		if (iter == bitcoindata.begin())
		{
			std::cout << "Error: invalid date" << std::endl;
			return ;
		}
		--iter;
		res = (iter->second) * value;
	}

	(value == static_cast<int>(value)) ?
		std::cout << date << " => " << static_cast<int>(value) << " = " << res << std::endl :
		std::cout << date << " => " << value << " = " << res << std::endl;

}

const	char * BitcoinExchange :: FileErrorException :: what(void) const throw()
{
	return (NULL);
}

