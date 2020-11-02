/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_access_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:18:32 by imicah            #+#    #+#             */
/*   Updated: 2020/11/02 15:33:17 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "catch.hpp"


TEMPLATE_TEST_CASE_SIG("Operator [] and method at getting an item tests map", "[map] [access]",
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
			if (i % 2)
				REQUIRE(ft_map.at(-i) == map.at(-i));
			else
				REQUIRE(ft_map.at(i) == map.at(i));
	}
}

TEMPLATE_TEST_CASE_SIG("Operator [] and method at element changes tests", "[vector] [access]",
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
			if (i % 2)
				REQUIRE(ft_map.at(-i) == map.at(-i));
			else
				REQUIRE(ft_map.at(i) == map.at(i));
	}
}
