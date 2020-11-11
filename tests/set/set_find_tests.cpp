/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_find_tests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 01:07:03 by imicah            #+#    #+#             */
/*   Updated: 2020/11/12 01:07:03 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Find method in map", "[map] [access]",
					   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::set<T>		ft_set;
	std::set<T>		set;
	typename ft::set<T>::iterator		ft_it;
	typename std::set<T>::iterator		it;

	SECTION("Find in empty map") {
		ft_set.find(8);
		set.find(8);
	}

	for (int i = 0; i < V; ++i) {
		ft_set.insert(i);
		set.insert(i);
	}

	SECTION("Find exist key") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_it = ft_set.find(i);
				it = set.find(i);
				REQUIRE(*ft_it == *it);
			}
		}
	}

	SECTION("Find non-exist key") {
		ft_set.find(99);
		set.find(99);
	}
}
