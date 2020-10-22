/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator_tests.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:22:29 by imicah            #+#    #+#             */
/*   Updated: 2020/10/22 14:17:07 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Default iterator", "[list] [iterator]",
										((typename T, int V), T, V), (int, 10), (char, 20)) {

	ft::list<T> ft_list;
	std::list<T> list;

	SECTION("InEmptyList") {
		typename ft::list<T>::iterator	ft_it = ft_list.begin();
		typename std::list<T>::iterator	it = list.begin();

		REQUIRE(ft_it == ft_list.end());
		REQUIRE(it == list.end());
	}

	SECTION("WithOneNode") {
		ft_list.push_back(1);
		list.push_back(1);

		typename ft::list<T>::iterator	ft_it = ft_list.begin();
		typename std::list<T>::iterator	it = list.begin();
		int			ft_count_iterations;
		int			count_iterations;

		REQUIRE(ft_it != ft_list.end());
		REQUIRE(it != list.end());
		REQUIRE(*ft_it == *it);

		for (ft_count_iterations = 0; ft_it != ft_list.end(); ++ft_count_iterations)
			++ft_it;
		for (count_iterations = 0; it != list.end(); ++count_iterations)
			++it;
		REQUIRE(ft_count_iterations == count_iterations);
	}

	SECTION("WithManyNode") {
		for (int i = 0; i < V; ++i) {
			ft_list.push_back(i);
			list.push_back(i);
		}

		typename ft::list<T>::iterator	ft_it = ft_list.begin();
		typename std::list<T>::iterator	it = list.begin();
		int			ft_count_iterations;
		int			count_iterations;

		REQUIRE(ft_it != ft_list.end());
		REQUIRE(it != list.end());
		REQUIRE(*ft_it == *it);

		for (ft_count_iterations = 0; ft_it != ft_list.end(); ++ft_count_iterations)
			++ft_it;
		for (count_iterations = 0; it != list.end(); ++count_iterations)
			++it;
		REQUIRE(ft_count_iterations == count_iterations);
	}
}
