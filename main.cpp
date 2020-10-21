/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:40:41 by imicah            #+#    #+#             */
/*   Updated: 2020/10/21 20:58:28 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "list.hpp"
#include <list>

TEST_CASE( "Default Constructors list container", "[list]" ) {

	SECTION("DefaultConstructor_CreateEmptylist_MatchWithOriginal") {
		ft::list<int>		ft_list;
		std::list<int>		list;

		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.size() == ft_list.size());
	}

	SECTION("DefaultConstructor_CreateWithSize_MatchWithOriginal") {
		for (int i = 0; i < 10; i++) {
			ft::list<int>		ft_list(i);
			std::list<int>		list(i);

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());
			list.clear();
			// TODO added ft_list.clear()
		}
	}

	SECTION("DefaultConstructor_CreateWithSizeAndDefaultVal_MatchWithOriginal") {
		for (int i = 0; i < 10; i++) {
			ft::list<char>		ft_list(i, 'a' + i);
			std::list<char>		list(i,'a' + i);

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());
			REQUIRE(*list.begin() == *ft_list.begin());
			list.clear();
			// TODO added ft_list.clear()
		}
	}
}

TEST_CASE("Copy constructor list container", "[list]") {

	SECTION("CopyConstructor_CreateEmptylist_MatchWithOriginal") {
		ft::list<int>		ft_list_for_copy;
		std::list<int>		list_for_copy;
		ft::list<int>		ft_list(ft_list_for_copy);
		std::list<int>		list(list_for_copy);

		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.size() == ft_list.size());
	}

	SECTION("DefaultConstructor_CreateWithSize_MatchWithOriginal") {
		for (int i = 0; i < 10; i++) {
			ft::list<int>		ft_list_for_copy(i);
			std::list<int>		list_for_copy(i);
			ft::list<int>		ft_list(ft_list_for_copy);
			std::list<int>		list(list_for_copy);

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());

			list.clear();
			list_for_copy.clear();
			// TODO added ft_list.clear()
		}
	}

	SECTION("DefaultConstructor_CreateWithSizeAndDefaultVal_MatchWithOriginal") {
		for (int i = 0; i < 10; i++) {
			ft::list<char>		ft_list_for_copy(i, 'a' + i);
			std::list<char>		list_for_copy(i, 'a' + i);

			ft::list<char>		ft_list(ft_list_for_copy);
			std::list<char>		list(list_for_copy);

			*ft_list.begin();
			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());
			REQUIRE(*list.begin() == *ft_list.begin());
			list.clear();
			list_for_copy.clear();
			// TODO added ft_list.clear()
		}
	}
}

TEST_CASE("Assignation operator list container", "[list]") {

	SECTION("AssignationOperator_CreateEmptylist_MatchWithOriginal") {
		ft::list<int>		ft_list_for_copy;
		std::list<int>		list_for_copy;
		ft::list<int>		ft_list = ft_list_for_copy;
		std::list<int>		list = list_for_copy;

		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.size() == ft_list.size());
	}

	SECTION("AssignationOperator_CreateWithSize_MatchWithOriginal") {
		for (int i = 0; i < 20; i++) {
			ft::list<int>		ft_list_for_copy(i);
			std::list<int>		list_for_copy(i);

			ft::list<int>		ft_list = ft_list_for_copy;
			std::list<int>		list = list_for_copy;

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());
			list.clear();
			list_for_copy.clear();
			// TODO added ft_list.clear()
		}
	}

	SECTION("AssignationOperator_CreateWithSizeAndDefaultVal_MatchWithOriginal") {
		for (int i = 0; i < 20; i++) {
			ft::list<char>		ft_list_for_copy(i, 'a' + i);
			std::list<char>		list_for_copy(i, 'a' + i);

			ft::list<char>		ft_list = ft_list_for_copy;
			std::list<char>		list = list_for_copy;

			*ft_list.begin();
			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());
			REQUIRE(*list.begin() == *ft_list.begin());
			list.clear();
			// TODO added ft_list.clear()
		}
	}
}

//int 	main() {
//	ft::list<int>		ft_list_for_copy;
//	std::list<int>		list_for_copy;
//	ft::list<int>		ft_list(ft_list_for_copy);
//	std::list<int>		list(list_for_copy);
//
//}
