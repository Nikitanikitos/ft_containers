/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructor_tests.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:51:19 by imicah            #+#    #+#             */
/*   Updated: 2020/10/27 13:37:13 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG( "Default Constructors in vector container", "[vector] [constructor]",
						((typename T, int V), T, V), (int, 10), (char, 20)) {

	SECTION("Create empty vector") {
		ft::vector<T>		ft_vector;
		std::vector<T>		vector;

		REQUIRE(vector.empty() == ft_vector.empty());
		REQUIRE(vector.size() == ft_vector.size());
	}

	SECTION("Create with size") {
		for (int i = 0; i < V; i++) {
			ft::vector<T>		ft_vector(i);
			std::vector<T>		vector(i);

			REQUIRE(ft_vector.empty() == ft_vector.empty());
			REQUIRE(ft_vector.size() == ft_vector.size());

			ft_vector.clear();
			ft_vector.clear();
		}
	}

	SECTION("Create with size and default value") {
		for (int i = 0; i < V; i++) {
			ft::vector<T>		ft_vector(i, 'a' + i);
			std::vector<T>		vector(i, 'a' + i);

			REQUIRE(vector.empty() == ft_vector.empty());
			REQUIRE(vector.size() == ft_vector.size());

			vector.clear();
			ft_vector.clear();
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Copy constructor in vector container", "[vector] [constructor]",
					   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::vector<T>		ft_vector_for_copy;
	std::vector<T>	vector_for_copy;

	SECTION("Empty vector") {
		ft::vector<T>		ft_vector(ft_vector_for_copy);
		std::vector<T>		vector(vector_for_copy);

		REQUIRE(vector.empty() == ft_vector.empty());
		REQUIRE(vector.size() == ft_vector.size());
	}

	SECTION("With size") {
		for (int i = 1; i < V; i++) {
			ft_vector_for_copy.push_back(i);
			vector_for_copy.push_back(i);

			ft::vector<T>		ft_vector(ft_vector_for_copy);
			std::vector<T>		vector(vector_for_copy);

			REQUIRE(vector.size() == ft_vector.size());
			REQUIRE(vector.back() == vector.back());

			vector.clear();
			ft_vector.clear();
		}
	}

	SECTION("With size and default value") {
		ft::vector<T>		ft_vector_for_copy(0, 'a');
		std::vector<T>		vector_for_copy(0, 'a');

		for (int i = 1; i < V; i++) {
			ft_vector_for_copy.push_back(i);
			vector_for_copy.push_back(i);

			ft::vector<T>		ft_vector(ft_vector_for_copy);
			std::vector<T>		vector(vector_for_copy);

			REQUIRE(vector.size() == ft_vector.size());
			REQUIRE(vector.back() == vector.back());

			vector.clear();
			ft_vector.clear();
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Assignation operator in vector container", "[vector] [constructor]",
					   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::vector<T>		ft_vector_for_copy;
	std::vector<T>	vector_for_copy;

	SECTION("Empty vector") {
		ft::vector<T>		ft_vector = ft_vector_for_copy;
		std::vector<T>		vector = vector_for_copy;

		REQUIRE(vector.empty() == ft_vector.empty());
		REQUIRE(vector.size() == ft_vector.size());
	}

	SECTION("With size") {
		for (int i = 1; i < V; i++) {
			vector_for_copy.push_back(i);
			ft_vector_for_copy.push_back(i);

			ft::vector<T>		ft_vector = ft_vector_for_copy;
			std::vector<T>		vector = vector_for_copy;

			REQUIRE(vector.size() == ft_vector.size());
			REQUIRE(vector.back() == ft_vector.back());

			vector.clear();
			ft_vector.clear();
		}
	}

	SECTION("With size") {
		for (int i = 1; i < V; i++) {
			vector_for_copy.push_back(i);
			ft_vector_for_copy.push_back(i);

			ft::vector<T>		ft_vector = ft_vector_for_copy;
			std::vector<T>		vector = vector_for_copy;

			REQUIRE(vector.size() == ft_vector.size());
			REQUIRE(vector.back() == ft_vector.back());

			vector.clear();
			ft_vector.clear();
		}
	}

	SECTION("With size and default value") {
		ft::vector<T>		ft_vector_for_copy(0, 'a');
		std::vector<T>		vector_for_copy(0, 'a');

		for (int i = 1; i < V; i++) {
			vector_for_copy.push_back(i);
			ft_vector_for_copy.push_back(i);

			ft::vector<T>		ft_vector = ft_vector_for_copy;
			std::vector<T>		vector = vector_for_copy;

			REQUIRE(vector.size() == ft_vector.size());
			REQUIRE(vector.back() == ft_vector.back());

			vector.clear();
			ft_vector.clear();
		}
	}

	SECTION("Assignation with different size") {
		ft::vector<T>		ft_vector_for_copy(12);
		std::vector<T>		vector_for_copy(12);

		SECTION("Assignation with lower size") {
			ft::vector<T>		ft_vector(6);
			std::vector<T>		vector(6);

			ft_vector = ft_vector_for_copy;
			vector = vector_for_copy;

			REQUIRE(vector.size() == ft_vector.size());
			REQUIRE(vector.front() == ft_vector.front());
			REQUIRE(vector.back() == ft_vector.back());
		}

		SECTION("Assignation with greater size") {
			ft::vector<T>		ft_vector(24);
			std::vector<T>		vector(24);

			ft_vector = ft_vector_for_copy;
			vector = vector_for_copy;

			REQUIRE(vector.size() == ft_vector.size());
			REQUIRE(vector.front() == ft_vector.front());
			REQUIRE(vector.back() == ft_vector.back());
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Constructor via iterators in vector container", "[vector] [constructor]",
					   ((typename T, int V), T, V), (int, 10), (char, 20)) {

	ft::vector<T>		ft_vector_for_copy;
	std::vector<T>		vector_for_copy;

	SECTION("Empty vector") {
		ft::vector<T>		ft_list(ft_vector_for_copy.begin(), ft_vector_for_copy.end());
		std::vector<T>		vector(vector_for_copy.begin(), vector_for_copy.end());

		REQUIRE(vector.empty() == ft_list.empty());
		REQUIRE(vector.size() == ft_list.size());
	}

	SECTION("With size") {
		for (int i = 0; i < V; i++) {

			ft::random_access_iterator<T>	w = ft_vector_for_copy.end();
			ft::vector<T>	ft_vector(ft_vector_for_copy.begin(), ft_vector_for_copy.end());
			std::vector<T>	vector(vector_for_copy.begin(), vector_for_copy.end());

			REQUIRE(vector.empty() == ft_vector.empty());
			REQUIRE(vector.size() == ft_vector.size());

			ft_vector_for_copy.push_back(i);
			vector_for_copy.push_back(i);
			vector.clear();
			ft_vector.clear();
		}
	}

	SECTION("With size and default value") {
		ft::vector<T>		ft_vector_for_copy(0, 'a');
		std::vector<T>	vector_for_copy(0, 'a');

		for (int i = 1; i < V; i++) {

			ft::vector<T>	ft_vector(ft_vector_for_copy.begin(), ft_vector_for_copy.end());
			std::vector<T>	vector(vector_for_copy.begin(), vector_for_copy.end());

			REQUIRE(vector.empty() == ft_vector.empty());
			REQUIRE(vector.size() == ft_vector.size());

			ft_vector_for_copy.push_back(i);
			vector_for_copy.push_back(i);
			vector.clear();
			ft_vector.clear();
		}
	}
}
