/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:28:20 by jjin              #+#    #+#             */
/*   Updated: 2023/05/30 21:06:53 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
	private:
		unsigned int	_size;
		T				*_arr;
	public:
		Array() : _size(0), _arr(new T[0]) {}

		Array(unsigned int n) : _size(n), _arr(new T[_size]) {}
		
		Array(const Array &other) : _size(other.size()), _arr(new T[other.size()])
		{
			*this = other;
		}

		Array& operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] _arr;
				_size = other.size();
				_arr = new T[other.size()];
				for (unsigned int i = 0; i < _size; i++)
					_arr[i] = other._arr[i];
			}
			return *this;
		}
		
		~Array()
		{
			delete[] _arr;
		}

		unsigned int size() const
		{
			return _size;
		};

		T& operator[](unsigned int idx)
		{
			if (idx < 0 || idx >= _size)
				throw std::exception();
			return _arr[idx];
		}

		const T& operator[](unsigned int idx) const
		{
			if (idx < 0 || idx >= _size)
				throw std::exception();
			return _arr[idx];
		}
};

#endif