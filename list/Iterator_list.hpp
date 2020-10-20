/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator_list.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:39:34 by imicah            #+#    #+#             */
/*   Updated: 2020/10/20 15:56:54 by imicah           ###   ########.fr       */
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
	IteratorList(T *p = 0);
	IteratorList(const IteratorList<T> &iterator);
	~IteratorList();

	IteratorList<T>		&operator=(const IteratorList<T> &);

	bool				operator!=(const IteratorList<T> &) const;
	bool				operator==(const IteratorList<T> &) const;
	IteratorList<T>		&operator++();
	IteratorList<T>		&operator--();
	T					&operator*();
};

template <class T>
IteratorList<T>::IteratorList(T *p) : _ptr(p) { }

template <class T>
IteratorList<T>::IteratorList(const IteratorList<T> &iterator) : _ptr(iterator._ptr) { }

template <class T>
IteratorList<T>::~IteratorList() { }

template<class T>
IteratorList<T>		&IteratorList<T>::operator=(const IteratorList<T> &iterator) {
	if (this != &iterator)
		_ptr = iterator._ptr;
	return (*this);
}

template<class T>
bool	IteratorList<T>::operator==(const IteratorList<T> &iterator) const { return (_ptr == iterator._ptr); }

template<class T>
bool	IteratorList<T>::operator!=(const IteratorList<T> &iterator) const { return (_ptr != iterator._ptr); }

template<class T>
IteratorList<T>		&IteratorList<T>::operator++() {
	_ptr = _ptr->next;
	return (*this);
}

template<class T>
IteratorList<T>		&IteratorList<T>::operator--() {
	_ptr = _ptr->prev;
	return (*this);
}

template<class T>
T	&IteratorList<T>::operator*() { return (_ptr->value); }

#endif
