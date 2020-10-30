/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_random_access_iterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:21:42 by imicah            #+#    #+#             */
/*   Updated: 2020/10/27 14:38:25 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_REVERSE_VECTOR_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_VECTOR_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>

namespace ft
{
	template<class T>
	class	reverse_vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T*		_ptr;

	public:
		reverse_vector_iterator() : _ptr(0) { }
		reverse_vector_iterator(T *ptr) : _ptr(ptr) { }
		reverse_vector_iterator(const reverse_vector_iterator<T> &x) : _ptr(x._ptr) { }
		~reverse_vector_iterator() { }

		reverse_vector_iterator<T>	&operator=(const reverse_vector_iterator<T> &x) {
			if (this != &x)
				_ptr = x._ptr;
			return (*this);
		}

		bool	operator==(const reverse_vector_iterator<T> &x) const { return (_ptr == x._ptr); }
		bool	operator!=(const reverse_vector_iterator<T> &x) const { return (_ptr != x._ptr); }
		bool	operator<(const reverse_vector_iterator<T> &x) const { return (_ptr < x._ptr); }
		bool	operator<=(const reverse_vector_iterator<T> &x) const { return (_ptr <= x._ptr); }
		bool	operator>(const reverse_vector_iterator<T> &x) const { return (_ptr > x._ptr); }
		bool	operator>=(const reverse_vector_iterator<T> &x) const { return (_ptr >= x._ptr); }

		reverse_vector_iterator<T>	&operator++() { _ptr--; return (*this); }
		reverse_vector_iterator<T>	&operator--() { _ptr++; return (*this); }

		reverse_vector_iterator<T>	operator++(int) {
			reverse_vector_iterator<T>		temp(_ptr);

			--_ptr;
			return (temp);
		}

		reverse_vector_iterator<T>	operator--(int) {
			reverse_vector_iterator<T>		temp(_ptr);

			++_ptr;
			return (temp);
		}

		reverse_vector_iterator<T>	operator+(reverse_vector_iterator<T> &x) { return (_ptr + x._ptr); }
		reverse_vector_iterator<T>	operator-(reverse_vector_iterator<T> &x) { return (_ptr + x._ptr); }
		reverse_vector_iterator<T>	operator+=(reverse_vector_iterator<T> &x) { _ptr += x._ptr; return (*this); }
		reverse_vector_iterator<T>	operator-=(reverse_vector_iterator<T> &x) { _ptr -= x._ptr; return (*this); }

		reverse_vector_iterator<T>	operator[](size_t n) { return (_ptr[n]); }

		T		&operator*() { return (*_ptr); }
		T		*operator->() { return (_ptr); }

		T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше
	};

	template<class T>
	class	const_reverse_vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T*		_ptr;

	public:
		const_reverse_vector_iterator() : _ptr(0) { }
		const_reverse_vector_iterator(T *ptr) : _ptr(ptr) { }
		const_reverse_vector_iterator(const const_reverse_vector_iterator<T> &x) : _ptr(x._ptr) { }
		const_reverse_vector_iterator(const reverse_vector_iterator<T> &x) : _ptr(x._get_ptr()) { }
		~const_reverse_vector_iterator() { }

		const_reverse_vector_iterator<T>	&operator=(const const_reverse_vector_iterator<T> &x) {
			if (this != &x)
				_ptr = x._ptr;
			return (*this);
		}

		const_reverse_vector_iterator<T>	&operator=(const reverse_vector_iterator<T> &x)
		        											{ _ptr = x._get_ptr(); return (*this); }

		bool	operator==(const const_reverse_vector_iterator<T> &x) const { return (_ptr == x._ptr); }
		bool	operator!=(const const_reverse_vector_iterator<T> &x) const { return (_ptr != x._ptr); }
		bool	operator<(const const_reverse_vector_iterator<T> &x) const { return (_ptr < x._ptr); }
		bool	operator<=(const const_reverse_vector_iterator<T> &x) const { return (_ptr <= x._ptr); }
		bool	operator>(const const_reverse_vector_iterator<T> &x) const { return (_ptr > x._ptr); }
		bool	operator>=(const const_reverse_vector_iterator<T> &x) const { return (_ptr >= x._ptr); }

		const_reverse_vector_iterator<T>	&operator++() { _ptr--; return (*this); }
		const_reverse_vector_iterator<T>	&operator--() { _ptr++; return (*this); }

		const_reverse_vector_iterator<T>	operator++(int) {
			reverse_vector_iterator<T>		temp(_ptr);

			--_ptr;
			return (temp);
		}

		const_reverse_vector_iterator<T>	operator--(int) {
			reverse_vector_iterator<T>		temp(_ptr);

			++_ptr;
			return (temp);
		}

		const_reverse_vector_iterator<T>	operator+(const_reverse_vector_iterator<T> &x) { return (_ptr + x._ptr); }
		const_reverse_vector_iterator<T>	operator-(const_reverse_vector_iterator<T> &x) { return (_ptr - x._ptr); }
		const_reverse_vector_iterator<T>	operator+=(const_reverse_vector_iterator<T> &x) { _ptr += x._ptr; return (*this); }
		const_reverse_vector_iterator<T>	operator-=(const_reverse_vector_iterator<T> &x) { _ptr -= x._ptr; return (*this); }

		const T								operator[](size_t n) { return (_ptr[n]); }
		T									&operator*() { return (*_ptr); }
		T									*operator->() { return (_ptr); }

		T*									_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше
	};
}

#endif
