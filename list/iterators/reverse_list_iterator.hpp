/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bidirectional_iterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:37:34 by imicah            #+#    #+#             */
/*   Updated: 2020/10/26 17:14:33 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_REVERSE_LIST_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_LIST_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>
# include "ft.hpp"

template<class T, class U>
class	ft::reverse_list_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*		_ptr;

public:
	reverse_list_iterator(T *p = 0) : _ptr(p) { }
	reverse_list_iterator(const reverse_list_iterator<T, U> &it) : _ptr(it._ptr) { }
	~reverse_list_iterator() { }

	reverse_list_iterator<T, U>		&operator=(const reverse_list_iterator<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool	operator!=(const reverse_list_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool	operator==(const reverse_list_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	U		&operator*() const { return (*_ptr->value); };
	U		*operator->() const { return (this->_ptr->value); }

	reverse_list_iterator<T, U>		&operator++() { _ptr = _ptr->prev; return (*this); }
	reverse_list_iterator<T, U>		&operator--() { _ptr = _ptr->next; return (*this); }

	reverse_list_iterator<T, U>		operator++(int) {
		reverse_list_iterator<T, U>	temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}

	reverse_list_iterator<T, U>		operator--(int) {
		reverse_list_iterator<T, U>	temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}
};

template<class T, class U>
class	ft::const_reverse_list_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*		_ptr;

public:
	const_reverse_list_iterator(T *p = 0) : _ptr(p) { }
	const_reverse_list_iterator(const reverse_list_iterator<T, U> &it) : _ptr(it._get_ptr()) { }
	~const_reverse_list_iterator() { }

	const_reverse_list_iterator<T, U>		&operator=(const reverse_list_iterator<T, U> &it) {
		_ptr = it._get_ptr();
		return (*this);
	}

	const_reverse_list_iterator<T, U>		&operator=(const const_reverse_list_iterator<T, U> &it) {
		if (this != &it)
			_ptr - it._ptr;
		return (*this);
	}

	bool		operator!=(const const_reverse_list_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const const_reverse_list_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	const U		&operator*() const { return (*(this->_ptr->value)); }
	const U		*operator->() const { return (this->_ptr->value); }

	const_reverse_list_iterator<T, U>		&operator++() { _ptr = _ptr->prev; return (*this); }
	const_reverse_list_iterator<T, U>		&operator--() { _ptr = _ptr->next; return (*this); }

	const_reverse_list_iterator<T, U>		operator++(int) {
		const_reverse_list_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}

	const_reverse_list_iterator<T, U>		operator--(int) {
		list_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}
};

#endif
