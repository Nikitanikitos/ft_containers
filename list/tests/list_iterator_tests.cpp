/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator_tests.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:22:29 by imicah            #+#    #+#             */
/*   Updated: 2020/10/22 20:55:35 by imicah           ###   ########.fr       */
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

		REQUIRE(ft_it == ft_list.end());
	}

	SECTION("WithOneNode") {
		ft_list.push_back(1);
		list.push_back(1);
		ft_it = ft_list.begin();

		REQUIRE(ft_it != ft_list.end());
		REQUIRE(*ft_it == *list.begin());
	}

	SECTION("WithManyNode") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_list.push_back(i);
			list.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_list.begin();
			it = list.begin();

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

		SECTION("Decrement test") {
			ft_it = ft_list.end();
			it = list.end();

			while (ft_it != ft_list.begin() && it != list.begin()) {
				if (ft_it != ft_list.begin())
					++ft_count_iterations;
				if (it != list.begin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Default constant iterator", "[list] [iterator]",
							   ((typename T, int V), T, V), (int, 10), (char, 20)) {

	ft::list<T>								ft_list;
	std::list<T>							list;
	typename ft::list<T>::const_iterator	ft_it;
	typename std::list<T>::const_iterator	it;

	SECTION("InEmptyList") {
		ft_it = ft_list.begin();

		REQUIRE(ft_it == ft_list.end());
	}

	SECTION("WithOneNode") {
		ft_list.push_back(1);
		list.push_back(1);
		ft_it = ft_list.begin();

		REQUIRE(ft_it != ft_list.end());
		REQUIRE(*ft_it == *list.begin());
	}

	SECTION("WithManyNode") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_list.push_back(i);
			list.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_list.begin();
			it = list.begin();

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

		SECTION("Decrement test") {
			ft_it = ft_list.end();
			it = list.end();

			while (ft_it != ft_list.begin() && it != list.begin()) {
				if (ft_it != ft_list.begin())
					++ft_count_iterations;
				if (it != list.begin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Reverse iterator", "[list] [iterator]",
					   ((typename T, int V), T, V), (int, 10), (char, 20)) {

	ft::list<T>									ft_list;
	std::list<T>								list;
	typename ft::list<T>::reverse_iterator		ft_it;
	typename std::list<T>::reverse_iterator		it;

	SECTION("InEmptyList") {
		ft_it = ft_list.rbegin();

		REQUIRE(ft_it == ft_list.rend());
	}

	SECTION("WithOneNode") {
		ft_list.push_back(1);
		list.push_back(1);
		ft_it = ft_list.rbegin();

		REQUIRE(ft_it != ft_list.rend());
		REQUIRE(*ft_it == *list.rbegin());
	}

	SECTION("WithManyNode") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_list.push_back(i);
			list.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_list.rbegin();
			it = list.rbegin();

			while (ft_it != ft_list.rend() && it != list.rend()) {
				if (ft_it != ft_list.rend())
					++ft_count_iterations;
				if (it != list.rend())
					++count_iterations;
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_list.rend();
			it = list.rend();

			while (ft_it != ft_list.rbegin() && it != list.rbegin()) {
				if (ft_it != ft_list.rbegin())
					++ft_count_iterations;
				if (it != list.rbegin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Reverse constant iterator", "[list] [iterator]",
					   ((typename T, int V), T, V), (int, 10), (char, 20)) {

	ft::list<T>										ft_list;
	std::list<T>									list;
	typename ft::list<T>::const_reverse_iterator	ft_it;
	typename std::list<T>::const_reverse_iterator	it;

	SECTION("InEmptyList") {
		ft_it = ft_list.rbegin();

		REQUIRE(ft_it == ft_list.rend());
	}

	SECTION("WithOneNode") {
		ft_list.push_back(1);
		list.push_back(1);
		ft_it = ft_list.rbegin();

		REQUIRE(ft_it != ft_list.rend());
		REQUIRE(*ft_it == *list.rbegin());
	}

	SECTION("WithManyNode") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_list.push_back(i);
			list.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_list.rbegin();
			it = list.rbegin();

			while (ft_it != ft_list.rend() && it != list.rend()) {
				if (ft_it != ft_list.rend())
					++ft_count_iterations;
				if (it != list.rend())
					++count_iterations;
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_list.rend();
			it = list.rend();

			while (ft_it != ft_list.rbegin() && it != list.rbegin()) {
				if (ft_it != ft_list.rbegin())
					++ft_count_iterations;
				if (it != list.rbegin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}
	}
}
