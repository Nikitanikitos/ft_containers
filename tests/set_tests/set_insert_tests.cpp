/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_insert_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 00:35:00 by imicah            #+#    #+#             */
/*   Updated: 2020/11/12 00:44:13 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Insert in set through value", "[set] [insert]",
									   ((typename T, int V), T, V), (int, 13), (char, 29), (float, 24)) {
	ft::set<T>							ft_set;
	std::set<T>							set;
	typename ft::set<T>::iterator		ft_it;
	typename std::set<T>::iterator		it;

	SECTION("1 node") {
		ft_set.insert(21);
		set.insert(21);

		REQUIRE(set.size() == ft_set.size());
		REQUIRE(*set.begin() == *ft_set.begin());
	}

	SECTION("in ascending order") {
		for (int i = 0; i < V; ++i) {
			ft_set.insert(i);
			set.insert(i);

			REQUIRE(*ft_set.begin() == *set.begin());
		}
		it = set.begin();
		REQUIRE(set.size() == ft_set.size());
		for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
			REQUIRE(*ft_it == *it++);
	}

	SECTION("in descending order") {
		for (int i = 0; i < V; ++i) {
			ft_set.insert(-i);
			set.insert(-i);

			REQUIRE(*ft_set.begin() == *set.begin());
		}
		it = set.begin();
		REQUIRE(set.size() == ft_set.size());
		for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
			REQUIRE(*ft_it == *it++);
	}

	SECTION("in random value") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_set.insert(-i);
				set.insert(-i);
			}
			else {
				ft_set.insert(i);
				set.insert(i);
			}

			REQUIRE(*ft_set.begin() == *set.begin());
		}

		it = set.begin();
		REQUIRE(set.size() == ft_set.size());
		for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
			REQUIRE(*ft_it == *it++);
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in set through two iterator", "[set] [insert]",
										  ((typename T, int V), T, V), (int, 13), (char, 29), (float, 24)) {
	ft::set<T>							ft_set;
	std::set<T>							set;
	ft::set<T>							ft_set_for_insert;
	std::set<T>							set_for_insert;
	typename ft::set<T>::iterator		ft_it;
	typename std::set<T>::iterator		it;

	SECTION("empty map") {
		ft_set.insert(ft_set_for_insert.begin(), ft_set_for_insert.end());
		set.insert(set_for_insert.begin(), set_for_insert.end());

		REQUIRE(set.size() == ft_set.size());
		REQUIRE(set.empty() == ft_set.empty());
	}

	for (int i = 0; i < V; ++i) {
		if (i % 2) {
			ft_set_for_insert.insert(-i);
			set_for_insert.insert(-i);
		}
		else {
			ft_set_for_insert.insert(i);
			set_for_insert.insert(i);
		}
	}

	ft_it = ft_set_for_insert.begin();
	it = set_for_insert.begin();
	for (int i = 0; i < V / 2; ++i) {
		++ft_it;
		++it;
	}

	SECTION("from first to last") {
		ft_set.insert(ft_set_for_insert.begin(), ft_set_for_insert.end());
		set.insert(set_for_insert.begin(), set_for_insert.end());

		it = set.begin();
		REQUIRE(set.size() == ft_set.size());
		for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
			REQUIRE(*ft_it == *it++);
	}

	SECTION("from first to middle") {
		ft_set.insert(ft_set_for_insert.begin(), ft_it);
		set.insert(set_for_insert.begin(), it);

		it = set.begin();
		REQUIRE(set.size() == ft_set.size());
		for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
			REQUIRE(*ft_it == *it++);
	}

	SECTION("from middle to first") {
		ft_set.insert(ft_it, ft_set_for_insert.end());
		set.insert(it, set_for_insert.end());

		it = set.begin();
		REQUIRE(set.size() == ft_set.size());
		for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
			REQUIRE(*ft_it == *it++);
	}
}
