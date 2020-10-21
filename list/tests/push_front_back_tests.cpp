/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front_back_tests.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:36:49 by imicah            #+#    #+#             */
/*   Updated: 2020/10/21 23:58:49 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "catch.hpp"

TEMPLATE_TEST_CASE("Push Back/Front in empty list", "[list] [push]", int) {

	SECTION("PushBackInt") {
		ft::list<TestType>	ft_list;
		std::list<TestType>	list;

		ft_list.push_back(42);
		list.push_back(42);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(*list.begin() == *ft_list.begin());
//		REQUIRE(*list.end() == *ft_list.end());
	}

	SECTION("PushBackString") {
		ft::list<std::string>	ft_list;
		std::list<std::string>	list;

		ft_list.push_back("School Twenty One");
		list.push_back("School Twenty One");

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(*list.begin() == *ft_list.begin());
//		REQUIRE(*list.end() == *ft_list.end());
	}
}
