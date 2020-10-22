/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator_list.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:39:34 by imicah            #+#    #+#             */
/*   Updated: 2020/10/22 20:00:47 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Iterator_hpp
# define Iterator_hpp

# include <iostream>
# include <iterator>

template<class T, class U>
class	IteratorList : public std::iterator<std::bidirectional_iterator_tag, T>
{
protected:
	T*		_ptr;

public:
	IteratorList(T *p = 0) : _ptr(p) { }
	IteratorList(const IteratorList<T, U> &it) : _ptr(it._ptr) { }
	~IteratorList() { }

	virtual IteratorList<T, U>		&operator=(const IteratorList<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool		operator!=(const IteratorList<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const IteratorList<T, U> &it) const { return (_ptr == it._ptr); }
	U			&operator*() const { return (*_ptr->value); }

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
};

template<class T, class U>
class	ConstIteratorList : public IteratorList<T, U>
{
public:
	ConstIteratorList(T *p = 0) : IteratorList<T,U>(p) { }
	ConstIteratorList(const IteratorList<T, U> &it) : IteratorList<T, U>(it) { }

	~ConstIteratorList() { }

	const U		&operator*() const { return (*(this->_ptr->value)); }
};

template<class T, class U>
class	RevIteratorList : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
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
};

template<class T, class U>
class	ConstRevIteratorList : public RevIteratorList<T, U>
{
public:
	ConstRevIteratorList(T *p = 0) : RevIteratorList<T,U>(p) { }
	ConstRevIteratorList(const RevIteratorList<T, U> &it) : RevIteratorList<T,U>(it) { }
	~ConstRevIteratorList() { }

	const U		&operator*() const { return (*(this->_ptr->value)); };
};

#endif
