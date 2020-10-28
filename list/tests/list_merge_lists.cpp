/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge_lists.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 14:55:05 by imicah            #+#    #+#             */
/*   Updated: 2020/10/26 15:04:34 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "catch.hpp"


template<typename T>
bool	reverse_compare(const T &first, const T &second) { return (first > second); }

TEMPLATE_TEST_CASE_SIG("Merge lists", "[list] [splice]", ((typename T, int V), T, V), (int, 23)) {
	ft::list<T>		ft_list_1;
	ft::list<T>		ft_list_2;
	std::list<T>	list_1;
	std::list<T>	list_2;

	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	for (int i = 0; i < V; ++i) {
		if (i % 3) {
			ft_list_2.push_back(i);
			list_2.push_back(i);
		}
		else {
			ft_list_2.push_back(i - 23);
			list_2.push_back(i - 23);
		}
	}

	for (int i = 0; i < V; ++i) {
		ft_list_1.push_back(i);
		list_1.push_back(i);
	}
	ft_list_1.sort();
	ft_list_2.sort();
	list_1.sort();
	list_2.sort();


	SECTION("without compare") {
		ft_list_1.merge(ft_list_2);
		list_1.merge(list_2);

		REQUIRE(ft_list_1.size() == list_1.size());
		REQUIRE(ft_list_2.size() == list_2.size());

		ft_it = ft_list_1.begin();
		it = list_1.begin();
		for (typename ft::list<T>::size_type i = 0; i < ft_list_1.size(); ++i) {
			REQUIRE(*it == *ft_it);
			++it;
			++ft_it;
		}
	}
	SECTION("without compare") {
		ft_list_1.merge(ft_list_2, reverse_compare<T>);
		list_1.merge(list_2, reverse_compare<T>);

		REQUIRE(ft_list_1.size() == list_1.size());
		REQUIRE(ft_list_2.size() == list_2.size());

		ft_it = ft_list_1.begin();
		it = list_1.begin();
		for (typename ft::list<T>::size_type i = 0; i < ft_list_1.size(); ++i) {
			REQUIRE(*it == *ft_it);
			++it;
			++ft_it;
		}
	}
}
