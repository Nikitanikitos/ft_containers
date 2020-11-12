/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructor_tests.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:44:36 by imicah            #+#    #+#             */
/*   Updated: 2020/11/04 13:59:48 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG( "Default Constructors in map container", "[map] [constructor]",
															((typename T, int V), T, V), (int, 10), (char, 20)) {
	SECTION("Create map list") {
		ft::map<T, float>		ft_map;
		std::map<T, float>		map;

		REQUIRE(map.empty() == ft_map.empty());
		REQUIRE(map.size() == ft_map.size());
		REQUIRE(ft_map.begin() == ft_map.end());
	}
}

TEMPLATE_TEST_CASE_SIG("Copy constructor in map container", "[map] [constructor]",
														   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::map<T, float>		ft_map_for_copy;
	std::map<T, float>		map_for_copy;

	SECTION("Empty map") {
		ft::map<T, float>		ft_map(ft_map_for_copy);
		std::map<T, float>		map(map_for_copy);

		REQUIRE(map.empty() == ft_map.empty());
		REQUIRE(map.size() == ft_map.size());
		REQUIRE(ft_map.begin() == ft_map.end());
	}

	SECTION("With size") {
		for (int i = 1; i < V; i++) {
			ft::map<T, float>			ft_map(ft_map_for_copy);
			std::map<T, float>			map(map_for_copy);

			REQUIRE(map.size() == ft_map.size());
			if (i > 1) REQUIRE(*map.begin() == *ft_map.begin());

			ft_map_for_copy.insert(std::make_pair(i, i + .21));
			map_for_copy.insert(std::make_pair(i, i + .21));
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Assignation operator in map container", "[map] [constructor]",
															 	((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::map<T, float>		ft_map_for_copy;
	std::map<T, float>		map_for_copy;

	SECTION("Empty list") {
		ft::map<T, float>		ft_map = ft_map_for_copy;
		std::map<T, float>		map = map_for_copy;

		REQUIRE(map.empty() == ft_map.empty());
		REQUIRE(map.size() == ft_map.size());
	}

	SECTION("With size") {
		for (int i = 0; i < V; i++) {
			ft::map<T, float>		ft_map = ft_map_for_copy;
			std::map<T, float>		map = map_for_copy;

			REQUIRE(map.size() == ft_map.size());
			if (i > 1) REQUIRE(*map.begin() == *ft_map.begin());

			ft_map_for_copy.insert(std::make_pair(i, i + .42));
			map_for_copy.insert(std::make_pair(i, i + .42));
		}
	}

	for (int i = 0; i < V; i++) {
		ft_map_for_copy.insert(std::make_pair(i, i + .42));
		map_for_copy.insert(std::make_pair(i, i + .42));
	}

	SECTION("Assignation with lower size") {
		ft::map<T, float>		ft_map;
		std::map<T, float>		map;

		for (int i = 0; i < V / 2; ++i) {
			ft_map.insert(std::make_pair(i, i + -.42));
			map.insert(std::make_pair(i, i + -.42));
		}

		ft_map = ft_map_for_copy;
		map = map_for_copy;

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(*map.begin() == *ft_map.begin());
	}

	SECTION("Assignation with greater size") {
		ft::map<T, float>		ft_map;
		std::map<T, float>		map;

		for (int i = 0; i < V * 2; ++i) {
			ft_map.insert(std::make_pair(i, i + -.42));
			map.insert(std::make_pair(i, i + -.42));
		}

		ft_map = ft_map_for_copy;
		map = map_for_copy;

		REQUIRE(map.size() == ft_map.size());
		REQUIRE(*map.begin() == *ft_map.begin());
	}
}

TEMPLATE_TEST_CASE_SIG("Constructor via iterators in map container", "[map] [constructor]",
															   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::map<T, float>		ft_map_for_copy;
	std::map<T, float>		map_for_copy;

	SECTION("Empty list") {
		ft::map<T, float>		ft_map(ft_map_for_copy.begin(), ft_map_for_copy.end());
		std::map<T, float>		map(map_for_copy.begin(), map_for_copy.end());

		REQUIRE(map.empty() == ft_map.empty());
		REQUIRE(map.size() == ft_map.size());
	}

	SECTION("With size") {
		for (int i = 0; i < V; i++) {

			ft::map<T, float>		ft_map(ft_map_for_copy.begin(), ft_map_for_copy.end());
			std::map<T, float>		map(map_for_copy.begin(), map_for_copy.end());

			REQUIRE(map.empty() == ft_map.empty());
			REQUIRE(map.size() == ft_map.size());

			ft_map_for_copy.insert(std::make_pair(i, i + .21));
			map_for_copy.insert(std::make_pair(i, i + .21));
			map.clear();
			ft_map.clear();
		}
	}
}
