/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator_tests.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:22:29 by imicah            #+#    #+#             */
/*   Updated: 2020/10/22 20:17:27 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Default iterator", "[list] [iterator]",
										((typename T, int V), T, V), (int, 10), (char, 20)) {

	ft::list<T>							ft_list;
	std::list<T>						list;
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	SECTION("InEmptyList") {
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(ft_it == ft_list.end());
//		REQUIRE(it == list.end());
	}

	SECTION("WithOneNode") {
		ft_list.push_back(1);
		list.push_back(1);
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(ft_it != ft_list.end());
//		REQUIRE(it != list.end());
		REQUIRE(*ft_it == *it);
	}

	SECTION("WithManyNode") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_list.push_back(i);
			list.push_back(i);
		}
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(ft_it != ft_list.end());
//		REQUIRE(it != list.end());

		while (ft_it != ft_list.end() && it != list.end()) {
			if (ft_it != ft_list.end())
				++ft_count_iterations;
			if (it != list.end())
				++count_iterations;
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
		REQUIRE(ft_count_iterations == count_iterations);
	}
}

TEMPLATE_TEST_CASE_SIG("Default constant iterator", "[list] [iterator]",
							   ((typename T, int V), T, V), (int, 10), (char, 20)) {

	ft::list<T> ft_list;
	std::list<T> list;
	typename ft::list<T>::const_iterator	ft_it;
	typename std::list<T>::const_iterator	it;

	SECTION("InEmptyList") {
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(ft_it == ft_list.end());
//		REQUIRE(it == list.end());
	}

	SECTION("WithOneNode") {
		int			ft_count_iterations;
		int			count_iterations;
		ft_list.push_back(1);
		list.push_back(1);
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(ft_it != ft_list.end());
//		REQUIRE(it != list.end());
		REQUIRE(*ft_it == *it);
	}

	SECTION("WithManyNode") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_list.push_back(i);
			list.push_back(i);
		}
		ft_it = ft_list.begin();
		it = list.begin();

		REQUIRE(ft_it != ft_list.end());
//		REQUIRE(it != list.end());

		while (ft_it != ft_list.end() && it != list.end()) {
			if (ft_it != ft_list.end())
				++ft_count_iterations;
			if (it != list.end())
				++count_iterations;
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
		REQUIRE(ft_count_iterations == count_iterations);
	}
}
