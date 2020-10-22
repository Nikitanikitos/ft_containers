/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:19:10 by imicah            #+#    #+#             */
/*   Updated: 2020/10/22 23:12:57 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef list_hpp
# define list_hpp

# include <iostream>
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
		size_type				max_size() const;

		reference		front() { return (*_first_node->value); }
		const_reference	front() const { return (*_first_node->value); }
		reference		back() { return (*_last_node->value); }
		const_reference	back() const { return (*_last_node->value); }

		template <class InputIterator>
		void			assign(InputIterator first, InputIterator last);
		void			assign(size_type n, const value_type& val);
		void			push_front(const value_type& val);
		void			pop_front();
		void			push_back(const value_type& val);
		void			pop_back();
		iterator		insert(iterator position, const value_type& val);
		void			insert(iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void			insert(iterator position, InputIterator first, InputIterator last);
		iterator		erase(iterator position);
		iterator		erase(iterator first, iterator last);
		void			swap (list& x);
		void			resize(size_type n, value_type val = value_type());
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
			push_front(val);
		_tie_end_node();
	}

	template<class T, class Alloc>
	template<class InputIterator>
	list<T, Alloc>::list(InputIterator first, InputIterator last, const allocator_type &alloc,
					 typename enable_if<std::__is_input_iterator<InputIterator>::value>::type *)
										: _first_node(0), _last_node(0), _size(0), _alloc(alloc) {
		_create_end_node();
		for(; first != last; ++first)
			push_front(*first);
		_tie_end_node();
	}

	template<class T, class Alloc>
	list<T, Alloc>::list(const list &list)
								: _first_node(0), _last_node(0), _size(0), _alloc(list._alloc) {
		const_iterator	it = list.begin();

		_create_end_node();
		for(; it != list.end(); ++it)
			push_front(*it);
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
				_alloc.destroy(temp_node->value);
				_alloc.construct(temp_node->value, *begin);
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
		value_type	*value_node = _alloc.allocate(1);
		s_list		*temp_node = _alloc_rebind.allocate(1);

		_alloc.construct(value_node, val);
		temp_node->value = value_node;
		temp_node->next = _end_node;
		temp_node->prev = _end_node;
		if (!_last_node) {
			_last_node = temp_node;
			_first_node = _last_node;
		}
		else {
			temp_node->prev = _last_node;
			_last_node->next = temp_node;
			_last_node = temp_node;
		}
		_tie_end_node();
		_size++;
	}

	template<class T, class Alloc>
	void list<T, Alloc>::push_front(const value_type &val) {
		s_list		*temp_node	= _alloc_rebind.allocate(1);
		value_type	*value_node	= _alloc.allocate(1);

		_alloc.construct(value_node, val);
		temp_node->value = value_node;
		temp_node->next = _end_node;
		temp_node->prev = _end_node;
		if (!_first_node)
		{
			_first_node = temp_node;
			_last_node = _first_node;
		}
		else {
			temp_node->next = _first_node;
			_first_node->prev = temp_node;
			_first_node = temp_node;
		}
		_tie_end_node();
		_size++;
	}

	template<class T, class Alloc>
	void list<T, Alloc>::pop_front() {
		s_list	*temp_node;

		temp_node = _first_node;
		_first_node = _first_node->next;
		_alloc.deallocate(temp_node->value, 1);
		_alloc_rebind.deallocate(temp_node, 1);
	}

	template<class T, class Alloc>
	void list<T, Alloc>::pop_back() {
		s_list	*temp_node;

		temp_node = _last_node;
		_last_node = _last_node->prev;
		_alloc.deallocate(temp_node->value, 1);
		_alloc_rebind.deallocate(temp_node, 1);
	}

	template <class T, class Alloc>
	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator< (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator> (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
}

#endif
