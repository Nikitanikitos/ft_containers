/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:19:10 by imicah            #+#    #+#             */
/*   Updated: 2020/10/26 16:59:32 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef list_hpp
# define list_hpp

# include <iostream>
# include <string>
# include "bidirectional_iterator.hpp"
# include "reverse_bidirectional_iterator.hpp"

namespace ft
{
	namespace {
		template<bool B, class T = void>
		struct enable_if {};

		template<class T>
		struct enable_if<true, T> { typedef T type; };
	}

	template<class T, class Alloc = std::allocator<T> >
	class	list
	{

	private:
		struct				s_list {
			T				*value;
			struct s_list	*next;
			struct s_list	*prev;
		};
	public:

	public:
		typedef				T												value_type;
		typedef				Alloc											allocator_type;
		typedef typename	allocator_type::reference						reference;
		typedef typename	allocator_type::const_reference					const_reference;
		typedef typename	allocator_type::pointer							pointer;
		typedef typename	allocator_type::const_pointer					const_pointer;
		typedef 			bidirectional_iterator<s_list, T>				iterator;
		typedef				const_bidirectional_iterator<s_list, T>			const_iterator;
		typedef				rev_bidirectional_iterator<s_list, T>			reverse_iterator;
		typedef				const_rev_bidirectional_iterator<s_list, T>		const_reverse_iterator;
		typedef				std::ptrdiff_t									difference_type;
		typedef				std::size_t										size_type;

		typedef typename allocator_type::template rebind<s_list>::other		alloc_rebind;

	private:
		s_list			*_first_node;
		s_list			*_last_node;
		s_list			*_end_node;
		size_type		_size;
		alloc_rebind	_alloc_rebind;
		allocator_type	_alloc;

		void	_create_end_node() {
			value_type	*value_node = _alloc.allocate(1);

			_alloc.construct(value_node, T());
			_end_node = _alloc_rebind.allocate(1);
			_end_node->next = _end_node;
			_end_node->prev = _end_node;
			_end_node->value = value_node;
		}

		void	_tie_end_node() { // TODO think about better name
			if (_first_node) {
				_first_node->prev = _end_node;
				_end_node->next = _first_node;
			}
			if (_last_node) {
				_last_node->next = _end_node;
				_end_node->prev = _last_node;
			}
		}

		void	_assign_new_value_to_node(s_list *node, const value_type &val) {
			_alloc.destroy(node->value);
			_alloc.construct(node->value, val);
		}

		s_list	*_new_node_init(const value_type &val) {
			value_type	*node_value = _alloc.allocate(1);
			s_list		*node = _alloc_rebind.allocate(1);

			_alloc.construct(node_value, val);
			node->value = node_value;
			node->next = _end_node;
			node->prev = _end_node;
			return (node);
		}

		void	_destroy_node(s_list *node) {
			_alloc.deallocate(node->value, 1);
			_alloc_rebind.deallocate(node, 1);
			_size--;
		}

		void	_first_last_node_init() {
			_first_node = _end_node->next;
			_last_node = _end_node->prev;
		}

		void	_insert_in_front_node(s_list *node_position, s_list *node) {
			node_position->prev->next = node;
			node->prev = node_position->prev;
			node->next = node_position;
			node_position->prev = node;
		}

		void	_check_for_insert() { // TODO think about better name
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
		explicit list(const allocator_type& alloc = allocator_type())
									: _size(0), _alloc(alloc) {
			_create_end_node();
			_first_node = _end_node;
			_last_node = _end_node;
		};

		explicit list(size_type, const value_type& val = value_type(),
													const allocator_type& alloc = allocator_type());

		template <class InputIterator>
		list(InputIterator, InputIterator, const allocator_type& alloc = allocator_type(),
				typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0);

		list(const list& list);
		list& operator=(const list&);
		~list();

		iterator				begin()			{ return (_end_node->next); }
		const_iterator			begin() const	{ return (_end_node->next); }
		iterator				end()			{ return (_end_node); }
		const_iterator			end() const		{ return (_end_node); }
		reverse_iterator		rbegin()		{ return (_end_node->prev); }
		const_reverse_iterator	rbegin() const	{ return (_end_node->prev); }
		reverse_iterator		rend()			{ return (_end_node); }
		const_reverse_iterator	rend() const	{ return (_end_node); }

		bool    				empty() const	{ return (!_size); }
		size_type				size() const	{return (_size); };
		size_type				max_size() const { return (std::numeric_limits<size_type>::max()); }

		reference				front()			{ return (*_first_node->value); }
		const_reference			front() const	{ return (*_first_node->value); }
		reference				back()			{ return (*_last_node->value); }
		const_reference			back() const	{ return (*_last_node->value); }

		template <class InputIterator>
		void			assign(InputIterator, InputIterator,
				   typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0);
		void			assign(size_type, const value_type&);
		void			push_front(const value_type&);
		void			pop_front();
		void			push_back(const value_type&);
		void			pop_back();
		iterator		insert(iterator, const value_type&);
		void			insert(iterator, size_type, const value_type&);
		template <class InputIterator>
		void			insert(iterator, InputIterator, InputIterator,
				   typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0);
		iterator		erase(iterator);
		iterator		erase(iterator, iterator);
		void			swap (list&);
		void			resize(size_type, value_type val = value_type());
		void			clear();

		void			splice(iterator position, list& x);
		void			splice(iterator position, list& x, iterator i);
		void			splice(iterator position, list& x, iterator first, iterator last);
		void			remove(const value_type& val);
		template <class Predicate>
		void			remove_if(Predicate pred);
		void			unique();
		template <class BinaryPredicate>
		void			unique(BinaryPredicate binary_pred);
		void			merge(list& x);
		template <class Compare>
		void			merge(list& x, Compare comp);
		void			sort();
		template <class Compare>
		void			sort(Compare comp);
		void			reverse();
	};

	template<class T, class Alloc>
	list<T, Alloc>::list(list::size_type n, const value_type &val, const allocator_type &alloc)
										: _size(0), _alloc(alloc) {
		_create_end_node();
		_first_last_node_init();

		for (size_type i = 0; i < n; ++i)
			push_back(val);
	}

	template<class T, class Alloc>
	template<class InputIterator>
	list<T, Alloc>::list(InputIterator first, InputIterator last, const allocator_type &alloc,
					 typename enable_if<std::__is_input_iterator<InputIterator>::value>::type *)
										: _first_node(0), _last_node(0), _size(0), _alloc(alloc) {
		_create_end_node();
		_first_last_node_init();

		for(; first != last; ++first)
			push_back(*first);
	}

	template<class T, class Alloc>
	list<T, Alloc>::list(const list &list)
								: _first_node(0), _last_node(0), _size(0), _alloc(list._alloc) {
		const_iterator	it = list.begin();

		_create_end_node();
		_first_last_node_init();

		for(; it != list.end(); ++it)
			push_back(*it);
	}

	template<class T, class Alloc>
	list<T, Alloc> & list<T,Alloc>::operator=(const list<T, Alloc> &list) {
		if (this == &list)
			return (*this);

		const_iterator	begin = list.begin();
		const_iterator	end = list.end();
		size_type		i = 0;
		s_list			*temp_node = _first_node;

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

	template<class T, class Alloc>
	list<T, Alloc>::~list() {
		s_list		*temp_node;

		for (size_type  i = 0; i < _size; ++i) {
			temp_node = _first_node;
			_first_node = _first_node->next;
			_alloc.deallocate(temp_node->value, 1);
			_alloc_rebind.deallocate(temp_node, 1);
		}
		_alloc.deallocate(_end_node->value, 1);
		_alloc_rebind.deallocate(_end_node, 1);
	}

	template<class T, class Alloc>
	void list<T, Alloc>::push_back(const value_type &val) {
		s_list		*node = _new_node_init(val);

		_end_node->prev = node;
		node->next = _end_node;
		node->prev = _last_node;
		_last_node->next = node;
		_last_node = _end_node->prev;

		if (_first_node == _end_node)
			_first_node = _last_node;
		_size++;
	}

	template<class T, class Alloc>
	void list<T, Alloc>::push_front(const value_type &val) {
		s_list		*node = _new_node_init(val);

		_end_node->next = node;
		node->prev = _end_node;
		node->next = _first_node;
		_first_node->prev = node;
		_first_node = _end_node->next;

		if (_last_node == _end_node)
			_last_node = _first_node;
		_size++;
	}

	template<class T, class Alloc>
	void list<T, Alloc>::pop_front() {
		s_list	*node;

		node = _first_node;
		_first_node->prev->next = _first_node->next;
		_first_node->next->prev = _first_node->prev;
		_destroy_node(node);
		_first_last_node_init();
	}

	template<class T, class Alloc>
	void list<T, Alloc>::pop_back() {
		s_list	*node;

		node = _last_node;
		_last_node->prev->next = _last_node->next;
		_last_node->next->prev = _last_node->prev;
		_destroy_node(node);
		_first_last_node_init();
	}

	template<class T, class Alloc>
	template<class InputIterator>
	void list<T, Alloc>::assign(InputIterator first, InputIterator last,
					typename enable_if<std::__is_input_iterator <InputIterator>::value>::type*) {
		size_type		i = 0;
		s_list			*temp_node = _first_node;

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

	template<class T, class Alloc>
	void list<T, Alloc>::assign(list::size_type n, const value_type &val) {
		s_list			*temp_node = _first_node;
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

	template<class T, class Alloc>
	typename list<T, Alloc>::iterator list<T,Alloc>::insert(iterator position,
														 					const value_type &val) {
		s_list		*temp_node = _new_node_init(val);
		s_list		*node_position = position._get_ptr();

		_insert_in_front_node(node_position, temp_node);
		_check_for_insert();
		_size++;
		return (temp_node);
	}

	template<class T, class Alloc>
		void	list<T,Alloc>::insert(iterator position, size_type n, const value_type& val) {
		s_list		*temp_node;
		s_list		*node_position = position._get_ptr();

		for (size_type i = 0; i < n; ++i) {
			temp_node = _new_node_init(val);
			_insert_in_front_node(node_position, temp_node);
			_size++;
		}
		_check_for_insert();
	}

	template<class T, class Alloc>
	template<class InputIterator>
	void list<T, Alloc>::insert(list::iterator position, InputIterator first, InputIterator last,
					typename enable_if<std::__is_input_iterator<InputIterator>::value>::type *) {
		s_list		*temp_node;
		s_list		*node_position = position._get_ptr();

		for (; first != last; ++first) {
			temp_node = _new_node_init(*first);
			_insert_in_front_node(node_position, temp_node);
			_size++;
		}
		_check_for_insert();
	}

	template<class T, class Alloc>
	void list<T, Alloc>::clear() {
		s_list		*temp_node;

		for (size_type i = 0; i < _size; ++i) {
			temp_node = _first_node;
			_first_node = _first_node->next;
			_alloc.deallocate(temp_node->value, 1);
			_alloc_rebind.deallocate(temp_node, 1);
		}
		_first_node = _end_node;
		_last_node = _end_node;
		_size = 0;
		_end_node->prev = _end_node; // TODO вынести в отдельный метод
		_end_node->next = _end_node;
	}

	template<class T, class Alloc>
	typename list<T, Alloc>::iterator list<T, Alloc>::erase(list::iterator position) {
		s_list		*node_position = position._get_ptr();
		iterator	it = node_position->next;

		node_position->prev->next = node_position->next;
		node_position->next->prev = node_position->prev;

		_destroy_node(node_position);
		_first_last_node_init();
		return (it);
	}

	template<class T, class Alloc>
	typename list<T, Alloc>::iterator list<T, Alloc>::erase(list::iterator first,
																			list::iterator last) {
		s_list		*first_node = first._get_ptr();
		s_list		*last_node = last._get_ptr();
		s_list		*temp_node;
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

	template<class T, class Alloc>
	void list<T, Alloc>::resize(list::size_type n, value_type val) {
		while (_size != n)
			(_size < n) ? push_back(val) : pop_back();
	}

	template<class T, class Alloc>
	void list<T, Alloc>::swap(list &list) {
		size_type	prev_this_size = _size;
		size_type	prev_list_size = list._size;
		iterator	this_it = begin();
		iterator	list_it = list.begin();
		value_type	val;

		if (_size > list._size)
			list.resize(_size);
		else if (list._size > _size)
			this->resize(list._size);

		for (size_type i = 0; i < _size; ++i) {
			val = *this_it;
			*this_it = *list_it;
			*list_it = val;
			++this_it;
			++list_it;
		}
			list.resize(prev_this_size);
			this->resize(prev_list_size);
	}

	template<class T, class Alloc>
	void list<T, Alloc>::remove(const value_type &val) {
		for (iterator it = begin(); it != end(); ++it)
			if (val == *it)
				it = erase(it);
	}

	template<class T, class Alloc>
	template<class Predicate>
	void list<T, Alloc>::remove_if(Predicate pred) {
		for (iterator it = begin(); it != end();)
			if (pred(*it))
				it = erase(it);
			else
				++it;
	}

	template<class T, class Alloc>
	void list<T, Alloc>::reverse() {
		value_type	temp_value;
		s_list		*start_list = _first_node;
		s_list		*end_list = _last_node;

		for (int i = 0; i < _size / 2; ++i) {
			temp_value = start_list->value;
			start_list->value = end_list->value;
			end_list->value = temp_value;
			start_list = start_list->next;
			end_list = end_list->prev;
		}
	}

	template<class T, class Alloc>
	void list<T, Alloc>::unique() {
		s_list		*list = _first_node;

		while (list != _end_node)
			if (*list->value == *list->next->value)
				list = erase(list)._get_ptr();
			else
				list = list->next;
	}

	template<class T, class Alloc>
	template<class BinaryPredicate>
	void list<T, Alloc>::unique(BinaryPredicate binary_pred) {
		s_list	*list = _first_node;

		while (list != _end_node)
			if (binary_pred(*list->value, *list->next->value))
				list = erase(list)._get_ptr();
			else
				list = list->next;
	}

	template<class T, class Alloc>
	void list<T, Alloc>::sort() {
		value_type	temp_value;
		s_list		*temp_node;
		s_list		*list;

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

	template<class T, class Alloc>
	template<class Compare>
	void list<T, Alloc>::sort(Compare comp) {
		value_type	temp_value;
		s_list		*temp_node;
		s_list		*list;

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

	template<class T, class Alloc>
	void list<T, Alloc>::splice(list::iterator position, list &x) {
		s_list	*node = position._get_ptr();

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

	template<class T, class Alloc>
	void list<T, Alloc>::splice(list::iterator position, list &x, list::iterator i) {
		s_list		*position_node = position._get_ptr();
		s_list		*node = i._get_ptr();

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

	template<class T, class Alloc>
	void list<T, Alloc>::splice(list::iterator position, list &x, list::iterator first,
																			list::iterator last) {
		s_list		*position_node = position._get_ptr();
		s_list		*first_node = first._get_ptr();
		s_list		*last_node = last._get_ptr();
		s_list		*new_last_node = last_node->prev;
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

	template<class T, class Alloc>
	void list<T, Alloc>::merge(list &x) {
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

	template<class T, class Alloc>
	template<class Compare>
	void list<T, Alloc>::merge(list &x, Compare comp) {
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

	template <class T, class Alloc>
	bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		typename list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
		typename list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

		while (it_lhs != lhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs == *it_rhs);
	}

	template <class T, class Alloc>
	bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		typename list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
		typename list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

		while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs != *it_rhs);
	}

	template <class T, class Alloc>
	bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		if (lhs.size() < rhs.size())
			return (true);
		typename list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
		typename list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

		while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs < *it_rhs);
	}

	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		if (lhs.size() < rhs.size())
			return (true);
		typename list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
		typename list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

		while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs <= *it_rhs);
	}

	template <class T, class Alloc>
	bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		if (lhs.size() > rhs.size())
			return (true);
		typename list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
		typename list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

		while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs > *it_rhs);
	}

	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		if (lhs.size() > rhs.size())
			return (true);
		typename list<T, Alloc>::const_iterator		it_lhs = lhs.begin();
		typename list<T, Alloc>::const_iterator		it_rhs = rhs.begin();

		while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs >= *it_rhs);
	}

	template <class T, class Alloc>
	void swap (list<T,Alloc>& x, list<T,Alloc>& y) {
		typename list<T,Alloc>::size_type	prev_this_size = x.size();
		typename list<T,Alloc>::size_type	prev_list_size = y.size();
		typename list<T,Alloc>::iterator	this_it = x.begin();
		typename list<T,Alloc>::iterator	list_it = y.begin();
		typename list<T,Alloc>::value_type	val;

		if (x.size() > y.size())
			y.resize(x.size());
		else if (y.size() > x.size())
			x.resize(y.size());

		for (typename list<T,Alloc>::size_type i = 0; i < x.size(); ++i) {
			val = *this_it;
			*this_it = *list_it;
			*list_it = val;
			++this_it;
			++list_it;
		}
		y.resize(prev_this_size);
		x.resize(prev_list_size);

	}
}

#endif
