/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:09:48 by imicah            #+#    #+#             */
/*   Updated: 2020/11/08 12:24:31 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_MAP_HPP
# define FT_CONTAINERS_MAP_HPP

# include <utility>
# include <limits>
# include "queue.hpp"
# include "tree.hpp"
# include "ft.hpp"
# include "map_iterator.hpp"
# include "reverse_map_iterator.hpp"

template < class Key, class Value, class Compare, class Alloc>
class ft::map
{

private:
	class				_tree;

	typedef				ft::tree<Key, Value, Compare, Alloc>					_tree_type;
	typedef typename	_tree_type::s_node										_node_type;

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

	typedef 			map_iterator<_node_type, value_type>						iterator;
	typedef				const_map_iterator<const _node_type, value_type>			const_iterator;
	typedef				reverse_map_iterator<_node_type, value_type>				reverse_iterator;
	typedef				const_reverse_map_iterator<const _node_type, value_type>	const_reverse_iterator;

	explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
		_tree._compare = comp;
		_tree._alloc = alloc;
		_tree._empty_tree_init();
	}

//		template <class InputIterator>
//		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
//							const allocator_type& alloc = allocator_type(),
//										typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0) {
//			_tree._compare = comp;
//			_tree._alloc = alloc;
//			_tree._empty_tree_init();
//			for (; first != last; ++first)
//				insert(*first);
//		}

	map(const map& x) {
		_tree._empty_tree_init();
		for (const_iterator	it = x.begin(); it != x.end(); ++it)
			insert(*it);
	}

	~map() {
//			clear();
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

	iterator					insert(iterator position, const value_type& val);

//		template <class InputIterator>
//		void						insert(InputIterator first, InputIterator last,
//									   typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0) {
//			for (; first != last; ++first)
//				insert(*first);
//		}

	void						erase(iterator position) {
		_node_type*	node = position._ptr;
		erase(node->_value->first);
	}

	size_type					erase(const key_type& k) {
		_tree._root = _tree._delete(_tree._root, k);
		if (empty())
			_tree._empty_nodes_init();
		return (1); }

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

			node = _tree._root;
			if (_tree._root)
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
	}

	key_compare					key_comp() const { return (_tree._compare); }
	value_compare				value_comp() const;

	iterator					find(const key_type& k) { return (iterator(_tree._search(k, _tree._root))); }
	const_iterator				find(const key_type& k) const { return (const_iterator(_tree._search(k, _tree._root))); }

	size_type					count(const key_type& k) const { return ((_search(k, _tree._root) != _tree._last_node) ? 1 : 0); }

	iterator					lower_bound(const key_type& k) {
		for (iterator	it = begin(); it != _tree._last_node; ++it)
			if (!_tree._compare(*it.first, k))
				return (it);
		return (iterator(_tree._last_node));
	}

	const_iterator				lower_bound(const key_type& k) const {
		for (const_iterator	it = begin(); it != _tree._last_node; ++it)
			if (!_tree._compare(*it.first, k))
				return (it);
		return (const_iterator(_tree._last_node));
	}

	iterator					upper_bound(const key_type& k) {
		for (iterator it = end(); it != _tree._first_node; --it)
			if (_tree._compare(k, *it.first))
				return (it);
		return (_tree._last_node);
	}

	const_iterator				upper_bound(const key_type& k) const {
		for (const_iterator it = end(); it != _tree._first_node; --it)
			if (_tree._compare(k, *it.first))
				return (it);
		return (_tree._last_node);
	}

	std::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
	std::pair<iterator,iterator>				equal_range (const key_type& k);
};

#endif
