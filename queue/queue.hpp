/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:17:26 by nikita            #+#    #+#             */
/*   Updated: 2020/10/29 12:24:36 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_QUEUE_HPP
# define FT_CONTAINERS_QUEUE_HPP

# include "list.hpp"

template <class T, class Container>
class ft::queue {
public:
	typedef		T				value_type;
	typedef		Container		container_type;
	typedef		std::size_t		size_type;

private:
	container_type	_queue;

public:
	explicit queue (const container_type& ctnr = container_type()) { _queue = ctnr; }
	~queue() { }

	bool				empty() const { return (_queue.empty()); }
	size_type			size() const { return (_queue.size()); }

	value_type&			front() { return (_queue.front()); }
	const value_type&	front() const { return (_queue.front()); }
	value_type&			back() { return (_queue.back()); }
	const value_type&	back() const { return (_queue.back()); }
	void				push (const value_type& val) { _queue.push_back(val); }
	void				pop () { _queue.pop_front(); }
};

template <class T, class Container>
bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return (lhs == rhs); }
template <class T, class Container>
bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return (lhs != rhs); }
template <class T, class Container>
bool operator<(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return (lhs < rhs); }
template <class T, class Container>
bool operator<=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return (lhs <= rhs); }
template <class T, class Container>
bool operator>(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return (lhs > rhs); }
template <class T, class Container>
bool operator>=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return (lhs >= rhs); }

#endif
