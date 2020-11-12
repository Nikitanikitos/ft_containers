/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_resize_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:04:25 by imicah            #+#    #+#             */
/*   Updated: 2020/10/25 13:09:06 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "../catch.hpp"

TEMPLATE_TEST_CASE_SIG("Resize list with empty list", "[list] [resize]", ((typename T,  int V), T, V), (int, 14)) {
	ft::list<T>							ft_list;
	std::list<T>						list;
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	SECTION("resize = 0") {
		ft_list.resize(0, 13);
		list.resize(0, 13);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
	}

	SECTION("resize = 1") {
		ft_list.resize(1, 13);
		list.resize(1, 13);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.front() == ft_list.front());
	}

	SECTION("resize = V") {
		ft_list.resize(V, 13);
		list.resize(V, 13);
		it = list.begin();

		for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
			REQUIRE(*ft_it == *it);
			++it;
		}
		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
	}
}

TEMPLATE_TEST_CASE_SIG("Resize list with size = V", "[list] [resize]", ((typename T,  int V), T, V), (int, 12)) {
	ft::list<T>							ft_list(V, 123);
	std::list<T>						list(V, 123);
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	SECTION("resize = 0") {
		ft_list.resize(0, 13);
		list.resize(0, 13);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
	}

	SECTION("resize = 1") {
		ft_list.resize(1, 31);
		list.resize(1, 31);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.front() == ft_list.front());
	}

	SECTION("resize = V / 2") {
		ft_list.resize(V / 2, -13);
		list.resize(V / 2, -13);
		it = list.begin();

		for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
			REQUIRE(*ft_it == *it);
			++it;
		}
		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
	}

	SECTION("resize = V * 2") {
		ft_list.resize(V * 2, 0);
		list.resize(V * 2, 0);
		it = list.begin();

		for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
			REQUIRE(*ft_it == *it);
			++it;
		}
		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
	}
}
