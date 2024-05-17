/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:49:01 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/04 16:38:33 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *array, size_t length, void	(*function)(T&))
{
	if (array == NULL || function == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void	iter(const T *array, const size_t length, void (*function)(const T&))
{
	if (array == NULL || function == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void	print(T &str)
{
	std::cout << str << " ";
}

template <typename T>
void	plus(T &num)
{
	num = num + 1;
}

#endif