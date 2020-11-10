/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_insert_tests.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:04:46 by imicah            #+#    #+#             */
/*   Updated: 2020/11/10 13:53:39 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include "deque.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE("Insert in empty deque through iterator", "[deque] [insert]", int) {
	ft::deque<TestType>		ft_deque(10);
	std::deque<TestType>	deque(10);

	SECTION("at the front") {
		ft_deque.insert(ft_deque.begin(), 21);
		deque.insert(deque.begin(), 21);

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque[i] == deque[i]);
	}

	SECTION("at the back") {
		ft_deque.insert(ft_deque.end(), 21);
		deque.insert(deque.end(), 21);

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque[i] == deque[i]);
	}

	SECTION("at the middle") {
		ft_deque.insert(ft_deque.begin() + 5, 21);
		deque.insert(deque.begin() + 5, 21);

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque[i] == deque[i]);
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in deque with size = V through iterator and size", "[deque] [insert]",
																		   ((typename T, int V), T, V), (int, 20)) {
	ft::deque<T>							ft_deque(V, 42);
	std::deque<T>							deque(V, 42);
	typename ft::deque<T>::iterator			ft_it = ft_deque.begin();
	typename std::deque<T>::iterator		it = deque.begin();

	SECTION("at the middle") {
		for (int i = 0; i < V / 2; ++i) {
			++ft_it;
			++it;
		}
		ft_deque.insert(ft_it, V / 2, 21);
		deque.insert(it, V / 2, 21);

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque[i] == deque[i]);
	}

	SECTION("at the front") {
		ft_deque.insert(ft_it, V / 2, 21);
		deque.insert(it, V / 2, 21);

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque[i] == deque[i]);
	}

	SECTION("at the end") {
		ft_deque.insert(ft_deque.end(), V / 2, 21);
		deque.insert(deque.end(), V / 2, 21);

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque[i] == deque[i]);
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in deque with size = V through two iterator", "[deque] [insert]",
																				((typename T, int V), T, V), (int, 20)) {
	ft::deque<T>				ft_deque;
	std::deque<T>				deque;
	ft::deque<T>				ft_deque_for_insert(V, -26);
	std::deque<T>				deque_for_insert(V, -26);

	SECTION("in empty vector") {
		ft_deque.insert(ft_deque.begin(), ft_deque_for_insert.begin(), ft_deque_for_insert.end());
		deque.insert(deque.begin(), deque_for_insert.begin(), deque_for_insert.end());

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(deque[i] == ft_deque[i]);
	}

	SECTION("From beginning to middle at the front") {
		ft_deque.insert(ft_deque.begin(), V / 3, 21);
		deque.insert(deque.begin(), V / 3, 21);

		ft_deque.insert(ft_deque.begin(), ft_deque_for_insert.begin(), ft_deque_for_insert.end() - V / 2);
		deque.insert(deque.begin(), deque_for_insert.begin(), deque_for_insert.end() - V / 2);

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(deque[i] == ft_deque[i]);
	}

	SECTION("From beginning to middle at the end") {
		ft_deque.insert(ft_deque.begin(), V / 2, 21);
		deque.insert(deque.begin(), V / 2, 21);

		ft_deque.insert(ft_deque.end(), ft_deque_for_insert.begin(), ft_deque_for_insert.end() - V / 2);
		deque.insert(deque.end(), deque_for_insert.begin(), deque_for_insert.end() - V / 2);

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(deque[i] == ft_deque[i]);
	}

	SECTION("From the middle to the end at the front") {
		ft_deque.insert(ft_deque.begin(), 3, 21);
		deque.insert(deque.begin(), 3, 21);

		ft_deque.insert(ft_deque.begin(), ft_deque_for_insert.begin() + V / 2, ft_deque_for_insert.end());
		deque.insert(deque.begin(), deque_for_insert.begin() + V / 2, deque_for_insert.end());

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque[i] == ft_deque[i]);
	}

	SECTION("From the middle to the end at the back") {
		ft_deque.insert(ft_deque.begin(), V / 3, 21);
		deque.insert(deque.begin(), V / 3, 21);

		ft_deque.insert(ft_deque.end(), ft_deque_for_insert.begin() + V / 2, ft_deque_for_insert.end());
		deque.insert(deque.end(), deque_for_insert.begin() + V / 2, deque_for_insert.end());

		REQUIRE(deque.size() == ft_deque.size());
		for (size_t i = 0; i < ft_deque.size(); ++i)
			REQUIRE(ft_deque[i] == deque[i]);
	}
}
