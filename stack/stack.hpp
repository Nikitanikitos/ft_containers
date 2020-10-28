/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:56:41 by nikita            #+#    #+#             */
/*   Updated: 2020/10/28 23:09:51 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_STACK_HPP
# define FT_CONTAINERS_STACK_HPP

#include "list.hpp"

namespace fd {

	template <class T, class Container = ft::list<T> >
	class stack {
		typedef		T				value_type;
		typedef		Container		container_type;
		typedef		std::size_t		size_type;

		container_type	&_stack;

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
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		typename stack<T, Container>::container_type::const_iterator	it_lhs = lhs.begin();
		typename stack<T, Container>::container_type::const_iterator	it_rhs = rhs.begin();

		while (it_lhs != lhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs == *it_rhs);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		typename stack<T, Container>::container_type::const_iterator	it_lhs = lhs.begin();
		typename stack<T, Container>::container_type::const_iterator	it_rhs = rhs.begin();

		while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs != *it_rhs);
	}

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		if (lhs.size() < rhs.size())
			return (true);
		typename stack<T, Container>::container_type::const_iterator	it_lhs = lhs.begin();
		typename stack<T, Container>::container_type::const_iterator	it_rhs = rhs.begin();

		while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs < *it_rhs);
	}

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		if (lhs.size() < rhs.size())
			return (true);
		typename stack<T, Container>::container_type::const_iterator	it_lhs = lhs.begin();
		typename stack<T, Container>::container_type::const_iterator	it_rhs = rhs.begin();

		while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs <= *it_rhs);
	}

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		if (lhs.size() > rhs.size())
			return (true);
		typename stack<T, Container>::container_type::const_iterator	it_lhs = lhs.begin();
		typename stack<T, Container>::container_type::const_iterator	it_rhs = rhs.begin();

		while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs > *it_rhs);
	}

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		if (lhs.size() > rhs.size())
			return (true);
		typename stack<T, Container>::container_type::const_iterator	it_lhs = lhs.begin();
		typename stack<T, Container>::container_type::const_iterator	it_rhs = rhs.begin();

		while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
			if (*it_rhs != *it_lhs)
				break;
			++it_rhs;
			++it_lhs;
		}
		return (*it_lhs >= *it_rhs);
	}
}

#endif
