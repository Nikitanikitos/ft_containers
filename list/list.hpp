/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:19:10 by imicah            #+#    #+#             */
/*   Updated: 2020/10/26 09:44:57 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef list_hpp
# define list_hpp

# include <iostream>
# include <string>
# include "Iterator_list.hpp"
# include "Reverse_iterator_list.hpp"



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
		typedef				T									value_type;
		typedef				Alloc								allocator_type;
		typedef typename	allocator_type::reference			reference;
		typedef typename	allocator_type::const_reference		const_reference;
		typedef typename	allocator_type::pointer				pointer;
		typedef typename	allocator_type::const_pointer		const_pointer;
		typedef 			IteratorList<s_list, T>				iterator;
		typedef				ConstIteratorList<s_list, T>		const_iterator;
		typedef				RevIteratorList<s_list, T>			reverse_iterator;
		typedef				ConstRevIteratorList<s_list, T>		const_reverse_iterator;
		typedef				std::ptrdiff_t						difference_type;
		typedef				std::size_t							size_type;

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

		void	_first_node_init(s_list *node) {
			_last_node = node;
			_first_node = _last_node;
		}

		void	_insert_in_front_of_the_node(s_list *node_position, s_list *node) {
			node->prev = node_position->prev;
			node->next = node_position;
			node_position->prev->next = node;
			node_position->prev = node;
		}

		void	_check_first_or_end_node(s_list *node_position, s_list *node) {

			if (_first_node == node_position)
				_first_node = node;
			else if (_end_node == node_position)
				_last_node = node;
			if (!_first_node)
				_first_node = _last_node;
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
									: _first_node(0), _last_node(0), _size(0), _alloc(alloc) {
			_create_end_node();
		};

		explicit list(size_type, const value_type& val = value_type(),
													const allocator_type& alloc = allocator_type());

		template <class InputIterator>
		list(InputIterator, InputIterator, const allocator_type& alloc = allocator_type(),
				typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0);

		list(const list& list);
		list& operator=(const list&);
		~list();

		iterator				begin()  { return (_end_node->next); }
		const_iterator			begin() const { return (_end_node->next); }
		iterator				end() { return (_end_node); }
		const_iterator			end() const { return (_end_node); }
		reverse_iterator		rbegin() { return (_end_node->prev); }
		const_reverse_iterator	rbegin() const { return (_end_node->prev); }
		reverse_iterator		rend() { return (_end_node); }
		const_reverse_iterator	rend() const { return (_end_node); }

		bool    				empty() const { return (!_size); }
		size_type				size() const {return (_size); };
		size_type				max_size() const { return (std::numeric_limits<size_type>::max()); }

		reference				front()
							{ return (_first_node) ? (*_first_node->value) : (*_end_node->value); }
		const_reference			front() const
							{ return (_first_node) ? (*_first_node->value) : (*_end_node->value); }
		reference				back()
							{ return (_last_node) ? (*_last_node->value) : (*_end_node->value); }
		const_reference			back() const
							{ return (_last_node) ? (*_last_node->value) : (*_end_node->value); }

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
										: _first_node(0), _last_node(0), _size(0), _alloc(alloc) {
		_create_end_node();

		if (n == 0) return ;
		for (size_type i = 0; i < n; ++i)
			push_back(val);
		_tie_end_node();
	}

	template<class T, class Alloc>
	template<class InputIterator>
	list<T, Alloc>::list(InputIterator first, InputIterator last, const allocator_type &alloc,
					 typename enable_if<std::__is_input_iterator<InputIterator>::value>::type *)
										: _first_node(0), _last_node(0), _size(0), _alloc(alloc) {
		_create_end_node();
		for(; first != last; ++first)
			push_back(*first);
		_tie_end_node();
	}

	template<class T, class Alloc>
	list<T, Alloc>::list(const list &list)
								: _first_node(0), _last_node(0), _size(0), _alloc(list._alloc) {
		const_iterator	it = list.begin();

		_create_end_node();
		for(; it != list.end(); ++it)
			push_back(*it);
		_tie_end_node();
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
		_tie_end_node();
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
	}

	template<class T, class Alloc>
	void list<T, Alloc>::push_back(const value_type &val) {
		s_list		*node = _new_node_init(val);

		if (!_last_node)
			_first_node_init(node);
		else {
			node->prev = _last_node;
			_last_node->next = node;
			_last_node = node;
		}
		_tie_end_node();
		_size++;
	}

	template<class T, class Alloc>
	void list<T, Alloc>::push_front(const value_type &val) {
		s_list		*node = _new_node_init(val);

		if (!_first_node)
			_first_node_init(node);
		else {
			node->next = _first_node;
			_first_node->prev = node;
			_first_node = node;
		}
		_tie_end_node();
		_size++;
	}

	template<class T, class Alloc>
	void list<T, Alloc>::pop_front() {
		s_list	*node;

		node = _first_node;
		_first_node->prev->next = _first_node->next;
		_first_node->next->prev = _first_node->prev;
		_first_node = _end_node->next;
		_destroy_node(node);
	}

	template<class T, class Alloc>
	void list<T, Alloc>::pop_back() {
		s_list	*node;

		node = _last_node;
		_last_node->prev->next = _last_node->next;
		_last_node->next->prev = _last_node->prev;
		_last_node = _end_node->prev;
		_destroy_node(node);
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
		_tie_end_node();
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
		_tie_end_node();
	}

	template<class T, class Alloc>
	typename list<T, Alloc>::iterator list<T,Alloc>::insert(iterator position,
														 					const value_type &val) {
		s_list		*temp_node;
		s_list		*node_position = position._get_ptr();

		temp_node = _new_node_init(val);
		_insert_in_front_of_the_node(node_position, temp_node);
		_check_first_or_end_node(node_position, temp_node);
		_size++;
		return (temp_node);
	}

	template<class T, class Alloc>
		void	list<T,Alloc>::insert(iterator position, size_type n, const value_type& val) {
		s_list		*temp_node;
		s_list		*node_position = position._get_ptr();

		if (!n)
			return ;
		for (size_type i = 0; i < n; ++i) {
			temp_node = _new_node_init(val);
			_insert_in_front_of_the_node(node_position, temp_node);
			_size++;
		}
		_check_first_or_end_node(node_position, temp_node);
	}

	template<class T, class Alloc>
	template<class InputIterator>
	void list<T, Alloc>::insert(list::iterator position, InputIterator first, InputIterator last,
					typename enable_if<std::__is_input_iterator<InputIterator>::value>::type *) {
		s_list		*temp_node;
		s_list		*node_position = position._get_ptr();

		if (first == last)
			return ;
		for (; first != last; ++first) {
			temp_node = _new_node_init(*first);
			_insert_in_front_of_the_node(node_position, temp_node);
			_size++;
		}
		_check_first_or_end_node(node_position, temp_node);
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
		_first_node = 0;
		_last_node = 0;
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

		if (_size == 0) {
			_first_node = 0;
			_last_node = 0;
		}
		else {
			_last_node = _end_node->prev;
			_first_node = _end_node->next;
		}
		return (it);
	}

	template<class T, class Alloc>
	typename list<T, Alloc>::iterator list<T, Alloc>::erase(list::iterator first,
																			list::iterator last) {
		s_list		*first_node = first._get_ptr();
		s_list		*last_node = last._get_ptr();
		s_list		*temp_node;
		iterator	it;

		if (first == last)
			return (first);
		first_node->prev->next = last_node;
		last_node->prev = first_node->prev;
		it = last_node;
		if (first_node == _first_node)
			_first_node = _end_node->next;
		else if (last_node == _last_node)
			_last_node = last_node;
		while (first_node != last_node) {
			temp_node = first_node;
			first_node = first_node->next;
			_destroy_node(temp_node);
		}
		return (it);
	}

	template<class T, class Alloc>
	void list<T, Alloc>::resize(list::size_type n, value_type val) {
		while (_size != n) {
			if (_size < n)
				push_back(val);
			else
				pop_back();
		}
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
		bool		flag;

		list = _first_node;
		while (list != _last_node) {
			flag = false;
			temp_node = list->next;
			while (temp_node != _last_node) {
				if (*list->value > *temp_node->value) {
					temp_value = *list->value;
					*list->value = *temp_node->value;
					*temp_node->value = temp_value;
					flag = true;
				}
				temp_node = temp_node->next;
			}
			if (!flag)
				return ;
			list = list->next;
		}
	}

	template<class T, class Alloc>
	template<class Compare>
	void list<T, Alloc>::sort(Compare comp) {
		value_type	temp_value;
		s_list		*temp_node;
		s_list		*list;
		bool		flag;

		list = _first_node;
		while (list != _last_node) {
			flag = false;
			temp_node = list->next;
			while (temp_node != _end_node) {
				if (!comp(*list->value, *temp_node->value)) {
					temp_value = *list->value;
					*list->value = *temp_node->value;
					*temp_node->value = temp_value;
					flag = true;
				}
				temp_node = temp_node->next;
			}
			if (!flag)
				return ;
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

		_first_node = _end_node->next;
		_last_node = _last_node->prev;

		x._end_node->next = x._end_node;
		x._end_node->prev = x._end_node;
		x._last_node = 0;
		x._first_node = 0;

		_size += x._size;
		x._size = 0;
	}

	template<class T, class Alloc>
	void list<T, Alloc>::splice(list::iterator position, list &x, list::iterator i) {
		s_list		*list = position._get_ptr();
		s_list		*node = i._get_ptr();
		value_type	segment_size = _get_segment_size(i, x.end());

		_size += segment_size;
		x._size -= segment_size;

		node->prev->next = node->next;
		node->next->prev = node->prev;

		x._first_node = x._end_node->next;
		x._last_node = x._last_node->prev;

		list->prev->next = node;
		node->prev = list->prev;
		node->next = list;
		list->prev = node;

		_first_node = _end_node->next;
		_last_node = _last_node->prev;

	}

	template<class T, class Alloc>
	void list<T, Alloc>::splice(list::iterator position, list &x, list::iterator first,
																			list::iterator last) {
		s_list		*list = position._get_ptr();
		s_list		*first_node = first._get_ptr();
		s_list		*last_node = last._get_ptr();
		value_type	segment_size = _get_segment_size(first, last);

		_size += segment_size;
		x._size -= segment_size;

		first_node->prev->next = last_node->next;
		last_node->next->prev = first_node->prev;

		x._first_node = x._end_node->next;
		x._last_node = x._last_node->prev;

		list->prev->next = first_node;
		first_node->prev = list->prev;
		last_node->prev = list;
		list->prev = last_node;

		_first_node = _end_node->next;
		_last_node = _last_node->prev;
	}

	template<class T, class Alloc>
	void list<T, Alloc>::merge(list &x) {
		iterator	it = begin();
		iterator	x_it = x.begin();

		while (it != end()) {
			while (*x_it <= *it) {
				insert(it, *x_it);
				x_it = x.erase(x_it);
			}
			++it;
		}
	}

	template<class T, class Alloc>
	template<class Compare>
	void list<T, Alloc>::merge(list &x, Compare comp) {
		iterator	it = begin();
		iterator	x_it = x.begin();

		while (it != end()) {
			while (comp(*x_it, *it)) {
				insert(it, *x_it);
				x_it = x.erase(x_it);
			}
			++it;
		}
	}

	template <class T, class Alloc>
	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
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
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
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
	bool operator< (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
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
	bool operator> (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
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
}

#endif
