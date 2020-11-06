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

#ifndef FT_CONTAINERS_LIST_ITERATOR_HPP
# define FT_CONTAINERS_LIST_ITERATOR_HPP

# include <iterator>
# include "ft.hpp"

template<class P, class V>
class	ft::list_iterator : public std::iterator<std::bidirectional_iterator_tag, P>
{
	template<class T>
	friend class list;
	friend class ft::const_list_iterator<P, V>;
private:
	P*		_ptr;

public:
	list_iterator(P *p = 0) : _ptr(p) { }
	list_iterator(const list_iterator<P, V> &it) : _ptr(it._ptr) { }
	~list_iterator() { }

	list_iterator<P, V>		&operator=(const list_iterator<P, V> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool		operator!=(const list_iterator<P, V> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const list_iterator<P, V> &it) const { return (_ptr == it._ptr); }
	V&			operator*() const { return (*_ptr->value); }
	V*			operator->() const { return (_ptr->value); }

	list_iterator<P, V>&	operator++() { _ptr = _ptr->next; return (*this); }
	list_iterator<P, V>&	operator--() { _ptr = _ptr->prev; return (*this); }

	list_iterator<P, V>		operator++(int) {
		list_iterator<P, V>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}

	list_iterator<P, V>		operator--(int) {
		list_iterator<P, V>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}
};

template<class P, class V>
class	ft::const_list_iterator : public std::iterator<std::bidirectional_iterator_tag, P>
{
	template<class T>
	friend class list;

private:
	P*	_ptr;

public:
	explicit const_list_iterator(P *ptr = 0) : _ptr(ptr) { }
	explicit const_list_iterator(const list_iterator<P, V> &it) : _ptr(it._ptr) { }
	const_list_iterator(const const_list_iterator<P, V> &it) : _ptr(it._ptr) { }
	~const_list_iterator() { }

	const_list_iterator<P, V>		&operator=(const list_iterator<P, V> &it) {
		_ptr = it.ptr;
		return (*this);
	}

	const_list_iterator<P, V>		&operator=(const const_list_iterator<P, V> &it) {
		if (this != &it)
			_ptr - it._ptr;
		return (*this);
	}

	bool		operator!=(const const_list_iterator<P, V> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const const_list_iterator<P, V> &it) const { return (_ptr == it._ptr); }
	const V		&operator*() const { return (*(this->_ptr->value)); }
	const V		*operator->() const { return (this->_ptr->value); }

	const_list_iterator<P, V>		&operator++() { _ptr = _ptr->next; return (*this); }
	const_list_iterator<P, V>		&operator--() { _ptr = _ptr->prev; return (*this); }

	const_list_iterator<P, V>		operator++(int) {
		list_iterator<P, V>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}

	const_list_iterator<P, V>		operator--(int) {
		list_iterator<P, V>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}
};

#endif
