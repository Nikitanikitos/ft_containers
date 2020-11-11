/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find_tests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:54:26 by imicah            #+#    #+#             */
/*   Updated: 2020/11/11 19:59:05 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "../catch.hpp"

TEMPLATE_TEST_CASE_SIG("Find method in map", "[map] [access]",
					   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::map<T, char>		ft_map;
	std::map<T, char>		map;
	typename ft::map<T, char>::iterator		ft_it;
	typename std::map<T, char>::iterator		it;

	SECTION("Find in empty map") {
		ft_map.find(8);
		map.find(8);
	}

	for (int i = 0; i < V; ++i) {
		ft_map.insert(std::make_pair(i, i + 1));
		map.insert(std::make_pair(i, i + 1));
	}

	SECTION("Find exist key") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_it = ft_map.find(i);
				it = map.find(i);
				REQUIRE(*ft_it == *it);
			}
		}
	}

	SECTION("Find non-exist key") {
		ft_map.find(99);
		map.find(99);
	}
}