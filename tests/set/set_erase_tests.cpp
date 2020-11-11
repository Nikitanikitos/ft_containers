/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_erase_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 00:46:53 by imicah            #+#    #+#             */
/*   Updated: 2020/11/12 00:51:04 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Erase in set through key", "[set] [erase]", ((typename T, int V), T, V), (int, 10)) {
	ft::set<T>							ft_set;
	std::set<T>							set;
	typename ft::set<T>::iterator		ft_it;
	typename std::set<T>::iterator		it;

	SECTION("with size = 1") {
		ft_set.insert(12);
		set.insert(12);

		set.erase(12);
		ft_set.erase(12);

		REQUIRE(set.size() == ft_set.size());
		REQUIRE(set.empty() == ft_set.empty());
	}
	for (int i = 0; i < V; ++i) {
		ft_set.insert(i);
		set.insert(i);
	}

	SECTION("with size = V") {
		for (size_t i = 0; i < ft_set.size(); i++) {
			if (i % 2) {
				ft_set.erase(i);
				set.erase(i);
				it = set.begin();
				REQUIRE(set.size() == ft_set.size());
				for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
					REQUIRE(*it++ == *ft_it);
			}
		}
	}

	SECTION("erase begin") {
		while (ft_set.size()) {
			T	ft_value = *ft_set.begin();
			T	value = *set.begin();
			ft_set.erase(ft_value);
			set.erase(value);
			it = set.begin();
			for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
				REQUIRE(*it++ == *ft_it);
		}
	}

	SECTION("erase end") {
		while (ft_set.size()) {
			ft_it = --ft_set.end();
			it = --set.end();
			T	ft_value = *ft_it;
			T	value = *it;
			ft_set.erase(ft_value);
			set.erase(value);
			it = set.begin();
			for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
				REQUIRE(*it++ == *ft_it);
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Erase in set through iterator", "[set] [erase]", ((typename T, int V), T, V), (int, 10)) {
	ft::set<T>							ft_set;
	std::set<T>							set;
	typename ft::set<T>::iterator		ft_it;
	typename std::set<T>::iterator		it;

	SECTION("with size = 1") {
		ft_set.insert(12);
		set.insert(12);

		set.erase(set.begin());
		ft_set.erase(ft_set.begin());

		REQUIRE(set.size() == ft_set.size());
		REQUIRE(set.empty() == ft_set.empty());
	}

	for (int i = 0; i < V; ++i) {
		ft_set.insert(i);
		set.insert(i);
	}

	SECTION("with size = V") {
		for (size_t i = 0; i < ft_set.size(); i++) {
			if (i % 2) {
				ft_it = ft_set.find(i);
				it = set.find(i);
				ft_set.erase(ft_it);
				set.erase(it);
				it = set.begin();
				REQUIRE(set.size() == ft_set.size());
				for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
					REQUIRE(*it++ == *ft_it);
			}
		}
	}

	SECTION("erase begin") {
		while (ft_set.size()) {
			ft_set.erase(ft_set.begin());
			set.erase(set.begin());
			it = set.begin();
			for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
				REQUIRE(*it++ == *ft_it);
		}
	}

	SECTION("erase end") {
		while (ft_set.size()) {
			ft_it = --ft_set.end();
			it = --set.end();
			ft_set.erase(ft_it);
			set.erase(it);
			it = set.begin();
			for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
				REQUIRE(*it++ == *ft_it);
		}
	}

}

TEMPLATE_TEST_CASE_SIG("Erase in set through with two iterator", "[set] [erase]",
					   ((typename T, int V), T, V), (int, 28), (char, 123)) {
	ft::set<T>							ft_set;
	std::set<T>							set;
	typename ft::set<T>::iterator		ft_it;
	typename std::set<T>::iterator		it;

	SECTION("with size = 1") {
		set.erase(set.begin(), set.begin());
		ft_set.erase(ft_set.begin(), ft_set.begin());

		REQUIRE(set.size() == ft_set.size());
		REQUIRE(set.empty() == ft_set.empty());
	}

	for (int i = 0; i < V; ++i) {
		ft_set.insert(i);
		set.insert(i);
	}

	SECTION("with size = V") {
		ft_it = ft_set.begin();
		it = set.begin();
		for (size_t i = 0; i < ft_set.size() / 2; ++i) {
			++it;
			++ft_it;
		}

		SECTION("First part") {
			ft_set.erase(ft_set.begin(), ft_it);
			set.erase(set.begin(), it);
			it = set.begin();

			REQUIRE(set.size() == ft_set.size());
			for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
				REQUIRE(*it++ == *ft_it);
		}

		SECTION("Second part") {
			ft_set.erase(ft_it, ft_set.end());
			set.erase(it, set.end());
			it = set.begin();

			REQUIRE(set.size() == ft_set.size());
			for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
				REQUIRE(*it++ == *ft_it);
		}

		SECTION("all list") {
			ft_set.erase(ft_it, --ft_set.end());
			set.erase(it, --set.end());
			it = set.begin();

			REQUIRE(set.size() == ft_set.size());
			for (ft_it = ft_set.begin(); ft_it != ft_set.end(); ++ft_it)
				REQUIRE(*it++ == *ft_it);
		}
	}
}
