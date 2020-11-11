/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_swap_tests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 00:54:14 by imicah            #+#    #+#             */
/*   Updated: 2020/11/12 01:04:15 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE("Swap empty set", "[set] [swap]", int) {
	ft::set<TestType>		ft_set_1;
	ft::set<TestType>		ft_set_2;
	std::set<TestType>		set_1;
	std::set<TestType>		set_2;

	REQUIRE(set_1.size() == ft_set_1.size());
	REQUIRE(set_1.empty() == ft_set_1.empty());
	REQUIRE(set_2.size() == ft_set_2.size());
	REQUIRE(set_2.empty() == ft_set_2.empty());

	ft_set_1.swap(ft_set_2);
	set_1.swap(set_2);

	REQUIRE(set_1.size() == ft_set_1.size());
	REQUIRE(set_1.empty() == ft_set_1.empty());
	REQUIRE(set_2.size() == ft_set_2.size());
	REQUIRE(set_2.empty() == ft_set_2.empty());
}

TEMPLATE_TEST_CASE("Swap set with size = 1", "[set] [swap]", int) {
	ft::set<TestType>		ft_set_1;
	ft::set<TestType>		ft_set_2;
	std::set<TestType>		set_1;
	std::set<TestType>		set_2;

	ft_set_1.insert(13);
	ft_set_2.insert(12);

	set_1.insert(13);
	set_2.insert(12);

	REQUIRE(set_1.size() == ft_set_1.size());
	REQUIRE(set_1.empty() == ft_set_1.empty());
	REQUIRE(set_2.size() == ft_set_2.size());
	REQUIRE(set_2.empty() == ft_set_2.empty());

	ft_set_1.swap(ft_set_2);
	set_1.swap(set_2);

	REQUIRE(set_1.size() == ft_set_1.size());
	REQUIRE(set_1.empty() == ft_set_1.empty());
	REQUIRE(set_2.size() == ft_set_2.size());
	REQUIRE(set_2.empty() == ft_set_2.empty());
}

TEMPLATE_TEST_CASE_SIG("Swap set with equal size", "[set] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::set<T>		ft_set_1;
	ft::set<T>		ft_set_2;
	std::set<T>		set_1;
	std::set<T>		set_2;

	typename ft::set<T>::iterator		ft_it_1;
	typename ft::set<T>::iterator		ft_it_2;
	typename std::set<T>::iterator		it_1;
	typename std::set<T>::iterator		it_2;

	for (int i = 0; i < V; ++i) {
		ft_set_1.insert(i);
		ft_set_2.insert(i - 2);
		set_1.insert(i);
		set_2.insert(i - 2);
	}

	REQUIRE(set_1.size() == ft_set_1.size());
	REQUIRE(set_2.size() == ft_set_2.size());

	ft_set_1.swap(ft_set_2);
	set_1.swap(set_2);

	REQUIRE(set_1.size() == ft_set_1.size());
	REQUIRE(set_2.size() == ft_set_2.size());

	ft_it_2 = ft_set_2.begin();
	it_1 = set_1.begin();
	it_2 = set_2.begin();
	for (ft_it_1 = ft_set_1.begin(); ft_it_1 != ft_set_1.end(); ++ft_it_1) {
		REQUIRE(*ft_it_1 == *it_1);
		REQUIRE(*ft_it_2 == *it_2);
		++ft_it_2;
		++it_1;
		++it_2;
	}
}

TEMPLATE_TEST_CASE_SIG("Swap set with greater size", "[set] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::set<T>		ft_set_1;
	ft::set<T>		ft_set_2;
	std::set<T>		set_1;
	std::set<T>		set_2;

	typename ft::set<T>::iterator		ft_it_1;
	typename ft::set<T>::iterator		ft_it_2;
	typename std::set<T>::iterator		it_1;
	typename std::set<T>::iterator		it_2;

	for (int i = 0; i < V; ++i) {
		if (i % 2) {
			ft_set_1.insert(i);
			set_1.insert(i);
		}
		ft_set_2.insert(i - 2);
		set_2.insert(i - 2);
	}

	REQUIRE(set_1.size() == ft_set_1.size());
	REQUIRE(set_2.size() == ft_set_2.size());

	ft_set_1.swap(ft_set_2);
	set_1.swap(set_2);

	REQUIRE(set_1.size() == ft_set_1.size());
	REQUIRE(set_2.size() == ft_set_2.size());

	it_1 = set_1.begin();
	for (ft_it_1 = ft_set_1.begin(); ft_it_1 != ft_set_1.end(); ++ft_it_1) {
		REQUIRE(*ft_it_1 == *it_1);
		++it_1;
	}
	it_2 = set_2.begin();
	for (ft_it_2 = ft_set_2.begin(); ft_it_2 != ft_set_2.end(); ++ft_it_2) {
		REQUIRE(*ft_it_2 == *it_2);
		++it_2;
	}
}

TEMPLATE_TEST_CASE_SIG("Swap set with lower size", "[set] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::set<T>		ft_set_1;
	ft::set<T>		ft_set_2;
	std::set<T>		set_1;
	std::set<T>		set_2;

	typename ft::set<T>::iterator		ft_it_1;
	typename ft::set<T>::iterator		ft_it_2;
	typename std::set<T>::iterator		it_1;
	typename std::set<T>::iterator		it_2;

	for (int i = 0; i < V; ++i) {
		if (i % 2) {
			ft_set_2.insert(i);
			set_2.insert(i);
		}
		ft_set_1.insert(i - 2);
		set_1.insert(i - 2);
	}

	REQUIRE(set_1.size() == ft_set_1.size());
	REQUIRE(set_2.size() == ft_set_2.size());

	ft_set_1.swap(ft_set_2);
	set_1.swap(set_2);

	REQUIRE(set_1.size() == ft_set_1.size());
	REQUIRE(set_2.size() == ft_set_2.size());

	it_1 = set_1.begin();
	for (ft_it_1 = ft_set_1.begin(); ft_it_1 != ft_set_1.end(); ++ft_it_1) {
		REQUIRE(*ft_it_1 == *it_1);
		++it_1;
	}
	it_2 = set_2.begin();
	for (ft_it_2 = ft_set_2.begin(); ft_it_2 != ft_set_2.end(); ++ft_it_2) {
		REQUIRE(*ft_it_2 == *it_2);
		++it_2;
	}
}
