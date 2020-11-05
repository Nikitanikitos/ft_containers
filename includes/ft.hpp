/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:33:02 by imicah            #+#    #+#             */
/*   Updated: 2020/11/05 13:10:30 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
# define FT_HPP

namespace ft {
	template < class Key, class Value, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,Value> > >
	class map;

	template < class Key, class Value, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,Value> > >
	class Tree;
}

#endif