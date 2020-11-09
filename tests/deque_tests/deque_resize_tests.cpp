/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_resize_tests.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:09:44 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 23:15:58 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.hpp"
#include <deque>
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Resize deque with empty vector", "[deque] [resize]",
																			((typename T,  int V), T, V), (int, 14)) {
	ft::deque<T>			ft_deque;
	std::deque<T>			deque;

	SECTION("resize = 0") {
	ft_deque.resize(0, 13);
	deque.resize(0, 13);

	REQUIRE(deque.size() == ft_deque.size());
	REQUIRE(deque.empty() == ft_deque.empty());
	}

	SECTION("resize = 1") {
	ft_deque.resize(1, 13);
	deque.resize(1, 13);

	REQUIRE(deque.size() == ft_deque.size());
	REQUIRE(deque.empty() == ft_deque.empty());
	REQUIRE(deque.front() == ft_deque.front());
	}

	SECTION("resize = V") {
		ft_deque.resize(V, 13);
		deque.resize(V, 13);

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque[i] == deque[i]);
	}
}

TEMPLATE_TEST_CASE_SIG("Resize deque with size = V", "[deque] [resize]", ((typename T,  int V), T, V), (int, 12)) {

	ft::deque<T>		ft_deque(V, 123);
	std::deque<T>		deque(V, 123);

	SECTION("resize = 0") {
		ft_deque.resize(0, 13);
		deque.resize(0, 13);

		REQUIRE(deque.size() == ft_deque.size());
		REQUIRE(deque.empty() == ft_deque.empty());
	}

	SECTION("resize = 1") {
		ft_deque.resize(1, 31);
		deque.resize(1, 31);

		REQUIRE(deque.size() == ft_deque.size());
		REQUIRE(deque.empty() == ft_deque.empty());
		REQUIRE(deque.front() == ft_deque.front());
	}

	SECTION("resize = V / 2") {
		ft_deque.resize(V / 2, -13);
		deque.resize(V / 2, -13);

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque[i] == deque[i]);
	}

	SECTION("resize = V * 2") {
		ft_deque.resize(V * 2, 0);
		deque.resize(V * 2, 0);

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque[i] == deque[i]);
	}
}
