/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:48:04 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/09 17:25:19 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public :
		MutantStack(){};

		MutantStack(const MutantStack &temp)
		{
			*this = temp;
		};

		MutantStack& operator=(const MutantStack &temp)
		{
			if (this != &temp)
			{
				*this = temp;
			}
			return (*this);
		};
		
		~MutantStack(){};
		typedef typename MutantStack<T>::stack::container_type::iterator ite;
		ite	begin(void)
		{
			return (this->c.begin());
		}
		ite	end(void)
		{
			return (this->c.end());
		}
		typedef	typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin(void)
		{
			return (this->c.rbegin());
		}
		reverse_iterator	rend(void)
		{
			return (this->c.rend());
		}
		// typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
		// const_iterator	cbegin()
		// {
		// 	return (this->c.cbegin());
		// }
		// const_iterator	cend()
		// {
		// 	return (this->c.cend());
		// }
		// typedef	typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
		// const_reverse_iterator crbegin()
		// {
		// 	return (this->c.rbegin());
		// }
		// const_reverse_iterator crend()
		// {
		// 	return (this->c.rend());
		// }
};

#endif