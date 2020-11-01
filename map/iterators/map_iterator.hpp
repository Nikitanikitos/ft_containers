/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:29:43 by imicah            #+#    #+#             */
/*   Updated: 2020/10/30 19:30:22 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_MAP_ITERATOR_HPP
# define FT_CONTAINERS_MAP_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>

template<class T, class U>
class	map_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
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
	U			&operator*() const { return (*_ptr->value); }
	U			*operator->() const { return (_ptr->value); }

	map_iterator<T, U>		&operator++() {
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
			if (_ptr->right != y)
				_ptr = y;
		}
		return (_ptr);
	}

	map_iterator<T, U>		&operator--() {
		if (_ptr->color == true && _ptr->parent->parent == _ptr)
			_ptr = _ptr->right;
		else if (_ptr->left != 0) {
			T* x = _ptr->left;
			while (x->right != 0)
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
		return (_ptr);

	}
};

#endif //FT_CONTAINERS_MAP_ITERATOR_HPP
