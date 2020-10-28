/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 14:25:01 by imicah            #+#    #+#             */
/*   Updated: 2020/10/25 14:57:10 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "catch.hpp"

template<typename T>
bool	remove_if_greater_21 (const T &i) { return (i > 21); }

TEMPLATE_TEST_CASE("remove in empty list", "[list] [remove]", int) {
	ft::list<TestType>		ft_list;
	std::list<TestType>		list;

	ft_list.remove(13);
	list.remove(13);

	REQUIRE(list.size() == ft_list.size());
	REQUIRE(list.empty() == ft_list.empty());
}

TEMPLATE_TEST_CASE("remove in list with size = 1", "[list] [remove]", int) {
	ft::list<TestType>		ft_list(1, 12);
	std::list<TestType>		list(1, 12);

	SECTION("existing value") {
		ft_list.remove(12);
		list.remove(12);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
	}

	SECTION("not existing value") {
		ft_list.remove(-12);
		list.remove(-12);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
	}
}

TEMPLATE_TEST_CASE_SIG("remove in list with size = V", "[list] [remove]", ((typename T, int V), T, V), (int, 13)) {
	ft::list<T>							ft_list;
	std::list<T>						list;
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	for (int i = 0; i < V; ++i) {
		if (i % 3) {
			ft_list.push_back(21);
			list.push_back(21);
		}
		ft_list.push_back(i - 2);
		list.push_back(i - 2);
	}

	SECTION("existing value") {
		ft_list.remove(21);
		list.remove(21);
		it = list.begin();

		REQUIRE(list.size() == ft_list.size());
		for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
			REQUIRE(*ft_it == *it);
			++it;
		}
	}

	SECTION("not existing value") {
		ft_list.remove(-212);
		list.remove(-212);
		it = list.begin();

		REQUIRE(list.size() == ft_list.size());
		for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
			REQUIRE(*ft_it == *it);
			++it;
		}
	}
}

TEMPLATE_TEST_CASE("remove_if in empty list", "[list] [remove_if]", int) {
	ft::list<TestType>		ft_list;
	std::list<TestType>		list;

	ft_list.remove_if(remove_if_greater_21<TestType>);
	list.remove_if(remove_if_greater_21<TestType>);

	REQUIRE(list.size() == ft_list.size());
	REQUIRE(list.empty() == ft_list.empty());
}

TEMPLATE_TEST_CASE("remove_if in list with size = 1", "[list] [remove_if]", int) {
	SECTION("existing value") {
		ft::list<TestType>		ft_list(1, 23);
		std::list<TestType>		list(1, 23);

		ft_list.remove_if(remove_if_greater_21<TestType>);
		list.remove_if(remove_if_greater_21<TestType>);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
	}

	SECTION("not existing value") {
		ft::list<TestType>		ft_list(1, 20);
		std::list<TestType>		list(1, 20);

		ft_list.remove_if(remove_if_greater_21<TestType>);
		list.remove_if(remove_if_greater_21<TestType>);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
	}
}

TEMPLATE_TEST_CASE_SIG("remove_if in list with size = V", "[list] [remove]", ((typename T, int V), T, V), (int, 13)) {
	ft::list<T>							ft_list;
	std::list<T>						list;
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	for (int i = 0; i < V; ++i) {
		if (i % 3) {
			ft_list.push_back(23);
			list.push_back(23);
		}
		ft_list.push_back(i + 2);
		list.push_back(i + 2);
	}
	ft_list.remove_if(remove_if_greater_21<T>);
	list.remove_if(remove_if_greater_21<T>);
	it = list.begin();

	REQUIRE(list.size() == ft_list.size());
	for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
		REQUIRE(*ft_it == *it);
		++it;
	}
}
