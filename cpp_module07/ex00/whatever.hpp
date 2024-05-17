/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:22:39 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/05 17:16:04 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &n1, T &n2)
{
	T temp = n1;

	n1 = n2;
	n2 = temp;
}

template <typename T>
T max(const T &n1, const T &n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

template <typename T>
T min(const T &n1, const T &n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

#endif