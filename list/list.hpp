/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:19:10 by imicah            #+#    #+#             */
/*   Updated: 2020/10/20 12:46:39 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef list_hpp
# define list_hpp

# include <iostream>
#include "Iterator_list.hpp"

namespace ft
{
	template<class T>
	struct					s_list {
		T					value;
		struct s_list<T>	*next;
		struct s_list<T>	*prev;
	};

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
		typedef std::iterator<std::bidirectional_iterator_tag, T>			iterator;
		typedef std::iterator<std::bidirectional_iterator_tag, const T>		const_iterator;
		typedef std::reverse_iterator<iterator>								reverse_iterator;
		typedef std::reverse_iterator<const_iterator>						const_reverse_iterator;
		typedef std::ptrdiff_t												difference_type;
		typedef std::size_t													size_type;
	};

}

#endif
