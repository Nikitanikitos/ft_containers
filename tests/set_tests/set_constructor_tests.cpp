/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constuctor_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:44:18 by imicah            #+#    #+#             */
/*   Updated: 2020/11/11 23:02:31 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG( "Default Constructors in set container", "[set] [constructor]",
													((typename T, int V), T, V), (int, 10), (char, 20)) {
	SECTION("Create empty set") {
	ft::set<T>		ft_set;
	std::set<T>		set;

	REQUIRE(set.empty() == ft_set.empty());
	REQUIRE(set.size() == ft_set.size());
	REQUIRE(ft_set.begin() == ft_set.end());
	}
}

TEMPLATE_TEST_CASE_SIG("Copy constructor in set container", "[set] [constructor]",
												   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::set<T>		ft_set_for_copy;
	std::set<T>		set_for_copy;

	SECTION("Empty set") {
		ft::set<T>			ft_set(ft_set_for_copy);
		std::set<T>			set(set_for_copy);

		REQUIRE(set.empty() == ft_set.empty());
		REQUIRE(set.size() == ft_set.size());
		REQUIRE(ft_set.begin() == ft_set.end());
	}

	SECTION("With size") {
		for (int i = 1; i < V; i++) {
			ft::set<T>			ft_set(ft_set_for_copy);
			std::set<T>			set(set_for_copy);

			REQUIRE(set.size() == ft_set.size());
			if (i > 1) REQUIRE(*set.begin() == *ft_set.begin());

			ft_set_for_copy.insert(i);
			set_for_copy.insert(i);
		}
	}
}
TEMPLATE_TEST_CASE_SIG("Assignation operator in set container", "[set] [constructor]",
					   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::set<T>		ft_set_for_copy;
	std::set<T>		set_for_copy;

	SECTION("Empty set") {
		ft::set<T>		ft_set = ft_set_for_copy;
		std::set<T>		set = set_for_copy;

		REQUIRE(set.empty() == ft_set.empty());
		REQUIRE(set.size() == ft_set.size());
	}

	SECTION("With size") {
		for (int i = 0; i < V; i++) {
			ft::set<T>			ft_set = ft_set_for_copy;
			std::set<T>			set = set_for_copy;

			REQUIRE(set.size() == ft_set.size());
			if (i > 1) REQUIRE(*set.begin() == *ft_set.begin());

			ft_set_for_copy.insert(i);
			set_for_copy.insert(i);
		}
	}

	for (int i = 0; i < V; i++) {
		ft_set_for_copy.insert(i);
		set_for_copy.insert(i);
	}

	SECTION("Assignation with lower size") {
		ft::set<T>		ft_set;
		std::set<T>		set;

		for (int i = 0; i < V / 2; ++i) {
			ft_set.insert(i);
			set.insert(i);
		}

		ft_set = ft_set_for_copy;
		set = set_for_copy;

		REQUIRE(set.size() == ft_set.size());
		REQUIRE(*set.begin() == *ft_set.begin());
	}

	SECTION("Assignation with greater size") {
		ft::set<T>		ft_set;
		std::set<T>		set;

		for (int i = 0; i < V * 2; ++i) {
			ft_set.insert(i);
			set.insert(i);
		}

		ft_set = ft_set_for_copy;
		set = set_for_copy;

		REQUIRE(set.size() == ft_set.size());
		REQUIRE(*set.begin() == *ft_set.begin());
	}
}

TEMPLATE_TEST_CASE_SIG("Constructor via iterators in set container", "[set] [constructor]",
																   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::set<T>		ft_set_for_copy;
	std::set<T>		set_for_copy;

	SECTION("Empty set") {
		ft::set<T>		ft_map(ft_set_for_copy.begin(), ft_set_for_copy.end());
		std::set<T>		map(set_for_copy.begin(), set_for_copy.end());

		REQUIRE(map.empty() == ft_map.empty());
		REQUIRE(map.size() == ft_map.size());
	}

	SECTION("With size") {
		for (int i = 0; i < V; i++) {

			ft::set<T>		ft_set(ft_set_for_copy.begin(), ft_set_for_copy.end());
			std::set<T>		set(set_for_copy.begin(), set_for_copy.end());

			REQUIRE(set.empty() == ft_set.empty());
			REQUIRE(set.size() == ft_set.size());

			ft_set_for_copy.insert(i);
			set_for_copy.insert(i);
			set.clear();
			ft_set.clear();
		}
	}
}
