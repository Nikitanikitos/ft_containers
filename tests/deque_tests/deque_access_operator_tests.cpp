/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_access_operator_tests.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:33:58 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 22:36:40 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include "deque.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Operator [] and method at getting an item deque", "[deque] [access]",
	((typename T, int V), T, V), (int, 10), (char, 20), (float, 12)) {
	ft::deque<T>		ft_deque;
	std::deque<T>		deque;

	for (int i = 0; i < V; ++i) {
		if (i % 2) {
			ft_deque.push_back(-i);
			deque.push_back(-i);
		}
		else {
			ft_deque.push_back(i);
			deque.push_back(i);
		}
	}

	REQUIRE(ft_deque.size() == deque.size());

	SECTION("Operator []") {
	for (int i = 0; i < V; ++i)
		REQUIRE(ft_deque[i] == deque[i]);
	}

	SECTION("Method at") {
	for (size_t i = 0; i < ft_deque.size(); ++i)
		REQUIRE(ft_deque.at(i) == deque.at(i));
	}
}

TEMPLATE_TEST_CASE_SIG("Operator [] and method at element changes deque", "[deque] [access]",
													((typename T, int V), T, V), (int, 10), (char, 20), (float, 12)) {
	ft::deque<T>		ft_deque;
	std::deque<T>		deque;

	for (int i = 0; i < V; ++i) {
		ft_deque.push_back(i);
		deque.push_back(i);
	}

	REQUIRE(ft_deque.size() == deque.size());

	SECTION("Operator []") {
		for (int i = 0; i < V; ++i) {
			ft_deque[i] = i - 42;
			deque[i] = i - 42;
		}

		for (int i = 0; i < V; ++i)
			REQUIRE(ft_deque[i] == deque[i]);
	}

	SECTION("Method at") {
		for (size_t i = 0; i < ft_deque.size(); ++i) {
			ft_deque.at(i) = i - 42;
			deque.at(i) = i - 42;
		}
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque.at(i) == deque.at(i));
	}
}

TEMPLATE_TEST_CASE("method at getting a non-existent item deque", "[deque] [access]", int) {
	ft::deque<TestType>			ft_deque;
	std::deque<TestType>		deque;

	for (int i = 0; i < 6; ++i) {
		if (i % 2) {
			ft_deque.push_back(i);
			deque.push_back(i);
		}
	}

	REQUIRE_THROWS(ft_deque.at(6));
	REQUIRE_THROWS(deque.at(6));
}
