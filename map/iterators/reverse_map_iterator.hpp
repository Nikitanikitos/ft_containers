/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_map_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:17:45 by imicah            #+#    #+#             */
/*   Updated: 2020/11/01 17:22:51 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_REVERSE_MAP_ITERATOR_HPP
# define FT_CONTAINERS_REVERSE_MAP_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>

template<class T, class U>
class	reverse_map_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
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
	U			&operator*() const { return (*_ptr->value); }
	U			*operator->() const { return (_ptr->value); }

	reverse_map_iterator<T, U>		&operator--() {
		if (_ptr->right->right) {
			_ptr = _ptr->right;
			while (_ptr->left->left)
				_ptr = _ptr->left;
		}
		else {
			T	*y = _ptr->parent;
			while (_ptr == y->right) {
				_ptr = y;
				y = y->parent;
			}
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
		if (_ptr->color == true && _ptr->parent->parent == _ptr)
			_ptr = _ptr->right;
		else if (_ptr->left && _ptr->left->left) {
			T* x = _ptr->left;
			while (_ptr->right && x->right->right)
				x = x->right;
			_ptr = x;
		}
		else {
			T* x = _ptr->parent;
			while (_ptr == x->left) {
				_ptr = x;
				x = x->parent;
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

	T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше
};

template<class T, class U>
class	const_reverse_map_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
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
	U			&operator*() const { return (*_ptr->value); }
	U			*operator->() const { return (_ptr->value); }

	const_reverse_map_iterator<T, U>		&operator--() {
		if (_ptr->right->right) {
			_ptr = _ptr->right;
			while (_ptr->left->left)
				_ptr = _ptr->left;
		}
		else {
			T	*y = _ptr->parent;
			while (_ptr == y->right) {
				_ptr = y;
				y = y->parent;
			}
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
		if (_ptr->color == true && _ptr->parent->parent == _ptr)
			_ptr = _ptr->right;
		else if (_ptr->left && _ptr->left->left) {
			T* x = _ptr->left;
			while (_ptr->right && x->right->right)
				x = x->right;
			_ptr = x;
		}
		else {
			T* x = _ptr->parent;
			while (_ptr == x->left && x->left->left) {
				_ptr = x;
				x = x->parent;
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

	T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше
};

#endif //FT_CONTAINERS_REVERSE_MAP_ITERATOR_HPP
