/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator_tests.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:58:39 by imicah            #+#    #+#             */
/*   Updated: 2020/10/27 14:38:39 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include "../catch.hpp"

TEMPLATE_TEST_CASE_SIG("Default iterator vector", "[vector] [iterator]",
																   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::vector<T>							ft_vector;
	std::vector<T>							vector;
	typename ft::vector<T>::iterator		ft_it;
	typename std::vector<T>::iterator		it;

	SECTION("Empty vector") {
		ft_it = ft_vector.begin();

		REQUIRE(ft_it == ft_vector.end());
	}

	SECTION("With one node") {
		ft_vector.push_back(1);
		vector.push_back(1);
		ft_it = ft_vector.begin();

		REQUIRE(ft_it != ft_vector.end());
		REQUIRE(*ft_it == *vector.begin());
	}

	SECTION("With many node") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_vector.push_back(i);
			vector.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_vector.begin();
			it = vector.begin();

			while (ft_it != ft_vector.end() && it != vector.end()) {
				if (ft_it != ft_vector.end())
					++ft_count_iterations;
				if (it != vector.end())
					++count_iterations;
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_vector.end();
			it = vector.end();

			while (ft_it != ft_vector.begin() && it != vector.begin()) {
				if (ft_it != ft_vector.begin())
					++ft_count_iterations;
				if (it != vector.begin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_vector.begin();
		typename ft::vector<T>::iterator		ft_it_copy(ft_it);

		REQUIRE(ft_it_copy == ft_it);
	}
}

TEMPLATE_TEST_CASE_SIG("Default constant iterator vector", "[vector] [iterator]",
																((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::vector<T>								ft_vector;
	std::vector<T>								vector;
	typename ft::vector<T>::const_iterator		ft_it;
	typename std::vector<T>::const_iterator		it;

	SECTION("Empty vector") {
		ft_it = ft_vector.begin();

		REQUIRE(ft_it == ft_vector.end());
	}

	SECTION("With one node") {
		ft_vector.push_back(1);
		vector.push_back(1);
		ft_it = ft_vector.begin();

		REQUIRE(ft_it != ft_vector.end());
		REQUIRE(*ft_it == *vector.begin());
	}

	SECTION("With many node") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_vector.push_back(i);
			vector.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_vector.begin();
			it = vector.begin();

			while (ft_it != ft_vector.end() && it != vector.end()) {
				if (ft_it != ft_vector.end())
					++ft_count_iterations;
				if (it != vector.end())
					++count_iterations;
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_vector.end();
			it = vector.end();

			while (ft_it != ft_vector.begin() && it != vector.begin()) {
				if (ft_it != ft_vector.begin())
					++ft_count_iterations;
				if (it != vector.begin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_vector.begin();
		typename ft::vector<T>::const_iterator	ft_it_copy(ft_it);

		REQUIRE(ft_it_copy == ft_it);
	}
}

TEMPLATE_TEST_CASE_SIG("Reverse iterator vector", "[vector] [iterator]",
																((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::vector<T>									ft_vector;
	std::vector<T>									vector;
	typename ft::vector<T>::reverse_iterator		ft_it;
	typename std::vector<T>::reverse_iterator		it;

	SECTION("Empty vector") {
		ft_it = ft_vector.rbegin();

		REQUIRE(ft_it == ft_vector.rend());
	}

	SECTION("With one node") {
		ft_vector.push_back(1);
		vector.push_back(1);
		ft_it = ft_vector.rbegin();

		REQUIRE(ft_it != ft_vector.rend());
		REQUIRE(*ft_it == *vector.rbegin());
	}

	SECTION("With many node") {
		int		ft_count_iterations = 0;
		int		count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_vector.push_back(i);
			vector.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_vector.rbegin();
			it = vector.rbegin();

			while (ft_it != ft_vector.rend() && it != vector.rend()) {
				if (ft_it != ft_vector.rend())
					++ft_count_iterations;
				if (it != vector.rend())
					++count_iterations;
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_vector.rend();
			it = vector.rend();

			while (ft_it != ft_vector.rbegin() && it != vector.rbegin()) {
				if (ft_it != ft_vector.rbegin())
					++ft_count_iterations;
				if (it != vector.rbegin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_vector.rbegin();
		typename ft::vector<T>::reverse_iterator	ft_it_copy(ft_it);

		REQUIRE(ft_it_copy == ft_it);
	}
}

TEMPLATE_TEST_CASE_SIG("Reverse constant iterator vector", "[vector] [iterator]",
																   ((typename T, int V), T, V), (int, 10), (char, 10)) {
	ft::vector<T>										ft_vector;
	std::vector<T>										vector;
	typename ft::vector<T>::const_reverse_iterator		ft_it;
	typename std::vector<T>::const_reverse_iterator		it;

	SECTION("Empty vector") {
		ft_it = ft_vector.rbegin();

		REQUIRE(ft_it == ft_vector.rend());
	}

	SECTION("With one node") {
		ft_vector.push_back(1);
		vector.push_back(1);

		ft_it = ft_vector.rbegin();
		REQUIRE(ft_it != ft_vector.rend());
		REQUIRE(*ft_it == *vector.rbegin());
	}

	SECTION("With many node") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_vector.push_back(i);
			vector.push_back(i);
		}

		SECTION("Increment iterator") {
			ft_it = ft_vector.rbegin();
			it = vector.rbegin();

			while (ft_it != ft_vector.rend() && it != vector.rend()) {
				if (ft_it != ft_vector.rend())
					++ft_count_iterations;
				if (it != vector.rend())
					++count_iterations;
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_vector.rend();
			it = vector.rend();

			while (it != vector.rbegin()) {
				if (ft_it != ft_vector.rbegin())
					++ft_count_iterations;
				if (it != vector.rbegin())
					++count_iterations;
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}
			REQUIRE(ft_count_iterations == count_iterations);
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_vector.rbegin();
		typename ft::vector<T>::const_reverse_iterator		ft_it_copy(ft_it);

		REQUIRE(ft_it_copy == ft_it);
	}
}
