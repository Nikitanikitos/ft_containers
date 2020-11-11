/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_swap_tests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:35:57 by imicah            #+#    #+#             */
/*   Updated: 2020/11/11 19:48:23 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE("Swap empty map", "[map] [swap]", int) {
	ft::map<TestType, char>		ft_map_1;
	ft::map<TestType, char>		ft_map_2;
	std::map<TestType, char>	map_1;
	std::map<TestType, char>	map_2;

	REQUIRE(map_1.size() == ft_map_1.size());
	REQUIRE(map_1.empty() == ft_map_1.empty());
	REQUIRE(map_2.size() == ft_map_2.size());
	REQUIRE(map_2.empty() == ft_map_2.empty());

	ft_map_1.swap(ft_map_2);
	map_1.swap(map_2);

	REQUIRE(map_1.size() == ft_map_1.size());
	REQUIRE(map_1.empty() == ft_map_1.empty());
	REQUIRE(map_2.size() == ft_map_2.size());
	REQUIRE(map_2.empty() == ft_map_2.empty());
}

TEMPLATE_TEST_CASE("Swap map with size = 1", "[map] [swap]", int) {
	ft::map<TestType, char>		ft_map_1;
	ft::map<TestType, char>		ft_map_2;
	std::map<TestType, char>	map_1;
	std::map<TestType, char>	map_2;

	ft_map_1.insert(std::make_pair(13, 12));
	ft_map_2.insert(std::make_pair(12, 13));

	map_1.insert(std::make_pair(13, 12));
	map_2.insert(std::make_pair(12, 13));

	REQUIRE(map_1.size() == ft_map_1.size());
	REQUIRE(map_1.empty() == ft_map_1.empty());
	REQUIRE(map_2.size() == ft_map_2.size());
	REQUIRE(map_2.empty() == ft_map_2.empty());

	ft_map_1.swap(ft_map_2);
	map_1.swap(map_2);

	REQUIRE(map_1.size() == ft_map_1.size());
	REQUIRE(map_1.empty() == ft_map_1.empty());
	REQUIRE(map_2.size() == ft_map_2.size());
	REQUIRE(map_2.empty() == ft_map_2.empty());
}

TEMPLATE_TEST_CASE_SIG("Swap map with equal size", "[map] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::map<T, char>		ft_map_1;
	ft::map<T, char>		ft_map_2;
	std::map<T, char>		map_1;
	std::map<T, char>		map_2;

	typename ft::map<T, char>::iterator		ft_it_1;
	typename ft::map<T, char>::iterator		ft_it_2;
	typename std::map<T, char>::iterator		it_1;
	typename std::map<T, char>::iterator		it_2;

	for (int i = 0; i < V; ++i) {
		ft_map_1.insert(std::make_pair(i, i - 2));
		ft_map_2.insert(std::make_pair(i - 2, i));
		map_1.insert(std::make_pair(i, i - 2));
		map_2.insert(std::make_pair(i - 2, i));
	}

	REQUIRE(map_1.size() == ft_map_1.size());
	REQUIRE(map_2.size() == ft_map_2.size());

	ft_map_1.swap(ft_map_2);
	map_1.swap(map_2);

	REQUIRE(map_1.size() == ft_map_1.size());
	REQUIRE(map_2.size() == ft_map_2.size());

	ft_it_2 = ft_map_2.begin();
	it_1 = map_1.begin();
	it_2 = map_2.begin();
	for (ft_it_1 = ft_map_1.begin(); ft_it_1 != ft_map_1.end(); ++ft_it_1) {
		REQUIRE(*ft_it_1 == *it_1);
		REQUIRE(*ft_it_2 == *it_2);
		++ft_it_2;
		++it_1;
		++it_2;
	}
}

TEMPLATE_TEST_CASE_SIG("Swap map with greater size", "[map] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::map<T, char>		ft_map_1;
	ft::map<T, char>		ft_map_2;
	std::map<T, char>		map_1;
	std::map<T, char>		map_2;

	typename ft::map<T, char>::iterator		ft_it_1;
	typename ft::map<T, char>::iterator		ft_it_2;
	typename std::map<T, char>::iterator		it_1;
	typename std::map<T, char>::iterator		it_2;

	for (int i = 0; i < V; ++i) {
		if (i % 2) {
			ft_map_1.insert(std::make_pair(i, i - 2));
			map_1.insert(std::make_pair(i, i - 2));
		}
		ft_map_2.insert(std::make_pair(i - 2, i));
		map_2.insert(std::make_pair(i - 2, i));
	}

	REQUIRE(map_1.size() == ft_map_1.size());
	REQUIRE(map_2.size() == ft_map_2.size());

	ft_map_1.swap(ft_map_2);
	map_1.swap(map_2);

	REQUIRE(map_1.size() == ft_map_1.size());
	REQUIRE(map_2.size() == ft_map_2.size());

	it_1 = map_1.begin();
	for (ft_it_1 = ft_map_1.begin(); ft_it_1 != ft_map_1.end(); ++ft_it_1) {
		REQUIRE(*ft_it_1 == *it_1);
		++it_1;
	}
	it_2 = map_2.begin();
	for (ft_it_2 = ft_map_2.begin(); ft_it_2 != ft_map_2.end(); ++ft_it_2) {
		REQUIRE(*ft_it_2 == *it_2);
		++it_2;
	}
}

TEMPLATE_TEST_CASE_SIG("Swap map with lower size", "[map] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::map<T, char>		ft_map_1;
	ft::map<T, char>		ft_map_2;
	std::map<T, char>		map_1;
	std::map<T, char>		map_2;

	typename ft::map<T, char>::iterator		ft_it_1;
	typename ft::map<T, char>::iterator		ft_it_2;
	typename std::map<T, char>::iterator		it_1;
	typename std::map<T, char>::iterator		it_2;

	for (int i = 0; i < V; ++i) {
		if (i % 2) {
			ft_map_2.insert(std::make_pair(i, i - 2));
			map_2.insert(std::make_pair(i, i - 2));
		}
		ft_map_1.insert(std::make_pair(i - 2, i));
		map_1.insert(std::make_pair(i - 2, i));
	}

	REQUIRE(map_1.size() == ft_map_1.size());
	REQUIRE(map_2.size() == ft_map_2.size());

	ft_map_1.swap(ft_map_2);
	map_1.swap(map_2);

	REQUIRE(map_1.size() == ft_map_1.size());
	REQUIRE(map_2.size() == ft_map_2.size());

	it_1 = map_1.begin();
	for (ft_it_1 = ft_map_1.begin(); ft_it_1 != ft_map_1.end(); ++ft_it_1) {
		REQUIRE(*ft_it_1 == *it_1);
		++it_1;
	}
	it_2 = map_2.begin();
	for (ft_it_2 = ft_map_2.begin(); ft_it_2 != ft_map_2.end(); ++ft_it_2) {
		REQUIRE(*ft_it_2 == *it_2);
		++it_2;
	}
}
