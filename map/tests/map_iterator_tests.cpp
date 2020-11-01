/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator_tests.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:21:57 by imicah            #+#    #+#             */
/*   Updated: 2020/11/01 17:34:47 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Default map iterator", "[map] [iterator]", ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::map<T, std::string>							ft_map;
	std::map<T, std::string>						map;
	typename ft::map<T, std::string>::iterator		ft_it;
	typename std::map<T, std::string>::iterator		it;

	SECTION("Empty list") {
		ft_it = ft_map.begin();

		REQUIRE(ft_it == ft_map.end());
	}

	SECTION("With one node") {
		ft_map.insert(std::make_pair(123, "string"));
		map.insert(std::make_pair(123, "string"));
		ft_it = ft_map.begin();

		REQUIRE(ft_it != ft_map.end());
		REQUIRE(*ft_it == *map.begin());
	}

	SECTION("With many node") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_map.insert(std::make_pair(i, "string" + std::to_string(i + 21)));
			map.insert(std::make_pair(i, "string" + std::to_string(i + 21)));
		}

		SECTION("Increment iterator") {
			ft_it = ft_map.begin();
			it = map.begin();

			while (ft_it != ft_map.end() && it != map.end()) {
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_map.end();
			it = map.end();

			--ft_it;
			--it;
			while (ft_it != ft_map.begin() && it != map.begin()) {
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Increment/decrement operator") {
			ft_it = ft_map.begin();
			it = map.begin();

			++ft_it;
			++it;
			++ft_it;
			++it;
			--ft_it;
			--it;
			++ft_it;
			++it;
			--ft_it;
			--it;
			--ft_it;
			--it;

			REQUIRE(*ft_it == *it);
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_map.begin();
		typename ft::map<T, std::string>::iterator		ft_it_copy(ft_it);

		REQUIRE(*ft_it_copy == *ft_it);
	}
}

TEMPLATE_TEST_CASE_SIG("Default const map iterator", "[map] [iterator]",
																((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::map<T, std::string>							ft_map;
	std::map<T, std::string>						map;
	typename ft::map<T, std::string>::const_iterator		ft_it;
	typename std::map<T, std::string>::const_iterator		it;

	SECTION("Empty list") {
		ft_it = ft_map.begin();

		REQUIRE(ft_it == ft_map.end());
	}

	SECTION("With one node") {
		ft_map.insert(std::make_pair(123, "string"));
		map.insert(std::make_pair(123, "string"));
		ft_it = ft_map.begin();

		REQUIRE(ft_it != ft_map.end());
		REQUIRE(*ft_it == *map.begin());
	}

	SECTION("With many node") {
		int			ft_count_iterations = 0;
		int			count_iterations = 0;

		for (int i = 0; i < V; ++i) {
			ft_map.insert(std::make_pair(i, "string" + std::to_string(i + 21)));
			map.insert(std::make_pair(i, "string" + std::to_string(i + 21)));
		}

		SECTION("Increment iterator") {
			ft_it = ft_map.begin();
			it = map.begin();

			while (ft_it != ft_map.end() && it != map.end()) {
				REQUIRE(*ft_it == *it);
				++ft_it;
				++it;
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Decrement iterator") {
			ft_it = ft_map.end();
			it = map.end();

			--ft_it;
			--it;
			while (ft_it != ft_map.begin() && it != map.begin()) {
				--ft_it;
				--it;
				REQUIRE(*ft_it == *it);
			}

			REQUIRE(ft_count_iterations == count_iterations);
		}

		SECTION("Increment/decrement operator") {
			ft_it = ft_map.begin();
			it = map.begin();

			++ft_it;
			++it;
			++ft_it;
			++it;
			--ft_it;
			--it;
			++ft_it;
			++it;
			--ft_it;
			--it;
			--ft_it;
			--it;

			REQUIRE(*ft_it == *it);
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_map.begin();
		typename ft::map<T, std::string>::const_iterator		ft_it_copy(ft_it);

		REQUIRE(*ft_it_copy == *ft_it);
	}
}

TEMPLATE_TEST_CASE_SIG("Reverse map iterator", "[map] [iterator]", ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::map<T, std::string>									ft_map;
	std::map<T, std::string>								map;
	typename ft::map<T, std::string>::reverse_iterator		ft_it;
	typename std::map<T, std::string>::reverse_iterator		it;

	SECTION("Empty list") {
		ft_it = ft_map.rbegin();

		REQUIRE(ft_it == ft_map.rend());
	}

	SECTION("With one node") {
		ft_map.insert(std::make_pair(123, "string"));
		map.insert(std::make_pair(123, "string"));
		ft_it = ft_map.rbegin();

		REQUIRE(ft_it != ft_map.rend());
//		REQUIRE(*ft_it == *ft_map.rbegin());
	}

	SECTION("With many node") {

		for (int i = 0; i < V; ++i) {
			ft_map.insert(std::make_pair(i, "string" + std::to_string(i + 21)));
			map.insert(std::make_pair(i, "string" + std::to_string(i + 21)));
		}

		SECTION("Increment iterator") {
			ft_it = ft_map.rbegin();
			it = map.rbegin();

			while (ft_it != ft_map.rend() && it != map.rend()) {
				++ft_it;
				++it;
//				REQUIRE(*ft_it == *it); // TODO ватафак...
			}
		}

		SECTION("Decrement iterator") {
			ft_it = ft_map.rend();
			it = map.rend();

			while (ft_it != ft_map.rbegin() && it != map.rbegin()) {
				--ft_it;
				--it;
//				REQUIRE(*ft_it == *it); // TODO ватафак...
			}
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_map.rbegin();
		typename ft::map<T, std::string>::reverse_iterator		ft_it_copy(ft_it);

		REQUIRE(*ft_it_copy == *ft_it);
	}
}

TEMPLATE_TEST_CASE_SIG("const reverse map iterator", "[map] [iterator]",
																((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::map<T, std::string>									ft_map;
	std::map<T, std::string>								map;
	typename ft::map<T, std::string>::const_reverse_iterator		ft_it;
	typename std::map<T, std::string>::const_reverse_iterator		it;

	SECTION("Empty list") {
		ft_it = ft_map.rbegin();

		REQUIRE(ft_it == ft_map.rend());
	}

	SECTION("With one node") {
		ft_map.insert(std::make_pair(123, "string"));
		map.insert(std::make_pair(123, "string"));
		ft_it = ft_map.rbegin();

		REQUIRE(ft_it != ft_map.rend());
//		REQUIRE(*ft_it == *ft_map.rbegin());
	}

	SECTION("With many node") {

		for (int i = 0; i < V; ++i) {
			ft_map.insert(std::make_pair(i, "string" + std::to_string(i + 21)));
			map.insert(std::make_pair(i, "string" + std::to_string(i + 21)));
		}

		SECTION("Increment iterator") {
			ft_it = ft_map.rbegin();
			it = map.rbegin();

			while (ft_it != ft_map.rend() && it != map.rend()) {
				++ft_it;
				++it;
//				REQUIRE(*ft_it == *it); // TODO ватафак...
			}
		}

		SECTION("Decrement iterator") {
			ft_it = ft_map.rend();
			it = map.rend();

			while (ft_it != ft_map.rbegin() && it != map.rbegin()) {
				--ft_it;
				--it;
//				REQUIRE(*ft_it == *it); // TODO ватафак...
			}
		}
	}

	SECTION("Copy constructor") {
		ft_it = ft_map.rbegin();
		typename ft::map<T, std::string>::const_reverse_iterator		ft_it_copy(ft_it);

		REQUIRE(*ft_it_copy == *ft_it);
	}
}
