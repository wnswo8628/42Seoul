/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:42:06 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/05 16:46:48 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class	Array
{
	private :
		unsigned int	len;
		T *array;
	public :
		Array() : len(0)
		{
			this->array = new T[this->len];
		}

		Array(unsigned int len) : len(len)
		{
			this->array = new T[this->len];
		}

		Array(const Array &temp) : len(temp.len)
		{
			if (temp.len != 0)
			{
				this->len = temp.size();
				this->array = new T[this->len];
			}
			for (unsigned int i = 0; i < this->len; i++)
				this->array[i] = temp.array[i];
		}

		Array& operator=(const Array &temp)
		{
			if (this != &temp)
			{
				if (this->array != NULL)
					delete [] this->array;
				if (temp.len != 0)
				{
					this->len = temp.size();
					this->array = new T[this->len];
				}
				for (unsigned int i = 0; i < this->len; i++)
					this->array[i] = temp.array[i];
			}
			return (*this);
		}
		
		~Array()
		{
			if (this->array != NULL)
				delete[] this->array;
		}

		unsigned int	size(void) const
		{
			return (this->len);
		}
		
		class	InvaildIndexException : public std::exception
		{
			public :
				const char *what() const throw();
		};

		T& operator[] (unsigned int i)
		{
			if (i >= this->len || this->array == NULL)
			{
				std::cout << "index : " << i << std::endl;
				throw Array :: InvaildIndexException();
			}
			return (this->array[i]);
		}
		
		const T& operator[] (unsigned int i) const
		{
			if (i >= this->len || this->array == NULL)
			{
				std::cout << "index : " << i << std::endl;
				throw Array :: InvaildIndexException();
			}
			return (this->array[i]);
		}
};

template <typename T>
const	char * Array<T> :: InvaildIndexException :: what(void) const throw()
{
	return ("Error : Invaild Index");
}

#endif