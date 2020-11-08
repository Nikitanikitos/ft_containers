/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_vector_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:21:42 by imicah            #+#    #+#             */
/*   Updated: 2020/11/06 18:05:18 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_REVERSE_VECTOR_ITERATOR_HPP
# define FT_CONTAINERS_REVERSE_VECTOR_ITERATOR_HPP

# include <iterator>
# include "ft.hpp"

template<class T>
class	ft::reverse_vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
	template <T, class Alloc>
	friend class	vector;
	friend class	const_reverse_vector_iterator<T>;

private:
	T*		_ptr;

public:
	reverse_vector_iterator(T *ptr = 0) : _ptr(ptr) { }
	reverse_vector_iterator(const reverse_vector_iterator<T> &x) : _ptr(x._ptr) { }
	~reverse_vector_iterator() { }

	reverse_vector_iterator<T>&		operator=(const reverse_vector_iterator<T> &x) {
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

	reverse_vector_iterator<T>&		operator++() { _ptr--; return (*this); }
	reverse_vector_iterator<T>&		operator--() { _ptr++; return (*this); }

	reverse_vector_iterator<T>		operator++(int) {
		reverse_vector_iterator<T>		temp(_ptr);

		--_ptr;
		return (temp);
	}

	reverse_vector_iterator<T>		operator--(int) {
		reverse_vector_iterator<T>		temp(_ptr);

		++_ptr;
		return (temp);
	}

	reverse_vector_iterator<T>	operator+(reverse_vector_iterator<T> &x) { return (_ptr + x._ptr); }
	reverse_vector_iterator<T>	operator-(reverse_vector_iterator<T> &x) { return (_ptr + x._ptr); }
	reverse_vector_iterator<T>	operator+=(reverse_vector_iterator<T> &x) { _ptr += x._ptr; return (*this); }
	reverse_vector_iterator<T>	operator-=(reverse_vector_iterator<T> &x) { _ptr -= x._ptr; return (*this); }

	reverse_vector_iterator<T>	operator[](size_t n) { return (_ptr[n]); }

	T&		operator*() { return (*_ptr); }
	T*		operator->() { return (_ptr); }
};

template<class T>
class	ft::const_reverse_vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
	template <T, class Alloc>
	friend class	vector;

private:
	T*		_ptr;

public:
	const_reverse_vector_iterator(T *ptr = 0) : _ptr(ptr) { }
	const_reverse_vector_iterator(const const_reverse_vector_iterator<T> &x) : _ptr(x._ptr) { }
	const_reverse_vector_iterator(const reverse_vector_iterator<T> &x) : _ptr(x._ptr) { }
	~const_reverse_vector_iterator() { }

	const_reverse_vector_iterator<T>&	operator=(const const_reverse_vector_iterator<T> &x) {
		if (this != &x)
			_ptr = x._ptr;
		return (*this);
	}

	const_reverse_vector_iterator<T>&	operator=(const reverse_vector_iterator<T> &x) {
		_ptr = x._ptr();
		return (*this);
	}

	bool	operator==(const const_reverse_vector_iterator<T> &x) const { return (_ptr == x._ptr); }
	bool	operator!=(const const_reverse_vector_iterator<T> &x) const { return (_ptr != x._ptr); }
	bool	operator<(const const_reverse_vector_iterator<T> &x) const { return (_ptr < x._ptr); }
	bool	operator<=(const const_reverse_vector_iterator<T> &x) const { return (_ptr <= x._ptr); }
	bool	operator>(const const_reverse_vector_iterator<T> &x) const { return (_ptr > x._ptr); }
	bool	operator>=(const const_reverse_vector_iterator<T> &x) const { return (_ptr >= x._ptr); }

	const_reverse_vector_iterator<T>&	operator++() { _ptr--; return (*this); }
	const_reverse_vector_iterator<T>&	operator--() { _ptr++; return (*this); }

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

	T									operator[](size_t n) { return (_ptr[n]); }
	const T&							operator*() { return (*_ptr); }
	const T*							operator->() { return (_ptr); }
};

#endif
