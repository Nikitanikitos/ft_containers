/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:29:43 by imicah            #+#    #+#             */
/*   Updated: 2020/11/03 18:17:01 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_MAP_ITERATOR_HPP
# define FT_CONTAINERS_MAP_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>
# include "tree.hpp"

template<class T, class U>
class	map_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	typedef typename ft::Tree<bool, bool>		_tree;

	T*		_ptr;

public:
	map_iterator(T *ptr = 0) : _ptr(ptr) { }
	map_iterator(const map_iterator<T, U> &it) : _ptr(it._ptr) { }
	~map_iterator() { }

	map_iterator<T, U>	&operator=(const map_iterator<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool		operator!=(const map_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const map_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	U			&operator*() const { return (*_ptr->_value); }
	U			*operator->() const { return (_ptr->_value); }

	map_iterator<T, U>		&operator++() {
		if (_ptr->_right) {
			_ptr = _ptr->_right;
			while (_ptr->_left)
				_ptr = _ptr->_left;
		}
		else {
			T	*y = _ptr->_parent;
			while (_ptr == y->_right) {
				_ptr = y;
				y = y->_parent;
			}
			_ptr = y;
		}
		return (*this);
	}

	map_iterator<T, U>		operator++(int) {
		map_iterator<T, U>		temp(_ptr);

		++temp;
		return (temp);
	}

	map_iterator<T, U>		&operator--() {
		if (_ptr->_color == true && _ptr->_parent->_parent == _ptr)
			_ptr = _ptr->_right;
		else if (_ptr->_left && _ptr->_left->_left) {
			T* x = _ptr->_left;
			while (_ptr->_right && x->_right->_right)
				x = x->_right;
			_ptr = x;
		}
		else {
			T* x = _ptr->_parent;
			while (_ptr == x->_left && x->_left->_left) {
				_ptr = x;
				x = x->_parent;
			}
			_ptr = x;
		}
		return (*this);
	}

	map_iterator<T, U>		operator--(int) {
		map_iterator<T, U>		temp(_ptr);

		--temp;
		return (temp);
	}

	T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше

};

template<class T, class U>
class	const_map_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T*		_ptr;

public:
	const_map_iterator(T *ptr = 0) : _ptr(ptr) { }
	const_map_iterator(const const_map_iterator<T, U> &it) : _ptr(it._ptr) { }
//	const_map_iterator(const map_iterator<T, U> &it) : _ptr(it._get_ptr()) { }
	~const_map_iterator() { }

	const_map_iterator<T, U>	&operator=(const const_map_iterator<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

//	const_map_iterator<T, U>	&operator=(const map_iterator<T, U> &it) {
//		_ptr = it._get_ptr();
//		return (*this);
//	}

	bool		operator!=(const const_map_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const const_map_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	U			&operator*() const { return (*_ptr->_value); }
	U			*operator->() const { return (_ptr->_value); }

	const_map_iterator<T, U>		&operator++() {
		if (_ptr->_right) {
			_ptr = _ptr->_right;
			while (_ptr->_left)
				_ptr = _ptr->_left;
		}
		else {
			T	*y = _ptr->_parent;
			while (_ptr == y->_right) {
				_ptr = y;
				y = y->_parent;
			}
//			if (_ptr->_parent != y)
				_ptr = y;
		}
		return (*this);
	}

	const_map_iterator<T, U>		operator++(int) {
		const_map_iterator<T, U>		temp(_ptr);

		++temp;
		return (temp);
	}

	const_map_iterator<T, U>		&operator--() {
		if (_ptr->color == true && _ptr->_parent->_parent == _ptr)
			_ptr = _ptr->_right;
		else if (_ptr->_left && _ptr->_left->_left) {
			T* x = _ptr->_left;
			while (_ptr->_right && x->_right->_right)
				x = x->_right;
			_ptr = x;
		}
		else {
			T* x = _ptr->_parent;
			while (_ptr == x->_left && x->_left->_left) {
				_ptr = x;
				x = x->_parent;
			}
			_ptr = x;
		}
		return (*this);
	}

	const_map_iterator<T, U>		operator--(int) {
		const_map_iterator<T, U>		temp(_ptr);

		--temp;
		return (temp);
	}
};

#endif //FT_CONTAINERS_MAP_ITERATOR_HPP
