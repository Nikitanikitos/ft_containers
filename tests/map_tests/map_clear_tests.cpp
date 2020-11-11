/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clear_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:51:44 by imicah            #+#    #+#             */
/*   Updated: 2020/11/11 19:51:44 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "../catch.hpp"

TEMPLATE_TEST_CASE("Clear list",  "[list] [clear]", int, float, char) {
	ft::map<TestType, char>		ft_map;
	std::map<TestType, char>	map;

	SECTION("empty list") {
		ft_map.clear();
		map.clear();

		REQUIRE(map.empty() == ft_map.empty());
		REQUIRE(map.size() == ft_map.size());
	}

	SECTION("size = 1") {
		ft_map.insert(std::make_pair(13, 13));
		map.insert(std::make_pair(13, 13));
		ft_map.clear();
		map.clear();

		REQUIRE(map.empty() == ft_map.empty());
		REQUIRE(map.size() == ft_map.size());
	}

	SECTION("with size = 42") {
		for (int i = 0; i < 42; ++i) {
			ft_map.insert(std::make_pair(i, i));
			map.insert(std::make_pair(i, i));
		}
		ft_map.clear();
		map.clear();

		REQUIRE(map.empty() == ft_map.empty());
		REQUIRE(map.size() == ft_map.size());
	}
}
