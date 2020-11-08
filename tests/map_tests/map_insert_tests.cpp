/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:37:20 by imicah            #+#    #+#             */
/*   Updated: 2020/11/02 15:10:30 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "../catch.hpp"

TEMPLATE_TEST_CASE_SIG("Insert in map through value", "[map] [insert]",
								   ((typename T, int V), T, V), (int, 13), (char, 29), (float, 24)) {
	ft::map<T, double>		ft_map;
	std::map<T, double>		map;

	SECTION("1 node") {
		ft_map.insert(std::make_pair(21, 21.42));
		map.insert(std::make_pair(21, 21.42));

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(*map.begin() == *ft_map.begin());
	}

	SECTION("in ascending order") {
		for (int i = 0; i < V; ++i) {
			ft_map.insert(std::make_pair(i, i - 21.42 * 0.1));
			map.insert(std::make_pair(i, i - 21.42 * 0.1));

			REQUIRE(*ft_map.begin() == *map.begin());
		}

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(*ft_map.begin() == *map.begin());
	}

	SECTION("in descending order") {
		for (int i = 0; i < V; ++i) {
			ft_map.insert(std::make_pair(-i, i - 21.42 * -0.1));
			map.insert(std::make_pair(-i, i - 21.42 * -0.1));

			REQUIRE(*ft_map.begin() == *map.begin());
		}

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(*ft_map.begin() == *map.begin());
	}

	SECTION("in random value") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_map.insert(std::make_pair(-i, i));
				map.insert(std::make_pair(-i, i));
			}
			else {
				ft_map.insert(std::make_pair(i, i));
				map.insert(std::make_pair(i, i));
			}

			REQUIRE(*ft_map.begin() == *map.begin());
		}

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(*ft_map.begin() == *map.begin());
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in map through two iterator", "[map] [insert]",
													 ((typename T, int V), T, V), (int, 13), (char, 29), (float, 24)) {
	ft::map<T, float>							ft_map;
	std::map<T, float>							map;
	ft::map<T, float>							ft_map_for_insert;
	std::map<T, float>							map_for_insert;
	typename ft::map<T, float>::iterator		ft_it;
	typename std::map<T, float>::iterator		it;

	SECTION("empty map") {
		ft_map.insert(ft_map_for_insert.begin(), ft_map_for_insert.end());
		map.insert(map_for_insert.begin(), map_for_insert.end());

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(map.empty() == ft_map.empty());
	}

	for (int i = 0; i < V; ++i) {
		if (i % 2) {
			ft_map_for_insert.insert(std::make_pair(-i, i));
			map_for_insert.insert(std::make_pair(-i, i));
		}
		else {
			ft_map_for_insert.insert(std::make_pair(i, i));
			map_for_insert.insert(std::make_pair(i, i));
		}
	}

	ft_it = ft_map_for_insert.begin();
	it = map_for_insert.begin();
	for (int i = 0; i < V / 2; ++i) {
		++ft_it;
		++it;
	}

	SECTION("from first to last") {
		ft_map.insert(ft_map_for_insert.begin(), ft_map_for_insert.end());
		map.insert(map_for_insert.begin(), map_for_insert.end());

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(*ft_map.begin() == *map.begin());
	}

	SECTION("from first to middle") {
		ft_map.insert(ft_map_for_insert.begin(), ft_it);
		map.insert(map_for_insert.begin(), it);

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(*ft_map.begin() == *map.begin());
	}

	SECTION("from middle to first") {
		ft_map.insert(ft_it, ft_map_for_insert.end());
		map.insert(it, map_for_insert.end());

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(*ft_map.begin() == *map.begin());
	}
}
