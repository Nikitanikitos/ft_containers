/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:40:41 by imicah            #+#    #+#             */
/*   Updated: 2020/10/21 22:37:18 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "list.hpp"
#include <list>

TEMPLATE_TEST_CASE( "Default Constructors in list container", "[list] [constructor]", int, char) {

	SECTION("CreateEmptyList_MatchWithOriginal") {
		ft::list<TestType>		ft_list;
		std::list<TestType>		list;

		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.size() == ft_list.size());
	}

	SECTION("CreateWithSize_MatchWithOriginal") {
		for (int i = 0; i < 10; i++) {
			ft::list<TestType>		ft_list(i);
			std::list<TestType>		list(i);

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());
			list.clear();
			// TODO added ft_list.clear()
		}
	}

	SECTION("CreateWithSizeAndDefaultVal_MatchWithOriginal") {
		for (int i = 0; i < 10; i++) {
			ft::list<TestType>		ft_list(i, 'a' + i);
			std::list<TestType>		list(i,'a' + i);

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());

			list.clear();
			// TODO added ft_list.clear()
		}
	}
}

TEMPLATE_TEST_CASE("Copy constructor in list container", "[list] [constructor]", int, char) {

	ft::list<TestType>		ft_list_for_copy;
	std::list<TestType>		list_for_copy;

	SECTION("EmptyList_MatchWithOriginal") {
		ft::list<TestType>		ft_list(ft_list_for_copy);
		std::list<TestType>		list(list_for_copy);

		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.size() == ft_list.size());
	}

	SECTION("WithSize_MatchWithOriginal") {
		for (int i = 0; i < 10; i++) {

			ft::list<TestType>		ft_list(ft_list_for_copy);
			std::list<TestType>		list(list_for_copy);

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());

			ft_list_for_copy.push_back(i);
			list_for_copy.push_back(i);
			list.clear();
			// TODO added ft_list.clear()
		}
	}

	SECTION("WithSizeAndDefaultVal_MatchWithOriginal") {
		ft::list<TestType>		ft_list_for_copy(0, 'a');
		std::list<TestType>		list_for_copy(0, 'a');

		for (int i = 0; i < 10; i++) {

			ft::list<TestType>		ft_list(ft_list_for_copy);
			std::list<TestType>		list(list_for_copy);

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());

			ft_list_for_copy.push_back('a' + i);
			list_for_copy.push_back('a' + i);
			list.clear();
			// TODO added ft_list.clear()
		}
	}
}

TEMPLATE_TEST_CASE("Assignation operator in list container", "[list] [constructor]", int, char) {

	ft::list<TestType>		ft_list_for_copy;
	std::list<TestType>		list_for_copy;

	SECTION("EmptyList_MatchWithOriginal") {
		ft::list<TestType>		ft_list = ft_list_for_copy;
		std::list<TestType>		list = list_for_copy;

		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.size() == ft_list.size());
	}

	SECTION("WithSize_MatchWithOriginal") {
		for (int i = 0; i < 10; i++) {
			ft::list<TestType>		ft_list = ft_list_for_copy;
			std::list<TestType>		list = list_for_copy;

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());

			list_for_copy.push_back(i);
			ft_list_for_copy.push_back(i);
			list.clear();
			// TODO added ft_list.clear()
		}
	}

	SECTION("WithSizeAndDefaultVal_MatchWithOriginal") {
		ft::list<TestType>		ft_list_for_copy(0, 'a');
		std::list<TestType>		list_for_copy(0, 'a');

		for (int i = 0; i < 10; i++) {
			ft::list<TestType>		ft_list = ft_list_for_copy;
			std::list<TestType>		list = list_for_copy;

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());

			list_for_copy.push_back(i);
			ft_list_for_copy.push_back(i);
			list.clear();
			// TODO added ft_list.clear()
		}
	}
}

TEMPLATE_TEST_CASE("Constructor via iterators in list container",
																"[list] [constructor]", int, char) {

	ft::list<TestType>		ft_list_for_copy;
	std::list<TestType>		list_for_copy;

	SECTION("EmptyList_MatchWithOriginal") {
		ft::list<TestType>		ft_list(ft_list_for_copy.begin(), ft_list_for_copy.end());
		std::list<TestType>		list(list_for_copy.begin(), list_for_copy.end());

		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.size() == ft_list.size());
	}

	SECTION("WithSize_MatchWithOriginal") {
		for (int i = 0; i < 20; i++) {

			ft::list<TestType>		ft_list(ft_list_for_copy.begin(), ft_list_for_copy.end());
			std::list<TestType>		list(list_for_copy.begin(), list_for_copy.end());

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());

			ft_list_for_copy.push_back(i);
			list_for_copy.push_back(i);
			list.clear();
			// TODO added ft_list.clear()
		}
	}

	SECTION("WithSizeAndDefaultVal_MatchWithOriginal") {
		ft::list<TestType>		ft_list_for_copy(0, 'a');
		std::list<TestType>		list_for_copy(0, 'a');

		for (int i = 0; i < 20; i++) {

			ft::list<TestType>		ft_list(ft_list_for_copy.begin(), ft_list_for_copy.end());
			std::list<TestType>		list(list_for_copy.begin(), list_for_copy.end());

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());

			ft_list_for_copy.push_back(i);
			list_for_copy.push_back(i);
			list.clear();
			// TODO added ft_list.clear()
		}
	}
}
