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


#ifndef FT_CONTAINERS_REVERSE_BIDIRECTIONAL_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_BIDIRECTIONAL_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>

template<class T, class U>
class	rev_bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
protected:
	T*		_ptr;

public:
	rev_bidirectional_iterator(T *p = 0) : _ptr(p) { }
	rev_bidirectional_iterator(const rev_bidirectional_iterator<T, U> &it) : _ptr(it._ptr) { }
	~rev_bidirectional_iterator() { }

	rev_bidirectional_iterator<T, U>		&operator=(const rev_bidirectional_iterator<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool	operator!=(const rev_bidirectional_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool	operator==(const rev_bidirectional_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	U		&operator*() const { return (*_ptr->value); };
	U		*operator->() const { return (this->_ptr->value); }

	rev_bidirectional_iterator<T, U>		&operator++() { _ptr = _ptr->prev; return (*this); }
	rev_bidirectional_iterator<T, U>		&operator--() { _ptr = _ptr->next; return (*this); }

	rev_bidirectional_iterator<T, U>		operator++(int) {
		rev_bidirectional_iterator<T, U>	temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}

	rev_bidirectional_iterator<T, U>		operator--(int) {
		rev_bidirectional_iterator<T, U>	temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}

	T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше
};

template<class T, class U>
class	const_rev_bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*		_ptr;

public:
	const_rev_bidirectional_iterator(T *p = 0) : _ptr(p) { }
	const_rev_bidirectional_iterator(const rev_bidirectional_iterator<T, U> &it) : _ptr(it._get_ptr()) { }
	~const_rev_bidirectional_iterator() { }

	const_rev_bidirectional_iterator<T, U>		&operator=(const rev_bidirectional_iterator<T, U> &it) {
		_ptr = it._get_ptr();
		return (*this);
	}

	const_rev_bidirectional_iterator<T, U>		&operator=(const const_rev_bidirectional_iterator<T, U> &it) {
		if (this != &it)
			_ptr - it._ptr;
		return (*this);
	}

	bool		operator!=(const const_rev_bidirectional_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const const_rev_bidirectional_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	const U		&operator*() const { return (*(this->_ptr->value)); }
	const U		*operator->() const { return (this->_ptr->value); }

	const_rev_bidirectional_iterator<T, U>		&operator++() { _ptr = _ptr->prev; return (*this); }
	const_rev_bidirectional_iterator<T, U>		&operator--() { _ptr = _ptr->next; return (*this); }

	const_rev_bidirectional_iterator<T, U>		operator++(int) {
		const_rev_bidirectional_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}

	const_rev_bidirectional_iterator<T, U>		operator--(int) {
		bidirectional_iterator<T, U>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}
};

#endif
