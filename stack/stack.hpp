/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:56:41 by nikita            #+#    #+#             */
/*   Updated: 2020/10/28 23:21:37 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_STACK_HPP
# define FT_CONTAINERS_STACK_HPP

# include "list.hpp"

namespace ft {

	template <class T, class Container = list<T> >
	class stack {
	public:
		typedef		T				value_type;
		typedef		Container		container_type;
		typedef		std::size_t		size_type;

	private:
		container_type	&_stack;

	public:
		explicit stack (const container_type& ctnr = container_type()) { _stack = ctnr; };
		~stack() { ~_stack(); }

		bool		empty() const { return (_stack.empty()); }
		size_type	size() const { return (_stack.size()); }

		value_type&			top() { return (_stack.back()); }
		const value_type&	top() const { return (_stack.back()); }
		void				push(const value_type& val) { _stack.psh_back(val); }
		void				pop() { _stack.pop_back(); }
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs == rhs); }

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs != rhs); }

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs < rhs); }

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs <= rhs); }

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs > rhs); }

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs >= rhs); }
}

#endif
