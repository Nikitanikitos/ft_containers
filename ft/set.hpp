/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:55:23 by imicah            #+#    #+#             */
/*   Updated: 2020/11/12 00:52:51 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_SET_HPP
# define FT_CONTAINERS_SET_HPP

# include "ft.hpp"
# include "queue.hpp"

template <class T, class Compare, class Alloc>
class	ft::set {
	typedef				T												key_type;
	typedef				T												mapped_type;
	typedef				key_type										value_type;
	typedef				Compare											key_compare;
	typedef				Compare											value_compare;
	typedef				Alloc											allocator_type;
	typedef typename	allocator_type::reference						reference;
	typedef typename	allocator_type::const_reference					const_reference;
	typedef typename	allocator_type::pointer							pointer;
	typedef typename	allocator_type::const_pointer					const_pointer;
	typedef				std::ptrdiff_t									difference_type;
	typedef				std::size_t										size_type;

private:
# define _RED true
# define _BLACK false

	class	_tree {
	public:
		typedef struct			_node_s {
			value_type*			_value;
			struct _node_s*		_left;
			struct _node_s*		_right;
			struct _node_s*		_parent;
			bool				_color;
		}						_node_t;

		typedef typename	Alloc::template rebind<_node_t>::other			_alloc_rebind_type;

		_node_t*				_root;
		_node_t*				_last_node;
		_node_t*				_first_node;

		size_type				_size;
		_alloc_rebind_type		_alloc_rebind;
		Alloc					_alloc;
		Compare					_compare;

		explicit _tree(const Compare& comp = Compare(), const Alloc& alloc = Alloc())
																			: _size(0), _alloc(alloc), _compare(comp) {
			_empty_tree_init();
		}

		bool		_is_red(const _node_t* node) { return (node && node->_color == _RED); }
		bool		_is_black(const _node_t* node) { return (!node || node->_color == _BLACK); }

		void		_flip_color(_node_t* node) {
			node->_color = !node->_color;
			node->_right->_color = !node->_right->_color;
			node->_left->_color = !node->_left->_color;
		}

		_node_t*		_fix_up(_node_t* node) {
			if (_is_red(node->_right))
				node = _rotate_left(node);
			if (_is_red(node->_left) && _is_red(node->_left->_left))
				node = _rotate_right(node);
			if (_is_red(node->_right) && _is_red(node->_left))
				_flip_color(node);
			return (node);
		}

		_node_t*		_rotate_left(_node_t* node) {
			_node_t*		x = node->_right;

			if (x->_left) x->_left->_parent = node;
			x->_parent = node->_parent;
			node->_parent = x;

			node->_right = x->_left;
			x->_left = node;
			x->_color = node->_color;
			node->_color = _RED;
			if (node == _root) _root = x;
			return (x);
		}

		_node_t*		_rotate_right(_node_t* node) {
			_node_t*		x = node->_left;

			if (x->_right) x->_right->_parent = node;
			x->_parent = node->_parent;
			node->_parent = x;

			node->_left = x->_right;
			x->_right = node;
			x->_color = node->_color;
			node->_color = _RED;
			if (node == _root) _root = x;
			return (x);
		}

		_node_t*		_move_red_left(_node_t *node) {
			_flip_color(node);
			if (_is_red(node->_right->_left)) {
				node->_right = _rotate_right(node->_right);
				node = _rotate_left(node);
				_flip_color(node);
			}
			return (node);
		}

		_node_t*		_move_red_right(_node_t *node) {
			_flip_color(node);
			if (_is_red(node->_left->_left)) {
				node = _rotate_right(node);
				_flip_color(node);
			}
			return (node);
		}

		_node_t*		_create_new_node(const value_type& val, _node_t *parent) {
			_node_t*		x = _alloc_rebind.allocate(1);

			x->_value = _alloc.allocate(1);
			_alloc.construct(x->_value, val);

			x->_left = 0;
			x->_right = 0;

			if (_compare(val, *_first_node->_parent->_value)) {
				x->_left = _first_node;
				_first_node->_parent = x;
			}
			else if (_compare(*_last_node->_parent->_value, val)) {
				x->_right = _last_node;
				_last_node->_parent = x;
			}

			x->_parent = parent;
			x->_color = _RED;
			return (x);
		}

		void		_empty_nodes_init() {
			_last_node->_right = _first_node;
			_last_node->_left = 0;
			_last_node->_parent = _first_node;

			_first_node->_right = 0;
			_first_node->_left = 0;
			_first_node->_parent = _last_node;

			_root = 0;
		}

		void		_empty_tree_init() {
			value_type*		value = _alloc.allocate(1);

			_alloc.construct(value, value_type());
			_last_node = _alloc_rebind.allocate(1);
			_first_node = _alloc_rebind.allocate(1);

			_last_node->_value = value;
			_first_node->_value = value;

			_last_node->_color = _BLACK;
			_first_node->_color = _BLACK;

			_empty_nodes_init();
		}

		void		_create_root_node(const value_type& val) {
			_root = _alloc_rebind.allocate(1);

			_root->_value = _alloc.allocate(1);
			_alloc.construct(_root->_value, val);

			_root->_left = _first_node;
			_root->_right = _last_node;
			_first_node->_parent = _root;
			_last_node->_parent = _root;
		}

		std::pair<_node_t*, bool>		_put(_node_t *node, const value_type& val) {
			std::pair<_node_t*, bool>	pair;
			bool						compare = _compare(val, *node->_value);

			if (val == *node->_value)
				return (std::make_pair(node, false));
			else if (_is_null_node(node->_left) && compare) {
				node->_left = _create_new_node(val, node);
				pair = std::make_pair(node, true);
			}
			else if (_is_null_node(node->_right) && !compare) {
				node->_right = _create_new_node(val, node);
				pair = std::make_pair(node, true);
			}
			else if (compare) {
				pair = _put(node->_left, val);
				node->_left = pair.first;
			}
			else {
				pair = _put(node->_right, val);
				node->_right = pair.first;
			}
			node = _fix_up(node);
			return (std::make_pair(node, pair.second));
		}

		_node_t*		_delete_min(_node_t* node) {
			if (_is_null_node(node))
				return (node);
			else if (_is_null_node(node->_left))
				return (_destroy_node(node));
			else if (_is_black(node->_left) && _is_black(node->_left->_left))
				node = _move_red_left(node);

			node->_left = _delete_min(node->_left);
			return (_fix_up(node));
		}

		_node_t*		_delete_max(_node_t* node) {
			if (_is_null_node(node))
				return (node);
			else if (_is_red(node->_left))
				node = _rotate_right(node);

			if (_is_null_node(node->_right))
				return (_destroy_node(node));
			else if (_is_black(node->_right) && _is_black(node->_right->_left))
				node = _move_red_right(node);

			node->_right = _delete_max(node->_right);
			return (_fix_up(node));
		}

		value_type*		_min(_node_t *node) {
			value_type*		val = _alloc.allocate(1);

			while (node->_left && node->_left != _first_node)
				node = node->_left;

			_alloc.construct(val, *node->_value);
			return (val);
		}

		bool			_is_null_node(_node_t* node) { return (node == 0 || node == _last_node || node == _first_node); }

		_node_t*		_delete(_node_t *node, const key_type &key) {
			if (_is_null_node(node)) return (node);

			bool	compare = _compare(*node->_value, key);

			if (compare == 0 && *node->_value != key) {
				if (_is_black(node->_left)&& _is_black(node->_left->_left))
					node = _move_red_left(node);
				node->_left = _delete(node->_left, key);
			}
			else {
				if (_is_red(node->_left))
					node = _rotate_right(node);
				if (*node->_value == key && _is_null_node(node->_right))
					return (_destroy_node(node));
				if (_is_black(node->_right) && _is_black(node->_right->_left))
					node = _move_red_right(node);
				if (*node->_value == key) {
					_alloc.destroy(node->_value);
					_alloc.deallocate(node->_value, 1);
					node->_value = _min(node->_right);
					node->_right = _delete_min(node->_right);
				}
				else
					node->_right = _delete(node->_right, key);
			}
			return (_fix_up(node));
		}

		_node_t*	_search(const key_type &key, _node_t *node) {
			_node_t*	result = node;

			while (result) {
				if (key == *result->_value)
					break ;
				else if (_compare(key, *result->_value))
					result = result->_left;
				else
					result = result->_right;
			}
			return (result);
		}

		_node_t*		_destroy_node(_node_t *node) {
			_node_t*		result = 0;
			if (node->_left == _first_node) {
				_first_node->_parent = node->_parent;
				result = _first_node;
			}
			else if (node->_right == _last_node) {
				_last_node->_parent = node->_parent;
				result = _last_node;
			}
			if (node == _last_node) {
				_alloc.destroy(node->_value);
				_alloc.deallocate(node->_value, 1);
			}
			_alloc_rebind.deallocate(node, 1);
			_size--;
			return (result);
		}
	};

	typedef				_tree								_tree_type;
	typedef typename	_tree_type::_node_t					_node_type;

	_tree_type 			_tree;

private:
	class	_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	public:
		_node_type*		_ptr;

		class	_const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
		public:
			_node_type*		_ptr;

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

				operator++();
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

				operator--();
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

			operator++();
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

			operator--();
			return (temp);
		}
	};

	class	_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	public:
		_node_type*		_ptr;

		class	_const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
		public:
			_node_type*		_ptr;

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

				operator--();
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

				operator++();
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

			operator--();
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

			operator++();
			return (temp);
		}
	};

public:
	typedef 			_iterator										iterator;
	typedef typename	_iterator::_const_iterator						const_iterator;
	typedef				_reverse_iterator								reverse_iterator;
	typedef typename	_reverse_iterator::_const_reverse_iterator		const_reverse_iterator;

	explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
		_tree._compare = comp;
		_tree._alloc = alloc;
		_tree._empty_tree_init();
	}

	template <class InputIterator>
	set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
																	const allocator_type& alloc = allocator_type()) {
		_tree._compare = comp;
		_tree._alloc = alloc;
		_tree._empty_tree_init();
		for (; first != last; ++first)
			insert(*first);
	}

	set (const set& x) {
		_tree._empty_tree_init();
		for (const_iterator	it = x.begin(); it != x.end(); ++it)
			insert(*it);
	}

	~set() {
		clear();
		_tree._destroy_node(_tree._last_node);
		_tree._destroy_node(_tree._first_node);
	}

	set& operator=(const set& x) {
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
		if (pair.second)
			_tree._size++;
		_tree._root->_parent = 0;
		_tree._root->_color = false;
		return (std::make_pair(find(val), pair.second));
	}

	iterator	insert(iterator position, const value_type& val) {
		(void )position;
		return (insert(val).first);
	}

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last,
									typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0) {
		for (; first != last; ++first)
			insert(*first);
	}

	void						erase(iterator position) {
		_node_type*		node = position._ptr;

		erase(*node->_value);
	}

	size_type					erase(const key_type& k) {
		if (k == *_tree._last_node->_parent->_value)
			_tree._root = _tree._delete_max(_tree._root);
		else if (k == *_tree._first_node->_parent->_value)
			_tree._root = _tree._delete_min(_tree._root);
		else
			_tree._root = _tree._delete(_tree._root, k);
		if (empty()) _tree._empty_nodes_init();
		else _tree._root->_color = false;
		return (1);
	}

	void						erase(iterator first, iterator last) {
		queue<key_type>		queue;

		for (; first != last; ++first)
			queue.push(*first);
		while (!queue.empty()) {
			erase(queue.front());
			queue.pop();
		}
	}

	void						swap(set& x) {
		std::swap(x._tree._root, _tree._root);
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
			if (!_tree._is_null_node(node->_right))
				queue.push(node->_right);
			if (!_tree._is_null_node(node->_left))
				queue.push(node->_left);
			_tree._destroy_node(queue.front());
			queue.pop();
			node = queue.front();
		}
		_tree._empty_nodes_init();
	}

	key_compare					key_comp() const { return (_tree._compare); }
	value_compare				value_comp() const { return (_tree._compare); }

	iterator					find(const key_type& k) { return (iterator(_tree._search(k, _tree._root))); }
	const_iterator				find(const key_type& k) const { return (const_iterator(_tree._search(k, _tree._root))); }

	size_type					count(const key_type& k) const { return ((_search(k, _tree._root) != _tree._last_node) ? 1 : 0); }

	iterator					lower_bound(const key_type& k) {
		for (iterator it = begin(); it != end(); ++it)
			if (_tree._compare(k, *it) || *it == k)
				return (it);
		return (end());
	}

	const_iterator				lower_bound(const key_type& k) const {
		for (const_iterator	it = begin(); it != end(); ++it)
			if (_tree._compare(k, *it) || *it == k)
				return (it);
		return (end());
	}

	iterator					upper_bound(const key_type& k) {
		for (iterator it = begin(); it != end(); ++it)
			if (_tree._compare(k, *it))
				return (it);
		return (end());
	}

	const_iterator				upper_bound(const key_type& k) const {
		for (const_iterator it = begin(); it != end(); ++it)
			if (_tree._compare(k, *it))
				return (it);
		return (end());
	}

	std::pair<const_iterator, const_iterator>	equal_range (const key_type& k) const {
		return (std::make_pair(lower_bound(k), upper_bound(k)));
	}

	std::pair<iterator,iterator>				equal_range (const key_type& k) {
		return (std::make_pair(lower_bound(k), upper_bound(k)));
	}
};

#endif //FT_CONTAINERS_SET_HPP
