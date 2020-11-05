/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_map_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:17:45 by imicah            #+#    #+#             */
/*   Updated: 2020/11/04 14:55:21 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_REVERSE_MAP_ITERATOR_HPP
# define FT_CONTAINERS_REVERSE_MAP_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>

template<class T, class U>
class	ft::reverse_map_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
	friend class ft::map<class Key, class Value>;
private:
	T*		_ptr;

public:
	reverse_map_iterator(T *ptr = 0) : _ptr(ptr) { }
	reverse_map_iterator(const reverse_map_iterator<T, U> &it) : _ptr(it._ptr) { }
	~reverse_map_iterator() { }

	reverse_map_iterator<T, U>	&operator=(const reverse_map_iterator<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool		operator!=(const reverse_map_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const reverse_map_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	U			&operator*() const { return (*_ptr->_value); }
	U			*operator->() const { return (_ptr->_value); }

	reverse_map_iterator<T, U>		&operator--() {
		if (_ptr->_right) {
			_ptr = _ptr->_right;
			while (_ptr->_left)
				_ptr = _ptr->_left;
		}
		else {
			T*		y = _ptr->_parent;
			while (_ptr == y->_right) {
				_ptr = y;
				y = y->_parent;
			}
			if (_ptr->_right != y)
				_ptr = y;
		}
		return (*this);
	}

	reverse_map_iterator<T, U>		operator--(int) {
		reverse_map_iterator<T, U>		temp(_ptr);

		++temp;
		return (temp);
	}

	reverse_map_iterator<T, U>		&operator++() {
		if (_ptr->_color == true && _ptr->_parent->_parent == _ptr)
			_ptr = _ptr->_right;
		else if (_ptr->_left) {
			T* x = _ptr->_left;
			while (x->_right)
				x = x->_right;
			_ptr = x;
		}
		else {
			T* x = _ptr->_parent;
			while (_ptr == x->_left) {
				_ptr = x;
				x = x->_parent;
			}
			_ptr = x;
		}
		return (*this);
	}

	reverse_map_iterator<T, U>		operator++(int) {
		reverse_map_iterator<T, U>		temp(_ptr);

		--temp;
		return (temp);
	}
};

template<class T, class U>
class	ft::const_reverse_map_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
	friend class ft::map<class Key, class Value>;
private:
	T*		_ptr;

public:
	const_reverse_map_iterator(T *ptr = 0) : _ptr(ptr) { }
	const_reverse_map_iterator(const const_reverse_map_iterator<T, U> &it) : _ptr(it._ptr) { }
	const_reverse_map_iterator(const reverse_map_iterator<T, U> &it) : _ptr(it._get_ptr()) { }
	~const_reverse_map_iterator() { }

	const_reverse_map_iterator<T, U>	&operator=(const const_reverse_map_iterator<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	const_reverse_map_iterator<T, U>	&operator=(const reverse_map_iterator<T, U> &it) {
		_ptr = it._get_ptr();
		return (*this);
	}

	bool		operator!=(const const_reverse_map_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool		operator==(const const_reverse_map_iterator<T, U> &it) const { return (_ptr == it._ptr); }
	U			&operator*() const { return (*_ptr->_value); }
	U			*operator->() const { return (_ptr->_value); }

	const_reverse_map_iterator<T, U>		&operator--() {
		if (_ptr->_right) {
			_ptr = _ptr->_right;
			while (_ptr->_left)
				_ptr = _ptr->_left;
		}
		else {
			T*		y = _ptr->_parent;
			while (_ptr == y->_right) {
				_ptr = y;
				y = y->_parent;
			}
			if (_ptr->_right != y)
				_ptr = y;
		}
		return (*this);
	}

	const_reverse_map_iterator<T, U>		operator--(int) {
		const_reverse_map_iterator<T, U>		temp(_ptr);

		++temp;
		return (temp);
	}

	const_reverse_map_iterator<T, U>		&operator++() {
		if (_ptr->_color == true && _ptr->_parent->_parent == _ptr)
			_ptr = _ptr->_right;
		else if (_ptr->_left) {
			T* x = _ptr->_left;
			while (x->_right)
				x = x->_right;
			_ptr = x;
		}
		else {
			T* x = _ptr->_parent;
			while (_ptr == x->_left) {
				_ptr = x;
				x = x->_parent;
			}
			_ptr = x;
		}
		return (*this);
	}

	const_reverse_map_iterator<T, U>		operator++(int) {
		const_reverse_map_iterator<T, U>		temp(_ptr);

		--temp;
		return (temp);
	}
};

#endif //FT_CONTAINERS_REVERSE_MAP_ITERATOR_HPP
