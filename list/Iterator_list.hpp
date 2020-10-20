/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator_list.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:39:34 by imicah            #+#    #+#             */
/*   Updated: 2020/10/20 12:41:40 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Iterator_hpp
# define Iterator_hpp

#include <iostream>

template<class T>
class	IteratorList : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*		p;

public:
	IteratorList(T *p);
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
IteratorList<T>::IteratorList(T *p) : p(p) { }

template <class T>
IteratorList<T>::IteratorList(const IteratorList<T> &iterator) : p(iterator.p) { }

template <class T>
IteratorList<T>::~IteratorList() { }

template<class T>
IteratorList<T>		&IteratorList<T>::operator=(const IteratorList<T> &iterator) {
	if (this != &iterator)
		p = iterator.p;
	return (*this);
}

template<class T>
bool	IteratorList<T>::operator==(const IteratorList<T> &iterator) const { return (p == iterator.p); }

template<class T>
bool	IteratorList<T>::operator!=(const IteratorList<T> &iterator) const { return (p != iterator.p); }

template<class T>
IteratorList<T>		&IteratorList<T>::operator++() {
	p++;
	return (*this);
}

template<class T>
IteratorList<T>		&IteratorList<T>::operator--() {
	p--;
	return (*this);
}

template<class T>
T	&IteratorList<T>::operator*() { return (*p); }

#endif
