/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:37:20 by imicah            #+#    #+#             */
/*   Updated: 2020/11/01 19:22:43 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "catch.hpp"

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

	SECTION("V node") {
		for (int i = 0; i < V; ++i) {
			ft_map.insert(std::make_pair(i, i - 21.42 * 0.1));
			map.insert(std::make_pair(i, i - 21.42 * 0.1));
		}

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(*map.begin() == *ft_map.begin());
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in empty map through two iterator", "[map] [insert]",
					   ((typename T, int V), T, V), (int, 5)) {
	ft::map<T, float>							ft_map;
	std::map<T, float>							map;
	ft::map<T, float>							ft_map_for_insert;
	std::map<T, float>							map_for_insert;
//	typename ft::map<T, float>::iterator		ft_it = ft_map.begin();
//	typename std::map<T, float>::iterator		it = map.begin();

	SECTION("empty ft_list_for_insert") {
		ft_map.insert(ft_map_for_insert.begin(), ft_map_for_insert.end());
		map.insert(map_for_insert.begin(), map_for_insert.end());

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(map.empty() == ft_map.empty());
	}

	SECTION("size ft_list_for_insert = V") {
		for (int i = 0; i < V; ++i) {
			ft_map_for_insert.insert(std::make_pair(-i, i));
			map_for_insert.insert(std::make_pair(-i, i));
		}
		ft_map.insert(ft_map_for_insert.begin(), ft_map_for_insert.end());
		map.insert(map_for_insert.begin(), map_for_insert.end());

		for (typename ft::map<T, float>::iterator		ft_it = ft_map_for_insert.begin(); ft_it != ft_map_for_insert.end(); ++ft_it)
			std::cout << 1 << std::endl;
//		REQUIRE(map.size() == ft_map.size());
//		REQUIRE(*ft_map.begin() == *map.begin());
	}

//	SECTION("at the front, size ft_list_for_insert = V") {
//		ft::list<T>							ft_list_for_insert(V, 32);
//		std::list<T>						list_for_insert(V, 32);
//		ft_map.insert(ft_map.begin(), ft_list_for_insert.begin(), ft_list_for_insert.end());
//		map.insert(map.begin(), map_for_insert.begin(), map_for_insert.end());
//
//		REQUIRE(map.size() == ft_map.size());
//		ft_it = ft_map.begin();
//		for (it = map.begin(); it != map.end(); ++it) {
//			REQUIRE(*it == *ft_it);
//			++ft_it;
//		}
//	}
//
//	SECTION("at the back, empty ft_list_for_insert") {
//		ft_map.insert(ft_map.end(), ft_map_for_insert.begin(), ft_map_for_insert.end());
//		map.insert(map.end(), map_for_insert.begin(), map_for_insert.end());
//
//		REQUIRE(map.size() == ft_map.size());
//		REQUIRE(map.front() == ft_map.front());
//		REQUIRE(map.back() == ft_map.back());
//	}
//
//	SECTION("at the back, size ft_list_for_insert = 1") {
//		ft::list<T>							ft_list_for_insert(1, 2);
//		std::list<T>						list_for_insert(1, 2);
//		ft_map.insert(ft_map.end(), ft_list_for_insert.begin(), ft_list_for_insert.end());
//		map.insert(map.end(), map_for_insert.begin(), map_for_insert.end());
//
//		REQUIRE(map.size() == ft_map.size());
//		REQUIRE(map.front() == ft_map.front());
//		REQUIRE(map.back() == ft_map.back());
//	}
//
//	SECTION("at the front, size ft_list_for_insert = V") {
//		ft::list<T>							ft_list_for_insert(V, 32);
//		std::list<T>						list_for_insert(V, 32);
//		ft_map.insert(ft_map.end(), ft_list_for_insert.begin(), ft_list_for_insert.end());
//		map.insert(map.end(), map_for_insert.begin(), map_for_insert.end());
//
//		REQUIRE(map.size() == ft_map.size());
//		ft_it = ft_map.begin();
//		for (it = map.begin(); it != map.end(); ++it) {
//			REQUIRE(*it == *ft_it);
//			++ft_it;
//		}
//	}
}
