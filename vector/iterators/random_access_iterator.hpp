/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:09:50 by imicah            #+#    #+#             */
/*   Updated: 2020/10/26 17:24:57 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
# define FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include <string>

namespace ft
{
	template<class T>
	class	random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T*		_ptr;

	public:
		random_access_iterator();
		random_access_iterator(const random_access_iterator<T> &);
		~random_access_iterator();

		random_access_iterator<T>	&operator=(const random_access_iterator<T> &);

		bool	operator==(const random_access_iterator<T> &);
		bool	operator!=(const random_access_iterator<T> &);
		bool	operator<(const random_access_iterator<T> &);
		bool	operator<=(const random_access_iterator<T> &);
		bool	operator>(const random_access_iterator<T> &);
		bool	operator>=(const random_access_iterator<T> &);

		random_access_iterator<T>	&operator++();
		random_access_iterator<T>	&operator--();

		random_access_iterator<T>	operator++(int);
		random_access_iterator<T>	operator--(int);

		random_access_iterator<T>	operator+(random_access_iterator<T> &);
		random_access_iterator<T>	operator-(random_access_iterator<T> &);

		random_access_iterator<T>	operator+=(random_access_iterator<T> &);
		random_access_iterator<T>	operator-=(random_access_iterator<T> &);
		random_access_iterator<T>	operator[](size_t);

		T		&operator*();
		T		*operator->();

		T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше

	};

	template<class T>
	class	const_random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T*		_ptr;

	public:
		const_random_access_iterator();
		const_random_access_iterator(const const_random_access_iterator<T> &);
		const_random_access_iterator(const random_access_iterator<T> &);
		~const_random_access_iterator();

		const_random_access_iterator<T>	&operator=(const const_random_access_iterator<T> &);
		const_random_access_iterator<T>	&operator=(const random_access_iterator<T> &);

		bool	operator==(const const_random_access_iterator<T> &);
		bool	operator!=(const const_random_access_iterator<T> &);
		bool	operator<(const const_random_access_iterator<T> &);
		bool	operator<=(const const_random_access_iterator<T> &);
		bool	operator>(const const_random_access_iterator<T> &);
		bool	operator>=(const const_random_access_iterator<T> &);

		const_random_access_iterator<T>	&operator++();
		const_random_access_iterator<T>	&operator--();

		const_random_access_iterator<T>	operator++(int);
		const_random_access_iterator<T>	operator--(int);

		const_random_access_iterator<T>	operator+(const_random_access_iterator<T> &);
		const_random_access_iterator<T>	operator-(const_random_access_iterator<T> &);

		const_random_access_iterator<T>	operator+=(const_random_access_iterator<T> &);
		const_random_access_iterator<T>	operator-=(const_random_access_iterator<T> &);
		const T							operator[](size_t);


		T		&operator*();
		T		*operator->();

		T*		_get_ptr() const { return(_ptr); } // TODO придумать что нибудь по лучше

	};

}

#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
