/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize_tests.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 22:56:05 by imicah            #+#    #+#             */
/*   Updated: 2020/10/26 22:57:52 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Resize vector with empty vector", "[vector] [resize]",
					   ((typename T,  int V), T, V), (int, 14)) {

	ft::vector<T>						ft_vector;
	std::vector<T>						vector;

	SECTION("resize = 0") {
		ft_vector.resize(0, 13);
		vector.resize(0, 13);

		REQUIRE(vector.size() == ft_vector.size());
		REQUIRE(vector.empty() == ft_vector.empty());
	}

	SECTION("resize = 1") {
		ft_vector.resize(1, 13);
		vector.resize(1, 13);

		REQUIRE(vector.size() == ft_vector.size());
		REQUIRE(vector.empty() == ft_vector.empty());
		REQUIRE(vector.front() == ft_vector.front());
	}

	SECTION("resize = V") {
		ft_vector.resize(V, 13);
		vector.resize(V, 13);

		REQUIRE(vector.size() == ft_vector.size());
		for (int i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}
}

TEMPLATE_TEST_CASE_SIG("Resize vector with size = V", "[vector] [resize]",
					   ((typename T,  int V), T, V), (int, 12)) {

	ft::vector<T>		ft_vector(V, 123);
	std::vector<T>		vector(V, 123);

	SECTION("resize = 0") {
		ft_vector.resize(0, 13);
		vector.resize(0, 13);

		REQUIRE(vector.size() == ft_vector.size());
		REQUIRE(vector.empty() == ft_vector.empty());
	}

	SECTION("resize = 1") {
		ft_vector.resize(1, 31);
		vector.resize(1, 31);

		REQUIRE(vector.size() == ft_vector.size());
		REQUIRE(vector.empty() == ft_vector.empty());
		REQUIRE(vector.front() == ft_vector.front());
	}

	SECTION("resize = V / 2") {
		ft_vector.resize(V / 2, -13);
		vector.resize(V / 2, -13);

		REQUIRE(vector.size() == ft_vector.size());
		for (int i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}

	SECTION("resize = V * 2") {
		ft_vector.resize(V * 2, 0);
		vector.resize(V * 2, 0);

		REQUIRE(vector.size() == ft_vector.size());
		for (int i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}
}
