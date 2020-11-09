/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_swap_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:44:36 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 16:00:32 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include "../catch.hpp"

TEMPLATE_TEST_CASE("Swap empty vectors", "[vector] [swap]", int) {
	ft::vector<TestType>		ft_vector_1;
	ft::vector<TestType>		ft_vector_2;
	std::vector<TestType>		vector_1;
	std::vector<TestType>		vector_2;

	SECTION("Empty with empty") {
		ft_vector_1.swap(ft_vector_2);
		vector_1.swap(vector_2);

		REQUIRE(vector_1.size() == ft_vector_1.size());
		REQUIRE(vector_1.empty() == ft_vector_1.empty());
		REQUIRE(vector_2.size() == ft_vector_2.size());
		REQUIRE(vector_2.empty() == ft_vector_2.empty());
	}

	SECTION("Empty with not empty") {
		ft::vector<TestType>		ft_vector_2(4);
		std::vector<TestType>		vector_2(4);

		ft_vector_1.swap(ft_vector_2);
		vector_1.swap(vector_2);

		REQUIRE(vector_1.size() == ft_vector_1.size());
		REQUIRE(vector_1.empty() == ft_vector_1.empty());
		REQUIRE(vector_2.size() == ft_vector_2.size());
		REQUIRE(vector_2.empty() == ft_vector_2.empty());
	}

	SECTION("Not empty with empty") {
		ft::vector<TestType>		ft_vector_1(4);
		std::vector<TestType>		vector_1(4);

		ft_vector_1.swap(ft_vector_2);
		vector_1.swap(vector_2);

		REQUIRE(vector_1.size() == ft_vector_1.size());
		REQUIRE(vector_1.empty() == ft_vector_1.empty());
		REQUIRE(vector_2.size() == ft_vector_2.size());
		REQUIRE(vector_2.empty() == ft_vector_2.empty());
	}
}

TEMPLATE_TEST_CASE_SIG("Swap vectors with equal size", "[vector] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::vector<T>		ft_vector_1(V, 13);
	ft::vector<T>		ft_vector_2(V, 31);
	std::vector<T>		vector_1(V, 13);
	std::vector<T>		vector_2(V, 31);

	REQUIRE(vector_1.size() == ft_vector_1.size());
	REQUIRE(vector_2.size() == ft_vector_2.size());

	ft_vector_1.swap(ft_vector_2);
	vector_1.swap(vector_2);

	REQUIRE(vector_1.size() == ft_vector_1.size());
	REQUIRE(vector_2.size() == ft_vector_2.size());

	for (size_t i = 0; i < vector_1.size(); ++i) {
		REQUIRE(vector_1[i] == ft_vector_1[i]);
		REQUIRE(vector_2[i] == ft_vector_2[i]);

	}
}

TEMPLATE_TEST_CASE_SIG("Swap vectors with lower size", "[vector] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::vector<T>		ft_vector_1(V / 2, 13);
	ft::vector<T>		ft_vector_2(V, 31);
	std::vector<T>		vector_1(V / 2, 13);
	std::vector<T>		vector_2(V, 31);

	REQUIRE(vector_1.size() == ft_vector_1.size());
	REQUIRE(vector_2.size() == ft_vector_2.size());

	ft_vector_1.swap(ft_vector_2);
	vector_1.swap(vector_2);

	REQUIRE(vector_1.size() == ft_vector_1.size());
	REQUIRE(vector_2.size() == ft_vector_2.size());

	for (size_t i = 0; i < vector_1.size(); ++i)
		REQUIRE(vector_1[i] == ft_vector_1[i]);
	for (size_t i = 0; i < vector_2.size(); ++i)
		REQUIRE(vector_2[i] == ft_vector_2[i]);
}

TEMPLATE_TEST_CASE_SIG("Swap vectors with greater size", "[vector] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::vector<T>		ft_vector_1(V, 13);
	ft::vector<T>		ft_vector_2(V / 2, 31);
	std::vector<T>		vector_1(V, 13);
	std::vector<T>		vector_2(V / 2, 31);

	REQUIRE(vector_1.size() == ft_vector_1.size());
	REQUIRE(vector_2.size() == ft_vector_2.size());

	ft_vector_1.swap(ft_vector_2);
	vector_1.swap(vector_2);

	REQUIRE(vector_1.size() == ft_vector_1.size());
	REQUIRE(vector_2.size() == ft_vector_2.size());

	for (size_t i = 0; i < vector_1.size(); ++i)
		REQUIRE(vector_1[i] == ft_vector_1[i]);
	for (size_t i = 0; i < vector_2.size(); ++i)
		REQUIRE(vector_2[i] == ft_vector_2[i]);
}
