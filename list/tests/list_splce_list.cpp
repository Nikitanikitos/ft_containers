/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_splce_list.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:31:27 by imicah            #+#    #+#             */
/*   Updated: 2020/10/26 14:08:27 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Splice lists with position and x", "[list] [splice]", ((typename T, int V), T, V), (int, 23)) {
	ft::list<T>		ft_list_1;
	ft::list<T>		ft_list_2;
	std::list<T>	list_1;
	std::list<T>	list_2;
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	for (int i = 0; i < V; ++i) {
		if (i % 3) {
			ft_list_2.push_back(i);
			list_2.push_back(i);
		}
		else {
			ft_list_2.push_back(i - 23);
			list_2.push_back(i - 23);
		}
	}

	SECTION("with empty list") {
		ft_list_1.splice(ft_list_1.begin(), ft_list_2);
		list_1.splice(list_1.begin(), list_2);

		REQUIRE(ft_list_1.size() == list_1.size());
		REQUIRE(ft_list_2.size() == list_2.size());

		ft_it = ft_list_1.begin();
		it = list_1.begin();
		for (typename ft::list<T>::size_type i = 0; i < ft_list_1.size(); ++i) {
			REQUIRE(*it == *ft_it);
			++it;
			++ft_it;
		}
	}

	for (int i = 0; i < V; ++i) {
			ft_list_1.push_back(i);
			list_1.push_back(i);
	}

	SECTION("with list size = V at the begin") {
		ft_list_1.splice(ft_list_1.begin(), ft_list_2);
		list_1.splice(list_1.begin(), list_2);

		REQUIRE(ft_list_1.size() == list_1.size());
		REQUIRE(ft_list_2.size() == list_2.size());

		ft_it = ft_list_1.begin();
		it = list_1.begin();
		for (typename ft::list<T>::size_type i = 0; i < ft_list_1.size(); ++i) {
			REQUIRE(*it == *ft_it);
			++it;
			++ft_it;
		}
	}

	SECTION("with list size = V at the middle") {
		ft_it = ft_list_1.begin();
		it = list_1.begin();
		for (typename ft::list<T>::size_type i = 0; i < list_1.size() / 2; ++i) {
			++ft_it;
			++it;
		}
		ft_list_1.splice(ft_it, ft_list_2);
		list_1.splice(it, list_2);

		REQUIRE(ft_list_1.size() == list_1.size());
		REQUIRE(ft_list_2.size() == list_2.size());

		ft_it = ft_list_1.begin();
		it = list_1.begin();
		for (typename ft::list<T>::size_type i = 0; i < ft_list_1.size(); ++i) {
			REQUIRE(*it == *ft_it);
			++it;
			++ft_it;
		}

		ft_it = ft_list_2.begin();
		it = list_2.begin();
		for (typename ft::list<T>::size_type i = 0; i < ft_list_2.size(); ++i) {
			REQUIRE(*it == *ft_it);
			++it;
			++ft_it;
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Splice lists with position, x, and i", "[list] [splice]", ((typename T, int V), T, V), (int, 15)) {
	ft::list<T>		ft_list_1;
	ft::list<T>		ft_list_2;
	std::list<T>	list_1;
	std::list<T>	list_2;
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	for (int i = 0; i < V; ++i) {
		if (i % 3) {
			ft_list_2.push_back(i);
			list_2.push_back(i);
		}
		else {
			ft_list_2.push_back(i - 23);
			list_2.push_back(i - 23);
		}
	}

	for (int i = 0; i < V; ++i) {
			ft_list_1.push_back(i);
			list_1.push_back(i);
	}

	ft_it = ft_list_1.begin();
	it = list_1.begin();
	for (typename ft::list<T>::size_type i = 0; i < list_1.size() / 2; ++i) {
		++ft_it;
		++it;
	}

	SECTION("with list size = V") {

		ft_it = ft_list_2.begin();
		it = list_2.begin();
		for (typename ft::list<T>::size_type i = 0; i < list_1.size() / 2; ++i) {
			++ft_it;
			++it;
			if (i % 3) {
				ft_list_1.splice(ft_list_1.begin(), ft_list_2, ft_it);
				list_1.splice(list_1.begin(), list_2, it);
			}
		}

		REQUIRE(ft_list_1.size() == list_1.size());
		REQUIRE(ft_list_2.size() == list_2.size());

		ft_it = ft_list_1.begin();
		it = list_1.begin();
		*ft_list_1.end() = list_1.size();
		for (typename ft::list<T>::size_type i = 0; i < ft_list_1.size(); ++i) {
			REQUIRE(*it == *ft_it);
			++it;
			++ft_it;
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Splice lists with position, x, first and last", "[list] [splice]",
					   									((typename T, int V), T, V), (int, 5)) {
	ft::list<T>		ft_list_1;
	ft::list<T>		ft_list_2;
	std::list<T>	list_1;
	std::list<T>	list_2;
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	for (int i = 0; i < V; ++i) {
		if (i % 3) {
			ft_list_2.push_back(i);
			list_2.push_back(i);
		}
		else {
			ft_list_2.push_back(i - 23);
			list_2.push_back(i - 23);
		}
	}

	for (int i = 0; i < V; ++i) {
			ft_list_1.push_back(i);
			list_1.push_back(i);
	}

	SECTION("with list size = V") {

		ft_it = ft_list_2.begin();
		it = list_2.begin();
		for (typename ft::list<T>::size_type i = 0; i < list_2.size() / 2; ++i) {
			++ft_it;
			++it;
		}

		ft_list_1.splice(ft_list_1.begin(), ft_list_2, ft_list_2.begin(), ft_it);
		list_1.splice(list_1.begin(), list_2, list_2.begin(), it);

		REQUIRE(ft_list_1.size() == list_1.size());
		REQUIRE(ft_list_2.size() == list_2.size());

		ft_it = ft_list_1.begin();
		it = list_1.begin();
		*ft_list_1.end() = list_1.size();
		for (typename ft::list<T>::size_type i = 0; i < ft_list_1.size(); ++i) {
			REQUIRE(*it == *ft_it);
			++it;
			++ft_it;
		}
	}
}
