/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_random_access_iterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:21:42 by imicah            #+#    #+#             */
/*   Updated: 2020/10/26 17:24:03 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_REVERSE_RANDOM_ACCESS_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>

namespace ft
{
	template<class T>
	class	rev_random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T*		_ptr;

	public:
		rev_random_access_iterator();
		rev_random_access_iterator(const rev_random_access_iterator<T> &);
		~rev_random_access_iterator();

		rev_random_access_iterator<T>	&operator=(const rev_random_access_iterator<T> &);

		bool	operator==(const rev_random_access_iterator<T> &);
		bool	operator!=(const rev_random_access_iterator<T> &);
		bool	operator<(const rev_random_access_iterator<T> &);
		bool	operator<=(const rev_random_access_iterator<T> &);
		bool	operator>(const rev_random_access_iterator<T> &);
		bool	operator>=(const rev_random_access_iterator<T> &);

		rev_random_access_iterator<T>	&operator++();
		rev_random_access_iterator<T>	&operator--();

		rev_random_access_iterator<T>	operator++(int);
		rev_random_access_iterator<T>	operator--(int);

		rev_random_access_iterator<T>	operator+(rev_random_access_iterator<T> &);
		rev_random_access_iterator<T>	operator-(rev_random_access_iterator<T> &);

		rev_random_access_iterator<T>	operator+=(rev_random_access_iterator<T> &);
		rev_random_access_iterator<T>	operator-=(rev_random_access_iterator<T> &);
		rev_random_access_iterator<T>	operator[](size_t);

		T		&operator*();
		T		*operator->();

		T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше

	};

	template<class T>
	class	const_rev_random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T*		_ptr;

	public:
		const_rev_random_access_iterator();
		const_rev_random_access_iterator(const const_rev_random_access_iterator<T> &);
		const_rev_random_access_iterator(const rev_random_access_iterator<T> &);
		~const_rev_random_access_iterator();

		const_rev_random_access_iterator<T>	&operator=(const const_rev_random_access_iterator<T> &);
		const_rev_random_access_iterator<T>	&operator=(const rev_random_access_iterator<T> &);

		bool	operator==(const const_rev_random_access_iterator<T> &);
		bool	operator!=(const const_rev_random_access_iterator<T> &);
		bool	operator<(const const_rev_random_access_iterator<T> &);
		bool	operator<=(const const_rev_random_access_iterator<T> &);
		bool	operator>(const const_rev_random_access_iterator<T> &);
		bool	operator>=(const const_rev_random_access_iterator<T> &);

		const_rev_random_access_iterator<T>	&operator++();
		const_rev_random_access_iterator<T>	&operator--();

		const_rev_random_access_iterator<T>	operator++(int);
		const_rev_random_access_iterator<T>	operator--(int);

		const_rev_random_access_iterator<T>	operator+(const_rev_random_access_iterator<T> &);
		const_rev_random_access_iterator<T>	operator-(const_rev_random_access_iterator<T> &);

		const_rev_random_access_iterator<T>	operator+=(const_rev_random_access_iterator<T> &);
		const_rev_random_access_iterator<T>	operator-=(const_rev_random_access_iterator<T> &);
		const T								operator[](size_t);

		T		&operator*();
		T		*operator->();

		T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше

	};

}


#endif //FT_CONTAINERS_REVERSE_RANDOM_ACCESS_ITERATOR_HPP
