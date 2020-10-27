/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:55:36 by imicah            #+#    #+#             */
/*   Updated: 2020/10/27 14:32:28 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

# include <iostream>
# include <string>
# include "random_access_iterator.hpp"
# include "reverse_random_access_iterator.hpp"

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
		typedef				T											value_type;
		typedef				Alloc										alloc_type;
		typedef typename	alloc_type::reference						reference;
		typedef typename	alloc_type::const_reference					const_reference;
		typedef typename	alloc_type::pointer							pointer;
		typedef typename	alloc_type::const_pointer					const_pointer;
		typedef 			ft::random_access_iterator<T>				iterator;
		typedef				ft::const_random_access_iterator<T>			const_iterator;
		typedef				ft::rev_random_access_iterator<T>			reverse_iterator;
		typedef				ft::const_rev_random_access_iterator<T>		const_reverse_iterator;
		typedef				std::ptrdiff_t								difference_type;
		typedef				std::size_t									size_type;

	private:
		T*				_ptr;
		size_type		_capacity;
		size_type		_size;
		alloc_type	_alloc;

		void		_realloc(const size_type n) {
			T*			temp_ptr = _alloc.allocate(_capacity + n);

			for (int i = 0; i < _size; ++i)
				_alloc.construct(temp_ptr + i, _ptr[i]);
			_alloc.deallocate(_ptr, _capacity);
			_capacity += n;
			_ptr = temp_ptr;
		}

	public:
		explicit	vector(const alloc_type& alloc = alloc_type())
										: _ptr(0), _capacity(0), _size(0), _alloc(alloc) { }

		explicit	vector(size_type n, const value_type& val = value_type(),
				  									const alloc_type& alloc = alloc_type());

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const alloc_type& alloc = alloc_type(),
	   				typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0);

		vector(const vector& x);

		~vector() { _alloc.deallocate(_ptr, _capacity); }

		vector& operator=(const vector& x) {
			if (this != &x) {
				_alloc.deallocate(_ptr, _capacity);
				_ptr = _alloc.allocate(x._capacity);
				for (size_type i = 0; i < x._size; ++i)
					_alloc.construct(_ptr + i, x[i]);
				_size = x._size;
				_capacity = x._capacity;
			}
			return (*this);
		}

		iterator				begin()
												{ return (random_access_iterator<T>(&_ptr[0])); }
		const_iterator			begin() const
											{ return (const_random_access_iterator<T>(&_ptr[0])); }
		iterator				end()
											{ return (random_access_iterator<T>(&_ptr[_size])); }
		const_iterator			end() const
										{ return (const_random_access_iterator<T>(&_ptr[_size])); }
		reverse_iterator		rbegin()
									{ return (rev_random_access_iterator<T>(&_ptr[_size - 1])); }
		const_reverse_iterator	rbegin() const
								{ return (const_rev_random_access_iterator<T>(&_ptr[_size - 1])); }
		reverse_iterator		rend()
											{ return (rev_random_access_iterator<T>(&_ptr[-1])); }
		const_reverse_iterator	rend() const
										{ return (const_rev_random_access_iterator<T>(&_ptr[-1])); }

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

	template<class T, class Alloc>
	vector<T, Alloc>::vector(vector::size_type n, const value_type &val,
							 const alloc_type &alloc) : _alloc(alloc) {
		_ptr = _alloc.allocate(n + 5);
		for (size_type i = 0; i < n; ++i)
			_alloc.construct(_ptr + i, val);
		_size = n;
		_capacity = n + 5;
	}

	template<class T, class Alloc>
	template<class InputIterator>
	vector<T, Alloc>::vector(InputIterator first, InputIterator last, const alloc_type &alloc,
					 typename enable_if<std::__is_input_iterator <InputIterator>::value>::type*)
												: _ptr(0), _capacity(0), _size(0), _alloc(alloc) {
		for (; first != last; ++first)
			push_back(*first);
	}

	template<class T, class Alloc>
	vector<T, Alloc>::vector(const vector &x)
										: _capacity(x._capacity), _size(x._size), _alloc(x._alloc) {
		_ptr = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; ++i) {
			_alloc.construct(_ptr + i, x[i]);
		}
	}

	template<class T, class Alloc>
	void vector<T, Alloc>::resize(vector::size_type n, value_type val) {
		if (n > _capacity)
			_realloc(n - _capacity);
		while (n != _size)
			(_size < n) ? push_back(val) : pop_back();
	}

	template<class T, class Alloc>
	void vector<T, Alloc>::reserve(vector::size_type n) {
		if (_capacity < n)
			_realloc(_capacity - n);
	}

	template<class T, class Alloc>
	void vector<T, Alloc>::push_back(const value_type &val) {
		if (_capacity < _size + 15)
			_realloc(10);
		_alloc.construct(_ptr + _size, val);
		_size++;
	}

	template<class T, class Alloc>
	void vector<T, Alloc>::pop_back() {
		_alloc.destroy(_ptr + _size - 1);
		_size--;
	}

	template<class T, class Alloc>
	void vector<T, Alloc>::clear() { while (_size) pop_back(); }

	template<class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::at(vector::size_type n) {
		if (n > _size)
			throw std::out_of_range("Out of range");
		else
			return (_ptr[n]);
	}

	template<class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(vector::size_type n) const {
		if (n > _size)
			throw std::out_of_range("Out of range");
		else
			return (_ptr[n]);
	}

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
