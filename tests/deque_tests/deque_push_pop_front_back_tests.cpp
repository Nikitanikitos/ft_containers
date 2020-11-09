/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_pop_front_back_tests.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:53:16 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 21:09:03 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include "deque.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE("Push back/front in empty deque", "[deque] [push]", int, float) {
	ft::deque<TestType>			ft_deque_number;
	std::deque<TestType>		deque_number;
	ft::deque<std::string>		ft_deque_string;
	std::deque<std::string>		deque_string;

	SECTION("Push back number") {
		ft_deque_number.push_back(42);
		deque_number.push_back(42);

		REQUIRE(deque_number.size() == ft_deque_number.size());
		REQUIRE(deque_number.front() == ft_deque_number.front());
		REQUIRE(deque_number.back() == ft_deque_number.back());
	}

	SECTION("Push back string") {
		ft_deque_string.push_back("Push Back String");
		deque_string.push_back("Push Back String");

		REQUIRE(deque_string.size() == ft_deque_string.size());
		REQUIRE(deque_string.front() == ft_deque_string.front());
		REQUIRE(deque_string.back() == ft_deque_string.back());
	}

	SECTION("Push front number") {
		ft_deque_number.push_front(42);
		deque_number.push_front(42);

		REQUIRE(deque_number.size() == ft_deque_number.size());
		REQUIRE(deque_number.front() == ft_deque_number.front());
		REQUIRE(deque_number.back() == ft_deque_number.back());
	}

	SECTION("Push front string") {
		ft_deque_string.push_front("Push Back String");
		deque_string.push_front("Push Back String");

		REQUIRE(deque_string.size() == ft_deque_string.size());
		REQUIRE(deque_string.front() == ft_deque_string.front());
		REQUIRE(deque_string.back() == ft_deque_string.back());
	}
}

TEMPLATE_TEST_CASE("Push back/front in deque with size = 1", "[deque] [push]", int, float) {
	ft::deque<TestType>			ft_deque_number(1);
	std::deque<TestType>		deque_number(1);
	ft::deque<std::string>		ft_deque_string(1);
	std::deque<std::string>		deque_string(1);

	SECTION("Push back number") {
		ft_deque_number.push_back(42);
		deque_number.push_back(42);

		REQUIRE(deque_number.size() == ft_deque_number.size());
		REQUIRE(deque_number.front() == ft_deque_number.front());
		REQUIRE(deque_number.back() == ft_deque_number.back());
	}

	SECTION("Push back string") {
		ft_deque_string.push_back("Push Back String");
		deque_string.push_back("Push Back String");

		REQUIRE(deque_string.size() == ft_deque_string.size());
		REQUIRE(deque_string.front() == ft_deque_string.front());
		REQUIRE(deque_string.back() == ft_deque_string.back());
	}

	SECTION("Push front number") {
		ft_deque_number.push_front(42);
		deque_number.push_front(42);

		REQUIRE(deque_number.size() == ft_deque_number.size());
		REQUIRE(deque_number.front() == ft_deque_number.front());
		REQUIRE(deque_number.back() == ft_deque_number.back());
	}

	SECTION("Push front string") {
		ft_deque_string.push_front("Push Back String");
		deque_string.push_front("Push Back String");

		REQUIRE(deque_string.size() == ft_deque_string.size());
		REQUIRE(deque_string.front() == ft_deque_string.front());
		REQUIRE(deque_string.back() == ft_deque_string.back());
	}
}

TEMPLATE_TEST_CASE_SIG("Push back/pop many times in deque", "[deque] [push]",
					 								  ((typename T, int V), T, V), (int, 10), (char, 20), (float, 12)) {
	ft::deque<T>					ft_deque_number;
	std::deque<T>					deque_number;
	ft::deque<std::string>			ft_deque_string;
	std::deque<std::string>			deque_string;

	SECTION("Push back number") {
		for (int i = 0; i < V; ++i) {
			ft_deque_number.push_back(i + 100);
			deque_number.push_back(i + 100);
		}

		REQUIRE(deque_number.size() == ft_deque_number.size());
		REQUIRE(deque_number.front() == ft_deque_number.front());
		REQUIRE(deque_number.back() == ft_deque_number.back());
		for (size_t i = 0; i < deque_number.size(); ++i) {
			REQUIRE(ft_deque_number[i] == deque_number[i]);
		}
	}

	SECTION("Push back string") {
		for (int i = 0; i < V; ++i) {
			ft_deque_string.push_back("Test string " + std::to_string(i));
			deque_string.push_back("Test string " + std::to_string(i));
		}

		REQUIRE(deque_string.size() == ft_deque_string.size());
		REQUIRE(deque_string.front() == ft_deque_string.front());
		REQUIRE(deque_string.back() == ft_deque_string.back());
		for (size_t i = 0; i < deque_string.size(); ++i) {
			REQUIRE(ft_deque_string[i] == deque_string[i]);
		}
	}

	SECTION("Push front number") {
		for (int i = 0; i < V; ++i) {
			ft_deque_number.push_front(i + 100);
			deque_number.push_front(i + 100);
		}

		REQUIRE(deque_number.size() == ft_deque_number.size());
		REQUIRE(deque_number.front() == ft_deque_number.front());
		REQUIRE(deque_number.back() == ft_deque_number.back());
		for (size_t i = 0; i < deque_number.size(); ++i) {
			REQUIRE(ft_deque_number[i] == deque_number[i]);
		}
	}

	SECTION("Push front string") {
		for (int i = 0; i < V; ++i) {
			ft_deque_string.push_front("Test string " + std::to_string(i));
			deque_string.push_front("Test string " + std::to_string(i));
		}

		REQUIRE(deque_string.size() == ft_deque_string.size());
		REQUIRE(deque_string.front() == ft_deque_string.front());
		REQUIRE(deque_string.back() == ft_deque_string.back());
		for (size_t i = 0; i < deque_string.size(); ++i) {
			REQUIRE(ft_deque_string[i] == deque_string[i]);
		}
	}
}

