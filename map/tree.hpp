/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:59:39 by imicah            #+#    #+#             */
/*   Updated: 2020/11/06 13:39:00 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_TREE_HPP
# define FT_CONTAINERS_TREE_HPP

# include "ft.hpp"

template < class Key, class Value, class Compare, class Alloc>
class ft::tree
{
	friend class ft::map<Key, Value>;
private:
	typedef				Key														key_type;
	typedef				Value													mapped_type;
	typedef				std::pair<const key_type, mapped_type>					value_type;
	typedef				std::size_t												size_type;

	enum color {
		_red	= true,
		_black	= false
	};

	struct		s_node {
		value_type					*_value;
		struct s_node				*_left;
		struct s_node				*_right;
		struct s_node				*_parent;
		bool						_color;
	};
	typedef				s_node											s_node;
	typedef typename	Alloc::template rebind<s_node>::other			alloc_rebind;

	s_node							*_root;
	s_node							*_last_node;
	s_node							*_first_node;

	size_type						_size;
	alloc_rebind					_alloc_rebind;
	Alloc							_alloc;
	Compare							_compare;

	explicit tree(const Compare& comp = Compare(), const Alloc& alloc = Alloc()) : _size(0), _alloc(alloc), _compare(comp) {
		_empty_tree_init();
	}

	template<class S>
	void		_swap(S &first, S &second) {
		S&	temp = S(first);

		first = temp;
		first = second;
	}

	bool		_is_red(const s_node* node) { return ((node) ? (node->_color == _red) : false); }
	bool		_is_black(const s_node* node) { return ((node) ? (node->_color == _black) : false); }

	void		_flip_color(s_node* node) {
		node->_color = !node->_color;
		node->_right->_color = !node->_right->_color;
		node->_left->_color = !node->_left->_color;
	}

	s_node*		_fix_up(s_node* node) {
		if (_is_red(node->_right))
			node = _rotate_left(node);
		if (_is_red(node->_left) && _is_red(node->_left->_left))
			node = _rotate_right(node);
		if (_is_red(node->_right) && _is_red(node->_left))
			_flip_color(node);
		return (node);
	}

	s_node*		_rotate_left(s_node* node) {
		s_node*		x = node->_right;


		if (x->_left)
			x->_left->_parent = node;
		x->_parent = node->_parent;
		node->_parent = x;

		node->_right = x->_left;
		x->_left = node;
		x->_color = node->_color;
		node->_color = _red;
		if (node == _root)
			_root = x;
		return (x);
	}

	s_node*		_rotate_right(s_node* node) {
		s_node*		x = node->_left;

		if (x->_right)
			x->_right->_parent = node;
		x->_parent = node->_parent;
		node->_parent = x;

		node->_left = x->_right;
		x->_right = node;
		x->_color = node->_color;
		node->_color = _red;
		if (node == _root)
			_root = x;
		return (x);
	}

	s_node*		_move_red_left(s_node *node) {
		_flip_color(node);
		if (_is_red(node->_right->_left)) {
			node->_right = _rotate_right(node->_right);
			node = _rotate_left(node);
			_flip_color(node);
		}
		return (node);
	}

	s_node*		_move_red_right(s_node *node) {
		_flip_color(node);
		if (_is_red(node->_left->_left)) {
			node = _rotate_right(node);
			_flip_color(node);
		}
		return (node);
	}

	s_node*		_create_new_node(const value_type& val, s_node *parent) {
		s_node*		x = _alloc_rebind.allocate(1);

		x->_value = _alloc.allocate(1);
		_alloc.construct(x->_value, val);

		x->_left = 0;
		x->_right = 0;

		if (_compare(val.first, _first_node->_parent->_value->first)) {
			x->_left = _first_node;
			_first_node->_parent = x;
		}
		else if (_compare(_last_node->_parent->_value->first, val.first)) {
			x->_right = _last_node;
			_last_node->_parent = x;
		}

		x->_parent = parent;
		x->_color = _red;
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
		value_type	*value = _alloc.allocate(1);

		_alloc.construct(value, value_type());
		_last_node = _alloc_rebind.allocate(1);
		_first_node = _alloc_rebind.allocate(1);

		_last_node->_value = value;
		_first_node->_value = value;

		_last_node->_color = _black;
		_first_node->_color = _black;

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

	std::pair<s_node*, bool>		_put(s_node *node, const value_type& val) {
		std::pair<s_node*, bool>	pair;

		if (val.first == node->_value->first)
			return (std::make_pair(node, false));

		if ((node->_left == 0 || node->_left == _first_node) && _compare(val.first, node->_value->first)) {
			node->_left = _create_new_node(val, node);
			pair = std::make_pair(node, true);
		}
		else if ((node->_right == 0 || node->_right == _last_node) && _compare(node->_value->first, val.first)) {
			node->_right = _create_new_node(val, node);
			pair = std::make_pair(node, true);
		}
		else if (_compare(val.first, node->_value->first)) {
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

	s_node		*_delete_min(s_node *node) {
		s_node	*return_node = (node->_right == _last_node) ? _last_node : 0;
		if (node->_left == _first_node || node->_left == 0) {
			_destroy_node(node);
			return (return_node);
		}
		if (_is_black(node->_left) && _is_black(node->_left->_left))
			_move_red_left(node);
		node->_left = _delete_min(node->_left);
		return (_fix_up(node));
	}

	value_type	*_min(s_node *node) {
		value_type	*val = _alloc.allocate(1);
		while (node->_left && node->_left != _first_node)
			node = node->_left;
		_alloc.construct(val, *node->_value);
		return (val);
	}

	bool		_is_list(s_node* node) {
		return ((node->_right == 0 || node->_right == _last_node) &&
				(node->_left == 0 || node->_left == _first_node));
	}

	s_node		*_delete(s_node *node, const key_type &key) {
		int		compare = _compare(node->_value->first, key);

		if (!compare && node->_value->first != key) {
			if (_is_black(node->_left)&& _is_black(node->_left->_left))
				node = _move_red_left(node);
			node->_left = _delete(node->_left, key);
		}
		else {
			if (_is_red(node->_left))
				node = _rotate_right(node);
			if (node->_value->first == key && _is_list(node)) {
				if (node->_right == _last_node) {
					_last_node->_parent = node->_parent;
					_destroy_node(node);
					return (_last_node);
				}
				if (node->_left == _first_node) {
					_first_node->_parent = node->_parent;
					_destroy_node(node);
					return (_first_node);
				}
				else {
					_destroy_node(node);
					return (0);
				}
			}
			if (_is_black(node->_right) && _is_black(node->_right->_left))
				node = _move_red_right(node);
			if (node->_value->first == key) {
				node->_value = _min(node->_right); // TODO убрать утечку
				node->_right = _delete_min(node->_right);
			}
			else
				node->_right = _delete(node->_right, key);
		}
		return _fix_up(node);
	}

	s_node		*_search(const key_type &key, s_node *node) {
		s_node	*temp_node = node;

		while (temp_node) {
			if (key == temp_node->_value->first)
				break ;
			else if (_compare(key, temp_node->_value->first))
				temp_node = temp_node->_left;
			else
				temp_node = temp_node->_right;
		}
		return (temp_node);
	}

	void		_destroy_node(s_node *node) {
		_alloc.deallocate(node->_value, 1);
		_alloc_rebind.deallocate(node, 1);
		_size--;
	}
};

#endif //FT_CONTAINERS_TREE_HPP
