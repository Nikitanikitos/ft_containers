/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:05:46 by imicah            #+#    #+#             */
/*   Updated: 2020/10/24 13:12:32 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "catch.hpp"

TEMPLATE_TEST_CASE("Clear list",  "[list] [clear]", int) {
	ft::list<TestType>		ft_list;
	std::list<TestType>		list;

	SECTION("empty list") {
		ft_list.clear();
		list.clear();

		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.size() == ft_list.size());
	}

	SECTION("size = 1") {
		ft_list.push_front(13);
		list.push_front(13);
		ft_list.clear();
		list.clear();

		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.size() == ft_list.size());
	}

	SECTION("with size = 42") {
		ft_list.insert(ft_list.begin(), 42, -42);
		list.insert(list.begin(), 42, -42);
		ft_list.clear();
		list.clear();

		REQUIRE(list.empty() == ft_list.empty());
		REQUIRE(list.size() == ft_list.size());
	}
}







//((typename T, int V), T, V), (int, 13), (char, 29), (float, 24)