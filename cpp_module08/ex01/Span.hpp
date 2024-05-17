/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:44:18 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/06 17:53:06 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <time.h>

class Span
{
	private:
		unsigned int n;
		std::vector<int> vec;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &temp);
		Span& operator=(const Span &temp);
		void	addNumber(int number);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void	addManyNumber(unsigned int range, time_t seed);
		~Span();

		class	CanNotStoreNumber : public std::exception
		{
			const	char * what(void) const throw();
		};
		
		class	NotEnoughNumber : public std::exception
		{
			const	char * what(void) const throw();
		};
};
#endif