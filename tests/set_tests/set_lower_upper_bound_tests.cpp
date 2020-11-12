/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lower_upper_bound_tests.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 01:08:43 by imicah            #+#    #+#             */
/*   Updated: 2020/11/12 01:10:38 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Lower/upper bound test in set", "[set] [lower_bound] [upper_bound]",
														   ((typename T, int V), T, V), (int, 10)) {
	ft::set<T>							ft_set;
	std::set<T>							set;
	typename ft::set<T>::iterator		ft_it;
	typename std::set<T>::iterator		it;

	for (int i = 0; i < V; ++i) {
		ft_set.insert(i);
		set.insert(i);
	}

	SECTION("lower bound") {
		ft_it = ft_set.lower_bound(V / 2);
		it = set.lower_bound(V / 2);
		REQUIRE(*ft_it == *it);

		ft_it = ft_set.lower_bound(1);
		it = set.lower_bound(1);
		REQUIRE(*ft_it == *it);

		ft_it = ft_set.lower_bound(V - 1);
		it = set.lower_bound(V - 1);
		REQUIRE(*ft_it == *it);
	}

	SECTION("upper bound") {
		ft_it = ft_set.upper_bound(V / 2);
		it = set.upper_bound(V / 2);
		REQUIRE(*ft_it == *it);

		ft_it = ft_set.upper_bound(1);
		it = set.upper_bound(1);
		REQUIRE(*ft_it == *it);
	}
}

TEMPLATE_TEST_CASE_SIG("Equal range test in set", "[set] [equal_range]", ((typename T, int V), T, V), (int, 10)) {
	ft::set<T>							ft_set;
	std::set<T>							set;
	std::pair<typename ft::set<T>::iterator, typename ft::set<T>::iterator>		ft_result;
	std::pair<typename std::set<T>::iterator, typename std::set<T>::iterator>		result;

	for (int i = 0; i < V; ++i) {
		ft_set.insert(i);
		set.insert(i);
	}

	SECTION("lower bound") {
		ft_result = ft_set.equal_range(V / 2);
		result = set.equal_range(V / 2);
		REQUIRE(*ft_result.first == *result.first);
		REQUIRE(*ft_result.second == *result.second);

		ft_result = ft_set.equal_range(1);
		result = set.equal_range(1);
		REQUIRE(*ft_result.first == *result.first);
		REQUIRE(*ft_result.second == *result.second);

	}
}
