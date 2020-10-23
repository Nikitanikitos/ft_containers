/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:08:08 by imicah            #+#    #+#             */
/*   Updated: 2020/10/23 18:07:50 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "catch.hpp"

TEMPLATE_TEST_CASE("Insert in empty list list through iterator", "[list] [insert]", int) {

	ft::list<TestType>		ft_list;
	std::list<TestType>		list;

	SECTION("at the front") {
		ft_list.insert(ft_list.begin(), 21);
		list.insert(list.begin(), 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("at the back") {
		ft_list.insert(ft_list.end(), 21);
		list.insert(list.end(), 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}
}

TEMPLATE_TEST_CASE("Insert in list with size = 1 list through iterator", "[list] [insert]", int) {

	ft::list<TestType>		ft_list(1, 12);
	std::list<TestType>		list(1, 12);

	SECTION("Into list with size = 1 at the front") {
		ft_list.insert(ft_list.begin(), 21);
		list.insert(list.begin(), 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("Into list with size = 1 at the back") {
		ft_list.insert(ft_list.end(), 21);
		list.insert(list.end(), 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in list with size = n list through iterator",  "[list] [insert]",
					   ((typename T, int V), T, V), (int, 13), (char, 29), (float, 24)) {

	ft::list<T>							ft_list(V, 42);
	std::list<T>						list(V, 42);
	typename ft::list<T>::iterator		ft_it = ft_list.begin();
	typename std::list<T>::iterator		it = list.begin();

	SECTION("Every two times")
	for (int i = 0; i < V; ++i) {
		if (i % 2) {
			ft_list.insert(ft_it, i % 21);
			list.insert(it, i % 21);
		}
		++ft_it;
		++it;
	}
	REQUIRE(list.size() == ft_list.size());
	ft_it = ft_list.begin();
	for (it = list.begin(); it != list.end(); ++it) {
		REQUIRE(*it == *ft_it);
		++ft_it;
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in empty list through iterator and size", "[list] [insert]",
											   ((typename T, int V), T, V), (int, 5)) {

	ft::list<T>							ft_list;
	std::list<T>						list;
	typename ft::list<T>::iterator		ft_it = ft_list.begin();
	typename std::list<T>::iterator		it = list.begin();

	SECTION("at the front, size = 1") {
		ft_list.insert(ft_list.begin(), 1, 21);
		list.insert(list.begin(), 1, 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("at the front, size = V") {
		ft_list.insert(ft_list.begin(), V, 21);
		list.insert(list.begin(), V, 21);

		REQUIRE(list.size() == ft_list.size());
		ft_it = ft_list.begin();
		for (it = list.begin(); it != list.end(); ++it) {
			REQUIRE(*it == *ft_it);
			++ft_it;
		}
	}

	SECTION("at the back, size = 1") {
		ft_list.insert(ft_list.end(), 1, 21);
		list.insert(list.end(), 1, 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("at the back, size = V") {
		ft_list.insert(ft_list.end(), V, 21);
		list.insert(list.end(), V, 21);

		REQUIRE(list.size() == ft_list.size());
		ft_it = ft_list.begin();
		for (it = list.begin(); it != list.end(); ++it) {
			REQUIRE(*it == *ft_it);
			++ft_it;
		}
	}

}

TEMPLATE_TEST_CASE_SIG("Insert in list with size = 1 through iterator and size", "[list] [insert]",
					   ((typename T, int V), T, V), (int, 5)) {

	ft::list<T>		ft_list(1, 12);
	std::list<T>	list(1, 12);
	typename ft::list<T>::iterator		ft_it = ft_list.begin();
	typename std::list<T>::iterator		it = list.begin();

	SECTION("List with size = 1 at the front and insert size = 1") {
		ft_list.insert(ft_list.begin(), 1, 21);
		list.insert(list.begin(), 1, 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("List with size = 1 at the front and insert size = V") {
		ft_list.insert(ft_list.begin(), V, 21);
		list.insert(list.begin(), V, 21);

		REQUIRE(list.size() == ft_list.size());
		ft_it = ft_list.begin();
		for (it = list.begin(); it != list.end(); ++it) {
			REQUIRE(*it == *ft_it);
			++ft_it;
		}
	}

	SECTION("List with size = 1 at the back and insert size = 1") {
		ft_list.insert(ft_list.end(), 1, 21);
		list.insert(list.end(), 1, 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("List with size = 1 at the back and insert size = V") {
		ft_list.insert(ft_list.end(), V, 21);
		list.insert(list.end(), V, 21);

		REQUIRE(list.size() == ft_list.size());
		ft_it = ft_list.begin();
		for (it = list.begin(); it != list.end(); ++it) {
			REQUIRE(*it == *ft_it);
			++ft_it;
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in list with size = V through iterator and size", "[list] [insert]",
					   ((typename T, int V), T, V), (int, 5)) {

	ft::list<T>		ft_list(V, 42);
	std::list<T>	list(V, 42);
	typename ft::list<T>::iterator		ft_it = ft_list.begin();
	typename std::list<T>::iterator		it = list.begin();

	SECTION("Every two times")
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_list.insert(ft_it, 3, i % 21);
				list.insert(it, 3, i % 21);
			}
			++ft_it;
			++it;
		}
	REQUIRE(list.size() == ft_list.size());
	ft_it = ft_list.begin();
	for (it = list.begin(); it != list.end(); ++it) {
		REQUIRE(*it == *ft_it);
		++ft_it;
	}
}
