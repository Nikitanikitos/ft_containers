	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_access_operator_tests.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:43:53 by imicah            #+#    #+#             */
/*   Updated: 2020/11/08 12:38:23 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include "../catch.hpp"

TEMPLATE_TEST_CASE_SIG("Operator [] and method at getting an item vector_tests vector", "[vector] [access]",
					 							  ((typename T, int V), T, V), (int, 10), (char, 20), (float, 12)) {
		ft::vector<T>		ft_vector;
		std::vector<T>		vector;

		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_vector.push_back(-i);
				vector.push_back(-i);
			}
			else {
				ft_vector.push_back(i);
				vector.push_back(i);
			}
		}

		REQUIRE(ft_vector.size() == vector.size());

		SECTION("Operator []") {
			for (int i = 0; i < V; ++i)
				REQUIRE(ft_vector[i] == vector[i]);
		}

		SECTION("Method at") {
			for (size_t i = 0; i < ft_vector.size(); ++i)
				REQUIRE(ft_vector.at(i) == vector.at(i));
		}
}

TEMPLATE_TEST_CASE_SIG("Operator [] and method at element changes vector_tests vector", "[vector] [access]",
									  			 ((typename T, int V), T, V), (int, 10), (char, 20), (float, 12)) {
		ft::vector<T>		ft_vector;
		std::vector<T>		vector;

		for (int i = 0; i < V; ++i) {
			ft_vector.push_back(i);
			vector.push_back(i);
		}

		REQUIRE(ft_vector.size() == vector.size());

		SECTION("Operator []") {
			for (int i = 0; i < V; ++i) {
				ft_vector[i] = i - 42;
				vector[i] = i - 42;
			}

			for (int i = 0; i < V; ++i)
				REQUIRE(ft_vector[i] == vector[i]);
		}

		SECTION("Method at") {
			for (size_t i = 0; i < ft_vector.size(); ++i) {
				ft_vector.at(i) = i - 42;
				vector.at(i) = i - 42;
			}
			for (size_t i = 0; i < ft_vector.size(); ++i)
				REQUIRE(ft_vector.at(i) == vector.at(i));
		}
}

TEMPLATE_TEST_CASE("method at getting a non-existent item vector", "[vector] [access]", int) {
		ft::vector<TestType>		ft_vector;
		std::vector<TestType>		vector;

		for (int i = 0; i < 6; ++i) {
			if (i % 2) {
				ft_vector.push_back(i);
				vector.push_back(i);
			}
		}
		REQUIRE_THROWS(ft_vector.at(6));
		REQUIRE_THROWS(vector.at(6));
	}
