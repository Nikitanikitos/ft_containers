/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:07:44 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 16:16:03 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_DEQUE_HPP
# define FT_CONTAINERS_DEQUE_HPP

# include "ft.hpp"

template <class T, class Alloc>
class ft::deque {
public:
	typedef				T											value_type;
	typedef				Alloc										alloc_type;
	typedef typename	alloc_type::reference						reference;
	typedef typename	alloc_type::const_reference					const_reference;
	typedef typename	alloc_type::pointer							pointer;
	typedef typename	alloc_type::const_pointer					const_pointer;
	typedef 			ft::vector_iterator<T>						iterator;
	typedef				ft::const_vector_iterator<T>				const_iterator;
	typedef				ft::reverse_vector_iterator<T>				reverse_iterator;
	typedef				ft::const_reverse_vector_iterator<T>		const_reverse_iterator;
	typedef				std::ptrdiff_t								difference_type;
	typedef				std::size_t									size_type;

private:
	T*			_ptr;
	size_type	_capacity;
	size_type	_offset;
	size_type	_size;
	alloc_type	_alloc;

public:
	explicit deque (const alloc_type& alloc = alloc_type()) : _ptr(0), _capacity(0), _offset(0), _size(0), _alloc(alloc) { }

	explicit deque (size_type n, const value_type& val = value_type(), const alloc_type& alloc = alloc_type())
																									: _alloc(alloc) {

	}
	template <class InputIterator>
	deque (InputIterator first, InputIterator last, const alloc_type& alloc = alloc_type());
	deque (const deque& x);

	~deque();

	deque& operator= (const deque& x);

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

	void					resize(size_type n, value_type val = value_type());

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
	void					assign(InputIterator first, InputIterator last);
	void					assign(size_type n, const value_type& val);

	void					push_back(const value_type& val);
	void					push_front(const value_type& val);
	void					pop_back();
	void					pop_front();

	iterator				insert(iterator position, const value_type& val);
	void					insert(iterator position, size_type n, const value_type& val);
	template <class InputIterator>
	void					insert(iterator position, InputIterator first, InputIterator last);

	iterator				erase(iterator position);
	iterator				erase(iterator first, iterator last);

	void					swap(deque& x);

	void					clear() { while (_size) pop_back(); }

};

template <class T, class Alloc>
bool operator==(const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	typename ft::deque<T, Alloc>::size_type	i = 0;

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
bool operator!=(const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	typename ft::deque<T, Alloc>::size_type	i = 0;

	if (!lhs.size() && !lhs.size())
		return (false);
	for (; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			break ;
	}
	return (lhs[i] != rhs[i]);
}
template <class T, class Alloc>
bool operator<(const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	typename ft::deque<T, Alloc>::size_type	i = 0;

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
bool operator<=(const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	typename ft::deque<T, Alloc>::size_type	i = 0;

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
bool operator>(const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	typename ft::deque<T, Alloc>::size_type	i = 0;

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
bool operator>=(const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	typename ft::deque<T, Alloc>::size_type	i = 0;

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


#endif //FT_CONTAINERS_DEQUE_HPP
