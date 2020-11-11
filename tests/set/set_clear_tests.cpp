/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_clear_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 01:05:11 by imicah            #+#    #+#             */
/*   Updated: 2020/11/12 01:05:11 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE("Clear set",  "[set] [clear]", int, float, char) {
	ft::set<TestType>		ft_set;
	std::set<TestType>		set;

	SECTION("empty list") {
		ft_set.clear();
		set.clear();

		REQUIRE(set.empty() == ft_set.empty());
		REQUIRE(set.size() == ft_set.size());
	}

	SECTION("size = 1") {
		ft_set.insert(13);
		set.insert(13);
		ft_set.clear();
		set.clear();

		REQUIRE(set.empty() == ft_set.empty());
		REQUIRE(set.size() == ft_set.size());
	}

	SECTION("with size = 42") {
		for (int i = 0; i < 42; ++i) {
			ft_set.insert(i);
			set.insert(i);
		}
		ft_set.clear();
		set.clear();

		REQUIRE(set.empty() == ft_set.empty());
		REQUIRE(set.size() == ft_set.size());
	}
}
