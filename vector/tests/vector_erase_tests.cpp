/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_erase_tests.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:23:40 by imicah            #+#    #+#             */
/*   Updated: 2020/10/28 18:48:55 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Erase in vector through one iterator", "[vector] [erase]",
																		   ((typename T, int V), T, V), (int, 10)) {
	ft::vector<T>							ft_vector(1, 23);
	std::vector<T>							vector(1, 23);
	typename ft::vector<T>::iterator		ft_it;
	typename std::vector<T>::iterator		it;

	SECTION("with size = 1") {
		vector.erase(vector.begin());
		ft_vector.erase(ft_vector.begin());

		REQUIRE(vector.size() == ft_vector.size());
		REQUIRE(vector.empty() == ft_vector.empty());
	}

	SECTION("with size = V") {
		ft::vector<T>		ft_vector(V, 21);
		std::vector<T>		vector(V, 21);

		ft_it = ft_vector.begin();
		it = vector.begin();
		SECTION("every two time") {
			for (int i = 0; ft_it != ft_vector.end(); ++ft_it) {
				if (i++ % 2) {
					ft_it = ft_vector.erase(ft_it);
					it = vector.erase(it);
					REQUIRE(*ft_it == *it);
					REQUIRE(vector.size() == ft_vector.size());
				}
				++it;
			}
			REQUIRE(vector.size() == ft_vector.size());
		}

		SECTION("from the middle") {
			for (size_t i = 0; i < ft_vector.size() / 2; ++i) {
				++it;
				++ft_it;
			}
			REQUIRE(*ft_vector.erase(ft_it) == *vector.erase(it));
			REQUIRE(vector.size() == ft_vector.size());
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Erase in vector through with two iterator", "[vector] [erase]",
																		   ((typename T, int V), T, V), (int, 10)) {
	ft::vector<T>							ft_vector(1, 23);
	std::vector<T>							vector(1, 23);
	typename ft::vector<T>::iterator		ft_it;
	typename ft::vector<T>::iterator		ft_it_2;
	typename std::vector<T>::iterator		it;

	SECTION("with size = 1") {
		vector.erase(vector.begin(), vector.begin());
		ft_vector.erase(ft_vector.begin(), ft_vector.begin());

		REQUIRE(vector.size() == ft_vector.size());
		REQUIRE(vector.empty() == ft_vector.empty());
	}

	SECTION("with size = V") {
		ft::vector<T>		ft_vector(V, 21);
		std::vector<T>		vector(V, 21);

		ft_it = ft_vector.begin();
		it = vector.begin();
		SECTION("every two time") {
			for (int i = 0; ft_vector[i] != ft_vector.back(); ++i) {
				if (!(i % 2)) {
					REQUIRE(ft_vector[i] == it[i]);
					REQUIRE(vector.size() == ft_vector.size());
				}
			}
		}

		SECTION("First part") {
			for (size_t i = 0; i < ft_vector.size() / 2; ++i) {
				++it;
				++ft_it;
			}
			REQUIRE(*ft_vector.erase(ft_vector.begin(), ft_it) == *vector.erase(vector.begin(), it));
			REQUIRE(vector.size() == ft_vector.size());
		}

		SECTION("Second part") {
			for (size_t i = 0; i < ft_vector.size(); ++i) {
				++it;
				++ft_it;
			}
			ft_vector.erase(ft_it, ft_vector.end());
			vector.erase(it, vector.end());
			REQUIRE(vector.front() == ft_vector.front());
			REQUIRE(vector.back() == ft_vector.back());
			REQUIRE(vector.size() == ft_vector.size());
		}

		SECTION("all vector") {
			ft_vector.erase(ft_it, --ft_vector.end());
			vector.erase(it, --vector.end());
			REQUIRE(vector.front() == ft_vector.front());
			REQUIRE(vector.back() == ft_vector.back());
			REQUIRE(vector.size() == ft_vector.size());
			REQUIRE(vector.empty() == ft_vector.empty());
		}
	}
}
