/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:19:10 by imicah            #+#    #+#             */
/*   Updated: 2020/10/20 14:16:22 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef list_hpp
# define list_hpp

# include <iostream>
#include "Iterator_list.hpp"

namespace ft
{
	namespace
	{
		template<class T>
		struct					s_list {
			T					value;
			struct s_list<T>	*next;
			struct s_list<T>	*prev;
		};

		template<bool B, class T = void>
		struct enable_if {};

		template<class T>
		struct enable_if<true, T> { typedef T type; };
	}

	template<class T, class Alloc = std::allocator<T> >
	class	list
	{
	public:
		typedef T															value_type;
		typedef Alloc														allocator_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef typename allocator_type::template rebind<s_list<T> >::other	alloc_rebind;
		typedef std::iterator<std::bidirectional_iterator_tag, T>			iterator;
		typedef std::iterator<std::bidirectional_iterator_tag, const T>		const_iterator;
		typedef std::reverse_iterator<iterator>								reverse_iterator;
		typedef std::reverse_iterator<const_iterator>						const_reverse_iterator;
		typedef std::ptrdiff_t												difference_type;
		typedef std::size_t													size_type;

	private:
		s_list<value_type>	*_list;
		s_list<value_type>	*_first_node;
		s_list<value_type>	*_last_node;
		size_type			_size;
		alloc_rebind		_alloc;

	public:
		explicit list(const allocator_type& alloc = allocator_type())
											: _list(0), _first_node(0), _last_node(0), _size(0) { };

		explicit list(size_type n, const value_type& val = value_type(),
												const allocator_type& alloc = allocator_type()) : _size(n) {
			s_list<value_type>	*temp_node;

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
		};

		template <class InputIterator>
		list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0);
		list (const list& x);
		list& operator=(const list& x);
		~list() { };

		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		bool    		empty() const;
		size_type		size() const;
		size_type		max_size() const;

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
