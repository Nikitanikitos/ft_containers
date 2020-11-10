/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_erase_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:57:02 by imicah            #+#    #+#             */
/*   Updated: 2020/11/10 19:52:13 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "list.hpp"
#include "../catch.hpp"

TEMPLATE_TEST_CASE_SIG("Erase in list through one iterator", "[list] [erase]",
																((typename T, int V), T, V), (int, 23), (char, 400)) {
	ft::list<T>							ft_list(1, 23);
	std::list<T>						list(1, 23);
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	SECTION("with size = 1") {
		list.erase(list.begin());
		ft_list.erase(ft_list.begin());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
	}

	SECTION("with size = V") {
		ft::list<T>		ft_list(V, 21);
		std::list<T>	list(V, 21);

		ft_it = ft_list.begin();
		it = list.begin();
		SECTION("every two time") {
			for (int i = 0; i < V / 2; ++ft_it) {
				if (i++ % 2) {
					ft_it = ft_list.erase(ft_it);
					it = list.erase(it);
					REQUIRE(*ft_it == *it);
					REQUIRE(list.size() == ft_list.size());
				}
				++it;
			}
		}

		SECTION("from the middle") {
			for (size_t i = 0; i < ft_list.size() / 2; ++i) {
				++it;
				++ft_it;
			}
			REQUIRE(*ft_list.erase(ft_it) == *list.erase(it));
			REQUIRE(list.size() == ft_list.size());
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Erase in list through with two iterator", "[list] [erase]",
																	((typename T, int V), T, V), (int, 28), (char, 123)) {
	ft::list<T>							ft_list(1, 23);
	std::list<T>						list(1, 23);
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	SECTION("with size = 1") {
		list.erase(list.begin(), list.begin());
		ft_list.erase(ft_list.begin(), ft_list.begin());

		REQUIRE(list.size() == ft_list.size());
		REQUIRE(list.empty() == ft_list.empty());
	}

	SECTION("with size = V") {
		ft::list<T>		ft_list(V, 21);
		std::list<T>	list(V, 21);

		ft_it = ft_list.begin();
		it = list.begin();
		SECTION("every two time") {
			for (int i = 0; ft_it != ft_list.end(); ++ft_it) {
				if (!(i++ % 2)) {
					REQUIRE(*ft_it == *it);
					ft_it = ft_list.erase(ft_it);
					it = list.erase(it);
					REQUIRE(list.size() == ft_list.size());
				}
				++it;
			}
		}

		SECTION("First part") {
			for (size_t i = 0; i < ft_list.size() / 2; ++i) {
				++it;
				++ft_it;
			}
			REQUIRE(*ft_list.erase(ft_list.begin(), ft_it) == *list.erase(list.begin(), it));
			REQUIRE(list.size() == ft_list.size());
		}

		SECTION("Second part") {
			for (size_t i = 0; i < ft_list.size(); ++i) {
				++it;
				++ft_it;
			}
			ft_list.erase(ft_it, ft_list.end());
			list.erase(it, list.end());
			REQUIRE(list.front() == ft_list.front());
			REQUIRE(list.back() == ft_list.back());
			REQUIRE(list.size() == ft_list.size());
		}

		SECTION("all list") {
			ft_list.erase(ft_it, --ft_list.end());
			list.erase(it, --list.end());
			REQUIRE(list.front() == ft_list.front());
			REQUIRE(list.back() == ft_list.back());
			REQUIRE(list.size() == ft_list.size());
			REQUIRE(list.empty() == ft_list.empty());
		}
	}
}
