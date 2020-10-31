/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:09:48 by imicah            #+#    #+#             */
/*   Updated: 2020/10/31 21:28:40 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_MAP_HPP
# define FT_CONTAINERS_MAP_HPP

# include <iostream>
# include <utility>
# include "map_iterator.hpp"
//# include "reverse_map_iterator.hpp"
# include "queue.hpp"

# define RED	true
# define BLACK	false

namespace ft
{

	template < class Key, class Value, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,Value> > >
	class map
	{
	private:
		struct		s_node {
			std::pair<const Key, Value>	*value;
			struct s_node				*left;
			struct s_node				*right;
			struct s_node				*parent;
			bool						color;
		};

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
		typedef 			list_iterator<s_node, value_type>						iterator;
		typedef				const_list_iterator<s_node, value_type>					const_iterator;
		typedef				reverse_list_iterator<s_node, value_type>				reverse_iterator;
		typedef				const_reverse_list_iterator<s_node, value_type>			const_reverse_iterator;
		typedef				std::ptrdiff_t											difference_type;
		typedef				std::size_t												size_type;

		typedef typename	allocator_type::template rebind<s_node>::other			alloc_rebind;

	private:
		s_node			*_root;
		s_node			*_first_node;
		s_node			*_last_node;
		s_node			*_end_node;
		size_type		_size;
		alloc_rebind	_alloc_rebind;
		allocator_type	_alloc;
		key_compare		_compare;

		bool		_is_red(const s_node* node) { return (node->color == RED); }
		bool		_is_black(const s_node* node) { return (node->color == BLACK); }

		void		_flip_color(s_node* node) {
			node->color = !node->color;
			node->right->color = !node->right->color;
			node->left->color = !node->left->color;
		}

		s_node*		_create_new_node(const value_type& val, s_node *parent) {
			s_node*		x = _alloc_rebind.allocate(1);

			x->value = _alloc.allocate(1);
			_alloc.construct(x->value, val);
			x->left = _end_node;
			x->right = _end_node;
			x->parent = parent;
			x->color = RED;
			return (x);
		}

		void		_create_end_node() {
			value_type	*value = _alloc.allocate(1);

			_alloc.construct(value, value_type());
			_end_node = _alloc_rebind.allocate(1);

			_end_node->value = value;
			_end_node->parent = _end_node;
			_end_node->left = 0;
			_end_node->right = 0;
			_end_node->color = BLACK;
		}

		s_node*		_fix_up(s_node* node) {
			if (node->right->color == RED)
				node = _rotate_left(node);
			if (_is_red(node->left) && _is_red(node->left->left))
				node = _rotate_right(node);
			if (_is_red(node->right) && _is_red(node->left))
				_flip_color(node);
			return (node);
		}

		std::pair<s_node*, bool>		_put(s_node *node, const value_type& val) {
			std::pair<s_node*, bool>	pair;
			bool						compare;

			if (node == _end_node) {
				s_node	*new_node = _create_new_node(val, _end_node->parent);
				compare = _compare(new_node->value->first, _first_node->value->first);
				if (compare)
					_first_node = new_node;
				else
					_last_node = new_node;
				return (std::make_pair(new_node, true));
			}

			compare = _compare(val.first, node->value->first);
			if (val.first == node->value->first)
				return (std::make_pair(node, false));
			else if (compare) {
				pair = _put(node->left, val);
				node->left = pair.first;
			}
			else {
				pair = _put(node->right, val);
				node->right = pair.first;
			}

			node = _fix_up(node);
			return (std::make_pair(node, pair.second));
		}

		s_node*		_rotate_left(s_node* node) {
			s_node*		x = node->right;

			x->left->parent = node;
			x->parent = node->parent;
			node->parent = x;

			node->right = x->left;
			x->left = node;
			x->color = node->color;
			node->color = RED;
			return (x);
		}

		s_node*		_rotate_right(s_node* node) {
			s_node*		x = node->left;

			x->right->parent = node;
			x->parent = node->parent;
			node->parent = x;

			node->left = x->right;
			x->right = node;
			x->color = node->color;
			node->color = RED;
			return (x);
		}

		s_node*		_move_red_left(s_node *node) {
			_flip_color(node);
			if (_is_red(node->right->left)) {
				node->right = _rotate_right(node->right);
				node = _rotate_left(node);
				_flip_color(node);
			}
			return (node);
		}

		s_node*		_move_red_right(s_node *node) {
			_flip_color(node);
			if (_is_red(node->left->left)) {
				node = _rotate_right(node);
				_flip_color(node);
			}
			return (node);
		}

		s_node		*_delete_min(s_node *node) {
			if (node->left == _end_node && node->right == _end_node) {
				_destroy_node(node);
				return (_end_node);
			}
			if (_is_black(node->left) && _is_black(node->left->left))
				_move_red_left(node);
			node->left = _delete_min(node->left);
			return (_fix_up(node));
		}

		s_node		*_delete(s_node *node, const key_type &key) {
			int		compare = _compare(node->value->first, key);

			if (compare < 0) {
				if (_is_black(node->left)&& _is_black(node->left->left))
					_move_red_left(node);
				node->left = _delete(node->left, key);
			}
			else {
				if (_is_red(node->left))
					node = _rotate_right(node);
				if (compare == 0 && node->right == _end_node) {
					_destroy_node(node);
					return (_end_node);
				}
				if (_is_black(node->right) && _is_black(node->right->left))
					node = _move_red_right(node);
				if (compare == 0) {
					node->value = _min(node->right);
					node->right = _delete_min(node->right);
				}

				return _fix_up(node);
			}
		}

		s_node		*_search(const key_type &key, s_node *node) {
			bool	compare = _compare(key, node->value->first);
			if (node == _end_node)
				return (_end_node);
			else if (key == node->value->first)
				return (node);
			else if (compare)
				_search(key, node->right);
			else
				_search(key, node->left);
			return (_end_node);
		}

		void		_destroy_node(s_node *node) {
			_alloc.deallocate(node->value, 1);
			_alloc_rebind.deallocate(node, 1);
			_size--;
		}

	public:
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type(),
										typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0)
													: _root(0), _end_node(0), _size(0), _alloc(alloc), _compare(comp) {
			_create_end_node();
			for (; first != last; ++first)
				insert(*first);
		}

		map(const map& x);
		~map() { clear(); }
		map&	operator=(const map& x) {
			if (this == &x)
				return (*this);
			clear();
			_size = 0;
			// TODO Доделать!
		}

		iterator				begin() { return (_first_node); }
		const_iterator			begin() const { return (_first_node); }
		iterator				end() { return (_last_node->right); }
		const_iterator			end() const { return (_last_node->right); }
		reverse_iterator		rbegin() { return (_last_node->right); }
		const_reverse_iterator	rbegin() const { return (_last_node->right); }
		reverse_iterator		rend() { return (_first_node); }
		const_reverse_iterator	rend() const { return (_first_node); }

		bool					empty() const { return (_size == 0); }
		size_type				size() const { return (_size); }
		size_type				max_size() const;

		mapped_type&			operator[](const key_type& k) {
			s_node	*node;

			if ((node = _search(k, _root) == _end_node))
				node = *insert(std::make_pair(k, mapped_type()));
			return (node->value.second);
		}

		std::pair<iterator,bool>	insert(const value_type& val) {
			std::pair<s_node*, bool>	pair;
			if (empty()) {
				_root = _create_new_node(val, 0);
				_first_node = _root;
				_last_node = _root;
				return (std::make_pair(_root, true));
			}
			else {
				pair = _put(_root, val);
				_root = pair.first;
			}
			_size++;
			return (std::make_pair(find(val.first), pair.second));
		}

		iterator					insert(iterator position, const value_type& val);

		template <class InputIterator>
		void						insert(InputIterator first, InputIterator last) {
			for (; first != last; ++first)
				insert(*first);
		}

		void						erase(iterator position);
		size_type					erase(const key_type& k);
		void						erase(iterator first, iterator last);
		void						swap(map& x);

		void						clear() {
			queue<s_node *>	queue;
			s_node			*node = _root;

			queue.push(node);
			while (!queue.empty()) {
				if (node->right != _end_node)
					queue.push(node->right);
				if (node->left != _end_node)
					queue.push(node->left);
				node = queue.front();
				_destroy_node(node);
				queue.pop();
				node = queue.front();
			}
		}

		key_compare					key_comp() const { return (_compare); }
		value_compare				value_comp() const;

		iterator					find(const key_type& k) {
			s_node*		node = _search(k, _root);

			return (node);
		}

		const_iterator				find(const key_type& k) const {
			s_node*		node = _search(k, _root);

			return (node);
		}

		size_type					count(const key_type& k) const { return ((_search(k, _root) != _end_node) ? 1 : 0); }

		iterator					lower_bound(const key_type& k);
		const_iterator				lower_bound(const key_type& k) const;
		iterator					upper_bound(const key_type& k);
		const_iterator				upper_bound(const key_type& k) const;

		std::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
		std::pair<iterator,iterator>				equal_range (const key_type& k);
	};

	template<class Key, class Value, class Compare, class Alloc>
	map<Key, Value, Compare, Alloc>::map(const key_compare &comp, const allocator_type &alloc)
													: _root(0), _end_node(0), _size(0), _alloc(alloc), _compare(comp) {
		_create_end_node();
	}

}

#endif
