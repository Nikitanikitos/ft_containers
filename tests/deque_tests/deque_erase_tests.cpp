/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_erase_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:51:55 by imicah            #+#    #+#             */
/*   Updated: 2020/11/10 15:53:38 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include "deque.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Erase in deque through one iterator", "[deque] [erase]",
																		   ((typename T, int V), T, V), (int, 10)) {
	ft::deque<T>							ft_deque(1, 23);
	std::deque<T>							deque(1, 23);
	typename ft::deque<T>::iterator			ft_it;
	typename std::deque<T>::iterator		it;

	SECTION("with size = 1") {
		deque.erase(deque.begin());
		ft_deque.erase(ft_deque.begin());

		REQUIRE(deque.size() == ft_deque.size());
		REQUIRE(deque.empty() == ft_deque.empty());
	}

	SECTION("with size = V") {
		ft::deque<T>		ft_deque(V, 21);
		std::deque<T>		deque(V, 21);

		ft_it = ft_deque.begin();
		it = deque.begin();
		SECTION("every two time") {
			for (int i = 0; ft_it != ft_deque.end(); ++ft_it) {
				if (i++ % 2) {
					ft_it = ft_deque.erase(ft_it);
					it = deque.erase(it);
					REQUIRE(*ft_it == *it);
					REQUIRE(deque.size() == ft_deque.size());
				}
				++it;
			}
			REQUIRE(deque.size() == ft_deque.size());
		}

		SECTION("from the middle") {
			for (size_t i = 0; i < ft_deque.size() / 2; ++i) {
				++it;
				++ft_it;
			}
			REQUIRE(*ft_deque.erase(ft_it) == *deque.erase(it));
			REQUIRE(deque.size() == ft_deque.size());
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Erase in vector through with two iterator", "[vector] [erase]",
					   ((typename T, int V), T, V), (int, 10)) {
	ft::deque<T>							ft_deque(1, 23);
	std::deque<T>							deque(1, 23);
	typename ft::deque<T>::iterator			ft_it;
	typename std::deque<T>::iterator		it;

	SECTION("with size = 1") {
		deque.erase(deque.begin(), deque.begin());
		ft_deque.erase(ft_deque.begin(), ft_deque.begin());

		REQUIRE(deque.size() == ft_deque.size());
		REQUIRE(deque.empty() == ft_deque.empty());
	}

	SECTION("with size = V") {
		ft::deque<T>		ft_deque(V, 21);
		std::deque<T>		deque(V, 21);

		ft_it = ft_deque.begin();
		it = deque.begin();
		SECTION("every two time") {
			for (int i = 0; ft_deque[i] != ft_deque.back(); ++i) {
				if (!(i % 2)) {
					REQUIRE(ft_deque[i] == it[i]);
					REQUIRE(deque.size() == ft_deque.size());
				}
			}
		}

		SECTION("First part") {
			for (size_t i = 0; i < ft_deque.size() / 2; ++i) {
				++it;
				++ft_it;
			}
			REQUIRE(*ft_deque.erase(ft_deque.begin(), ft_it) == *deque.erase(deque.begin(), it));
			REQUIRE(deque.size() == ft_deque.size());
		}

		SECTION("Second part") {
			for (size_t i = 0; i < ft_deque.size(); ++i) {
				++it;
				++ft_it;
			}
			ft_deque.erase(ft_it, ft_deque.end());
			deque.erase(it, deque.end());
			REQUIRE(deque.front() == ft_deque.front());
			REQUIRE(deque.back() == ft_deque.back());
			REQUIRE(deque.size() == ft_deque.size());
		}

		SECTION("all vector") {
			ft_deque.erase(ft_it, --ft_deque.end());
			deque.erase(it, --deque.end());
			REQUIRE(deque.front() == ft_deque.front());
			REQUIRE(deque.back() == ft_deque.back());
			REQUIRE(deque.size() == ft_deque.size());
			REQUIRE(deque.empty() == ft_deque.empty());
		}
	}
}
