/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:40:41 by imicah            #+#    #+#             */
/*   Updated: 2020/10/21 19:39:53 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "list.hpp"
#include <list>

TEST_CASE( "Constructors and destructor list container", "[list]" ) {

	SECTION("List_CreateEmptylist_MatchWithOriginal") {
		ft::list<int>		ft_list;
		std::list<int>		list;

		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.size() == ft_list.size());
	}

	SECTION("List_CreateWithSize_MatchWithOriginal") {
		for (int i = 0; i < 10; i++) {
			ft::list<int>		ft_list(i);
			std::list<int>		list(i);

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());
			list.clear();
		}
	}

	SECTION("List_CreateWithSizeAndDefaultVal_MatchWithOriginal") {
		for (int i = 0; i < 10; i++) {
			ft::list<char>		ft_list(i, 'a' + i);
			std::list<char>		list(i,'a' + i);

			REQUIRE(list.empty() == ft_list.empty());
			REQUIRE(list.size() == ft_list.size());
			REQUIRE(*list.begin() == *ft_list.begin());
			list.clear();
		}

	}
}

//int 	main() {
//	for (int i = 0; i < 10; i++) {
//		ft::list<char>		ft_list(i, 'a' + i);
//		std::list<char>		list(i,'a' + i);
//		std::list<char>::iterator	it;
//
//		list.empty() == ft_list.empty();
//		list.size() == ft_list.size();
//		char w = *list.begin();
//		char q = *ft_list.begin();
//		list.clear();
//	}
//}
