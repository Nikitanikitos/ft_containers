/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:55:36 by imicah            #+#    #+#             */
/*   Updated: 2020/11/11 23:04:45 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_VECTOR_HPP
# define FT_CONTAINERS_VECTOR_HPP

# include <limits>
# include "ft.hpp"

template <class T, class Alloc>
class	ft::vector
{
private:
	class	_iterator : public std::iterator<std::random_access_iterator_tag, T> {
	public:
		T*		_ptr;

	public:
		class	_const_iterator : public std::iterator<std::random_access_iterator_tag, T> {
		private:
			T*		_ptr;

		public:
			_const_iterator(T *ptr = 0) : _ptr(ptr) { }
			_const_iterator(const _const_iterator& x) : _ptr(x._ptr) { }
			_const_iterator(const _iterator& x) : _ptr(x._ptr) { }
			~_const_iterator() { }

			_const_iterator&	operator=(const _const_iterator& x) {
				if (this != &x)
					_ptr = x._ptr;
				return (*this);
			}

			_const_iterator&	operator=(const _iterator& x) {
				_ptr = x._ptr;
				return (*this);
			}

			bool	operator==(const _const_iterator& x) const { return (_ptr == x._ptr); }
			bool	operator!=(const _const_iterator& x) const { return (_ptr != x._ptr); }
			bool	operator<(const _const_iterator& x) const { return (_ptr < x._ptr); }
			bool	operator<=(const _const_iterator& x) const { return (_ptr <= x._ptr); }
			bool	operator>(const _const_iterator& x) const { return (_ptr > x._ptr); }
			bool	operator>=(const _const_iterator& x) const { return (_ptr >= x._ptr); }

			_const_iterator&		operator++() { _ptr++; return (*this); }
			_const_iterator&		operator--() { _ptr--; return (*this); }

			_const_iterator		operator++(int) {
				_const_iterator		temp(_ptr);

				++_ptr;
				return (temp);
			}

			_const_iterator		operator--(int) {
				_const_iterator		temp(_ptr);

				--_ptr;
				return (temp);
			}

			_const_iterator		operator+(std::ptrdiff_t x) {
				_const_iterator		temp(_ptr);

				temp += x;
				return (temp);
			}

			_const_iterator		operator-(int x) {
				_const_iterator		temp(_ptr);

				temp -= x;
				return (temp);
			}

			_const_iterator		operator+=(std::ptrdiff_t x) { _ptr += x; return (*this); }
			_const_iterator		operator-=(std::ptrdiff_t x) { _ptr -= x; return (*this); }

			T					operator[](size_t n) { return (_ptr[n]); }
			const T&			operator*() { return (*_ptr); }
			const T*			operator->() { return (_ptr); }
		};

		_iterator(T *ptr = 0) : _ptr(ptr) { }
		_iterator(const _iterator& it) : _ptr(it._ptr) { }
		~_iterator() { }

		_iterator&		operator=(const _iterator& it) {
			if (this != &it)
				_ptr = it._ptr;
			return (*this);
		}

		bool	operator==(const _iterator& x) const { return (_ptr == x._ptr); }
		bool	operator!=(const _iterator& x) const { return (_ptr != x._ptr); }
		bool	operator<(const _iterator& x) const { return (_ptr < x._ptr); }
		bool	operator<=(const _iterator& x) const { return (_ptr <= x._ptr); }
		bool	operator>(const _iterator& x) const { return (_ptr > x._ptr); }
		bool	operator>=(const _iterator& x) const { return (_ptr >= x._ptr); }

		_iterator&		operator++() { _ptr++; return (*this); }
		_iterator&		operator--() { _ptr--; return (*this); }

		_iterator			operator++(int) {
			_iterator		temp(_ptr);

			++_ptr;
			return (temp);
		}

		_iterator		operator--(int) {
			_iterator		temp(_ptr);

			--_ptr;
			return (temp);
		}

		_iterator		operator+(std::ptrdiff_t x) {
			_iterator		temp(_ptr);

			temp += x;
			return (temp);
		}

		_iterator		operator-(std::ptrdiff_t x) {
			_iterator		temp(_ptr);

			temp -= x;
			return (temp);
		}

		_iterator		operator+=(std::ptrdiff_t x) { _ptr += x; return (*this); }
		_iterator		operator-=(std::ptrdiff_t x) { _ptr -= x; return (*this); }

		_iterator		operator[](size_t n) { return (_ptr[n]); }
		T&					operator*() { return (*_ptr); }
		T*					operator->() { return (_ptr); }
	};

	class	_reverse_iterator : public std::iterator<std::random_access_iterator_tag, T> {
	private:
		T*		_ptr;

	public:
		class	_const_reverse_iterator : public std::iterator<std::random_access_iterator_tag, T> {
		private:
			T*		_ptr;

		public:
			_const_reverse_iterator(T* ptr = 0) : _ptr(ptr) { }
			_const_reverse_iterator(const _const_reverse_iterator& x) : _ptr(x._ptr) { }
			_const_reverse_iterator(const _reverse_iterator& x) : _ptr(x._ptr) { }
			~_const_reverse_iterator() { }

			_const_reverse_iterator&	operator=(const _const_reverse_iterator& it) {
				if (this != &it)
					_ptr = it._ptr;
				return (*this);
			}

			_const_reverse_iterator&	operator=(const _reverse_iterator& it) {
				_ptr = it._ptr;
				return (*this);
			}

			bool	operator==(const _const_reverse_iterator& x) const { return (_ptr == x._ptr); }
			bool	operator!=(const _const_reverse_iterator& x) const { return (_ptr != x._ptr); }
			bool	operator<(const _const_reverse_iterator& x) const { return (_ptr < x._ptr); }
			bool	operator<=(const _const_reverse_iterator& x) const { return (_ptr <= x._ptr); }
			bool	operator>(const _const_reverse_iterator& x) const { return (_ptr > x._ptr); }
			bool	operator>=(const _const_reverse_iterator& x) const { return (_ptr >= x._ptr); }

			_const_reverse_iterator&	operator++() { _ptr--; return (*this); }
			_const_reverse_iterator&	operator--() { _ptr++; return (*this); }

			_const_reverse_iterator		operator++(int) {
				_const_reverse_iterator		temp(_ptr);

				--_ptr;
				return (temp);
			}

			_const_reverse_iterator		operator--(int) {
				_const_reverse_iterator		temp(_ptr);

				++_ptr;
				return (temp);
			}

			_const_reverse_iterator		operator+(_const_reverse_iterator& x) { return (_ptr + x._ptr); }
			_const_reverse_iterator		operator-(_const_reverse_iterator& x) { return (_ptr - x._ptr); }
			_const_reverse_iterator		operator+=(_const_reverse_iterator& x) { _ptr += x._ptr; return (*this); }
			_const_reverse_iterator		operator-=(_const_reverse_iterator& x) { _ptr -= x._ptr; return (*this); }

			T								operator[](size_t n) { return (_ptr[n]); }
			const T&						operator*() { return (*_ptr); }
			const T*						operator->() { return (_ptr); }
		};

		_reverse_iterator(T *ptr = 0) : _ptr(ptr) { }
		_reverse_iterator(const _reverse_iterator& x) : _ptr(x._ptr) { }
		~_reverse_iterator() { }

		_reverse_iterator&		operator=(const _reverse_iterator& x) {
			if (this != &x)
				_ptr = x._ptr;
			return (*this);
		}

		bool	operator==(const _reverse_iterator& x) const { return (_ptr == x._ptr); }
		bool	operator!=(const _reverse_iterator& x) const { return (_ptr != x._ptr); }
		bool	operator<(const _reverse_iterator& x) const { return (_ptr < x._ptr); }
		bool	operator<=(const _reverse_iterator& x) const { return (_ptr <= x._ptr); }
		bool	operator>(const _reverse_iterator& x) const { return (_ptr > x._ptr); }
		bool	operator>=(const _reverse_iterator& x) const { return (_ptr >= x._ptr); }

		_reverse_iterator&		operator++() { _ptr--; return (*this); }
		_reverse_iterator&		operator--() { _ptr++; return (*this); }

		_reverse_iterator		operator++(int) {
			_reverse_iterator		temp(_ptr);

			--_ptr;
			return (temp);
		}

		_reverse_iterator		operator--(int) {
			_reverse_iterator		temp(_ptr);

			++_ptr;
			return (temp);
		}

		_reverse_iterator	operator+(_reverse_iterator& x) { return (_ptr + x._ptr); }
		_reverse_iterator	operator-(_reverse_iterator& x) { return (_ptr + x._ptr); }
		_reverse_iterator	operator+=(_reverse_iterator& x) { _ptr += x._ptr; return (*this); }
		_reverse_iterator	operator-=(_reverse_iterator& x) { _ptr -= x._ptr; return (*this); }

		_reverse_iterator	operator[](size_t n) { return (_ptr[n]); }

		T&					operator*() { return (*_ptr); }
		T*					operator->() { return (_ptr); }
	};

public:
	typedef				T												value_type;
	typedef				Alloc											alloc_type;
	typedef typename	alloc_type::reference							reference;
	typedef typename	alloc_type::const_reference						const_reference;
	typedef typename	alloc_type::pointer								pointer;
	typedef typename	alloc_type::const_pointer						const_pointer;
	typedef 			_iterator										iterator;
	typedef	typename	_iterator::_const_iterator						const_iterator;
	typedef				_reverse_iterator								reverse_iterator;
	typedef	typename	_reverse_iterator::_const_reverse_iterator		const_reverse_iterator;
	typedef				std::ptrdiff_t									difference_type;
	typedef				std::size_t										size_type;

private:
	T*				_ptr;
	size_type		_capacity;
	size_type		_size;
	alloc_type		_alloc;

	void		_realloc(const size_type n) {
		T*			temp_ptr = _alloc.allocate(_capacity + n);

		for (size_type  i = 0; i < _size; ++i) {
			_alloc.construct(temp_ptr + i, _ptr[i]);
			_alloc.destroy(_ptr + i);
		}
		_alloc.deallocate(_ptr, _capacity);
		_capacity += n;
		_ptr = temp_ptr;
	}

	size_type	_index_element(iterator &position) {
		size_type	i = 0;

		while (_ptr + i != position._ptr)
			i++;
		return(i);
	}

public:
	explicit	vector(const alloc_type& alloc = alloc_type()) : _ptr(0), _capacity(0), _size(0), _alloc(alloc) { }

	explicit	vector(size_type n, const value_type& val = value_type(), const alloc_type& alloc = alloc_type())
																									: _alloc(alloc) {
		_ptr = _alloc.allocate(n + 1);
		for (size_type i = 0; i < n; ++i)
			_alloc.construct(_ptr + i, val);
		_size = n;
		_capacity = n + 1;
	}

	template <class InputIterator>
	vector(InputIterator first, InputIterator last, const alloc_type& alloc = alloc_type(),
										typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0)
																	: _ptr(0), _capacity(0), _size(0), _alloc(alloc) {
		for (; first != last; ++first)
			push_back(*first);
	}

	vector(const vector& x) : _capacity(x._capacity), _size(x._size), _alloc(x._alloc) {
		_ptr = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; ++i) {
			_alloc.construct(_ptr + i, x[i]);
		}
	}

	~vector() {
		clear();
		_alloc.deallocate(_ptr, _capacity);
	}

	vector& operator=(const vector& x) {
		if (this != &x) {
			assign(x.begin(), x.end());
			_alloc = x._alloc;
			}
		return (*this);
	}

	iterator				begin() { return (iterator(_ptr)); }
	const_iterator			begin() const { return (const_iterator(_ptr)); }
	iterator				end() { return (iterator(_ptr + _size)); }
	const_iterator			end() const { return (const_iterator(_ptr + _size)); }
	reverse_iterator		rbegin() { return (reverse_iterator(_ptr + _size - 1)); }
	const_reverse_iterator	rbegin() const { return (const_reverse_iterator(_ptr + _size - 1)); }
	reverse_iterator		rend() { return (reverse_iterator(_ptr - 1)); }
	const_reverse_iterator	rend() const { return (const_reverse_iterator(_ptr - 1)); }

	size_type				size() const {return (_size); };
	size_type				max_size() const { return (std::numeric_limits<size_type>::max()); }

	void					resize(size_type n, value_type val = value_type()) {
		if (n > _capacity) _realloc(n - _capacity);
		while (n != _size)
			(_size < n) ? push_back(val) : pop_back();
	}

	size_type				capacity() const { return (_capacity); }
	bool					empty() const { return (!_size); }

	void					reserve (size_type n) { if (_capacity < n) _realloc(n - _capacity); }

	reference				operator[](size_type n) { return (_ptr[n]);}
	const_reference			operator[](size_type n) const { return (_ptr[n]); }

	reference				at(size_type n) {
		if (n > _size) throw std::out_of_range("Out of range");
		else return (_ptr[n]);
	}

	const_reference			at(size_type n) const {
		if (n > _size) throw std::out_of_range("Out of range");
		else return (_ptr[n]);
	}

	reference				front()			{ return (_ptr[0]); }
	const_reference			front() const	{ return (_ptr[0]); }
	reference				back()			{ return (_ptr[_size - 1]); }
	const_reference			back() const	{ return (_ptr[_size - 1]); }

	template <class InputIterator>
	void					assign(InputIterator first, InputIterator last) {
		for (size_t i = 0; i < _size; ++i)
			_alloc.destroy(_ptr + i);
		_alloc.deallocate(_ptr, _capacity);

		_ptr = _alloc.allocate(_capacity);
		_size = 0;
		for (; first != last; ++first)
			push_back(*first);
	}

	void					assign(size_type n, const value_type& val) {
		for (size_t i = 0; i < _size; ++i)
			_alloc.destroy(_ptr + i);
		_alloc.deallocate(_ptr, _capacity);

		_ptr = _alloc.allocate(n + 1);
		_capacity = n + 1;
		_size = n;
		for (size_type i = 0; i < n; i++)
			_alloc.construct(_ptr + i, val);
	}

	void					push_back(const value_type& val) {
		if (_capacity < _size + 15)
			_realloc(15);
		_alloc.construct(_ptr + _size, val);
		_size++;
	}

	void					pop_back() {
		if (_capacity > _size + 20)
			_realloc(-10);
		_alloc.destroy(_ptr + _size - 1);
		_size--;
	}

	iterator				insert(iterator position, const value_type& val) {
		size_type i = _index_element(position);
		size_type index_for_iter = i;

		reserve(_size + 2);
		for (size_type q = 0; _ptr + i != _ptr + _size - q; ++q) {
			_alloc.construct(_ptr + _size - q, _ptr[_size - q - 1]);
			_alloc.destroy(_ptr + _size - q - 1);
		}
		_alloc.construct(_ptr + i, val);
		_size++;
		return (iterator(_ptr + index_for_iter));
	}

	void					insert(iterator position, size_type n, const value_type& val) {
		size_type i = _index_element(position);

		reserve(_size + n);
		for (size_type q = 0; _ptr + i != _ptr + _size - q; ++q) {
			_alloc.construct(_ptr + _size - q + n - 1, _ptr[_size - q - 1]);
			_alloc.destroy(_ptr + _size - q - 1);
		}
		_size += n;
		while (n--) _alloc.construct(_ptr + i++, val);
	}

	template <class InputIterator>
	void					insert(iterator position, InputIterator first, InputIterator last,
									typename enable_if<std::__is_input_iterator <InputIterator>::value>::type* = 0) {
		size_type n = 0;
		size_type i = _index_element(position);

		for (InputIterator	temp_first = first; temp_first != last ; ++temp_first)
			n++;
		reserve(_size + n);
		for (size_type q = 0; _ptr + i != _ptr + _size - q; ++q) {
			_alloc.construct(_ptr + _size - q + n - 1, _ptr[_size - q - 1]);
			_alloc.destroy(_ptr + _size - q - 1);
		}
		for (; first != last; ++first) {
			_alloc.construct(_ptr + i++, *first);
			_size++;
		}
	}

	iterator				erase (iterator position) {
		size_type	i = _index_element(position);
		size_type	index_for_iter = i;

		_alloc.destroy(_ptr + i);
		for (; _ptr + i != _ptr + _size; i++) {
			_alloc.construct(_ptr + i, _ptr[i + 1]);
			_alloc.destroy(_ptr + i + 1);
		}
		_size--;
		return (iterator(_ptr + index_for_iter));
	}

	iterator				erase(iterator first, iterator last) {
		size_type	n = 0;
		size_type	i = _index_element(first);
		size_type	index_for_iter = i;

		for (iterator temp_first = first; temp_first != last ; ++temp_first)
			n++;
		while (first != last) {
			_alloc.destroy(_ptr + i);
			_alloc.construct(_ptr + i, _ptr[i + n]);
			_alloc.destroy(_ptr + i++ + n);
			_size--;
			++first;
		}
		return (iterator(_ptr + index_for_iter));
	}

	void					swap (vector& vector) {
		std::swap(_ptr, vector._ptr);
		std::swap(_capacity, vector._capacity);
		std::swap(_size, vector._size);
		std::swap(_alloc, vector._alloc);
	}

	void					clear() { while (_size) pop_back(); }
};

template <class T, class Alloc>
bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	typename ft::vector<T, Alloc>::size_type	i = 0;

	if (lhs.size() != rhs.size())
		return (false);
	else if (!lhs.size())
		return (true);
	for (; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			break ;
	}
	return (lhs[i] == rhs[i]);
}

template <class T, class Alloc>
bool operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	typename ft::vector<T, Alloc>::size_type	i = 0;

	if (!lhs.size() && !lhs.size())
		return (false);
	for (; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			break ;
	}
	return (lhs[i] != rhs[i]);
}
template <class T, class Alloc>
bool operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	typename ft::vector<T, Alloc>::size_type	i = 0;

	if (lhs.size() < rhs.size())
		return (true);
	else if (!rhs.size())
		return (false);
	for (; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			break ;
	}
	return (lhs[i] < rhs[i]);
}

template <class T, class Alloc>
bool operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	typename ft::vector<T, Alloc>::size_type	i = 0;

	if (lhs.size() < rhs.size())
		return (true);
	else if (!lhs.size() && !rhs.size())
		return (true);
	else if (!lhs.size())
		return (true);
	for (; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			break ;
	}
	return (lhs[i] <= rhs[i]);
}

template <class T, class Alloc>
bool operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	typename ft::vector<T, Alloc>::size_type	i = 0;

	if (lhs.size()> rhs.size())
		return (true);
	else if (!lhs.size())
		return (false);
	for (; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			break ;
	}
	return (lhs[i] > rhs[i]);
}

template <class T, class Alloc>
bool operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	typename ft::vector<T, Alloc>::size_type	i = 0;

	if (lhs.size() > rhs.size())
		return (true);
	else if (!lhs.size() && !rhs.size())
		return (true);
	else if (!lhs.size())
		return (false);
	for (; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			break ;
	}
	return (lhs[i] >= rhs[i]);
}

#endif
