/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_front_back_tests.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:36:49 by imicah            #+#    #+#             */
/*   Updated: 2020/10/23 12:54:47 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "catch.hpp"

TEMPLATE_TEST_CASE("Push Back/Front in empty list", "[list] [push]", int, float) {
	ft::list<TestType>		ft_list_number;
	std::list<TestType>		list_number;
	ft::list<std::string>	ft_list_string;
	std::list<std::string>	list_string;

	SECTION("Push back number") {
		ft_list_number.push_back(42);
		list_number.push_back(42);

		REQUIRE(list_number.size() == ft_list_number.size());
		REQUIRE(list_number.front() == ft_list_number.front());
		REQUIRE(list_number.back() == ft_list_number.back());
	}

	SECTION("Push back string") {
		ft_list_string.push_back("Push Back String");
		list_string.push_back("Push Back String");

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(list_string.front() == ft_list_string.front());
		REQUIRE(list_string.back() == ft_list_string.back());
	}

	SECTION("Push front number") {
		ft_list_number.push_front(42);
		list_number.push_front(42);

		REQUIRE(list_number.size() == ft_list_number.size());
		REQUIRE(list_number.front() == ft_list_number.front());
		REQUIRE(list_number.back() == ft_list_number.back());
	}

	SECTION("Push front string") {
		ft_list_string.push_front("Push Front String");
		list_string.push_front("Push Front String");

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(list_string.front() == ft_list_string.front());
		REQUIRE(list_string.back() == ft_list_string.back());
	}
}

TEMPLATE_TEST_CASE("Push Back/Front in list with size = 1", "[list] [push]", int, float) {
	ft::list<TestType>		ft_list_number(1);
	std::list<TestType>		list_number(1);
	ft::list<std::string>	ft_list_string(1);
	std::list<std::string>	list_string(1);

	SECTION("Push back number") {
		ft_list_number.push_back(42);
		list_number.push_back(42);

		REQUIRE(list_number.size() == ft_list_number.size());
		REQUIRE(list_number.front() == ft_list_number.front());
		REQUIRE(list_number.back() == ft_list_number.back());
	}

	SECTION("Push back string") {
		ft_list_string.push_back("Push Back String");
		list_string.push_back("Push Back String");

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(list_string.front() == ft_list_string.front());
		REQUIRE(list_string.back() == ft_list_string.back());
	}

	SECTION("Push front number") {
		ft_list_number.push_front(42);
		list_number.push_front(42);

		REQUIRE(list_number.size() == ft_list_number.size());
		REQUIRE(list_number.front() == ft_list_number.front());
		REQUIRE(list_number.back() == ft_list_number.back());
	}

	SECTION("Push front string") {
		ft_list_string.push_front("Push Front String");
		list_string.push_front("Push Front String");

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(list_string.front() == ft_list_string.front());
		REQUIRE(list_string.back() == ft_list_string.back());
	}
}

TEMPLATE_TEST_CASE_SIG("Push back/front many times", "[list] [push]",
													((typename T, int V), T, V), (int, 10), (char, 20), (float, 12)) {
	ft::list<T>							ft_list_number;
	std::list<T>						list_number;
	ft::list<std::string>				ft_list_string;
	std::list<std::string>				list_string;

	typename ft::list<T>::iterator				ft_number_it;
	typename std::list<T>::iterator				number_it;
	typename ft::list<std::string>::iterator	ft_string_it;
	typename std::list<std::string>::iterator	string_it;

	SECTION("Push back number") {
		for (int i = 0; i < V; ++i) {
			ft_list_number.push_back(i + 100);
			list_number.push_back(i + 100);
		}
		ft_number_it = ft_list_number.begin();
		number_it = list_number.begin();

		REQUIRE(list_number.size() == ft_list_number.size());
		REQUIRE(list_number.front() == ft_list_number.front());
		REQUIRE(list_number.back() == ft_list_number.back());
		while (*ft_number_it != *ft_list_number.end()) {
			REQUIRE(*ft_number_it == *number_it);
			++ft_number_it;
			++number_it;
		}
	}

	SECTION("Push front number") {
		for (int i = 0; i < V; ++i) {
			ft_list_number.push_front(i + 100);
			list_number.push_front(i + 100);
		}
		ft_number_it = ft_list_number.begin();
		number_it = list_number.begin();

		REQUIRE(list_number.size() == ft_list_number.size());
		REQUIRE(list_number.front() == ft_list_number.front());
		REQUIRE(list_number.back() == ft_list_number.back());
		while (*ft_number_it != *ft_list_number.end()) {
			REQUIRE(*ft_number_it == *number_it);
			++ft_number_it;
			++number_it;
		}
	}

	SECTION("Push back string") {
		for (int i = 0; i < V; ++i) {
			ft_list_string.push_back("Test string " + std::to_string(i));
			list_string.push_back("Test string " + std::to_string(i));
		}
		ft_string_it = ft_list_string.begin();
		string_it = list_string.begin();

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(list_string.front() == ft_list_string.front());
		REQUIRE(list_string.back() == ft_list_string.back());
		while (*ft_string_it != *ft_list_string.end()) {
			REQUIRE(*ft_string_it == *string_it);
			++ft_string_it;
			++string_it;
		}
	}

	SECTION("Push front string") {
		for (int i = 0; i < V; ++i) {
			ft_list_string.push_front("Test string " + std::to_string(i));
			list_string.push_front("Test string " + std::to_string(i));
		}
		ft_string_it = ft_list_string.begin();
		string_it = list_string.begin();

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(list_string.front() == ft_list_string.front());
		REQUIRE(list_string.back() == ft_list_string.back());
		while (*ft_string_it != *ft_list_string.end()) {
			REQUIRE(*ft_string_it == *string_it);
			++ft_string_it;
			++string_it;
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Alternation push back/front", "[list] [push]",
												  ((typename T, int V), T, V), (int, 13), (char, 29), (float, 24)) {
	ft::list<T>							ft_list_number;
	std::list<T>						list_number;
	ft::list<std::string>				ft_list_string;
	std::list<std::string>				list_string;

	typename ft::list<T>::iterator				ft_number_it;
	typename std::list<T>::iterator				number_it;
	typename ft::list<std::string>::iterator	ft_string_it;
	typename std::list<std::string>::iterator	string_it;

	SECTION("Alternation push number") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_list_number.push_back(i + 100);
				list_number.push_back(i + 100);
			}
			else {
				ft_list_number.push_front(i + 100);
				list_number.push_front(i + 100);
			}
		}
		ft_number_it = ft_list_number.begin();
		number_it = list_number.begin();

		REQUIRE(list_number.size() == ft_list_number.size());
		REQUIRE(list_number.front() == ft_list_number.front());
		REQUIRE(list_number.back() == ft_list_number.back());
		while (*ft_number_it != *ft_list_number.end()) {
			REQUIRE(*ft_number_it == *number_it);
			++ft_number_it;
			++number_it;
		}
	}

	SECTION("Alternation push string") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_list_string.push_back("Test string " + std::to_string(i));
				list_string.push_back("Test string " + std::to_string(i));
			}
			else {
				ft_list_string.push_front("Test string " + std::to_string(i));
				list_string.push_front("Test string " + std::to_string(i));
			}
		}
		ft_string_it = ft_list_string.begin();
		string_it = list_string.begin();

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(list_string.front() == ft_list_string.front());
		REQUIRE(list_string.back() == ft_list_string.back());
		while (*ft_string_it != *ft_list_string.end()) {
			REQUIRE(*ft_string_it == *string_it);
			++ft_string_it;
			++string_it;
		}
	}
}
