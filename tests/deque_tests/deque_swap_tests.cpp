/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_swap_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:49:28 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 22:53:54 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include "deque.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE("Swap empty deque", "[deque] [swap]", int) {
	ft::deque<TestType>		ft_deque_1;
	ft::deque<TestType>		ft_deque_2;
	std::deque<TestType>		deque_1;
	std::deque<TestType>		deque_2;

	SECTION("Empty with empty") {
		ft_deque_1.swap(ft_deque_2);
		deque_1.swap(deque_2);

		REQUIRE(deque_1.size() == ft_deque_1.size());
		REQUIRE(deque_1.empty() == ft_deque_1.empty());
		REQUIRE(deque_2.size() == ft_deque_2.size());
		REQUIRE(deque_2.empty() == ft_deque_2.empty());
	}

	SECTION("Empty with not empty") {
		ft::deque<TestType>		ft_deque_2(4);
		std::deque<TestType>		deque_2(4);

		ft_deque_1.swap(ft_deque_2);
		deque_1.swap(deque_2);

		REQUIRE(deque_1.size() == ft_deque_1.size());
		REQUIRE(deque_1.empty() == ft_deque_1.empty());
		REQUIRE(deque_2.size() == ft_deque_2.size());
		REQUIRE(deque_2.empty() == ft_deque_2.empty());
	}

	SECTION("Not empty with empty") {
		ft::deque<TestType>		ft_deque_1(4);
		std::deque<TestType>	deque_1(4);

		ft_deque_1.swap(ft_deque_2);
		deque_1.swap(deque_2);

		REQUIRE(deque_1.size() == ft_deque_1.size());
		REQUIRE(deque_1.empty() == ft_deque_1.empty());
		REQUIRE(deque_2.size() == ft_deque_2.size());
		REQUIRE(deque_2.empty() == ft_deque_2.empty());
	}
}

TEMPLATE_TEST_CASE_SIG("Swap deque with equal size", "[deque] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::deque<T>		ft_deque_1(V, 13);
	ft::deque<T>		ft_deque_2(V, 31);
	std::deque<T>		deque_1(V, 13);
	std::deque<T>		deque_2(V, 31);

	REQUIRE(deque_1.size() == ft_deque_1.size());
	REQUIRE(deque_2.size() == ft_deque_2.size());

	ft_deque_1.swap(ft_deque_2);
	deque_1.swap(deque_2);

	REQUIRE(deque_1.size() == ft_deque_1.size());
	REQUIRE(deque_2.size() == ft_deque_2.size());

	for (size_t i = 0; i < deque_1.size(); ++i) {
		REQUIRE(deque_1[i] == ft_deque_1[i]);
		REQUIRE(deque_2[i] == ft_deque_2[i]);

	}
}

TEMPLATE_TEST_CASE_SIG("Swap deque with lower size", "[deque] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::deque<T>		ft_deque_1(V / 2, 13);
	ft::deque<T>		ft_deque_2(V, 31);
	std::deque<T>		deque_1(V / 2, 13);
	std::deque<T>		deque_2(V, 31);

	REQUIRE(deque_1.size() == ft_deque_1.size());
	REQUIRE(deque_2.size() == ft_deque_2.size());

	ft_deque_1.swap(ft_deque_2);
	deque_1.swap(deque_2);

	REQUIRE(deque_1.size() == ft_deque_1.size());
	REQUIRE(deque_2.size() == ft_deque_2.size());

	for (size_t i = 0; i < deque_1.size(); ++i)
		REQUIRE(deque_1[i] == ft_deque_1[i]);
	for (size_t i = 0; i < deque_2.size(); ++i)
		REQUIRE(deque_2[i] == ft_deque_2[i]);
}

TEMPLATE_TEST_CASE_SIG("Swap deque with greater size", "[deque] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::deque<T>		ft_deque_1(V, 13);
	ft::deque<T>		ft_deque_2(V / 2, 31);
	std::deque<T>		deque_1(V, 13);
	std::deque<T>		deque_2(V / 2, 31);

	REQUIRE(deque_1.size() == ft_deque_1.size());
	REQUIRE(deque_2.size() == ft_deque_2.size());

	ft_deque_1.swap(ft_deque_2);
	deque_1.swap(deque_2);

	REQUIRE(deque_1.size() == ft_deque_1.size());
	REQUIRE(deque_2.size() == ft_deque_2.size());

	for (size_t i = 0; i < deque_1.size(); ++i)
		REQUIRE(deque_1[i] == ft_deque_1[i]);
	for (size_t i = 0; i < deque_2.size(); ++i)
		REQUIRE(deque_2[i] == ft_deque_2[i]);
}
