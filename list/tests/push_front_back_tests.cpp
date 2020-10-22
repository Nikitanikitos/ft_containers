/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front_back_tests.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:36:49 by imicah            #+#    #+#             */
/*   Updated: 2020/10/22 12:07:49 by imicah           ###   ########.fr       */
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

	SECTION("PushBackNumber") {
		ft_list_number.push_back(42);
		list_number.push_back(42);

		REQUIRE(list_number.size() == ft_list_number.size());
		REQUIRE(list_number.front() == ft_list_number.front());
		REQUIRE(list_number.back() == ft_list_number.back());
	}

	SECTION("PushBackString") {
		ft_list_string.push_back("Push Back String");
		list_string.push_back("Push Back String");

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(list_string.front() == ft_list_string.front());
		REQUIRE(list_string.back() == ft_list_string.back());
	}

	SECTION("PushFrontNumber") {
		ft_list_number.push_front(42);
		list_number.push_front(42);

		REQUIRE(list_number.size() == ft_list_number.size());
		REQUIRE(list_number.front() == ft_list_number.front());
		REQUIRE(list_number.back() == ft_list_number.back());
	}

	SECTION("PushFrontString") {
		ft_list_string.push_front("Push Front String");
		list_string.push_front("Push Front String");

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(list_string.front() == ft_list_string.front());
		REQUIRE(list_string.back() == ft_list_string.back());
	}
}

TEMPLATE_TEST_CASE("Push Back/Front with size list equal 1", "[list] [push]", int, float) {

	ft::list<TestType>		ft_list_number(1);
	std::list<TestType>		list_number(1);
	ft::list<std::string>	ft_list_string(1);
	std::list<std::string>	list_string(1);

	SECTION("PushBackNumber") {
		ft_list_number.push_back(42);
		list_number.push_back(42);

		REQUIRE(list_number.size() == ft_list_number.size());
		REQUIRE(list_number.front() == ft_list_number.front());
		REQUIRE(list_number.back() == ft_list_number.back());
	}

	SECTION("PushBackString") {
		ft_list_string.push_back("Push Back String");
		list_string.push_back("Push Back String");

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(list_string.front() == ft_list_string.front());
		REQUIRE(list_string.back() == ft_list_string.back());
	}

	SECTION("PushFrontNumber") {
		ft_list_number.push_front(42);
		list_number.push_front(42);

		REQUIRE(list_number.size() == ft_list_number.size());
		REQUIRE(list_number.front() == ft_list_number.front());
		REQUIRE(list_number.back() == ft_list_number.back());
	}

	SECTION("PushFrontString") {
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
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	SECTION("PushBackNumber") {
		for (int i = 0; i < V; ++i) {
			ft_list_number.push_back(i + 100);
			list_number.push_back(i + 100);
		}

		ft_it = ft_list_number.begin();
		it = list_number.begin();

		REQUIRE(list_number.size() == ft_list_number.size());
		while (*ft_it != *ft_list_number.end()) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}

	SECTION("PushFrontNumber") {
		for (int i = 0; i < V; ++i) {
			ft_list_number.push_front(i + 100);
			list_number.push_front(i + 100);
		}

		ft_it = ft_list_number.begin();
		it = list_number.begin();
		REQUIRE(list_number.size() == ft_list_number.size());
		while (*ft_it != *ft_list_number.end()) {
			REQUIRE(*ft_it == *it);
			++ft_it;
			++it;
		}
	}
}
