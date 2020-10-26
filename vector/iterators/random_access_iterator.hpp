/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:09:50 by imicah            #+#    #+#             */
/*   Updated: 2020/10/26 17:27:50 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
# define FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>

namespace ft
{
	template<class T>
	class	random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T*		_ptr;

	public:
		random_access_iterator() : _ptr(0) { }
		random_access_iterator(const random_access_iterator<T> &x) : _ptr(x._ptr) { }
		~random_access_iterator() { }

		random_access_iterator<T>	&operator=(const random_access_iterator<T> &x) {
			if (this != &x)
				_ptr = x._ptr;
			return (*this);
		}

		bool	operator==(const random_access_iterator<T> &x) { return (*_ptr == *x._ptr); }
		bool	operator!=(const random_access_iterator<T> &x) { return (*_ptr != *x._ptr); }
		bool	operator<(const random_access_iterator<T> &x) { return (*_ptr < *x._ptr); }
		bool	operator<=(const random_access_iterator<T> &x) { return (*_ptr <= *x._ptr); }
		bool	operator>(const random_access_iterator<T> &x) { return (*_ptr > *x._ptr); }
		bool	operator>=(const random_access_iterator<T> &x) { return (*_ptr >= *x._ptr); }

		random_access_iterator<T>	&operator++() { _ptr++; return (*this); }
		random_access_iterator<T>	&operator--() { _ptr--; return (*this); }

		random_access_iterator<T>	operator++(int) {
			random_access_iterator<T>		temp(_ptr);

			++_ptr;
			return (temp);
		}

		random_access_iterator<T>	operator--(int) {
			random_access_iterator<T>		temp(_ptr);

			--_ptr;
			return (temp);
		}

		random_access_iterator<T>	operator+(random_access_iterator<T> &x)
																	{ return (*_ptr + *x._ptr); }
		random_access_iterator<T>	operator-(random_access_iterator<T> &x)
																	{ return (*_ptr + *x._ptr); }

		random_access_iterator<T>	operator+=(random_access_iterator<T> &);
		random_access_iterator<T>	operator-=(random_access_iterator<T> &);
		random_access_iterator<T>	operator[](size_t);

		T		&operator*() { return (*_ptr); }
		T		*operator->() { return (_ptr); }

		T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше

	};

	template<class T>
	class	const_random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T*		_ptr;

	public:
		const_random_access_iterator() : _ptr(0) { }
		const_random_access_iterator(const const_random_access_iterator<T> &x) : _ptr(x._ptr) { }
		const_random_access_iterator(const random_access_iterator<T> &x) : _ptr(x._get_ptr()) { }
		~const_random_access_iterator() { }

		const_random_access_iterator<T>	&operator=(const const_random_access_iterator<T> &x) {
			if (this != &x)
				_ptr = x._ptr;
			return (*this);
		}

		const_random_access_iterator<T>	&operator=(const random_access_iterator<T> &x) {
			if (this != &x)
				_ptr = x._get_ptr();
			return (*this);
		}

		bool	operator==(const const_random_access_iterator<T> &x) { return (*_ptr == *x._ptr); }
		bool	operator!=(const const_random_access_iterator<T> &x) { return (*_ptr != *x._ptr); }
		bool	operator<(const const_random_access_iterator<T> &x) { return (*_ptr < *x._ptr); }
		bool	operator<=(const const_random_access_iterator<T> &x) { return (*_ptr <= *x._ptr); }
		bool	operator>(const const_random_access_iterator<T> &x) { return (*_ptr > *x._ptr); }
		bool	operator>=(const const_random_access_iterator<T> &x) { return (*_ptr >= *x._ptr); }

		const_random_access_iterator<T>	&operator++() { _ptr++; return (*this); }
		const_random_access_iterator<T>	&operator--() { _ptr--; return (*this); }

		const_random_access_iterator<T>	operator++(int) {
			const_random_access_iterator<T>		temp(_ptr);

			++_ptr;
			return (temp);
		}
		const_random_access_iterator<T>	operator--(int) {
			const_random_access_iterator<T>		temp(_ptr);

			--_ptr;
			return (temp);
		}

		const_random_access_iterator<T>	operator+(const_random_access_iterator<T> &x)
																	{ return (*_ptr + *x._ptr); }
		const_random_access_iterator<T>	operator-(const_random_access_iterator<T> &x)
																	{ return (*_ptr - *x._ptr); }

		const_random_access_iterator<T>	operator+=(const_random_access_iterator<T> &);
		const_random_access_iterator<T>	operator-=(const_random_access_iterator<T> &);
		const T							operator[](size_t);

		T		&operator*() { return (*_ptr); }
		T		*operator->() { return (_ptr); }

		T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше

	};

}

#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP