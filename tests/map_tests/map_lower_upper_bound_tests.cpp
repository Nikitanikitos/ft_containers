/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lower_upper_bound_tests.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:50:21 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 15:16:30 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Lower/upper bound test in map", "[map] [lower_bound] [upper_bound]",
					 														  ((typename T, int V), T, V), (int, 10)) {
	ft::map<T, int>							ft_map;
	std::map<T, int>						map;
	typename ft::map<T, int>::iterator		ft_it;
	typename std::map<T, int>::iterator		it;

	for (int i = 0; i < V; ++i) {
		ft_map.insert(std::make_pair(i, i));
		map.insert(std::make_pair(i, i));
	}

	SECTION("lower bound") {
		ft_it = ft_map.lower_bound(V / 2);
		it = map.lower_bound(V / 2);
		REQUIRE(*ft_it == *it);

		ft_it = ft_map.lower_bound(1);
		it = map.lower_bound(1);
		REQUIRE(*ft_it == *it);

		ft_it = ft_map.lower_bound(V - 1);
		it = map.lower_bound(V - 1);
		REQUIRE(*ft_it == *it);
	}

	SECTION("upper bound") {
		ft_it = ft_map.upper_bound(V / 2);
		it = map.upper_bound(V / 2);
		REQUIRE(*ft_it == *it);

		ft_it = ft_map.upper_bound(1);
		it = map.upper_bound(1);
		REQUIRE(*ft_it == *it);
	}
}

TEMPLATE_TEST_CASE_SIG("Equal range test in map", "[map] [equal_range]", ((typename T, int V), T, V), (int, 10)) {
	ft::map<T, int>							ft_map;
	std::map<T, int>						map;
	std::pair<typename ft::map<T, int>::iterator, typename ft::map<T, int>::iterator>		ft_result;
	std::pair<typename std::map<T, int>::iterator, typename std::map<T, int>::iterator>		result;

	for (int i = 0; i < V; ++i) {
		ft_map.insert(std::make_pair(i, i));
		map.insert(std::make_pair(i, i));
	}

	SECTION("lower bound") {
		ft_result = ft_map.equal_range(V / 2);
		result = map.equal_range(V / 2);
		REQUIRE(*ft_result.first == *result.first);
		REQUIRE(*ft_result.second == *result.second);

		ft_result = ft_map.equal_range(1);
		result = map.equal_range(1);
		REQUIRE(*ft_result.first == *result.first);
		REQUIRE(*ft_result.second == *result.second);

	}
}
