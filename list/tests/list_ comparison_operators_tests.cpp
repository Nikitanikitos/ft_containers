/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ comparison_operators.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:13:50 by imicah            #+#    #+#             */
/*   Updated: 2020/10/24 13:38:14 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG("Operator \"more\" and \"more or equal\" list", "[list] [operator more] [comparison operators]",
														   ((typename T, int V), T, V), (int, 12)) {
	ft::list<T>		ft_lhs;
	ft::list<T>		ft_rhs;
	std::list<T>	lhs;
	std::list<T>	rhs;

	SECTION("empty list") {
		REQUIRE((ft_lhs > ft_rhs) == (lhs > rhs));
		REQUIRE((ft_lhs >= ft_rhs) == (lhs >= rhs));
	}

	SECTION("one node") {
		ft_rhs.push_back(-42);
		ft_lhs.push_back(42);
		rhs.push_back(-42);
		lhs.push_back(42);

		REQUIRE((ft_lhs > ft_rhs) == (lhs > rhs));
		REQUIRE((ft_lhs >= ft_rhs) == (lhs >= rhs));
	}

	SECTION("size = V") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_rhs.push_back(-i);
				rhs.push_back(-i);
			}
			else {
				ft_lhs.push_back(i);
				lhs.push_back(i);
			}
		}

		REQUIRE((ft_lhs > ft_rhs) == (lhs > rhs));
		REQUIRE((ft_lhs >= ft_rhs) == (lhs >= rhs));
	}

	SECTION("with different sizes") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_rhs.push_back(-i);
				rhs.push_back(-i);
			}
			ft_lhs.push_back(i);
			lhs.push_back(i);
		}

		REQUIRE((ft_lhs > ft_rhs) == (lhs > rhs));
		REQUIRE((ft_lhs >= ft_rhs) == (lhs >= rhs));
	}
}

TEMPLATE_TEST_CASE_SIG("Operator \"less\" and \"less or equal\" list", "[list] [operator more] [comparison operators]",
														   ((typename T, int V), T, V), (int, 12)) {
	ft::list<T>		ft_lhs;
	ft::list<T>		ft_rhs;
	std::list<T>	lhs;
	std::list<T>	rhs;

	SECTION("empty list") {
		REQUIRE((ft_lhs < ft_rhs) == (lhs < rhs));
		REQUIRE((ft_lhs <= ft_rhs) == (lhs <= rhs));
	}

	SECTION("one node") {
		ft_rhs.push_back(-V);
		ft_lhs.push_back(V);
		rhs.push_back(-V);
		lhs.push_back(V);

		REQUIRE((ft_lhs < ft_rhs) == (lhs < rhs));
		REQUIRE((ft_lhs <= ft_rhs) == (lhs <= rhs));
	}

	SECTION("size = V") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_rhs.push_back(-i);
				rhs.push_back(-i);
			}
			else {
				ft_lhs.push_back(i);
				lhs.push_back(i);
			}
		}

		REQUIRE((ft_lhs < ft_rhs) == (lhs < rhs));
		REQUIRE((ft_lhs <= ft_rhs) == (lhs <= rhs));
	}

	SECTION("with different sizes") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_rhs.push_back(-i);
				rhs.push_back(-i);
			}
			ft_lhs.push_back(i);
			lhs.push_back(i);
		}

		REQUIRE((ft_lhs < ft_rhs) == (lhs < rhs));
		REQUIRE((ft_lhs <= ft_rhs) == (lhs <= rhs));
	}
}

TEMPLATE_TEST_CASE_SIG("Operator \"equal\" and \"not equal\" list", "[list] [operator more] [comparison operators]",
														   ((typename T, int V), T, V), (int, 12)) {
	ft::list<T>		ft_lhs;
	ft::list<T>		ft_rhs;
	std::list<T>	lhs;
	std::list<T>	rhs;

	SECTION("empty list") {
		REQUIRE((ft_lhs == ft_rhs) == (lhs == rhs));
		REQUIRE((ft_lhs != ft_rhs) == (lhs != rhs));
	}

	SECTION("one node") {
		ft_rhs.push_back(-V);
		ft_lhs.push_back(V);
		rhs.push_back(-V);
		lhs.push_back(V);

		REQUIRE((ft_lhs == ft_rhs) == (lhs == rhs));
		REQUIRE((ft_lhs != ft_rhs) == (lhs != rhs));
	}

	SECTION("size = V") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_rhs.push_back(-i);
				rhs.push_back(-i);
			}
			else {
				ft_lhs.push_back(i);
				lhs.push_back(i);
			}
		}

		REQUIRE((ft_lhs == ft_rhs) == (lhs == rhs));
		REQUIRE((ft_lhs != ft_rhs) == (lhs != rhs));
	}

	SECTION("with different sizes") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_rhs.push_back(-i);
				rhs.push_back(-i);
			}
			ft_lhs.push_back(i);
			lhs.push_back(i);
		}

		REQUIRE((ft_lhs == ft_rhs) == (lhs == rhs));
		REQUIRE((ft_lhs != ft_rhs) == (lhs != rhs));
	}
}
