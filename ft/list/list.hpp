/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:19:10 by imicah            #+#    #+#             */
/*   Updated: 2020/11/10 16:37:28 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_LIST_HPP
# define FT_CONTAINERS_LIST_HPP

# include <limits>
# include "ft.hpp"
# include "list_iterator.hpp"
# include "reverse_list_iterator.hpp"

template<class T, class Alloc>
class	ft::list
{
private:
	typedef struct		_list_s {
		T*				value;
		_list_s*		next;
		_list_s*		prev;
	}					_list_t;

public:
	typedef				T												value_type;
	typedef				Alloc											allocator_type;
	typedef typename	allocator_type::reference						reference;
	typedef typename	allocator_type::const_reference					const_reference;
	typedef typename	allocator_type::pointer							pointer;
	typedef typename	allocator_type::const_pointer					const_pointer;
	typedef 			list_iterator<_list_t, T>						iterator;
	typedef				const_list_iterator<_list_t, T>					const_iterator;
	typedef				reverse_list_iterator<_list_t, T>				reverse_iterator;
	typedef				const_reverse_list_iterator<_list_t, T>			const_reverse_iterator;
	typedef				std::ptrdiff_t									difference_type;
	typedef				std::size_t										size_type;

private:
	typedef typename allocator_type::template rebind<_list_t>::other		alloc_rebind;

	_list_t			*_first_node;
	_list_t			*_last_node;
	_list_t			*_end_node;
	size_type		_size;
	alloc_rebind	_alloc_rebind;
	allocator_type	_alloc;

	void		_create_end_node() {
		value_type	*value_node = _alloc.allocate(1);

		_alloc.construct(value_node, T());
		_end_node = _alloc_rebind.allocate(1);
		_end_node->next = _end_node;
		_end_node->prev = _end_node;
		_end_node->value = value_node;
	}

	void		_assign_new_value_to_node(_list_t *node, const value_type &val) {
		_alloc.destroy(node->value);
		_alloc.construct(node->value, val);
	}

	_list_t*		_new_node_init(const value_type &val) {
		value_type	*node_value = _alloc.allocate(1);
		_list_t		*node = _alloc_rebind.allocate(1);

		_alloc.construct(node_value, val);
		node->value = node_value;
		node->next = _end_node;
		node->prev = _end_node;
		return (node);
	}

	void		_destroy_node(_list_t *node) {
		_alloc.destroy(node->value);
		_alloc.deallocate(node->value, 1);
		_alloc_rebind.deallocate(node, 1);
		_size--;
	}

	void		_first_last_node_init() {
		_first_node = _end_node->next;
		_last_node = _end_node->prev;
	}

	void		_insert_in_front_node(_list_t *node_position, _list_t *node) {
		node_position->prev->next = node;
		node->prev = node_position->prev;
		node->next = node_position;
		node_position->prev = node;
	}

	void		_check_for_insert() { // TODO think about better name
		_first_node = _end_node->next;
		if (_size == 0)
			_last_node = _first_node;
		else
			_last_node = _end_node->prev;
	}

	size_type	_get_segment_size(iterator begin, iterator end) {
		size_type	result = 0;
		while (begin != end) {
			++begin;
			result++;
		}
		return (result);
	}

public:
	explicit list(const allocator_type& alloc = allocator_type()) : _size(0), _alloc(alloc) {
		_create_end_node();
		_first_node = _end_node;
		_last_node = _end_node;
	};

	explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(0), _alloc(alloc) {
		_create_end_node();
		_first_last_node_init();

		for (size_type i = 0; i < n; ++i)
			push_back(val);
	}

	template <class InputIterator>
	list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
										typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0)
															: _first_node(0), _last_node(0), _size(0), _alloc(alloc) {
		_create_end_node();
		_first_last_node_init();

		for(; first != last; ++first)
			push_back(*first);
	}

	list(const list& list) : _first_node(0), _last_node(0), _size(0), _alloc(list._alloc) {
		const_iterator	it = list.begin();

		_create_end_node();
		_first_last_node_init();

		for(; it != list.end(); ++it)
			push_back(*it);
	}

	list& operator=(const list& list) {
		if (this == &list)
			return (*this);

		const_iterator	begin = list.begin();
		const_iterator	end = list.end();
		size_type		i = 0;
		_list_t			*temp_node = _first_node;

		for (; begin != end; begin++) {
			if (_size >= list._size)
				break ;
			else if (i++ < _size) {
				_assign_new_value_to_node(temp_node, *begin);
				temp_node = temp_node->next;
			}
			else if (_size < list._size)
				push_back(*begin);
		}
		while (_size > list._size)
			pop_back();
		_first_last_node_init();
		return (*this);
	}

	~list() {
		clear();
		_destroy_node(_end_node);
	}

	iterator				begin()			{ return (iterator(_end_node->next)); }
	const_iterator			begin() const	{ return (const_iterator(_end_node->next)); }
	iterator				end()			{ return (iterator(_end_node)); }
	const_iterator			end() const		{ return (const_iterator(_end_node)); }
	reverse_iterator		rbegin()		{ return (reverse_iterator(_end_node->prev)); }
	const_reverse_iterator	rbegin() const	{ return (const_reverse_iterator(_end_node->prev)); }
	reverse_iterator		rend()			{ return (reverse_iterator(_end_node)); }
	const_reverse_iterator	rend() const	{ return const_reverse_iterator((_end_node)); }

	bool    				empty() const	{ return (!_size); }
	size_type				size() const	{return (_size); };
	size_type				max_size() const { return (std::numeric_limits<size_type>::max()); }

	reference				front()			{ return (*_first_node->value); }
	const_reference			front() const	{ return (*_first_node->value); }
	reference				back()			{ return (*_last_node->value); }
	const_reference			back() const	{ return (*_last_node->value); }

	template <class InputIterator>
	void			assign(InputIterator first, InputIterator last,
									typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0) {
		size_type		i = 0;
		_list_t			*temp_node = _first_node;

		for (; first != last; ++first) {
			if (i++ < _size) {
				_assign_new_value_to_node(temp_node, *first);
				temp_node = temp_node->next;
			}
			else
				push_back(*first);
		}
		while (i < _size)
			pop_back();
	}

	void			assign(list::size_type n, const value_type &val) {
		_list_t			*temp_node = _first_node;
		size_type		i;

		for (i = 0; i < n; ++i) {
			if (i < _size) {
				_assign_new_value_to_node(temp_node, val);
				temp_node = temp_node->next;
			}
			else
				push_back(val);
		}
		while (i < _size)
			pop_back();
	}

	void			push_front(const value_type& val) {
		_list_t		*node = _new_node_init(val);

		_end_node->next = node;
		node->prev = _end_node;
		node->next = _first_node;
		_first_node->prev = node;
		_first_node = _end_node->next;

		if (_last_node == _end_node)
			_last_node = _first_node;
		_size++;
	}

	void			pop_front() {
		_list_t	*node;

		node = _first_node;
		_first_node->prev->next = _first_node->next;
		_first_node->next->prev = _first_node->prev;
		_destroy_node(node);
		_first_last_node_init();
	}

	void			push_back(const value_type& val) {
		_list_t		*node = _new_node_init(val);

		_end_node->prev = node;
		node->next = _end_node;
		node->prev = _last_node;
		_last_node->next = node;
		_last_node = _end_node->prev;

		if (_first_node == _end_node)
			_first_node = _last_node;
		_size++;
	}

	void			pop_back() {
		_list_t	*node;

		node = _last_node;
		_last_node->prev->next = _last_node->next;
		_last_node->next->prev = _last_node->prev;
		_destroy_node(node);
		_first_last_node_init();
	}

	iterator		insert(iterator position, const value_type &val) {
		_list_t		*temp_node = _new_node_init(val);
		_list_t		*node_position = position._ptr;

		_insert_in_front_node(node_position, temp_node);
		_check_for_insert();
		_size++;
		return (iterator(temp_node));
	}

	void			insert(iterator position, size_type n, const value_type& val) {
		_list_t		*temp_node;
		_list_t		*node_position = position._ptr;

		for (size_type i = 0; i < n; ++i) {
			temp_node = _new_node_init(val);
			_insert_in_front_node(node_position, temp_node);
			_size++;
		}
		_check_for_insert();
	}

	template <class InputIterator>
	void			insert(iterator position, InputIterator first, InputIterator last,
									typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0) {
		_list_t		*temp_node;
		_list_t		*node_position = position._ptr;

		for (; first != last; ++first) {
			temp_node = _new_node_init(*first);
			_insert_in_front_node(node_position, temp_node);
			_size++;
		}
		_check_for_insert();
	}

	iterator		erase(list::iterator position) {
		_list_t		*node_position = position._ptr;
		iterator	it = node_position->next;

		node_position->prev->next = node_position->next;
		node_position->next->prev = node_position->prev;

		_destroy_node(node_position);
		_first_last_node_init();
		return (it);
	}

	iterator		erase(list::iterator first, list::iterator last) {
		_list_t		*first_node = first._ptr;
		_list_t		*last_node = last._ptr;
		_list_t		*temp_node;
		iterator	it;

		first_node->prev->next = last_node;
		last_node->prev = first_node->prev;
		it = last_node;
		while (first_node != last_node) {
			temp_node = first_node;
			first_node = first_node->next;
			_destroy_node(temp_node);
		}
		_first_last_node_init();
		return (it);
	}

	void			swap(list &list) {
		std::swap(_size, list._size);
		std::swap(_alloc, list._alloc);
		std::swap(_end_node, list._end_node);
		std::swap(_last_node, list._last_node);
		std::swap(_first_node, list._first_node);
		std::swap(_alloc_rebind, list._alloc_rebind);
	}

	void			resize(list::size_type n, value_type val) {
		while (_size != n)
			(_size < n) ? push_back(val) : pop_back();
	}

	void			clear() {
		_list_t		*temp_node;

		while (_size) {
			temp_node = _first_node;
			_first_node = _first_node->next;
			_destroy_node(temp_node);
		}
		_first_node = _end_node;
		_last_node = _end_node;
		_end_node->prev = _end_node; // TODO вынести в отдельный метод
		_end_node->next = _end_node;
	}

	void			splice(iterator position, list& x) {
		_list_t	*node = position._ptr;

		node->prev->next = x._first_node;
		x._first_node->prev = node->prev;
		node->prev = x._last_node;
		x._last_node->next = node;

		_first_last_node_init();

		x._end_node->next = x._end_node;
		x._end_node->prev = x._end_node;
		x._first_last_node_init();

		_size += x._size;
		x._size = 0;
	}

	void			splice(iterator position, list& x, iterator i) {
		_list_t		*position_node = position._ptr;
		_list_t		*node = i._ptr;

		node->prev->next = node->next;
		node->next->prev = node->prev;
		x._first_last_node_init();

		position_node->prev->next = node;
		node->prev = position_node->prev;
		position_node->prev = node;
		node->next = position_node;
		_first_last_node_init();

		_size++;
		x._size--;
	}

	void			splice(iterator position, list& x, iterator first, iterator last) {
		_list_t		*position_node = position._ptr;
		_list_t		*first_node = first._ptr;
		_list_t		*last_node = last._ptr;
		_list_t		*new_last_node = last_node->prev;
		value_type	segment_size = _get_segment_size(first, last);

		_size += segment_size;
		x._size -= segment_size;

		first_node->prev->next = last_node;
		last_node->prev = first_node->prev;
		x._first_last_node_init();
		first_node->prev = position_node->prev;
		position_node->prev->next = first_node;
		new_last_node->next = position_node;
		position_node->prev = new_last_node;
		_first_last_node_init();
	}

	void			remove(const value_type& val) {
		for (iterator it = begin(); it != end(); ++it)
			if (val == *it)
				it = erase(it);
	}

	template <class Predicate>
	void			remove_if(Predicate pred) {
		for (iterator it = begin(); it != end();)
			if (pred(*it))
				it = erase(it);
			else
				++it;
	}

	void			unique() {
		for (_list_t*	list = _first_node; list != _end_node;)
			(*list->value == *list->next->value) ? list = erase(list)._ptr :list = list->next;
	}

	template <class BinaryPredicate>
	void			unique(BinaryPredicate binary_pred) {
		for (_list_t*	list = _first_node; list != _end_node;)
			(binary_pred(*list->value, *list->next->value)) ? list = erase(list)._ptr : list = list->next;
	}

	void			merge(list& x) {
		iterator	it = begin();
		iterator	x_it = x.begin();

		while (x_it != x.end()) {
			while ((*x_it <= *it || it == end()) && x_it != x.end()) {
				insert(it, *x_it);
				x_it = x.erase(x_it);
			}
			if (it != end())
				++it;
		}
	}

	template <class Compare>
	void			merge(list& x, Compare comp) {
		iterator	it = begin();
		iterator	x_it = x.begin();

		while (x_it != x.end()) {
			while ((comp(*x_it, *it) || it == end()) && x_it != x.end()) {
				insert(it, *x_it);
				x_it = x.erase(x_it);
			}
			if (it != end())
				++it;
		}
	}

	void			sort() {
		value_type	temp_value;
		_list_t		*temp_node;
		_list_t		*list;

		list = _first_node;
		while (list != _end_node) {
			temp_node = list->next;
			while (temp_node != _end_node) {
				if (*list->value > *temp_node->value) {
					temp_value = *list->value;
					*list->value = *temp_node->value;
					*temp_node->value = temp_value;
				}
				temp_node = temp_node->next;
			}
			list = list->next;
		}
	}

	template <class Compare>
	void			sort(Compare comp) {
		value_type temp_value;
		_list_t *temp_node;
		_list_t *list;

		list = _first_node;
		while (list != _last_node) {
			temp_node = list->next;
			while (temp_node != _end_node) {
				if (!comp(*list->value, *temp_node->value)) {
					temp_value = *list->value;
					*list->value = *temp_node->value;
					*temp_node->value = temp_value;
				}
				temp_node = temp_node->next;
			}
			list = list->next;
		}
	}

	void			reverse() {
		value_type	temp_value;
		_list_t		*start_list = _first_node;
		_list_t		*end_list = _last_node;

		for (int i = 0; i < _size / 2; ++i) {
			temp_value = start_list->value;
			start_list->value = end_list->value;
			end_list->value = temp_value;
			start_list = start_list->next;
			end_list = end_list->prev;
		}
	}
};

template <class T, class Alloc>
bool operator==(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return (false);
	typename ft::list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

	while (it_lhs != lhs.end()) {
		if (*it_rhs != *it_lhs)
			break;
		++it_rhs;
		++it_lhs;
	}
	return (*it_lhs == *it_rhs);
}

template <class T, class Alloc>
bool operator!=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	typename ft::list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

	while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
		if (*it_rhs != *it_lhs)
			break;
		++it_rhs;
		++it_lhs;
	}
	return (*it_lhs != *it_rhs);
}

template <class T, class Alloc>
bool operator<(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	if (lhs.size() < rhs.size())
		return (true);
	typename ft::list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

	while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
		if (*it_rhs != *it_lhs)
			break;
		++it_rhs;
		++it_lhs;
	}
	return (*it_lhs < *it_rhs);
}

template <class T, class Alloc>
bool operator<= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	if (lhs.size() < rhs.size())
		return (true);
	typename ft::list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

	while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
		if (*it_rhs != *it_lhs)
			break;
		++it_rhs;
		++it_lhs;
	}
	return (*it_lhs <= *it_rhs);
}

template <class T, class Alloc>
bool operator>(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	if (lhs.size() > rhs.size())
		return (true);
	typename ft::list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

	while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
		if (*it_rhs != *it_lhs)
			break;
		++it_rhs;
		++it_lhs;
	}
	return (*it_lhs > *it_rhs);
}

template <class T, class Alloc>
bool operator>= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	if (lhs.size() > rhs.size())
		return (true);
	typename ft::list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

	while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
		if (*it_rhs != *it_lhs)
			break;
		++it_rhs;
		++it_lhs;
	}
	return (*it_lhs >= *it_rhs);
}

template <class T, class Alloc>
void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y) {
	typename ft::list<T,Alloc>::size_type	prev_this_size = x.size();
	typename ft::list<T,Alloc>::size_type	prev_list_size = y.size();
	typename ft::list<T,Alloc>::iterator	this_it = x.begin();
	typename ft::list<T,Alloc>::iterator	list_it = y.begin();
	typename ft::list<T,Alloc>::value_type	val;

	if (x.size() > y.size())
		y.resize(x.size());
	else if (y.size() > x.size())
		x.resize(y.size());

	for (typename ft::list<T,Alloc>::size_type i = 0; i < x.size(); ++i) {
		val = *this_it;
		*this_it = *list_it;
		*list_it = val;
		++this_it;
		++list_it;
	}
	y.resize(prev_this_size);
	x.resize(prev_list_size);
}

#endif
