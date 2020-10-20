/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator_list.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:39:34 by imicah            #+#    #+#             */
/*   Updated: 2020/10/20 16:49:13 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Iterator_hpp
# define Iterator_hpp

#include <iostream>
# include <iterator>

template<class T>
class	IteratorList : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*		_ptr;

public:
	IteratorList(T *p = 0) : _ptr(p) { };
	IteratorList(const IteratorList<T> &it) : _ptr(it._ptr) { };
	~IteratorList() { };

	IteratorList<T>		&operator=(const IteratorList<T> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	};

	bool				operator!=(const IteratorList<T> &it) const { return (_ptr != it._ptr); };
	bool				operator==(const IteratorList<T> &it) const { return (_ptr == it._ptr); };
	T					&operator*() { return (_ptr->value); };

	IteratorList<T>		&operator++() {
		_ptr = _ptr->next;
		return (*this);
	};

	IteratorList<T>		&operator--() {
		_ptr = _ptr->prev;
		return (*this);
	};
};

#endif