TEMPLATE_TEST_CASE("Pop back/front in deque with size = 1", "[deque] [pop]", int, float) {
	ft::deque<TestType>			ft_deque_number(1, 42);
	std::deque<TestType>		deque_number(1, 42);
	ft::deque<std::string>		ft_deque_string(1, "Push Back String");
	std::deque<std::string>		deque_string(1, "Push Back String");

	SECTION("Pop back number") {
		ft_deque_number.pop_back();
		deque_number.pop_back();

		REQUIRE(deque_number.size() == ft_deque_number.size());
		REQUIRE(deque_number.empty() == ft_deque_number.empty());
	}

	SECTION("Pop back string") {
		ft_deque_string.pop_back();
		deque_string.pop_back();

		REQUIRE(deque_string.size() == ft_deque_string.size());
		REQUIRE(deque_string.empty() == ft_deque_string.empty());
	}

	SECTION("Pop front number") {
		ft_deque_number.pop_front();
		deque_number.pop_front();

		REQUIRE(deque_number.size() == ft_deque_number.size());
		REQUIRE(deque_number.empty() == ft_deque_number.empty());
	}

	SECTION("Pop front string") {
		ft_deque_string.pop_front();
		deque_string.pop_front();

		REQUIRE(deque_string.size() == ft_deque_string.size());
		REQUIRE(deque_string.empty() == ft_deque_string.empty());
	}
}

TEMPLATE_TEST_CASE_SIG("Pop back/front many times", "[deque] [pop]",
													 ((typename T, int V), T, V), (int, 10), (char, 20), (float, 12)) {
	ft::deque<T>					ft_deque_number;
	std::deque<T>					deque_number;
	ft::deque<std::string>			ft_deque_string;
	std::deque<std::string>			deque_string;

	for (int i = 0; i < V; ++i) {
		ft_deque_number.push_back(i + 100);
		deque_number.push_back(i + 100);
	}
	for (int i = 0; i < V; ++i) {
		ft_deque_string.push_back("Test string " + std::to_string(i));
		deque_string.push_back("Test string " + std::to_string(i));
	}

	SECTION("Pop back number") {
		for (int i = 0; i < V / 2; ++i) {
			ft_deque_number.pop_back();
			deque_number.pop_back();

			REQUIRE(deque_number.size() == ft_deque_number.size());
			REQUIRE(deque_number.front() == ft_deque_number.front());
			REQUIRE(deque_number.back() == ft_deque_number.back());
			for (size_t q = 0; q < deque_number.size(); ++q) {
				REQUIRE(ft_deque_number[q] == deque_number[q]);
			}
		}

	}

	SECTION("Push back string") {
		for (int i = 0; i < V / 2; ++i) {
			ft_deque_string.pop_back();
			deque_string.pop_back();

			REQUIRE(deque_string.size() == ft_deque_string.size());
			REQUIRE(deque_string.front() == ft_deque_string.front());
			REQUIRE(deque_string.back() == ft_deque_string.back());
			for (size_t q = 0; q < deque_string.size(); ++q) {
				REQUIRE(ft_deque_string[q] == deque_string[q]);
			}
		}
	}

	SECTION("Pop front number") {
		for (int i = 0; i < V / 2; ++i) {
			ft_deque_number.pop_front();
			deque_number.pop_front();

			REQUIRE(deque_number.size() == ft_deque_number.size());
			REQUIRE(deque_number.front() == ft_deque_number.front());
			REQUIRE(deque_number.back() == ft_deque_number.back());
			for (size_t q = 0; q < deque_number.size(); ++q) {
				REQUIRE(ft_deque_number[q] == deque_number[q]);
			}
		}
	}

	SECTION("Pop front string") {
		for (int i = 0; i < V / 2; ++i) {
			ft_deque_string.pop_front();
			deque_string.pop_front();

			REQUIRE(deque_string.size() == ft_deque_string.size());
			REQUIRE(deque_string.front() == ft_deque_string.front());
			REQUIRE(deque_string.back() == ft_deque_string.back());
			for (size_t q = 0; q < deque_string.size(); ++q) {
				REQUIRE(ft_deque_string[q] == deque_string[q]);
			}
		}
	}
}
