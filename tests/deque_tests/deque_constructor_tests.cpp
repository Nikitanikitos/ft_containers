/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_constructor_tests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:25:55 by imicah            #+#    #+#             */
/*   Updated: 2020/11/09 22:29:30 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include "deque.hpp"
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG( "Default Constructors in deque container", "[deque] [constructor]",
																((typename T, int V), T, V), (int, 10), (char, 20)) {

		SECTION("Create empty deque") {
			ft::deque<T>		ft_deque;
			std::deque<T>		deque;

			REQUIRE(deque.empty() == ft_deque.empty());
			REQUIRE(deque.size() == ft_deque.size());
		}

		SECTION("Create with size") {
			for (int i = 1; i < V; i++) {
				ft::deque<T>		ft_deque(i);
				std::deque<T>		deque(i);

				REQUIRE(ft_deque.empty() == ft_deque.empty());
				REQUIRE(ft_deque.size() == ft_deque.size());
				REQUIRE(ft_deque.front() == ft_deque.front());
				REQUIRE(ft_deque.back() == ft_deque.back());

				ft_deque.clear();
			}
		}

		SECTION("Create with size and default value") {
			for (int i = 1; i < V; i++) {
				ft::deque<T>		ft_deque(i, 'a' + i);
				std::deque<T>		deque(i, 'a' + i);

				REQUIRE(deque.empty() == ft_deque.empty());
				REQUIRE(deque.size() == ft_deque.size());
				REQUIRE(ft_deque.front() == ft_deque.front());
				REQUIRE(ft_deque.back() == ft_deque.back());

				deque.clear();
				ft_deque.clear();
			}
	}
}

TEMPLATE_TEST_CASE_SIG("Copy constructor in deque container", "[deque] [constructor]",
																   ((typename T, int V), T, V), (int, 10)) {
	ft::deque<T>		ft_deque_for_copy;
	std::deque<T>		deque_for_copy;

	SECTION("Empty vector") {
		ft::deque<T>		ft_deque(ft_deque_for_copy);
		std::deque<T>		deque(deque_for_copy);

		REQUIRE(deque.empty() == ft_deque.empty());
		REQUIRE(deque.size() == ft_deque.size());
	}

	SECTION("With size") {
		for (int i = 1; i < V; i++) {
			ft_deque_for_copy.push_back(i);
			ft_deque_for_copy.push_front(i + 2);
			deque_for_copy.push_back(i);
			deque_for_copy.push_front(i + 2);

			ft::deque<T>		ft_deque(ft_deque_for_copy);
			std::deque<T>		deque(deque_for_copy);

			REQUIRE(deque.size() == ft_deque.size());
			REQUIRE(deque.back() == ft_deque.back());
			REQUIRE(deque.front() == ft_deque.front());

			deque.clear();
			ft_deque.clear();
		}
	}

	SECTION("With size and default value") {
		ft::deque<T>		ft_deque_for_copy(0, 'a');
		std::deque<T>		deque_for_copy(0, 'a');

		for (int i = 1; i < V; i++) {
			ft_deque_for_copy.push_back(i);
			ft_deque_for_copy.push_front(i + 2);
			deque_for_copy.push_back(i);
			deque_for_copy.push_front(i + 2);

			ft::deque<T>		ft_deque(ft_deque_for_copy);
			std::deque<T>		deque(deque_for_copy);

			REQUIRE(deque.size() == ft_deque.size());
			REQUIRE(deque.back() == ft_deque.back());
			REQUIRE(deque.front() == ft_deque.front());

			deque.clear();
			ft_deque.clear();
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Assignation operator in deque container", "[deque] [constructor]",
																   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::deque<T>		ft_deque_for_copy;
	std::deque<T>		deque_for_copy;

	SECTION("Empty vector") {
		ft::deque<T>		ft_deque = ft_deque_for_copy;
		std::deque<T>		deque = deque_for_copy;

		REQUIRE(deque.empty() == ft_deque.empty());
		REQUIRE(deque.size() == ft_deque.size());
	}

	SECTION("With size") {
		for (int i = 1; i < V; i++) {
			deque_for_copy.push_back(i);
			deque_for_copy.push_front(i - 2);
			ft_deque_for_copy.push_back(i);
			ft_deque_for_copy.push_front(i - 2);

			ft::deque<T>		ft_deque = ft_deque_for_copy;
			std::deque<T>		deque = deque_for_copy;

			REQUIRE(deque.size() == ft_deque.size());
			REQUIRE(deque.back() == ft_deque.back());
			REQUIRE(deque.front() == ft_deque.front());

			deque.clear();
			ft_deque.clear();
		}
	}

	SECTION("With size and default value") {
		ft::deque<T>		ft_deque_for_copy(0, 'a');
		std::deque<T>		deque_for_copy(0, 'a');

		for (int i = 1; i < V; i++) {
			deque_for_copy.push_back(i);
			ft_deque_for_copy.push_back(i);

			ft::deque<T>		ft_deque = ft_deque_for_copy;
			std::deque<T>		deque = deque_for_copy;

			REQUIRE(deque.size() == ft_deque.size());
			REQUIRE(deque.back() == ft_deque.back());

			deque.clear();
			ft_deque.clear();
		}
	}

	SECTION("Assignation with different size") {
		ft::deque<T>		ft_deque_for_copy(12);
		std::deque<T>		deque_for_copy(12);

		SECTION("Assignation with lower size") {
			ft::deque<T>		ft_deque(6);
			std::deque<T>		deque(6);

			ft_deque = ft_deque_for_copy;
			deque = deque_for_copy;

			REQUIRE(deque.size() == ft_deque.size());
			REQUIRE(deque.front() == ft_deque.front());
			REQUIRE(deque.back() == ft_deque.back());
		}

		SECTION("Assignation with greater size") {
			ft::deque<T>		ft_deque(24);
			std::deque<T>		deque(24);

			ft_deque = ft_deque_for_copy;
			deque = deque_for_copy;

			REQUIRE(deque.size() == ft_deque.size());
			REQUIRE(deque.front() == ft_deque.front());
			REQUIRE(deque.back() == ft_deque.back());
		}
	}
}

TEMPLATE_TEST_CASE_SIG("Constructor via iterators in deque container", "[deque] [constructor]",
																   ((typename T, int V), T, V), (int, 10), (char, 20)) {
	ft::deque<T>		ft_deque_for_copy;
	std::deque<T>		deque_for_copy;

	SECTION("Empty vector") {
		ft::deque<T>		ft_deque(ft_deque_for_copy.begin(), ft_deque_for_copy.end());
		std::deque<T>		deque(deque_for_copy.begin(), deque_for_copy.end());

		REQUIRE(deque.empty() == ft_deque.empty());
		REQUIRE(deque.size() == ft_deque.size());
	}

	SECTION("With size") {
		for (int i = 0; i < V; i++) {

			ft::deque<T>	ft_deque(ft_deque_for_copy.begin(), ft_deque_for_copy.end());
			std::deque<T>	deque(deque_for_copy.begin(), deque_for_copy.end());

			REQUIRE(deque.empty() == ft_deque.empty());
			REQUIRE(deque.size() == ft_deque.size());
			if (i) {
				REQUIRE(deque.front() == ft_deque.front());
				REQUIRE(deque.back() == ft_deque.back());
			}

			ft_deque_for_copy.push_back(i);
			ft_deque_for_copy.push_front(2 - i);
			deque_for_copy.push_front(2 - i);
			deque_for_copy.push_back(i);

			deque.clear();
			ft_deque.clear();
		}
	}

	SECTION("With size and default value") {
		ft::deque<T>		ft_deque_for_copy(0, 'a');
		std::deque<T>		deque_for_copy(0, 'a');

		for (int i = 0; i < V; i++) {

			ft::deque<T>	ft_deque(ft_deque_for_copy.begin(), ft_deque_for_copy.end());
			std::deque<T>	deque(deque_for_copy.begin(), deque_for_copy.end());

			REQUIRE(deque.empty() == ft_deque.empty());
			REQUIRE(deque.size() == ft_deque.size());
			if (i) {
				REQUIRE(deque.front() == ft_deque.front());
				REQUIRE(deque.back() == ft_deque.back());
			}

			ft_deque_for_copy.push_back(i);
			ft_deque_for_copy.push_front(2 - i);
			deque_for_copy.push_front(2 - i);
			deque_for_copy.push_back(i);

			deque.clear();
			ft_deque.clear();
		}
	}
}
