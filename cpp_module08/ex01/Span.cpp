/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:18:12 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/07 16:48:04 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span :: Span() : n(0)
{
	this->vec.reserve(n);
}

Span :: Span(unsigned int n) : n(n)
{
	this->vec.reserve(n);
}

Span :: Span(const Span &temp) : n(temp.n)
{
	*this = temp;
}

Span&	Span :: operator=(const Span &temp)
{
	if (this != &temp)
	{
		this->n = temp.n;
		this->vec = temp.vec;
	}
	return (*this);
}

void	Span :: addNumber(int number)
{
	if (vec.size() >= n)
		throw Span :: CanNotStoreNumber();
	this->vec.push_back(number);
}

unsigned int	Span :: shortestSpan(void)
{
	if (vec.size() < 2)
		throw Span :: NotEnoughNumber();
	std::sort(vec.begin(), vec.end());
	int	min = vec[1] - vec[0];
	for (size_t i = 2; i < vec.size(); i++)
	{
		int	temp = vec[i] - vec[i - 1];
		if (temp < min)
			min = temp;
	}
	return (min);
}

unsigned int	Span :: longestSpan(void)
{
	if (vec.size() < 2)
		throw	Span :: NotEnoughNumber();
	std::sort(vec.begin(), vec.end());
	int max = vec[vec.size() - 1] - vec[0];
	return (max);
}

void	Span :: addManyNumber(unsigned int range, time_t seed)
{
	srand(seed);
	for (size_t i = 0; i < range; i++)
	{
		try
		{
			addNumber(rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

Span :: ~Span()
{
	
}

const	char * Span :: CanNotStoreNumber :: what(void) const throw()
{
	return ("Already vector is full!");
}

const	char * Span :: NotEnoughNumber :: what(void) const throw()
{
	return ("Not enough numbers to calculate");
}