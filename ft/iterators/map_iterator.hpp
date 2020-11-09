/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:29:43 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 14:24:05 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_MAP_ITERATOR_HPP
# define FT_CONTAINERS_MAP_ITERATOR_HPP

# include <iterator>

template<class T, class U>
class	ft::map_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
	template < class Key, class Value, class Compare, class Alloc>
	friend class	map;
	friend class	const_map_iterator<T, U>;

private:
	T*	_ptr;

public:
	explicit map_iterator(T *ptr = 0) : _ptr(ptr) { }
	map_iterator(const map_iterator<T, U> &it) : _ptr(it._ptr) { }
	~map_iterator() { }

	map_iterator<T, U>&		operator=(const map_iterator<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	bool	operator!=(const map_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool	operator==(const map_iterator<T, U> &it) const { return (_ptr == it._ptr); }

	U&		operator*() const { return (*_ptr->_value); }
	U*		operator->() const { return (_ptr->_value); }

	map_iterator<T, U>&		operator++() {
		if (_ptr->_right) {
			_ptr = _ptr->_right;
			while (_ptr->_left)
				_ptr = _ptr->_left;
		} else {
			T *y = _ptr->_parent;
			while (_ptr == y->_right) {
				_ptr = y;
				y = y->_parent;
			}
			if (_ptr->_right != y)
				_ptr = y;
		}
		return (*this);
	}

	map_iterator<T, U>		operator++(int) {
		map_iterator<T, U> temp(_ptr);

		++temp;
		return (temp);
	}

	map_iterator<T, U>&		operator--() {
		if (_ptr->_color == true && _ptr->_parent->_parent == _ptr)
			_ptr = _ptr->_right;
		else if (_ptr->_left) {
			T *x = _ptr->_left;
			while (x->_right)
				x = x->_right;
			_ptr = x;
		} else {
			T *x = _ptr->_parent;
			while (_ptr == x->_left) {
				_ptr = x;
				x = x->_parent;
			}
			_ptr = x;
		}
		return (*this);
	}

	map_iterator<T, U>		operator--(int) {
		map_iterator<T, U> temp(_ptr);

		--temp;
		return (temp);
	}
};

template<class T, class U>
class	ft::const_map_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
	template < class Key, class Value, class Compare, class Alloc>
	friend class	map;

private:
	T*		_ptr;

public:
	explicit const_map_iterator(T *ptr = 0) : _ptr(ptr) { }
	const_map_iterator(const const_map_iterator<T, U> &it) : _ptr(it._ptr) { }
	const_map_iterator(const map_iterator<T, U> &it) : _ptr(it._ptr) { }
	~const_map_iterator() { }

	const_map_iterator<T, U>&	operator=(const const_map_iterator<T, U> &it) {
		if (this != &it)
			_ptr = it._ptr;
		return (*this);
	}

	const_map_iterator<T, U>&	operator=(const map_iterator<T, U> &it) {
		_ptr = it._ptr;
		return (*this);
	}

	bool	operator!=(const const_map_iterator<T, U> &it) const { return (_ptr != it._ptr); }
	bool	operator==(const const_map_iterator<T, U> &it) const { return (_ptr == it._ptr); }

	const U&	operator*() const { return (*_ptr->_value); }
	const U*	operator->() const { return (_ptr->_value); }

	const_map_iterator<T, U>&		operator++() {
		if (_ptr->_right) {
			_ptr = _ptr->_right;
			while (_ptr->_left)
				_ptr = _ptr->_left;
		} else {
			T *y = _ptr->_parent;
			while (_ptr == y->_right) {
				_ptr = y;
				y = y->_parent;
			}
			if (_ptr->_right != y)
				_ptr = y;
		}
		return (*this);
	}

	const_map_iterator<T, U>		operator++(int) {
		const_map_iterator<T, U> temp(_ptr);

		++temp;
		return (temp);
	}

	const_map_iterator<T, U>&		operator--() {
		if (_ptr->_color == true && _ptr->_parent->_parent == _ptr)
			_ptr = _ptr->_right;
		else if (_ptr->_left) {
			T *x = _ptr->_left;
			while (x->_right)
				x = x->_right;
			_ptr = x;
		} else {
			T *x = _ptr->_parent;
			while (_ptr == x->_left) {
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
