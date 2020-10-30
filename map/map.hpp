/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:09:48 by imicah            #+#    #+#             */
/*   Updated: 2020/10/30 13:45:13 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_MAP_HPP
# define FT_CONTAINERS_MAP_HPP

# include <iostream>
# include <utility>
# include "bidirectional_iterator.hpp"
# include "reverse_bidirectional_iterator.hpp"

# define RED	true
# define BLACK	false

namespace ft
{
	namespace {
		template<bool B, class T = void>
		struct enable_if {};

		template<class T>
		struct enable_if<true, T> { typedef T type; };
	}

	template < class Key, class Value, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,Value> > >
	class map
	{
	private:
		struct		s_node {
			std::pair<Key, Value>	*val;
			struct s_node			*left;
			struct s_node			*right;
			struct s_node			*parent;
			bool					color;
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
		typedef 			bidirectional_iterator<s_node, value_type>				iterator;
		typedef				const_bidirectional_iterator<s_node, value_type>		const_iterator;
		typedef				rev_bidirectional_iterator<s_node, value_type>			reverse_iterator;
		typedef				const_rev_bidirectional_iterator<s_node, value_type>	const_reverse_iterator;
		typedef				std::ptrdiff_t											difference_type;
		typedef				std::size_t												size_type;

		typedef typename	allocator_type::template rebind<s_node>::other			alloc_rebind;

	private:
		s_node			*_root;
		s_node			*_end_node;
		size_type		_size;
		alloc_rebind	_alloc_rebind;
		allocator_type	_alloc;

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
										const allocator_type& alloc = allocator_type(),
										typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0);
		map(const map& x);
		~map();
		map&	operator=(const map& x);

		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		bool					empty() const;
		size_type				size() const;
		size_type				max_size() const;

		mapped_type&			operator[](const key_type& k);

		std::pair<iterator,bool>	insert(const value_type& val);
		iterator					insert(iterator position, const value_type& val);
		template <class InputIterator>
		void						insert(InputIterator first, InputIterator last);
		void						erase(iterator position);
		size_type					erase(const key_type& k);
		void						erase(iterator first, iterator last);
		void						swap(map& x);
		void						clear();

		key_compare					key_comp() const;
		value_compare				value_comp() const;

		iterator					find(const key_type& k);
		const_iterator				find(const key_type& k) const;

		size_type					count(const key_type& k) const;
		iterator					lower_bound(const key_type& k);
		const_iterator				lower_bound(const key_type& k) const;
		iterator					upper_bound(const key_type& k);
		const_iterator				upper_bound(const key_type& k) const;

		std::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
		std::pair<iterator,iterator>				equal_range (const key_type& k);
	};
}

#endif
