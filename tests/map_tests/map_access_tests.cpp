/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_access_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:18:32 by imicah            #+#    #+#             */
/*   Updated: 2020/11/08 12:38:24 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "../catch.hpp"

TEMPLATE_TEST_CASE_SIG("Operator [] and method at getting an item vector_tests map", "[map] [access]",
											   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::map<T, char>		ft_map;
	std::map<T, char>		map;

	for (int i = 0; i < V; ++i) {
		if (i % 2) {
			ft_map.insert(std::make_pair(-i, i));
			map.insert(std::make_pair(-i, i));
		}
		else {
			ft_map.insert(std::make_pair(i, -i));
			map.insert(std::make_pair(i, -i));
		}
	}

	REQUIRE(ft_map.size() == map.size());
	SECTION("Operator []") {
		for (int i = 0; i < V; ++i)
			REQUIRE(ft_map[i] == map[i]);
	}

	SECTION("Method at") {
		for (size_t i = 0; i < V; ++i)
			if (i % 2) REQUIRE(ft_map.at(-i) == map.at(-i));
			else REQUIRE(ft_map.at(i) == map.at(i));
	}
}

TEMPLATE_TEST_CASE_SIG("Operator [] and method at element changes vector_tests map", "[map] [access]",
												   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::map<T, char>		ft_map;
	std::map<T, char>		map;

	for (int i = 0; i < V; ++i) {
		if (i % 2) {
			ft_map.insert(std::make_pair(-i, i));
			map.insert(std::make_pair(-i, i));
		}
		else {
			ft_map.insert(std::make_pair(i, -i));
			map.insert(std::make_pair(i, -i));
		}
	}

	REQUIRE(ft_map.size() == map.size());
	SECTION("Operator []") {
		for (int i = 0; i < V; ++i) {
			ft_map[i] = i - 42;
			map[i] = i - 42;
		}

		for (int i = 0; i < V; ++i)
			REQUIRE(ft_map[i] == map[i]);
	}

	SECTION("Method at") {
		for (size_t i = 0; i < ft_map.size(); ++i) {
			if (i % 2) {
				ft_map.at(-i) = i - 42;
				map.at(-i) = i - 42;
			}
			else {
				ft_map.at(i) = i - 42;
				map.at(i) = i - 42;
			}
		}

		for (size_t i = 0; i < V; ++i)
			if (i % 2) REQUIRE(ft_map.at(-i) == map.at(-i));
			else REQUIRE(ft_map.at(i) == map.at(i));
	}
}

TEMPLATE_TEST_CASE("method at getting a nonexistent item vector_tests map", "[map] [access]", int) {
	ft::map<TestType, char>		ft_map;
	std::map<TestType, char>	map;

	for (int i = 0; i < 7; ++i) {
		if (i % 2) {
			ft_map.insert(std::make_pair(-i, i));
			map.insert(std::make_pair(-i, i));
		}
		else {
			ft_map.insert(std::make_pair(i, -i));
			map.insert(std::make_pair(i, -i));
		}
	}

	REQUIRE_THROWS(ft_map.at(9));
	REQUIRE_THROWS(map.at(9));
}
