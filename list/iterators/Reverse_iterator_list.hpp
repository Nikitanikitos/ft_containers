/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_list.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:37:34 by imicah            #+#    #+#             */
/*   Updated: 2020/10/22 23:12:24 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_REVERSE_ITERATOR_LIST_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_LIST_HPP

# include <iostream>
# include <iterator>
# include <string>

template<class T, class U>
class	RevIteratorList : public std::iterator<std::bidirectional_iterator_tag, T>
{
protected:
	T*		_ptr;

public:
	RevIteratorList(T *p = 0) : _ptr(p) { }
	RevIteratorList(const RevIteratorList<T, U> &it) : _ptr(it._ptr) { }
	~RevIteratorList() { }

	RevIteratorList<T, U>		&operator=(const RevIteratorList<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool	operator!=(const RevIteratorList<T, U> &it) const { return (_ptr != it._ptr); }
	bool	operator==(const RevIteratorList<T, U> &it) const { return (_ptr == it._ptr); }
	U		&operator*() const { return (*_ptr->value); };
	U		*operator->() const { return (this->_ptr->value); }

	RevIteratorList<T, U>		&operator++() { _ptr = _ptr->prev; return (*this); }
	RevIteratorList<T, U>		&operator--() { _ptr = _ptr->next; return (*this); }

	RevIteratorList<T, U>		operator++(int) {
		RevIteratorList<T, U>	temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}

	RevIteratorList<T, U>		operator--(int) {
		RevIteratorList<T, U>	temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}

	T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше
};

template<class T, class U>
class	ConstRevIteratorList : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*		_ptr;

public:
	ConstRevIteratorList(T *p = 0) : _ptr(p) { }
	ConstRevIteratorList(const RevIteratorList<T, U> &it) : _ptr(it._get_ptr()) { }
	~ConstRevIteratorList() { }

	ConstRevIteratorList<T, U>		&operator=(const RevIteratorList<T, U> &it) {
		_ptr = it._get_ptr();
		return (*this);
	}

	ConstRevIteratorList<T, U>		&operator=(const ConstRevIteratorList<T, U> &it) {
		if (this != &it)
			_ptr - it._ptr;
		return (*this);
	}

	bool		operator!=(const ConstRevIteratorList<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const ConstRevIteratorList<T, U> &it) const { return (_ptr == it._ptr); }
	const U		&operator*() const { return (*(this->_ptr->value)); }
	const U		*operator->() const { return (this->_ptr->value); }

	ConstRevIteratorList<T, U>		&operator++() { _ptr = _ptr->prev; return (*this); }
	ConstRevIteratorList<T, U>		&operator--() { _ptr = _ptr->next; return (*this); }

	ConstRevIteratorList<T, U>		operator++(int) {
		ConstRevIteratorList<T, U>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}

	ConstRevIteratorList<T, U>		operator--(int) {
		IteratorList<T, U>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}
};

#endif
