/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:33:02 by imicah            #+#    #+#             */
/*   Updated: 2020/11/11 15:15:22 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_FT_HPP
# define FT_CONTAINERS_FT_HPP

# include <iostream>
# include <string>

namespace ft {
	template<bool B, class T = void>
	struct enable_if { };

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <class Key, class Value, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,Value> > >
	class	map;

	template<class T, class Alloc = std::allocator<T> >
	class	list;

	template <class T, class Alloc = std::allocator<T> >
	class	deque;

	template <class T, class Container = deque<T> >
	class	stack;

	template <class T, class Container = deque<T> >
	class	queue;

	template <class T, class Alloc = std::allocator<T> >
	class	vector;

	template <class Key, class Value, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,Value> > >
	class	tree;
}

#endif
