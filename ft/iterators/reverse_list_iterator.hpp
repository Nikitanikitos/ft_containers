/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_list_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:37:34 by imicah            #+#    #+#             */
/*   Updated: 2020/11/08 12:59:41 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_REVERSE_LIST_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_LIST_ITERATOR_HPP

# include <iterator>
# include "ft.hpp"

template<class P, class V>
class	ft::reverse_list_iterator : public std::iterator<std::bidirectional_iterator_tag, P>
{
	template<class T, class Alloc>
	friend class	list;
	friend class	const_reverse_list_iterator<P, V>;

private:
	P*		_ptr;

public:
	explicit reverse_list_iterator(P *p = 0) : _ptr(p) { }
	reverse_list_iterator(const reverse_list_iterator<P, V> &it) : _ptr(it._ptr) { }
	~reverse_list_iterator() { }

	reverse_list_iterator<P, V>&	operator=(const reverse_list_iterator<P, V> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool	operator!=(const reverse_list_iterator<P, V> &it) const { return (_ptr != it._ptr); }
	bool	operator==(const reverse_list_iterator<P, V> &it) const { return (_ptr == it._ptr); }
	V&		operator*() const { return (*_ptr->value); };
	V*		operator->() const { return (_ptr->value); }

	reverse_list_iterator<P, V>&	operator++() { _ptr = _ptr->prev; return (*this); }
	reverse_list_iterator<P, V>&	operator--() { _ptr = _ptr->next; return (*this); }

	reverse_list_iterator<P, V>		operator++(int) {
		reverse_list_iterator<P, V>	temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}

	reverse_list_iterator<P, V>		operator--(int) {
		reverse_list_iterator<P, V>	temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}
};

template<class P, class V>
class	ft::const_reverse_list_iterator : public std::iterator<std::bidirectional_iterator_tag, P>
{
	template<class T, class Alloc>
	friend class	list;

private:
	P*		_ptr;

public:
	explicit const_reverse_list_iterator(P *p = 0) : _ptr(p) { }
	const_reverse_list_iterator(const const_reverse_list_iterator<P, V> &it) : _ptr(it._ptr) { }
	const_reverse_list_iterator(const reverse_list_iterator<P, V> &it) : _ptr(it._ptr) { }
	~const_reverse_list_iterator() { }

	const_reverse_list_iterator<P, V>&		operator=(const reverse_list_iterator<P, V> &it) {
		_ptr = it._ptr;
		return (*this);
	}

	const_reverse_list_iterator<P, V>&		operator=(const const_reverse_list_iterator<P, V> &it) {
		if (this != &it)
			_ptr - it._ptr;
		return (*this);
	}

	bool		operator!=(const const_reverse_list_iterator<P, V> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const const_reverse_list_iterator<P, V> &it) const { return (_ptr == it._ptr); }
	const V&	operator*() const { return (*(this->_ptr->value)); }
	const V*	operator->() const { return (this->_ptr->value); }

	const_reverse_list_iterator<P, V>&		operator++() { _ptr = _ptr->prev; return (*this); }
	const_reverse_list_iterator<P, V>&		operator--() { _ptr = _ptr->next; return (*this); }

	const_reverse_list_iterator<P, V>		operator++(int) {
		const_reverse_list_iterator<P, V>		temp(_ptr);

		_ptr = _ptr->prev;
		return (temp);
	}

	const_reverse_list_iterator<P, V>		operator--(int) {
		const_reverse_list_iterator<P, V>		temp(_ptr);

		_ptr = _ptr->next;
		return (temp);
	}
};

#endif
