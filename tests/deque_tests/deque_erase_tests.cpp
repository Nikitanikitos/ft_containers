/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_erase_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:51:55 by imicah            #+#    #+#             */
/*   Updated: 2020/11/10 18:37:40 by imicah           ###   ########.fr       */
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
		ft::deque<T>		ft_deque;
		std::deque<T>		deque;

		for (int i = 0; i < V; ++i) {
			ft_deque.push_back(i);
			deque.push_back(i);
		}
		ft_it = ft_deque.begin();
		it = deque.begin();
		SECTION("every two time") {
			for (int i = 0; i < V / 2; ++ft_it) {
				if (i++ % 2) {
					ft_it = ft_deque.erase(ft_it);
					it = deque.erase(it);
					REQUIRE(*ft_it == *it);
					REQUIRE(deque.size() == ft_deque.size());
				}
				++it;
			}

			REQUIRE(deque.size() == ft_deque.size());
			for (size_t i = 0; i < ft_deque.size(); ++i)
				REQUIRE(deque[i] == ft_deque[i]);
		}

		SECTION("from the middle") {
			for (size_t i = 0; i < ft_deque.size() / 2; ++i) {
				++it; ++ft_it;
			}
			REQUIRE(*ft_deque.erase(ft_it) == *deque.erase(it));
			REQUIRE(deque.size() == ft_deque.size());
			for (size_t i = 0; i < ft_deque.size(); ++i)
				REQUIRE(deque[i] == ft_deque[i]);
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Erase in deque through with two iterator", "[deque] [erase]",
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
		ft::deque<T>		ft_deque;
		std::deque<T>		deque;

		for (int i = 0; i < V; ++i) {
			ft_deque.push_back(i);
			deque.push_back(i);
		}
		ft_it = ft_deque.begin();
		it = deque.begin();
		for (size_t i = 0; i < ft_deque.size() / 2; ++i) {
			++it; ++ft_it;
		}

		SECTION("First part") {
			it = deque.erase(deque.begin(), it);
			ft_it = ft_deque.erase(ft_deque.begin(), ft_it);

			REQUIRE(*ft_it == *it);
			REQUIRE(deque.size() == ft_deque.size());
			for (size_t i = 0; i < ft_deque.size(); ++i)
				REQUIRE(deque[i] == ft_deque[i]);
		}

		SECTION("Second part") {
			ft_deque.erase(ft_it, ft_deque.end());
			deque.erase(it, deque.end());

			REQUIRE(deque.size() == ft_deque.size());
			for (size_t i = 0; i < ft_deque.size(); ++i)
				REQUIRE(deque[i] == ft_deque[i]);
		}

		SECTION("all vector") {
			ft_deque.erase(ft_it, --ft_deque.end());
			deque.erase(it, --deque.end());

			REQUIRE(deque.size() == ft_deque.size());
			REQUIRE(deque.empty() == ft_deque.empty());
			for (size_t i = 0; i < ft_deque.size(); ++i)
				REQUIRE(deque[i] == ft_deque[i]);
		}
	}
}
