/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:38:59 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/04 18:10:06 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <list>

class	InvaildIndexException : public std::exception
{
	public:
		const char *what() const throw();
};

const	char * InvaildIndexException :: what(void) const throw()
{
	return ("Error: Invaild Index");
}

template <typename T>
typename T::iterator	easyfind(T& temp, int value)
{
	typename T::iterator iter;
	iter = std::find(temp.begin(), temp.end(), value);
	if (iter == temp.end())
	{
		throw InvaildIndexException();
	}
	return (iter);
}

#endif