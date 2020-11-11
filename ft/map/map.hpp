/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:09:48 by imicah            #+#    #+#             */
/*   Updated: 2020/11/11 16:57:47 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_MAP_HPP
# define FT_CONTAINERS_MAP_HPP

# include <utility>
# include <limits>
# include "queue.hpp"
# include "tree.hpp"
# include "ft.hpp"

template < class Key, class Value, class Compare, class Alloc>
class ft::map
{
private:
	typedef				ft::tree<Key, Value, Compare, Alloc>					_tree_type;
	typedef typename	_tree_type::_node_t										_node_type;

	_tree_type 			_tree;

public:
	typedef				Key														key_type;
	typedef				Value													mapped_type;
	typedef				std::pair<const key_type, mapped_type>					value_type;
	typedef				Compare													key_compare;
	typedef				Compare													value_compare;
	typedef				Alloc													allocator_type;
	typedef typename	allocator_type::reference								reference;
	typedef typename	allocator_type::const_reference							const_reference;
	typedef typename	allocator_type::pointer									pointer;
	typedef typename	allocator_type::const_pointer							const_pointer;
	typedef				std::ptrdiff_t											difference_type;
	typedef				std::size_t												size_type;

private:
	class	_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	public:
		_node_type*		_ptr;

	public:
		class	_const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
		private:
			_node_type*		_ptr;

		public:
			explicit _const_iterator(_node_type* ptr = 0) : _ptr(ptr) { }
			_const_iterator(const _const_iterator& it) : _ptr(it._ptr) { }
			_const_iterator(const _iterator& it) : _ptr(it._ptr) { }
			~_const_iterator() { }

			_const_iterator&	operator=(const _const_iterator& it) {
				if (this != &it)
					_ptr = it._ptr;
				return (*this);
			}

			_const_iterator&	operator=(const _iterator& it) {
				_ptr = it._ptr;
				return (*this);
			}

			bool	operator!=(const _const_iterator& it) const { return (_ptr != it._ptr); }
			bool	operator==(const _const_iterator& it) const { return (_ptr == it._ptr); }

			const value_type&	operator*() const { return (*_ptr->_value); }
			const value_type*	operator->() const { return (_ptr->_value); }

			_const_iterator&		operator++() {
				if (_ptr->_right) {
					_ptr = _ptr->_right;
					while (_ptr->_left)
						_ptr = _ptr->_left;
				} else {
					_node_type* y = _ptr->_parent;
					while (_ptr == y->_right) {
						_ptr = y;
						y = y->_parent;
					}
					if (_ptr->_right != y)
						_ptr = y;
				}
				return (*this);
			}

			_const_iterator		operator++(int) {
				_const_iterator		temp(_ptr);

				++temp;
				return (temp);
			}

			_const_iterator&	operator--() {
				if (_ptr->_color == true && _ptr->_parent->_parent == _ptr)
					_ptr = _ptr->_right;
				else if (_ptr->_left) {
					_node_type* x = _ptr->_left;
					while (x->_right)
						x = x->_right;
					_ptr = x;
				} else {
					_node_type* x = _ptr->_parent;
					while (_ptr == x->_left) {
						_ptr = x;
						x = x->_parent;
					}
					_ptr = x;
				}
				return (*this);
			}

			_const_iterator		operator--(int) {
				_const_iterator		temp(_ptr);

				--temp;
				return (temp);
			}
		};

		explicit _iterator(_node_type* ptr = 0) : _ptr(ptr) { }
		_iterator(const _iterator& it) : _ptr(it._ptr) { }
		~_iterator() { }

		_iterator&		operator=(const _iterator& it) {
			if (this != &it)
				_ptr = it._ptr;
			return (*this);
		}

		bool	operator!=(const _iterator& it) const { return (_ptr != it._ptr); }
		bool	operator==(const _iterator& it) const { return (_ptr == it._ptr); }

		value_type&		operator*() const { return (*_ptr->_value); }
		value_type*		operator->() const { return (_ptr->_value); }

		_iterator&		operator++() {
			if (_ptr->_right) {
				_ptr = _ptr->_right;
				while (_ptr->_left)
					_ptr = _ptr->_left;
			} else {
				_node_type* y = _ptr->_parent;
				while (_ptr == y->_right) {
					_ptr = y;
					y = y->_parent;
				}
				if (_ptr->_right != y)
					_ptr = y;
			}
			return (*this);
		}

		_iterator		operator++(int) {
			_iterator	temp(_ptr);

			++temp;
			return (temp);
		}

		_iterator&		operator--() {
			if (_ptr->_color == true && _ptr->_parent->_parent == _ptr)
				_ptr = _ptr->_right;
			else if (_ptr->_left) {
				_node_type* x = _ptr->_left;
				while (x->_right)
					x = x->_right;
				_ptr = x;
			} else {
				_node_type* x = _ptr->_parent;
				while (_ptr == x->_left) {
					_ptr = x;
					x = x->_parent;
				}
				_ptr = x;
			}
			return (*this);
		}

		_iterator		operator--(int) {
			_iterator	temp(_ptr);

			--temp;
			return (temp);
		}
	};

	class	_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	private:
		_node_type*		_ptr;

	public:
		class	_const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
		private:
			_node_type*		_ptr;

		public:

			_const_reverse_iterator(_node_type* ptr = 0) : _ptr(ptr) { }
			_const_reverse_iterator(const _const_reverse_iterator& it) : _ptr(it._ptr) { }
			_const_reverse_iterator(const _reverse_iterator& it) : _ptr(it._ptr) { }
			~_const_reverse_iterator() { }

			_const_reverse_iterator&		operator=(const _const_reverse_iterator& it) {
				if (this != &it)
					_ptr = it._ptr;
				return (*this);
			}

			_const_reverse_iterator&		operator=(const _reverse_iterator& it) {
				_ptr = it._ptr;
				return (*this);
			}

			bool		operator!=(const _const_reverse_iterator& it) const { return (_ptr != it._ptr); }
			bool		operator==(const _const_reverse_iterator& it) const { return (_ptr == it._ptr); }

			const value_type&	operator*() const { return (*_ptr->_value); }
			const value_type*	operator->() const { return (_ptr->_value); }

			_const_reverse_iterator&		operator--() {
				if (_ptr->_right) {
					_ptr = _ptr->_right;
					while (_ptr->_left)
						_ptr = _ptr->_left;
				}
				else {
					_node_type*	y = _ptr->_parent;
					while (_ptr == y->_right) {
						_ptr = y;
						y = y->_parent;
					}
					if (_ptr->_right != y)
						_ptr = y;
				}
				return (*this);
			}

			_const_reverse_iterator		operator--(int) {
				_const_reverse_iterator		temp(_ptr);

				++temp;
				return (temp);
			}

			_const_reverse_iterator&		operator++() {
				if (_ptr->_color == true && _ptr->_parent->_parent == _ptr)
					_ptr = _ptr->_right;
				else if (_ptr->_left) {
					_node_type*	x = _ptr->_left;
					while (x->_right)
						x = x->_right;
					_ptr = x;
				}
				else {
					_node_type*	x = _ptr->_parent;
					while (_ptr == x->_left) {
						_ptr = x;
						x = x->_parent;
					}
					_ptr = x;
				}
				return (*this);
			}

			_const_reverse_iterator		operator++(int) {
				_const_reverse_iterator		temp(_ptr);

				--temp;
				return (temp);
			}
		};

		_reverse_iterator(_node_type* ptr = 0) : _ptr(ptr) { }
		_reverse_iterator(const _reverse_iterator& it) : _ptr(it._ptr) { }
		~_reverse_iterator() { }

		_reverse_iterator& operator=(const _reverse_iterator& it) {
			if (this != &it)
				_ptr = it._ptr;
			return (*this);
		}

		bool		operator!=(const _reverse_iterator& it) const { return (_ptr != it._ptr); }
		bool		operator==(const _reverse_iterator& it) const { return (_ptr == it._ptr); }

		value_type&			operator*() const { return (*_ptr->_value); }
		value_type*			operator->() const { return (_ptr->_value); }

		_reverse_iterator&		operator--() {
			if (_ptr->_right) {
				_ptr = _ptr->_right;
				while (_ptr->_left)
					_ptr = _ptr->_left;
			}
			else {
				_node_type* y = _ptr->_parent;
				while (_ptr == y->_right) {
					_ptr = y;
					y = y->_parent;
				}
				if (_ptr->_right != y)
					_ptr = y;
			}
			return (*this);
		}

		_reverse_iterator		operator--(int) {
			_reverse_iterator		temp(_ptr);

			++temp;
			return (temp);
		}

		_reverse_iterator&		operator++() {
			if (_ptr->_color == true && _ptr->_parent->_parent == _ptr)
				_ptr = _ptr->_right;
			else if (_ptr->_left) {
				_node_type* x = _ptr->_left;
				while (x->_right)
					x = x->_right;
				_ptr = x;
			}
			else {
				_node_type* x = _ptr->_parent;
				while (_ptr == x->_left) {
					_ptr = x;
					x = x->_parent;
				}
				_ptr = x;
			}
			return (*this);
		}

		_reverse_iterator		operator++(int) {
			_reverse_iterator		temp(_ptr);

			--temp;
			return (temp);
		}
	};

public:
	typedef 			_iterator												iterator;
	typedef				typename _iterator::_const_iterator						const_iterator;
	typedef				_reverse_iterator										reverse_iterator;
	typedef				typename _reverse_iterator::_const_reverse_iterator		const_reverse_iterator;

	explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
		_tree._compare = comp;
		_tree._alloc = alloc;
		_tree._empty_tree_init();
	}

	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type(),
									typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0) {
		_tree._compare = comp;
		_tree._alloc = alloc;
		_tree._empty_tree_init();
		for (; first != last; ++first)
			insert(*first);
	}

	map(const map& x) {
		_tree._empty_tree_init();
		for (const_iterator	it = x.begin(); it != x.end(); ++it)
			insert(*it);
	}

	~map() {
			clear();
	}

	map&	operator=(const map& x) {
		if (this == &x)
			return (*this);
		clear();
		_tree._size = 0;
		for (const_iterator	it = x.begin(); it != x.end(); ++it)
			insert(*it);
		return (*this);
	}

	iterator				begin() { return (iterator(_tree._first_node->_parent)); }
	const_iterator			begin() const { return (const_iterator(_tree._first_node->_parent)); }
	iterator				end() { return (iterator(_tree._last_node)); }
	const_iterator			end() const { return (const_iterator(_tree._last_node)); }

	reverse_iterator		rbegin() { return (_tree._last_node->_parent); }
	const_reverse_iterator	rbegin() const { return (_tree._last_node->_parent); }
	reverse_iterator		rend() { return (_tree._first_node); }
	const_reverse_iterator	rend() const { return (_tree._first_node); }

	bool					empty() const { return (_tree._size == 0); }
	size_type				size() const { return (_tree._size); }
	size_type				max_size() const { return (std::numeric_limits<size_type>::max()); }

	mapped_type&			operator[](const key_type& k) {
		_node_type*	node = _tree._search(k, _tree._root);
		iterator	it;

		if (node == _tree._last_node || node == _tree._first_node || node == 0) {
			it = insert(std::make_pair(k, mapped_type())).first;
			node = it._ptr;
		}
		return (node->_value->second);
	}

	mapped_type&				at(const key_type& k) {
		_node_type*	node = _tree._search(k, _tree._root);

		if (node == _tree._last_node || node == _tree._first_node || node == 0)
			throw std::out_of_range("Out of range");
		return (node->_value->second);
	}

	const mapped_type&			at(const key_type& k) const {
		_node_type*	node = _search(k, _tree->_root);

		if (node == _tree._last_node || node == _tree._first_node || node == 0)
			throw std::out_of_range("Out of range");
		return (node->_value->second);
	}

	std::pair<iterator,bool>	insert(const value_type& val) {
		std::pair<_node_type*, bool>	pair;

		if (empty()) {
			_tree._create_root_node(val);
			pair = std::make_pair(_tree._root, true);
		}
		else {
			pair = _tree._put(_tree._root, val);
			_tree._root = pair.first;
		}
		_tree._size++;
		_tree._root->_parent = 0;
		_tree._root->_color = false;
		return (std::make_pair(find(val.first), pair.second));
	}

	iterator					insert(iterator position, const value_type& val) {
		(void )position;
		return (insert(val).first);
	}

	template <class InputIterator>
	void						insert(InputIterator first, InputIterator last,
								   typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0) {
		for (; first != last; ++first)
			insert(*first);
	}

	void						erase(iterator position) {
		_node_type*	node = position._ptr;
		erase(node->_value->first);
	}

	size_type					erase(const key_type& k) {
		if (k == _tree._last_node->_parent->_value->first)
			_tree._root = _tree._delete_max(_tree._root);
		else if (k == _tree._first_node->_parent->_value->first)
			_tree._root = _tree._delete_min(_tree._root);
		else
			_tree._root = _tree._delete(_tree._root, k);
		if (empty()) _tree._empty_nodes_init();
		else _tree._root->_color = false;
		return (1);
	}

	void						erase(iterator first, iterator last) {
		iterator	temp_it = first;

		for (; temp_it != last; ++temp_it) {
			temp_it = first;
			++temp_it;
			erase(first);
		}
	}

	void						swap(map& x) {
		std::swap(x._tree._root, _tree._root);
		std::swap(x._tree._first_node, _tree._first_node);
		std::swap(x._tree._last_node, _tree._last_node);
		std::swap(x._tree._first_node, _tree._first_node);
		std::swap(x._tree._last_node, _tree._last_node);
		std::swap(x._tree._alloc, _tree._alloc);
		std::swap(x._tree._alloc_rebind, _tree._alloc_rebind);
		std::swap(x._tree._size, _tree._size);
		std::swap(x._tree._compare, _tree._compare);
	}

	void						clear() {
		queue<_node_type*>	queue;
		_node_type*			node;

		if ((node = _tree._root))
			queue.push(node);
		while (!queue.empty()) {
			if (node->_right && node->_right != _tree._last_node)
				queue.push(node->_right);
			if (node->_left && node->_left != _tree._first_node)
				queue.push(node->_left);
			node = queue.front();
			_tree._destroy_node(node);
			queue.pop();
			node = queue.front();
		}
		_tree._empty_nodes_init();
	}

	key_compare					key_comp() const { return (_tree._compare); }
	value_compare				value_comp() const;

	iterator					find(const key_type& k) { return (iterator(_tree._search(k, _tree._root))); }
	const_iterator				find(const key_type& k) const { return (const_iterator(_tree._search(k, _tree._root))); }

	size_type					count(const key_type& k) const { return ((_search(k, _tree._root) != _tree._last_node) ? 1 : 0); }

	iterator					lower_bound(const key_type& k) {
		for (iterator it = begin(); it != end(); ++it)
			if (_tree._compare(k, it->first) || it->first == k)
				return (it);
		return (end());
	}

	const_iterator				lower_bound(const key_type& k) const {
		for (const_iterator	it = begin(); it != end(); ++it)
			if (_tree._compare(k, it->first) || it->first == k)
				return (it);
		return (end());
	}

	iterator					upper_bound(const key_type& k) {
		for (iterator it = begin(); it != end(); ++it)
			if (_tree._compare(k, it->first))
				return (it);
		return (end());
	}

	const_iterator				upper_bound(const key_type& k) const {
		for (const_iterator it = end(); it != begin(); --it)
			if (_tree._compare(k, it->first))
				return (it);
		return (end());
	}

	std::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const {
		return (std::make_pair(lower_bound(k), upper_bound(k)));
	}

	std::pair<iterator,iterator>				equal_range (const key_type& k) {
		return (std::make_pair(lower_bound(k), upper_bound(k)));
	}
};

#endif
