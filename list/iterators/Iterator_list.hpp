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
class	IteratorList : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*		_ptr;

public:
	IteratorList(T *p = 0) : _ptr(p) { }
	IteratorList(const IteratorList<T, U> &it) : _ptr(it._ptr) { }
	~IteratorList() { }

	IteratorList<T, U>		&operator=(const IteratorList<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool		operator!=(const IteratorList<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const IteratorList<T, U> &it) const { return (_ptr == it._ptr); }
	U			&operator*() const { return (*_ptr->value); }
	U			*operator->() const { return (_ptr->value); }

	IteratorList<T, U>		&operator++() { _ptr = _ptr->next; return (*this); }
	IteratorList<T, U>		&operator--() { _ptr = _ptr->prev; return (*this); }

	IteratorList<T, U>		&operator++(int) {
		IteratorList<T, U>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}

	IteratorList<T, U>		&operator--(int) {
		IteratorList<T, U>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}

	T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше

};

template<class T, class U>
class	ConstIteratorList : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*	_ptr;

public:
	ConstIteratorList(T *ptr = 0) : _ptr(ptr) { }
	ConstIteratorList(const IteratorList<T, U> &it) : _ptr(it._get_ptr()) { }
	ConstIteratorList(const ConstIteratorList<T, U> &it) : _ptr(it._ptr) { }
	~ConstIteratorList() { }

	ConstIteratorList<T, U>		&operator=(const IteratorList<T, U> &it) {
		_ptr = it._get_ptr();
		return (*this);
	}

	ConstIteratorList<T, U>		&operator=(const ConstIteratorList<T, U> &it) {
		if (this != &it)
			_ptr - it._ptr;
		return (*this);
	}

	bool		operator!=(const ConstIteratorList<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const ConstIteratorList<T, U> &it) const { return (_ptr == it._ptr); }
	const U		&operator*() const { return (*(this->_ptr->value)); }
	const U		*operator->() const { return (this->_ptr->value); }

	ConstIteratorList<T, U>		&operator++() { _ptr = _ptr->next; return (*this); }
	ConstIteratorList<T, U>		&operator--() { _ptr = _ptr->prev; return (*this); }

	ConstIteratorList<T, U>		operator++(int) {
		IteratorList<T, U>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}

	ConstIteratorList<T, U>		operator--(int) {
		IteratorList<T, U>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}
};

#endif
