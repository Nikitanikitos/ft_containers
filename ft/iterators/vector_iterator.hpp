/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:09:50 by imicah            #+#    #+#             */
/*   Updated: 2020/11/10 13:07:42 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_VECTOR_ITERATOR_HPP
# define FT_CONTAINERS_VECTOR_ITERATOR_HPP

# include <iterator>
# include "ft.hpp"

template<class T>
class	ft::vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
	template <class U, class Alloc>
	friend class	vector;
	template <class U, class Alloc>
	friend class	deque;
	friend class	const_vector_iterator<T>;

private:
	T*		_ptr;

public:
	vector_iterator(T *ptr = 0) : _ptr(ptr) { }
	vector_iterator(const vector_iterator<T> &it) : _ptr(it._ptr) { }
	~vector_iterator() { }

	vector_iterator<T>&		operator=(const vector_iterator<T> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool	operator==(const vector_iterator<T> &x) const { return (_ptr == x._ptr); }
	bool	operator!=(const vector_iterator<T> &x) const { return (_ptr != x._ptr); }
	bool	operator<(const vector_iterator<T> &x) const { return (_ptr < x._ptr); }
	bool	operator<=(const vector_iterator<T> &x) const { return (_ptr <= x._ptr); }
	bool	operator>(const vector_iterator<T> &x) const { return (_ptr > x._ptr); }
	bool	operator>=(const vector_iterator<T> &x) const { return (_ptr >= x._ptr); }

	vector_iterator<T>&		operator++() { _ptr++; return (*this); }
	vector_iterator<T>&		operator--() { _ptr--; return (*this); }

	vector_iterator<T>		operator++(int) {
		vector_iterator<T>		temp(_ptr);

		++_ptr;
		return (temp);
	}

	vector_iterator<T>		operator--(int) {
		vector_iterator<T>	temp(_ptr);

		--_ptr;
		return (temp);
	}

	vector_iterator<T>		operator+(std::ptrdiff_t x) {
		vector_iterator<T>	temp(_ptr);

		temp += x;
		return (temp);
	}

	vector_iterator<T>		operator-(std::ptrdiff_t x) {
		vector_iterator<T>	temp(_ptr);

		temp -= x;
		return (temp);
	}

	vector_iterator<T>		operator+=(std::ptrdiff_t x) { _ptr += x; return (*this); }
	vector_iterator<T>		operator-=(std::ptrdiff_t x) { _ptr -= x; return (*this); }

	vector_iterator<T>		operator[](size_t n) { return (_ptr[n]); }
	T&						operator*() { return (*_ptr); }
	T*						operator->() { return (_ptr); }
};

template<class T>
class	ft::const_vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
	template <class U, class Alloc>
	friend class	vector;
	template <class U, class Alloc>
	friend class	deque;

private:
	T*		_ptr;

public:
	const_vector_iterator(T *ptr = 0) : _ptr(ptr) { }
	const_vector_iterator(const const_vector_iterator<T> &x) : _ptr(x._ptr) { }
	const_vector_iterator(const vector_iterator<T> &x) : _ptr(x._ptr) { }
	~const_vector_iterator() { }

	const_vector_iterator<T>&	operator=(const const_vector_iterator<T> &x) {
		if (this != &x)
			_ptr = x._ptr;
		return (*this);
	}

	const_vector_iterator<T>&	operator=(const vector_iterator<T> &x) {
		_ptr = x._ptr;
		return (*this);
	}

	bool	operator==(const const_vector_iterator<T> &x) const { return (_ptr == x._ptr); }
	bool	operator!=(const const_vector_iterator<T> &x) const { return (_ptr != x._ptr); }
	bool	operator<(const const_vector_iterator<T> &x) const { return (_ptr < x._ptr); }
	bool	operator<=(const const_vector_iterator<T> &x) const { return (_ptr <= x._ptr); }
	bool	operator>(const const_vector_iterator<T> &x) const { return (_ptr > x._ptr); }
	bool	operator>=(const const_vector_iterator<T> &x) const { return (_ptr >= x._ptr); }

	const_vector_iterator<T>&		operator++() { _ptr++; return (*this); }
	const_vector_iterator<T>&		operator--() { _ptr--; return (*this); }

	const_vector_iterator<T>		operator++(int) {
		const_vector_iterator<T>		temp(_ptr);

		++_ptr;
		return (temp);
	}

	const_vector_iterator<T>		operator--(int) {
		const_vector_iterator<T>		temp(_ptr);

		--_ptr;
		return (temp);
	}

	const_vector_iterator<T>		operator+(std::ptrdiff_t x) {
		const_vector_iterator<T>		temp(_ptr);

		temp += x;
		return (temp);
	}

	const_vector_iterator<T>		operator-(int x) {
		const_vector_iterator<T>		temp(_ptr);

		temp -= x;
		return (temp);
	}

	const_vector_iterator<T>		operator+=(std::ptrdiff_t x) { _ptr += x; return (*this); }
	const_vector_iterator<T>		operator-=(std::ptrdiff_t x) { _ptr -= x; return (*this); }

	T								operator[](size_t n) { return (_ptr[n]); }
	const T&						operator*() { return (*_ptr); }
	const T*						operator->() { return (_ptr); }
};

#endif
