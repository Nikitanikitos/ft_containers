/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_assign_tests.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:21:22 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 23:27:59 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include "deque.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Assign with iterators in deque", "[deque] [assign]",
														   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::deque<T>							ft_deque_for_assign;
	std::deque<T>							deque_for_assign;
	typename ft::deque<T>::iterator			ft_it;
	typename std::deque<T>::iterator		it;

	SECTION("Empty list") {
		ft::deque<T>		ft_deque;
		std::deque<T>		deque(5);

		deque.erase(deque.begin(), deque.begin());
		ft_deque.assign(ft_deque_for_assign.begin(), ft_deque_for_assign.end());
		deque.assign(deque_for_assign.begin(), deque_for_assign.end());

		REQUIRE(ft_deque_for_assign.size() == ft_deque.size());
		REQUIRE(ft_deque_for_assign.empty() == ft_deque.empty());

		REQUIRE(deque.size() == ft_deque.size());
		REQUIRE(deque.empty() == ft_deque.empty());
	}

	SECTION("One node") {
		ft::deque<T>		ft_deque;
		std::deque<T>		deque;

		ft_deque_for_assign.push_back(T());
		deque_for_assign.push_back(T());

		ft_deque.assign(ft_deque_for_assign.begin(), ft_deque_for_assign.end());
		deque.assign(deque_for_assign.begin(), deque_for_assign.end());

		REQUIRE(ft_deque_for_assign.size() == ft_deque.size());
		REQUIRE(ft_deque_for_assign.empty() == ft_deque.empty());
		REQUIRE(ft_deque_for_assign.front() == ft_deque.front());
		REQUIRE(ft_deque_for_assign.back() == ft_deque.back());

		REQUIRE(deque.size() == ft_deque.size());
		REQUIRE(deque.empty() == ft_deque.empty());
		REQUIRE(deque.front() == ft_deque.front());
		REQUIRE(deque.back() == ft_deque.back());
	}

	SECTION("Many with equal size") {
		ft::deque<T>		ft_deque;
		std::deque<T>		deque;
		for (int i = 0; i < V; ++i) {
			ft_deque_for_assign.push_back(i + 3);
			deque_for_assign.push_back(i + 3);
			ft_deque.push_front(i);
			deque.push_front(i);
		}

		ft_deque.assign(ft_deque_for_assign.begin(), ft_deque_for_assign.end());
		deque.assign(deque_for_assign.begin(), deque_for_assign.end());

		ft_it = ft_deque.begin();
		it = deque.begin();

		REQUIRE(ft_deque_for_assign.front() == ft_deque.front());
		REQUIRE(ft_deque_for_assign.back() == ft_deque.back());
		REQUIRE(ft_deque_for_assign.size() == ft_deque.size());
		REQUIRE(deque.size() == ft_deque.size());
		for (int i = 0; i < V; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}

	SECTION("Many with greater size") {
		ft::deque<T>	ft_deque;
		std::deque<T>	deque;

		for (int i = 0; i < V; ++i) {
			ft_deque_for_assign.push_back(i + 3);
			deque_for_assign.push_back(i + 3);
			if (i % 2) {
				ft_deque.push_front(i);
				deque.push_front(i);
			}
		}

		ft_deque.assign(ft_deque_for_assign.begin(), ft_deque_for_assign.end());
		deque.assign(deque_for_assign.begin(), deque_for_assign.end());

		ft_it = ft_deque.begin();
		it = deque.begin();

		REQUIRE(ft_deque_for_assign.front() == ft_deque.front());
		REQUIRE(ft_deque_for_assign.back() == ft_deque.back());
		REQUIRE(ft_deque_for_assign.size() == ft_deque.size());
		REQUIRE(deque.size() == ft_deque.size());
		for (int i = 0; i < V; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}

	SECTION("Many with lower size") {
		ft::deque<T>		ft_deque;
		std::deque<T>		deque;
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_deque_for_assign.push_back(i + 3);
				deque_for_assign.push_back(i + 3);
			}
			ft_deque.push_front(i);
			deque.push_front(i);
		}

		ft_deque.assign(ft_deque_for_assign.begin(), ft_deque_for_assign.end());
		deque.assign(deque_for_assign.begin(), deque_for_assign.end());

		ft_it = ft_deque.begin();
		it = deque.begin();

		REQUIRE(ft_deque_for_assign.front() == ft_deque.front());
		REQUIRE(ft_deque_for_assign.back() == ft_deque.back());
		REQUIRE(ft_deque_for_assign.size() == ft_deque.size());
		REQUIRE(deque.size() == ft_deque.size());
		for (int i = 0; i < V / 2; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Assign with size and val in deque", "[deque] [assign]",
					   								((typename T, int V), T, V), (int, 10), (char, 20)) {
	typename ft::deque<T>::iterator			ft_it;
	typename std::deque<T>::iterator		it;

	SECTION("Empty list") {
		ft::deque<T>		ft_deque;
		std::deque<T>		deque;

		ft_deque.assign(V, -T());
		deque.assign(V, -T());

		REQUIRE(deque.size() == ft_deque.size());
		REQUIRE(deque.empty() == ft_deque.empty());
		REQUIRE(deque.front() == ft_deque.front());
		REQUIRE(deque.back() == ft_deque.back());

	}

	SECTION("One node") {
		ft::deque<T>	ft_deque(1, -42);
		std::deque<T>	deque(1, -42);

		ft_deque.assign(V, 42);
		deque.assign(V, 42);

		REQUIRE(deque.size() == ft_deque.size());
		REQUIRE(deque.empty() == ft_deque.empty());
		REQUIRE(deque.front() == ft_deque.front());
		REQUIRE(deque.back() == ft_deque.back());
	}

	SECTION("Many with equal size") {
		ft::deque<T>	ft_deque(V, 21);
		std::deque<T>	deque(V, 21);

		ft_deque.assign(V, -21);
		deque.assign(V, -21);
		ft_it = ft_deque.begin();
		it = deque.begin();

		REQUIRE(deque.size() == ft_deque.size());
		for (int i = 0; i < V; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}

	SECTION("Many with greater size") {
		ft::deque<T>		ft_deque(V / 2, 21);
		std::deque<T>		deque(V / 2, 21);

		ft_deque.assign(V, -21);
		deque.assign(V, -21);
		ft_it = ft_deque.begin();
		it = deque.begin();

		REQUIRE(deque.size() == ft_deque.size());
		for (int i = 0; i < V; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}

	SECTION("Many with lower size") {
		ft::deque<T>	ft_deque(V, 21);
		std::deque<T>	deque(V, 21);

		ft_deque.assign(V / 2, -21);
		deque.assign(V / 2, -21);
		ft_it = ft_deque.begin();
		it = deque.begin();

		REQUIRE(deque.size() == ft_deque.size());
		for (int i = 0; i < V / 2; ++i) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}
}
