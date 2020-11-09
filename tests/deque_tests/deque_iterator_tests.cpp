/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_iterator_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:37:41 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 22:45:22 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include "deque.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Default iterator deque", "[deque] [iterator]",
													   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::deque<T>						ft_deque;
	std::deque<T>						deque;
	typename ft::deque<T>::iterator		ft_it;
	typename std::deque<T>::iterator	it;

	SECTION("Empty deque") {
		ft_it = ft_deque.begin();

		REQUIRE(ft_it == ft_deque.end());
	}

	SECTION("With one node") {
		ft_deque.push_back(1);
		deque.push_back(1);
		ft_it = ft_deque.begin();

		REQUIRE(ft_it != ft_deque.end());
		REQUIRE(*ft_it == *deque.begin());
	}

	SECTION("With many node") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_deque.push_back(i);
			deque.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_deque.begin();
			it = deque.begin();

			while (ft_it != ft_deque.end() && it != deque.end()) {
				if (ft_it != ft_deque.end())
					++ft_count_iterations;
				if (it != deque.end())
					++count_iterations;
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_deque.end();
			it = deque.end();

			while (ft_it != ft_deque.begin() && it != deque.begin()) {
				if (ft_it != ft_deque.begin())
					++ft_count_iterations;
				if (it != deque.begin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_deque.begin();
		typename ft::deque<T>::iterator		ft_it_copy(ft_it);

		REQUIRE(ft_it_copy == ft_it);
	}
}

TEMPLATE_TEST_CASE_SIG("Default constant iterator deque", "[deque] [iterator]",
															   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::deque<T>								ft_deque;
	std::deque<T>								deque;
	typename ft::deque<T>::const_iterator		ft_it;
	typename std::deque<T>::const_iterator		it;

	SECTION("Empty deque") {
		ft_it = ft_deque.begin();

		REQUIRE(ft_it == ft_deque.end());
	}

	SECTION("With one node") {
		ft_deque.push_back(1);
		deque.push_back(1);
		ft_it = ft_deque.begin();

		REQUIRE(ft_it != ft_deque.end());
		REQUIRE(*ft_it == *deque.begin());
	}

	SECTION("With many node") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_deque.push_back(i);
			deque.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_deque.begin();
			it = deque.begin();

			while (ft_it != ft_deque.end() && it != deque.end()) {
				if (ft_it != ft_deque.end())
					++ft_count_iterations;
				if (it != deque.end())
					++count_iterations;
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_deque.end();
			it = deque.end();

			while (ft_it != ft_deque.begin() && it != deque.begin()) {
				if (ft_it != ft_deque.begin())
					++ft_count_iterations;
				if (it != deque.begin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_deque.begin();
		typename ft::deque<T>::const_iterator	ft_it_copy(ft_it);

		REQUIRE(ft_it_copy == ft_it);
	}
}

TEMPLATE_TEST_CASE_SIG("Reverse iterator deque", "[deque] [iterator]",
															 ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::deque<T>								ft_deque;
	std::deque<T>								deque;
	typename ft::deque<T>::reverse_iterator		ft_it;
	typename std::deque<T>::reverse_iterator	it;

	SECTION("Empty vector") {
		ft_it = ft_deque.rbegin();

		REQUIRE(ft_it == ft_deque.rend());
	}

	SECTION("With one node") {
		ft_deque.push_back(1);
		deque.push_back(1);
		ft_it = ft_deque.rbegin();

		REQUIRE(ft_it != ft_deque.rend());
		REQUIRE(*ft_it == *deque.rbegin());
	}

	SECTION("With many node") {
		int		ft_count_iterations = 0;
		int		count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_deque.push_back(i);
			deque.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_deque.rbegin();
			it = deque.rbegin();

			while (ft_it != ft_deque.rend() && it != deque.rend()) {
				if (ft_it != ft_deque.rend())
					++ft_count_iterations;
				if (it != deque.rend())
					++count_iterations;
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_deque.rend();
			it = deque.rend();

			while (ft_it != ft_deque.rbegin() && it != deque.rbegin()) {
				if (ft_it != ft_deque.rbegin())
					++ft_count_iterations;
				if (it != deque.rbegin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_deque.rbegin();
		typename ft::deque<T>::reverse_iterator	ft_it_copy(ft_it);

		REQUIRE(ft_it_copy == ft_it);
	}
}

TEMPLATE_TEST_CASE_SIG("Reverse constant iterator deque", "[deque] [iterator]",
															   ((typename T, int V), T, V), (int, 10), (char, 10)) {
	ft::deque<T>										ft_deque;
	std::deque<T>										deque;
	typename ft::deque<T>::const_reverse_iterator		ft_it;
	typename std::deque<T>::const_reverse_iterator		it;

	SECTION("Empty vector") {
		ft_it = ft_deque.rbegin();

		REQUIRE(ft_it == ft_deque.rend());
	}

	SECTION("With one node") {
		ft_deque.push_back(1);
		deque.push_back(1);

		ft_it = ft_deque.rbegin();
		REQUIRE(ft_it != ft_deque.rend());
		REQUIRE(*ft_it == *deque.rbegin());
	}

	SECTION("With many node") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_deque.push_back(i);
			deque.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_deque.rbegin();
			it = deque.rbegin();

			while (ft_it != ft_deque.rend() && it != deque.rend()) {
				if (ft_it != ft_deque.rend())
					++ft_count_iterations;
				if (it != deque.rend())
					++count_iterations;
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_deque.rend();
			it = deque.rend();

			while (it != deque.rbegin()) {
				if (ft_it != ft_deque.rbegin())
					++ft_count_iterations;
				if (it != deque.rbegin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}
			REQUIRE(ft_count_iterations == count_iterations);
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_deque.rbegin();
		typename ft::deque<T>::const_reverse_iterator		ft_it_copy(ft_it);

		REQUIRE(ft_it_copy == ft_it);
	}
}
