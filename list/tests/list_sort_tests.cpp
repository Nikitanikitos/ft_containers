/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:34:48 by imicah            #+#    #+#             */
/*   Updated: 2020/10/25 18:56:12 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "catch.hpp"

template<typename T>
bool	reverse_compare(const T &first, const T &second) { return (first > second); }

TEMPLATE_TEST_CASE_SIG("Sort list", "[list] [sort]", ((typename T, int V), T, V), (int, 10)) {
	ft::list<T>							ft_list;
	std::list<T>						list;
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	for (int i = 0; i < V; ++i) {
		if (i % 3) {
			ft_list.push_back(-i);
			list.push_back(-i);
		}
		else {
			ft_list.push_back(i);
			list.push_back(i);
		}
	}

	SECTION("sort without compare") {
		list.sort();
		ft_list.sort();

		REQUIRE(ft_list.size() == list.size());
		it = list.begin();
		for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
			REQUIRE(*ft_it == *it);
			++it;
		}
	}

	SECTION("sort with compare") {
		list.sort(reverse_compare<T>);
		ft_list.sort(reverse_compare<T>);

		REQUIRE(ft_list.size() == list.size());
		it = list.begin();
		for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
			REQUIRE(*ft_it == *it);
			++it;
		}
	}
}
