/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert_tests.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:58:43 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 15:58:08 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include "../catch.hpp"

TEMPLATE_TEST_CASE("Insert in empty vector through iterator", "[vector] [insert]", int) {
	ft::vector<TestType>		ft_vector(10);
	std::vector<TestType>		vector(10);

	SECTION("at the front") {
		ft_vector.insert(ft_vector.begin(), 21);
		vector.insert(vector.begin(), 21);

		REQUIRE(vector.size() == ft_vector.size());
		for (size_t i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}

	SECTION("at the back") {
		ft_vector.insert(ft_vector.end(), 21);
		vector.insert(vector.end(), 21);

		REQUIRE(vector.size() == ft_vector.size());
		for (size_t i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}

	SECTION("at the middle") {
		ft_vector.insert(ft_vector.begin() + 5, 21);
		vector.insert(vector.begin() + 5, 21);

		REQUIRE(vector.size() == ft_vector.size());
		for (size_t i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in vector with size = V through iterator and size", "[vector] [insert]",
																		   ((typename T, int V), T, V), (int, 7)) {
	ft::vector<T>							ft_vector(V, 42);
	std::vector<T>							vector(V, 42);
	typename ft::vector<T>::iterator		ft_it = ft_vector.begin();
	typename std::vector<T>::iterator		it = vector.begin();

	SECTION("at the middle") {
		for (int i = 0; i < V / 2; ++i) {
			++ft_it;
			++it;
		}
		ft_vector.insert(ft_it, 3, 21);
		vector.insert(it, 3, 21);

		REQUIRE(vector.size() == ft_vector.size());
		for (size_t i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}

	SECTION("at the front") {
		ft_vector.insert(ft_it, 3, 21);
		vector.insert(it, 3, 21);

		REQUIRE(vector.size() == ft_vector.size());
		for (size_t i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}

	SECTION("at the end") {
		ft_vector.insert(ft_vector.end(), 3, 21);
		vector.insert(vector.end(), 3, 21);

		REQUIRE(vector.size() == ft_vector.size());
		for (size_t i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in vector with size = V through two iterator", "[vector] [insert]",
																		   ((typename T, int V), T, V), (int, 5)) {
	ft::vector<T>							ft_vector;
	std::vector<T>							vector;
	ft::vector<T>							ft_vector_for_insert(V, -26);
	std::vector<T>							vector_for_insert(V, -26);

	SECTION("in empty vector") {
		ft_vector.insert(ft_vector.begin(), ft_vector_for_insert.begin(), ft_vector_for_insert.end());
		vector.insert(vector.begin(), vector_for_insert.begin(), vector_for_insert.end());

		REQUIRE(vector.size() == ft_vector.size());
		for (size_t i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}

	SECTION("From beginning to middle at the front") {
		ft_vector.insert(ft_vector.begin(), 3, 21);
		vector.insert(vector.begin(), 3, 21);

		ft_vector.insert(ft_vector.begin(), ft_vector_for_insert.begin(), ft_vector_for_insert.end() - V /2);
		vector.insert(vector.begin(), vector_for_insert.begin(), vector_for_insert.end() - V / 2);

		REQUIRE(vector.size() == ft_vector.size());
		for (size_t i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}

	SECTION("From beginning to middle at the end") {
		ft_vector.insert(ft_vector.begin(), 3, 21);
		vector.insert(vector.begin(), 3, 21);

		ft_vector.insert(ft_vector.end(), ft_vector_for_insert.begin(), ft_vector_for_insert.end() - V /2);
		vector.insert(vector.end(), vector_for_insert.begin(), vector_for_insert.end() - V / 2);

		REQUIRE(vector.size() == ft_vector.size());
		for (size_t i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}

	SECTION("From the middle to the end at the front") {
		ft_vector.insert(ft_vector.begin(), 3, 21);
		vector.insert(vector.begin(), 3, 21);

		ft_vector.insert(ft_vector.begin(), ft_vector_for_insert.begin() + V / 2, ft_vector_for_insert.end());
		vector.insert(vector.begin(), vector_for_insert.begin() + V / 2, vector_for_insert.end());

		REQUIRE(vector.size() == ft_vector.size());
		for (size_t i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}

	SECTION("From the middle to the end at the back") {
		ft_vector.insert(ft_vector.begin(), 3, 21);
		vector.insert(vector.begin(), 3, 21);

		ft_vector.insert(ft_vector.end(), ft_vector_for_insert.begin() + V / 2, ft_vector_for_insert.end());
		vector.insert(vector.end(), vector_for_insert.begin() + V / 2, vector_for_insert.end());

		REQUIRE(vector.size() == ft_vector.size());
		for (size_t i = 0; i < ft_vector.size(); ++i)
			REQUIRE(ft_vector[i] == vector[i]);
	}
}
