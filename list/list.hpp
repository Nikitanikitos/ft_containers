/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:19:10 by imicah            #+#    #+#             */
/*   Updated: 2020/10/20 17:06:31 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef list_hpp
# define list_hpp

# include <iostream>
# include "Iterator_list.hpp"

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
			T				value;
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
		typedef 			IteratorList<s_list>				iterator;
		typedef				IteratorList<const s_list>			const_iterator;
		typedef				ReverseIteratorList<s_list>			reverse_iterator;
		typedef				ReverseIteratorList<const s_list>	const_reverse_iterator;
		typedef				std::ptrdiff_t						difference_type;
		typedef				std::size_t							size_type;

		typedef typename allocator_type::template rebind<s_list>::other		alloc_rebind;

	private:
		s_list			*_first_node;
		s_list			*_last_node;
		size_type		_size;
		alloc_rebind	_alloc;

	public:
		explicit list(const allocator_type& alloc = allocator_type())
											: _first_node(0), _last_node(0), _size(0) { };

		explicit list(size_type n, const value_type& val = value_type(),
										const allocator_type& alloc = allocator_type());

		template <class InputIterator>
		list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0);
		list(const list& x);
		list& operator=(const list& x);
		~list() { };

		iterator				begin()  { return (_first_node); }
		const_iterator			begin() const  { return (_first_node); }
		iterator				end() { return (_last_node->next); }
		const_iterator			end() const { return (_last_node->next); }
		reverse_iterator		rbegin() { return (_last_node); }
		const_reverse_iterator	rbegin() const { return (_last_node); }
		reverse_iterator		rend() { return (_first_node); }
		const_reverse_iterator	rend() const { return (_first_node); }

		bool    				empty() const { return (_size == 0); }
		size_type				size() const {return (_size); };
		size_type				max_size() const;

		reference		front();
		const_reference	front() const;
		reference		back();
		const_reference	back() const;

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
																						: _size(n) {
		s_list	*temp_node;

		_first_node = _alloc.allocate(1);
		_first_node->value = val;
		_first_node->next = 0;
		_first_node->prev = 0;
		temp_node = _first_node;
		for (int i = 1; i < n; ++i) {
			temp_node->next = _alloc.allocate(1);
			temp_node->next->value = val;
			temp_node->next->prev = temp_node;
			temp_node->next->next = 0;
			temp_node = temp_node->next;
		}
		_last_node = temp_node;
	}

	template<class T, class Alloc>
	template<class InputIterator>
	list<T, Alloc>::list(InputIterator first, InputIterator last, const allocator_type &alloc,
					 typename enable_if<std::__is_input_iterator<InputIterator>::value>::type *) { }

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
