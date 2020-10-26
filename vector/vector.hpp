/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:55:36 by imicah            #+#    #+#             */
/*   Updated: 2020/10/26 17:30:41 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

# include <iostream>
# include <string>


namespace ft
{
	namespace {
		template<bool B, class T = void>
		struct enable_if {};

		template<class T>
		struct enable_if<true, T> { typedef T type; };
	}

	template <class T, class Alloc = std::allocator<T> >
	class	vector
	{
	public:
		typedef				T									value_type;
		typedef				Alloc								allocator_type;
		typedef typename	allocator_type::reference			reference;
		typedef typename	allocator_type::const_reference		const_reference;
		typedef typename	allocator_type::pointer				pointer;
		typedef typename	allocator_type::const_pointer		const_pointer;
		typedef 			std::reverse_iterator<T>			iterator;
		typedef				std::reverse_iterator<T>			const_iterator;
		typedef				std::reverse_iterator<T>			reverse_iterator;
		typedef				std::reverse_iterator<T>			const_reverse_iterator;
		typedef				std::ptrdiff_t						difference_type;
		typedef				std::size_t							size_type;

	private:
		T*				_ptr;
		size_type		_capacity;
		size_type		_size;

	public:
		explicit	vector(const allocator_type& alloc = allocator_type());
		explicit	vector(size_type n, const value_type& val = value_type(),
				  									const allocator_type& alloc = allocator_type());

		template <class InputIterator>
					vector(InputIterator first, InputIterator last,
													const allocator_type& alloc = allocator_type());
					vector(const vector& x);

		iterator				begin()			{ return (_ptr); }
		const_iterator			begin() const	{ return (_ptr); }
		iterator				end()			{ return (_ptr); }
		const_iterator			end() const		{ return (_ptr); }
		reverse_iterator		rbegin()		{ return (_ptr); }
		const_reverse_iterator	rbegin() const	{ return (_ptr); }
		reverse_iterator		rend()			{ return (_ptr); }
		const_reverse_iterator	rend() const	{ return (_ptr); }

		size_type				size() const {return (_size); };
		size_type				max_size() const { return (std::numeric_limits<size_type>::max()); }
		void					resize (size_type n, value_type val = value_type());
		size_type				capacity() const { return (_capacity); }
		bool					empty() const { return (!_size); }
		void					reserve (size_type n);

		reference				operator[] (size_type n) { return (_ptr[n]);}
		const_reference			operator[] (size_type n) const { return (_ptr[n]); }
		reference				at(size_type n);
		const_reference			at(size_type n) const;
		reference				front()			{ return (_ptr[0]); }
		const_reference			front() const	{ return (_ptr[0]); }
		reference				back()			{ return (_ptr[_size - 1]); }
		const_reference			back() const	{ return (_ptr[_size - 1]); }

		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last);
		void					assign(size_type n, const value_type& val);
		void					push_back(const value_type& val);
		void					pop_back();
		iterator				insert (iterator position, const value_type& val);
		void					insert (iterator position, size_type n, const value_type& val);

		template <class InputIterator>
		void					insert (iterator position, InputIterator first, InputIterator last);
		iterator				erase (iterator position);
		iterator				erase (iterator first, iterator last);
		void					swap (vector& x);
		void					clear();
	};

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
}

#endif
