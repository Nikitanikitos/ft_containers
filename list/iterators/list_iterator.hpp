/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:39:34 by imicah            #+#    #+#             */
/*   Updated: 2020/10/23 20:56:56 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>
# include "ft.hpp"

template<class T, class U>
class	ft::list_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
	friend class ft::list<class S>;
	friend class ft::const_list_iterator<T, U>;
private:
	T*		_ptr;

public:
	list_iterator(T *p = 0) : _ptr(p) { }
	list_iterator(const list_iterator<T, U> &it) : _ptr(it._ptr) { }
	~list_iterator() { }

	list_iterator<T, U>		&operator=(const list_iterator<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool		operator!=(const list_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const list_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	U			&operator*() const { return (*_ptr->value); }
	U			*operator->() const { return (_ptr->value); }

	list_iterator<T, U>		&operator++() { _ptr = _ptr->next; return (*this); }
	list_iterator<T, U>		&operator--() { _ptr = _ptr->prev; return (*this); }

	list_iterator<T, U>		operator++(int) {
		list_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}

	list_iterator<T, U>		&operator--(int) {
		list_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}
};

template<class T, class U>
class	ft::const_list_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*	_ptr;

public:
	const_list_iterator(T *ptr = 0) : _ptr(ptr) { }
	const_list_iterator(const list_iterator<T, U> &it) : _ptr(it._ptr) { }
	const_list_iterator(const const_list_iterator<T, U> &it) : _ptr(it._ptr) { }
	~const_list_iterator() { }

	const_list_iterator<T, U>		&operator=(const list_iterator<T, U> &it) {
		_ptr = it.ptr;
		return (*this);
	}

	const_list_iterator<T, U>		&operator=(const const_list_iterator<T, U> &it) {
		if (this != &it)
			_ptr - it._ptr;
		return (*this);
	}

	bool		operator!=(const const_list_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const const_list_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	const U		&operator*() const { return (*(this->_ptr->value)); }
	const U		*operator->() const { return (this->_ptr->value); }

	const_list_iterator<T, U>		&operator++() { _ptr = _ptr->next; return (*this); }
	const_list_iterator<T, U>		&operator--() { _ptr = _ptr->prev; return (*this); }

	const_list_iterator<T, U>		operator++(int) {
		list_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}

	const_list_iterator<T, U>		operator--(int) {
		list_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}
};

#endif
