/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:08:08 by imicah            #+#    #+#             */
/*   Updated: 2020/10/23 20:50:35 by imicah           ###   ########.fr       */
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

	SECTION("At the front") {
		ft_list.insert(ft_list.begin(), 21);
		list.insert(list.begin(), 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("At the back") {
		ft_list.insert(ft_list.end(), 21);
		list.insert(list.end(), 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in list with size = V list through iterator",  "[list] [insert]",
							   ((typename T, int V), T, V), (int, 13), (char, 29), (float, 24)) {

	ft::list<T>							ft_list(V, 42);
	std::list<T>						list(V, 42);
	typename ft::list<T>::iterator		ft_it = ft_list.begin();
	typename std::list<T>::iterator		it = list.begin();

	SECTION("Every two times") {
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
}

TEMPLATE_TEST_CASE_SIG("Insert in empty list through iterator and size", "[list] [insert]",
														   ((typename T, int V), T, V), (int, 5)) {

	ft::list<T>							ft_list;
	std::list<T>						list;
	typename ft::list<T>::iterator		ft_it = ft_list.begin();
	typename std::list<T>::iterator		it = list.begin();

	SECTION("At the front, size = 1") {
		ft_list.insert(ft_list.begin(), 1, 21);
		list.insert(list.begin(), 1, 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("At the front, size = V") {
		ft_list.insert(ft_list.begin(), V, 21);
		list.insert(list.begin(), V, 21);

		REQUIRE(list.size() == ft_list.size());
		ft_it = ft_list.begin();
		for (it = list.begin(); it != list.end(); ++it) {
			REQUIRE(*it == *ft_it);
			++ft_it;
		}
	}

	SECTION("At the back, size = 1") {
		ft_list.insert(ft_list.end(), 1, 21);
		list.insert(list.end(), 1, 21);

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("At the back, size = V") {
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

TEMPLATE_TEST_CASE_SIG("Insert in list with size = V through iterator and size", "[list] [insert]",
														   ((typename T, int V), T, V), (int, 5)) {

	ft::list<T>		ft_list(V, 42);
	std::list<T>	list(V, 42);
	typename ft::list<T>::iterator		ft_it = ft_list.begin();
	typename std::list<T>::iterator		it = list.begin();

	SECTION("Every two times") {
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
}

TEMPLATE_TEST_CASE_SIG("Insert in list empty list through two iterator", "[list] [insert]",
					   ((typename T, int V), T, V), (int, 5)) {

	ft::list<T>							ft_list;
	std::list<T>						list;
	ft::list<T>							ft_list_for_insert;
	std::list<T>						list_for_insert;
	typename ft::list<T>::iterator		ft_it = ft_list.begin();
	typename std::list<T>::iterator		it = list.begin();

	SECTION("at the front, empty ft_list_for_insert") {
		ft_list.insert(ft_list.begin(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.begin(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("at the front, size ft_list_for_insert = 1") {
		ft::list<T>							ft_list_for_insert(1, 2);
		std::list<T>						list_for_insert(1, 2);
		ft_list.insert(ft_list.begin(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.begin(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("at the front, size ft_list_for_insert = V") {
		ft::list<T>							ft_list_for_insert(V, 32);
		std::list<T>						list_for_insert(V, 32);
		ft_list.insert(ft_list.begin(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.begin(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		ft_it = ft_list.begin();
		for (it = list.begin(); it != list.end(); ++it) {
			REQUIRE(*it == *ft_it);
			++ft_it;
		}
	}

	SECTION("at the back, empty ft_list_for_insert") {
		ft_list.insert(ft_list.end(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.end(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("at the back, size ft_list_for_insert = 1") {
		ft::list<T>							ft_list_for_insert(1, 2);
		std::list<T>						list_for_insert(1, 2);
		ft_list.insert(ft_list.end(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.end(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("at the front, size ft_list_for_insert = V") {
		ft::list<T>							ft_list_for_insert(V, 32);
		std::list<T>						list_for_insert(V, 32);
		ft_list.insert(ft_list.end(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.end(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		ft_it = ft_list.begin();
		for (it = list.begin(); it != list.end(); ++it) {
			REQUIRE(*it == *ft_it);
			++ft_it;
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in list with size = 1 through two iterator", "[list] [insert]",
					   ((typename T, int V), T, V), (int, 5)) {

	ft::list<T>							ft_list(1, 13);
	std::list<T>						list(1, 13);
	ft::list<T>							ft_list_for_insert;
	std::list<T>						list_for_insert;
	typename ft::list<T>::iterator		ft_it = ft_list.begin();
	typename std::list<T>::iterator		it = list.begin();

	SECTION("at the front, empty ft_list_for_insert") {
		ft_list.insert(ft_list.begin(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.begin(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("at the front, size ft_list_for_insert = 1") {
		ft::list<T>							ft_list_for_insert(1, 2);
		std::list<T>						list_for_insert(1, 2);
		ft_list.insert(ft_list.begin(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.begin(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("at the front, size ft_list_for_insert = V") {
		ft::list<T>							ft_list_for_insert(V, 32);
		std::list<T>						list_for_insert(V, 32);
		ft_list.insert(ft_list.begin(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.begin(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		ft_it = ft_list.begin();
		for (it = list.begin(); it != list.end(); ++it) {
			REQUIRE(*it == *ft_it);
			++ft_it;
		}
	}

	SECTION("at the back, empty ft_list_for_insert") {
		ft_list.insert(ft_list.end(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.end(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("at the back, size ft_list_for_insert = 1") {
		ft::list<T>							ft_list_for_insert(1, 2);
		std::list<T>						list_for_insert(1, 2);
		ft_list.insert(ft_list.end(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.end(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.front() == ft_list.front());
		REQUIRE(list.back() == ft_list.back());
	}

	SECTION("at the front, size ft_list_for_insert = V") {
		ft::list<T>							ft_list_for_insert(V, 32);
		std::list<T>						list_for_insert(V, 32);
		ft_list.insert(ft_list.end(), ft_list_for_insert.begin(), ft_list_for_insert.end());
		list.insert(list.end(), list_for_insert.begin(), list_for_insert.end());

		REQUIRE(list.size() == ft_list.size());
		ft_it = ft_list.begin();
		for (it = list.begin(); it != list.end(); ++it) {
			REQUIRE(*it == *ft_it);
			++ft_it;
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Insert in list with size = V through two iterator", "[list] [insert]",
					   ((typename T, int V), T, V), (int, 5)) {

	ft::list<T>							ft_list(V, -26);
	std::list<T>						list(V, -26);
	ft::list<T>							ft_list_for_insert;
	std::list<T>						list_for_insert;
	typename ft::list<T>::iterator		ft_it = ft_list.begin();
	typename std::list<T>::iterator		it = list.begin();

	SECTION("Every two times with empty list") {
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_list.insert(ft_it, ft_list_for_insert.begin(), ft_list_for_insert.end());
				list.insert(it, list_for_insert.begin(), list_for_insert.end());
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

	SECTION("Every two times with size list = 1") {
		ft::list<T>							ft_list_for_insert(1);
		std::list<T>						list_for_insert(1);
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_list.insert(ft_it, ft_list_for_insert.begin(), ft_list_for_insert.end());
				list.insert(it, list_for_insert.begin(), list_for_insert.end());
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

	SECTION("Every two times with size list = 1") {
		ft::list<T>							ft_list_for_insert(3, 33);
		std::list<T>						list_for_insert(3, 33);
		for (int i = 0; i < V; ++i) {
			if (i % 2) {
				ft_list.insert(ft_it, ft_list_for_insert.begin(), ft_list_for_insert.end());
				list.insert(it, list_for_insert.begin(), list_for_insert.end());
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
}
