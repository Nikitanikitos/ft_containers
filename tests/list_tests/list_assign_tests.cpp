/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_assign_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:03:13 by imicah            #+#    #+#             */
/*   Updated: 2020/11/11 00:15:35 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "../catch.hpp"

TEMPLATE_TEST_CASE_SIG("Assign with iterators in list", "[list] [assign]",
																((typename T, int V), T, V), (int, 6), (char, 6)) {
	ft::list<T>							ft_list_for_assign;
	std::list<T>						list_for_assign;
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	SECTION("Empty list") {
		ft::list<T>		ft_list;
		std::list<T>	list(5);

		list.erase(list.begin(), list.begin());
		ft_list.assign(ft_list_for_assign.begin(), ft_list_for_assign.end());
		list.assign(list_for_assign.begin(), list_for_assign.end());

		REQUIRE(ft_list_for_assign.size() == ft_list.size());
		REQUIRE(ft_list_for_assign.empty() == ft_list.empty());
		REQUIRE(ft_list_for_assign.front() == ft_list.front());
		REQUIRE(ft_list_for_assign.back() == ft_list.back());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("One node") {
		ft::list<T>		ft_list;
		std::list<T>	list;

		ft_list_for_assign.push_back(T());
		list_for_assign.push_back(T());

		ft_list.assign(ft_list_for_assign.begin(), ft_list_for_assign.end());
		list.assign(list_for_assign.begin(), list_for_assign.end());

		REQUIRE(ft_list_for_assign.size() == ft_list.size());
		REQUIRE(ft_list_for_assign.empty() == ft_list.empty());
		REQUIRE(ft_list_for_assign.front() == ft_list.front());
		REQUIRE(ft_list_for_assign.back() == ft_list.back());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("Many with equal size") {
		ft::list<T>		ft_list;
		std::list<T>	list;

		for (int i = 0; i < V; ++i) {
			ft_list_for_assign.push_back(i + 3);
			list_for_assign.push_back(i + 3);
			ft_list.push_front(i);
			list.push_front(i);
		}

		ft_list.assign(ft_list_for_assign.begin(), ft_list_for_assign.end());
		list.assign(list_for_assign.begin(), list_for_assign.end());
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(ft_list_for_assign.front() == ft_list.front());
		REQUIRE(ft_list_for_assign.back() == ft_list.back());
		REQUIRE(ft_list_for_assign.size() == ft_list.size());
		REQUIRE(list.size() == ft_list.size());
		for (int i = 0; i < V; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}

	SECTION("Many with greater size") {
		ft::list<T>		ft_list;
		std::list<T>	list;
		for (int i = 0; i < V; ++i) {
			ft_list_for_assign.push_back(i + 3);
			list_for_assign.push_back(i + 3);
			if (i % 2) {
				ft_list.push_front(i);
				list.push_front(i);
			}
		}

		ft_list.assign(ft_list_for_assign.begin(), ft_list_for_assign.end());
		list.assign(list_for_assign.begin(), list_for_assign.end());
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(ft_list_for_assign.front() == ft_list.front());
		REQUIRE(ft_list_for_assign.back() == ft_list.back());
		REQUIRE(ft_list_for_assign.size() == ft_list.size());
		REQUIRE(list.size() == ft_list.size());
		for (int i = 0; i < V; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}

	SECTION("Many with lower size") {
		ft::list<T>		ft_list;
		std::list<T>	list;
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_list_for_assign.push_back(i + 3);
				list_for_assign.push_back(i + 3);
			}
			ft_list.push_front(i);
			list.push_front(i);
		}

		ft_list.assign(ft_list_for_assign.begin(), ft_list_for_assign.end());
		list.assign(list_for_assign.begin(), list_for_assign.end());
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(ft_list_for_assign.front() == ft_list.front());
		REQUIRE(ft_list_for_assign.back() == ft_list.back());
		REQUIRE(ft_list_for_assign.size() == ft_list.size());
		REQUIRE(list.size() == ft_list.size());
		for (int i = 0; i < V / 2; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Assign with size and val in list", "[list] [assign]",
																((typename T, int V), T, V), (int, 29), (char, 43)) {
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	SECTION("Empty list") {
		ft::list<T>		ft_list;
		std::list<T>	list;

		ft_list.assign(V, -T());
		list.assign(V, -T());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());

	}

	SECTION("One node") {
		ft::list<T>		ft_list(1, -42);
		std::list<T>	list(1, -42);

		ft_list.assign(V, 42);
		list.assign(V, 42);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("Many with equal size") {
		ft::list<T>		ft_list(V, 21);
		std::list<T>	list(V, 21);

		ft_list.assign(V, -21);
		list.assign(V, -21);
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(list.size() == ft_list.size());
		for (int i = 0; i < V; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}

	SECTION("Many with greater size") {
		ft::list<T>		ft_list(V / 2, 21);
		std::list<T>	list(V / 2, 21);

		ft_list.assign(V, -21);
		list.assign(V, -21);
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(list.size() == ft_list.size());
		for (int i = 0; i < V; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}

	SECTION("Many with lower size") {
		ft::list<T>		ft_list(V, 21);
		std::list<T>	list(V, 21);

		ft_list.assign(V / 2, -21);
		list.assign(V / 2, -21);
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(list.size() == ft_list.size());
		for (int i = 0; i < V / 2; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}
}
