/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_front_back_tests.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 22:42:10 by imicah            #+#    #+#             */
/*   Updated: 2020/10/26 22:50:15 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include "catch.hpp"

TEMPLATE_TEST_CASE("Push Back in empty vector", "[vector] [push]", int, float) {

	ft::vector<TestType>		ft_vector_number;
	std::vector<TestType>		vector_number;
	ft::vector<std::string>		ft_vector_string;
	std::vector<std::string>	vector_string;

	SECTION("Push back number") {
		ft_vector_number.push_back(42);
		vector_number.push_back(42);

		REQUIRE(vector_number.size() == ft_vector_number.size());
		REQUIRE(vector_number.front() == ft_vector_number.front());
		REQUIRE(vector_number.back() == ft_vector_number.back());
	}

	SECTION("Push back string") {
		ft_vector_string.push_back("Push Back String");
		vector_string.push_back("Push Back String");

		REQUIRE(vector_string.size() == ft_vector_string.size());
		REQUIRE(vector_string.front() == ft_vector_string.front());
		REQUIRE(vector_string.back() == ft_vector_string.back());
	}
}

TEMPLATE_TEST_CASE("Push Back in vector with size = 1", "[vector] [push]", int, float) {

	ft::vector<TestType>		ft_vector_number(1);
	std::vector<TestType>		vector_number(1);
	ft::vector<std::string>		ft_vector_string(1);
	std::vector<std::string>	vector_string(1);

	SECTION("Push back number") {
		ft_vector_number.push_back(42);
		vector_number.push_back(42);

		REQUIRE(vector_number.size() == ft_vector_number.size());
		REQUIRE(vector_number.front() == ft_vector_number.front());
		REQUIRE(vector_number.back() == ft_vector_number.back());
	}

	SECTION("Push back string") {
		ft_vector_string.push_back("Push Back String");
		vector_string.push_back("Push Back String");

		REQUIRE(vector_string.size() == ft_vector_string.size());
		REQUIRE(vector_string.front() == ft_vector_string.front());
		REQUIRE(vector_string.back() == ft_vector_string.back());
	}
}


TEMPLATE_TEST_CASE_SIG("Push back/front many times", "[vector] [push]",
					   ((typename T, int V), T, V), (int, 10), (char, 20), (float, 12)) {
	ft::vector<T>							ft_vector_number;
	std::vector<T>						vector_number;
	ft::vector<std::string>				ft_vector_string;
	std::vector<std::string>				vector_string;


	SECTION("Push back number") {
		for (int i = 0; i < V; ++i) {
			ft_vector_number.push_back(i + 100);
			vector_number.push_back(i + 100);
		}

		REQUIRE(vector_number.size() == ft_vector_number.size());
		REQUIRE(vector_number.front() == ft_vector_number.front());
		REQUIRE(vector_number.back() == ft_vector_number.back());
		for (int i = 0; i < vector_number.size(); ++i) {
			REQUIRE(ft_vector_number[i] == vector_number[i]);
		}
	}

	SECTION("Push back string") {
		for (int i = 0; i < V; ++i) {
			ft_vector_string.push_back("Test string " + std::to_string(i));
			vector_string.push_back("Test string " + std::to_string(i));
		}

		REQUIRE(vector_string.size() == ft_vector_string.size());
		REQUIRE(vector_string.front() == ft_vector_string.front());
		REQUIRE(vector_string.back() == ft_vector_string.back());
		for (int i = 0; i < vector_string.size(); ++i) {
			REQUIRE(ft_vector_string[i] == vector_string[i]);
		}
	}
}
