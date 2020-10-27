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


#ifndef FT_CONTAINERS_REVERSE_RANDOM_ACCESS_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>

namespace ft
{
	template<class T>
	class	rev_random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T*		_ptr;

	public:
		rev_random_access_iterator() : _ptr(0) { }
		rev_random_access_iterator(T *ptr) : _ptr(ptr) { }
		rev_random_access_iterator(const rev_random_access_iterator<T> &x) : _ptr(x._ptr) { }
		~rev_random_access_iterator() { }

		rev_random_access_iterator<T>	&operator=(const rev_random_access_iterator<T> &x) {
			if (this != &x)
				_ptr = x._ptr;
			return (*this);
		}

		bool	operator==(const rev_random_access_iterator<T> &x) const { return (_ptr == x._ptr); }
		bool	operator!=(const rev_random_access_iterator<T> &x) const { return (_ptr != x._ptr); }
		bool	operator<(const rev_random_access_iterator<T> &x) const { return (_ptr < x._ptr); }
		bool	operator<=(const rev_random_access_iterator<T> &x) const { return (_ptr <= x._ptr); }
		bool	operator>(const rev_random_access_iterator<T> &x) const { return (_ptr > x._ptr); }
		bool	operator>=(const rev_random_access_iterator<T> &x) const { return (_ptr >= x._ptr); }

		rev_random_access_iterator<T>	&operator++() { _ptr--; return (*this); }
		rev_random_access_iterator<T>	&operator--() { _ptr++; return (*this); }

		rev_random_access_iterator<T>	operator++(int) {
			rev_random_access_iterator<T>		temp(_ptr);

			--_ptr;
			return (temp);
		}

		rev_random_access_iterator<T>	operator--(int) {
			rev_random_access_iterator<T>		temp(_ptr);

			++_ptr;
			return (temp);
		}

		rev_random_access_iterator<T>	operator+(rev_random_access_iterator<T> &x) { return (_ptr + x._ptr); }
		rev_random_access_iterator<T>	operator-(rev_random_access_iterator<T> &x) { return (_ptr + x._ptr); }
		rev_random_access_iterator<T>	operator+=(rev_random_access_iterator<T> &x) { _ptr += x._ptr; return (*this); }
		rev_random_access_iterator<T>	operator-=(rev_random_access_iterator<T> &x) { _ptr -= x._ptr; return (*this); }

		rev_random_access_iterator<T>	operator[](size_t n) { return (_ptr[n]); }

		T		&operator*() { return (*_ptr); }
		T		*operator->() { return (_ptr); }

		T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше
	};

	template<class T>
	class	const_rev_random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T*		_ptr;

	public:
		const_rev_random_access_iterator() : _ptr(0) { }
		const_rev_random_access_iterator(T *ptr) : _ptr(ptr) { }
		const_rev_random_access_iterator(const const_rev_random_access_iterator<T> &x) : _ptr(x._ptr) { }
		const_rev_random_access_iterator(const rev_random_access_iterator<T> &x) : _ptr(x._get_ptr()) { }
		~const_rev_random_access_iterator() { }

		const_rev_random_access_iterator<T>	&operator=(const const_rev_random_access_iterator<T> &x) {
			if (this != &x)
				_ptr = x._ptr;
			return (*this);
		}

		const_rev_random_access_iterator<T>	&operator=(const rev_random_access_iterator<T> &x)
		        											{ _ptr = x._get_ptr(); return (*this); }

		bool	operator==(const const_rev_random_access_iterator<T> &x) const { return (_ptr == x._ptr); }
		bool	operator!=(const const_rev_random_access_iterator<T> &x) const { return (_ptr != x._ptr); }
		bool	operator<(const const_rev_random_access_iterator<T> &x) const { return (_ptr < x._ptr); }
		bool	operator<=(const const_rev_random_access_iterator<T> &x) const { return (_ptr <= x._ptr); }
		bool	operator>(const const_rev_random_access_iterator<T> &x) const { return (_ptr > x._ptr); }
		bool	operator>=(const const_rev_random_access_iterator<T> &x) const { return (_ptr >= x._ptr); }

		const_rev_random_access_iterator<T>	&operator++() { _ptr--; return (*this); }
		const_rev_random_access_iterator<T>	&operator--() { _ptr++; return (*this); }

		const_rev_random_access_iterator<T>	operator++(int) {
			rev_random_access_iterator<T>		temp(_ptr);

			--_ptr;
			return (temp);
		}

		const_rev_random_access_iterator<T>	operator--(int) {
			rev_random_access_iterator<T>		temp(_ptr);

			++_ptr;
			return (temp);
		}

		const_rev_random_access_iterator<T>	operator+(const_rev_random_access_iterator<T> &x) { return (_ptr + x._ptr); }
		const_rev_random_access_iterator<T>	operator-(const_rev_random_access_iterator<T> &x) { return (_ptr - x._ptr); }
		const_rev_random_access_iterator<T>	operator+=(const_rev_random_access_iterator<T> &x) { _ptr += x._ptr; return (*this); }
		const_rev_random_access_iterator<T>	operator-=(const_rev_random_access_iterator<T> &x) { _ptr -= x._ptr; return (*this); }

		const T								operator[](size_t n) { return (_ptr[n]); }
		T									&operator*() { return (*_ptr); }
		T									*operator->() { return (_ptr); }

		T*									_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше
	};
}

#endif
