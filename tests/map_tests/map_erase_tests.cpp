/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_erase_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:21:06 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 00:57:52 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "../catch.hpp"

TEMPLATE_TEST_CASE_SIG("Erase in map through key", "[map] [erase]",
					   ((typename T, int V), T, V), (int, 10)) {
	ft::map<T, int>							ft_map;
	std::map<T, int>							map;
	typename ft::map<T, int>::iterator		ft_it;
	typename std::map<T, int>::iterator		it;

	SECTION("with size = 1") {
		ft_map.insert(std::make_pair(12, 12));
		map.insert(std::make_pair(12, 12));

		map.erase(12);
		ft_map.erase(12);

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(map.empty() == ft_map.empty());
	}
	for (int i = 0; i < V; ++i) {
		ft_map.insert(std::make_pair(i, i));
		map.insert(std::make_pair(i, i));
	}

	SECTION("with size = V") {
		for (size_t i = 0; i < ft_map.size(); i++) {
			if (i % 2) {
				ft_map.erase(i);
				map.erase(i);
				it = map.begin();
				for (ft_it = ft_map.begin(); ft_it != ft_map.end(); ++ft_it) {
					REQUIRE(*it++ == *ft_it);
				}
				REQUIRE(map.size() == ft_map.size());
			}
		}
	}

	SECTION("erase begin") {
		while (ft_map.size() > 1) {
			ft_map.erase(ft_map.begin());
			map.erase(map.begin());
			it = map.begin();
			for (ft_it = ft_map.begin(); ft_it != ft_map.end(); ++ft_it) {
				REQUIRE(*it++ == *ft_it);
			}
		}
	}

	SECTION("erase end") {
		while (ft_map.size() > 2) {
			ft_it = --ft_map.end();
			it = --map.end();
			ft_map.erase(ft_it);
			map.erase(it);
			ft_it = --ft_map.end();
			it = --map.end();
			REQUIRE(*it == *ft_it);
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Erase in map through iterator", "[map] [erase]",
					   ((typename T, int V), T, V), (int, 10)) {
	ft::map<T, double>						ft_map;
	std::map<T, double>						map;
	typename ft::map<T, double>::iterator		ft_it;
	typename std::map<T, double>::iterator		it;

	SECTION("with size = 1") {
		ft_map.insert(std::make_pair(12, 12));
		ft_map.insert(std::make_pair(4, 12));
		map.insert(std::make_pair(12, 12));
		map.insert(std::make_pair(4, 12));

		map.erase(map.begin());
		ft_map.erase(ft_map.begin());

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(map.empty() == ft_map.empty());
	}

	SECTION("with size = V") {
		for (int i = 0; i < V; ++i) {
			ft_map.insert(std::make_pair(i, i - 21.42 * -0.1));
			map.insert(std::make_pair(i, i - 21.42 * -0.1));
		}

		for (size_t i = 0; i < ft_map.size(); i++) {
			if (i % 2) {
				ft_it = ft_map.find(i / 2);
				it = map.find(i / 2);
				ft_map.erase(ft_it);
				map.erase(it);
				ft_it = ft_map.begin();
				it = map.begin();
				REQUIRE(*ft_it == *it);
				REQUIRE(map.size() == ft_map.size());
			}
		}
	}
}
