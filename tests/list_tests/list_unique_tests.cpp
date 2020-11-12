/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_unique_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:48:57 by imicah            #+#    #+#             */
/*   Updated: 2020/10/25 17:46:08 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "../catch.hpp"

bool	negative_pred(int &i, int &q) { return (-i == -q); }

bool	module_pred(const int &i, const int &q) {
	int 	i_temp = (i < 0) ? -i : i;
	int 	q_temp = (q < 0) ? -q : q;
	return (i_temp == q_temp);
}

TEMPLATE_TEST_CASE_SIG("Unique list with size = 2", "[list] [unique]", ((typename T, int V), T, V), (int, 12)) {
	ft::list<T>							ft_list(2, 21);
	std::list<T>						list(2, 21);
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	SECTION("without binary_pred") {
		ft_list.unique();
		list.unique();

		REQUIRE(ft_list.size() == ft_list.size());

		it = list.begin();
		for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
			REQUIRE(*ft_it == *it);
			++it;
		}
	}

	SECTION("with binary_pred") {
		ft_list.unique(negative_pred);
		list.unique(negative_pred);

		REQUIRE(ft_list.size() == ft_list.size());

		it = list.begin();
		for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
			REQUIRE(*ft_it == *it);
			++it;
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Unique list with size = V", "[list] [unique]", ((typename T, int V), T, V), (int, 12)) {
	ft::list<T>							ft_list(2, 21);
	std::list<T>						list(2, 21);
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	SECTION("without binary_pred") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_list.push_back(i - 1);
				list.push_back(i - 1);
			}
			ft_list.push_back(i);
			list.push_back(i);
		}
		ft_list.unique();
		list.unique();

		REQUIRE(ft_list.size() == ft_list.size());

		it = list.begin();
		for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
			REQUIRE(*ft_it == *it);
			++it;
		}
	}

	SECTION("with binary_pred") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_list.push_back(-i - 1);
				list.push_back(-i - 1);
			}
			ft_list.push_back(i);
			list.push_back(i);
		}
		ft_list.unique(module_pred);
		list.unique(module_pred);

		REQUIRE(ft_list.size() == ft_list.size());

		it = list.begin();
		for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
			REQUIRE(*ft_it == *it);
			++it;
		}
	}
}
