/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:56:41 by nikita            #+#    #+#             */
/*   Updated: 2020/10/29 11:57:28 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_STACK_HPP
# define FT_CONTAINERS_STACK_HPP

# include "ft.hpp"
# include "deque.hpp"

template <class T, class Container>
class	ft::stack {
public:
	typedef		T				value_type;
	typedef		Container		container_type;
	typedef		std::size_t		size_type;

private:
	container_type	_stack;

public:
	explicit stack (const container_type& ctnr = container_type()) { _stack = ctnr; };
	~stack() { }

	bool				empty() const { return (_stack.empty()); }
	size_type			size() const { return (_stack.size()); }

	value_type&			top() { return (_stack.back()); }
	const value_type&	top() const { return (_stack.back()); }
	void				push(const value_type& val) { _stack.push_back(val); }
	void				pop() { _stack.pop_back(); }
};

template <class T, class Container>
bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs == rhs); }
template <class T, class Container>
bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs != rhs); }
template <class T, class Container>
bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs < rhs); }
template <class T, class Container>
bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs <= rhs); }
template <class T, class Container>
bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs > rhs); }
template <class T, class Container>
bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs >= rhs); }

#endif
