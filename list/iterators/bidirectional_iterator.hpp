/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator_list.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:39:34 by imicah            #+#    #+#             */
/*   Updated: 2020/10/23 20:56:56 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Iterator_hpp
# define Iterator_hpp

# include <iostream>
# include <iterator>
# include <string>

template<class T, class U>
class	bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*		_ptr;

public:
	bidirectional_iterator(T *p = 0) : _ptr(p) { }
	bidirectional_iterator(const bidirectional_iterator<T, U> &it) : _ptr(it._ptr) { }
	~bidirectional_iterator() { }

	bidirectional_iterator<T, U>		&operator=(const bidirectional_iterator<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool		operator!=(const bidirectional_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const bidirectional_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	U			&operator*() const { return (*_ptr->value); }
	U			*operator->() const { return (_ptr->value); }

	bidirectional_iterator<T, U>		&operator++() { _ptr = _ptr->next; return (*this); }
	bidirectional_iterator<T, U>		&operator--() { _ptr = _ptr->prev; return (*this); }

	bidirectional_iterator<T, U>		operator++(int) {
		bidirectional_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}

	bidirectional_iterator<T, U>		&operator--(int) {
		bidirectional_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}

	T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше

};

template<class T, class U>
class	const_bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*	_ptr;

public:
	const_bidirectional_iterator(T *ptr = 0) : _ptr(ptr) { }
	const_bidirectional_iterator(const bidirectional_iterator<T, U> &it) : _ptr(it._get_ptr()) { }
	const_bidirectional_iterator(const const_bidirectional_iterator<T, U> &it) : _ptr(it._ptr) { }
	~const_bidirectional_iterator() { }

	const_bidirectional_iterator<T, U>		&operator=(const bidirectional_iterator<T, U> &it) {
		_ptr = it._get_ptr();
		return (*this);
	}

	const_bidirectional_iterator<T, U>		&operator=(const const_bidirectional_iterator<T, U> &it) {
		if (this != &it)
			_ptr - it._ptr;
		return (*this);
	}

	bool		operator!=(const const_bidirectional_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const const_bidirectional_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	const U		&operator*() const { return (*(this->_ptr->value)); }
	const U		*operator->() const { return (this->_ptr->value); }

	const_bidirectional_iterator<T, U>		&operator++() { _ptr = _ptr->next; return (*this); }
	const_bidirectional_iterator<T, U>		&operator--() { _ptr = _ptr->prev; return (*this); }

	const_bidirectional_iterator<T, U>		operator++(int) {
		bidirectional_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}

	const_bidirectional_iterator<T, U>		operator--(int) {
		bidirectional_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}
};

#endif
