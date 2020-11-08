/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 14:04:18 by imicah            #+#    #+#             */
/*   Updated: 2020/10/25 14:22:26 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "../catch.hpp"

TEMPLATE_TEST_CASE("Swap empty lists", "[list] [swap]", int) {
	ft::list<TestType>		ft_list_1;
	ft::list<TestType>		ft_list_2;
	std::list<TestType>		list_1;
	std::list<TestType>		list_2;

	REQUIRE(list_1.size() == ft_list_1.size());
	REQUIRE(list_1.empty() == ft_list_1.empty());
	REQUIRE(list_2.size() == ft_list_2.size());
	REQUIRE(list_2.empty() == ft_list_2.empty());

	ft_list_1.swap(ft_list_2);
	list_1.swap(list_2);

	REQUIRE(list_1.size() == ft_list_1.size());
	REQUIRE(list_1.empty() == ft_list_1.empty());
	REQUIRE(list_2.size() == ft_list_2.size());
	REQUIRE(list_2.empty() == ft_list_2.empty());
}

TEMPLATE_TEST_CASE("Swap lists with size = 1", "[list] [swap]", int) {
	ft::list<TestType>		ft_list_1(1);
	ft::list<TestType>		ft_list_2(1);
	std::list<TestType>		list_1(1);
	std::list<TestType>		list_2(1);

	REQUIRE(list_1.size() == ft_list_1.size());
	REQUIRE(list_1.empty() == ft_list_1.empty());
	REQUIRE(list_2.size() == ft_list_2.size());
	REQUIRE(list_2.empty() == ft_list_2.empty());

	ft_list_1.swap(ft_list_2);
	list_1.swap(list_2);

	REQUIRE(list_1.size() == ft_list_1.size());
	REQUIRE(list_1.empty() == ft_list_1.empty());
	REQUIRE(list_2.size() == ft_list_2.size());
	REQUIRE(list_2.empty() == ft_list_2.empty());
}

TEMPLATE_TEST_CASE_SIG("Swap lists with equal size", "[list] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::list<T>		ft_list_1(V, 13);
	ft::list<T>		ft_list_2(V, 31);
	std::list<T>	list_1(V, 13);
	std::list<T>	list_2(V, 31);

	typename ft::list<T>::iterator		ft_it_1;
	typename ft::list<T>::iterator		ft_it_2;
	typename std::list<T>::iterator		it_1;
	typename std::list<T>::iterator		it_2;

	REQUIRE(list_1.size() == ft_list_1.size());
	REQUIRE(list_2.size() == ft_list_2.size());

	ft_list_1.swap(ft_list_2);
	list_1.swap(list_2);

	REQUIRE(list_1.size() == ft_list_1.size());
	REQUIRE(list_2.size() == ft_list_2.size());

	ft_it_2 = ft_list_2.begin();
	it_1 = list_1.begin();
	it_2 = list_2.begin();
	for (ft_it_1 = ft_list_1.begin(); ft_it_1 != ft_list_1.end(); ++ft_it_1) {
		REQUIRE(*ft_it_1 == *it_1);
		REQUIRE(*ft_it_2 == *it_2);
		++ft_it_2;
		++it_1;
		++it_2;
	}
}

TEMPLATE_TEST_CASE_SIG("Swap lists with lower size", "[list] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::list<T>		ft_list_1(V / 2, 13);
	ft::list<T>		ft_list_2(V, 31);
	std::list<T>	list_1(V / 2, 13);
	std::list<T>	list_2(V, 31);

	typename ft::list<T>::iterator		ft_it_1;
	typename ft::list<T>::iterator		ft_it_2;
	typename std::list<T>::iterator		it_1;
	typename std::list<T>::iterator		it_2;

	REQUIRE(list_1.size() == ft_list_1.size());
	REQUIRE(list_2.size() == ft_list_2.size());

	ft_list_1.swap(ft_list_2);
	list_1.swap(list_2);

	REQUIRE(list_1.size() == ft_list_1.size());
	REQUIRE(list_2.size() == ft_list_2.size());

	it_1 = list_1.begin();
	for (ft_it_1 = ft_list_1.begin(); ft_it_1 != ft_list_1.end(); ++ft_it_1) {
		REQUIRE(*ft_it_1 == *it_1);
		++it_1;
	}
	it_2 = list_2.begin();
	for (ft_it_2 = ft_list_2.begin(); ft_it_2 != ft_list_2.end(); ++ft_it_2) {
		REQUIRE(*ft_it_2 == *it_2);
		++it_2;
	}
}

TEMPLATE_TEST_CASE_SIG("Swap lists with greater size", "[list] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::list<T>		ft_list_1(V, 21);
	ft::list<T>		ft_list_2(V / 2, 32);
	std::list<T>	list_1(V, 21);
	std::list<T>	list_2(V / 2, 32);

	typename ft::list<T>::iterator		ft_it_1;
	typename ft::list<T>::iterator		ft_it_2;
	typename std::list<T>::iterator		it_1;
	typename std::list<T>::iterator		it_2;

	REQUIRE(list_1.size() == ft_list_1.size());
	REQUIRE(list_2.size() == ft_list_2.size());

	ft_list_1.swap(ft_list_2);
	list_1.swap(list_2);

	REQUIRE(list_1.size() == ft_list_1.size());
	REQUIRE(list_2.size() == ft_list_2.size());

	it_1 = list_1.begin();
	for (ft_it_1 = ft_list_1.begin(); ft_it_1 != ft_list_1.end(); ++ft_it_1) {
		REQUIRE(*ft_it_1 == *it_1);
		++it_1;
	}
	it_2 = list_2.begin();
	for (ft_it_2 = ft_list_2.begin(); ft_it_2 != ft_list_2.end(); ++ft_it_2) {
		REQUIRE(*ft_it_2 == *it_2);
		++it_2;
	}
}
