/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push_front_tests.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:21:06 by imicah            #+#    #+#             */
/*   Updated: 2020/10/29 12:28:46 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.hpp"
#include <queue>
#include "catch.hpp"

TEMPLATE_TEST_CASE("Push/pop queue", "[queue] [push]", int, float) {
	ft::queue<TestType>			ft_queue_number;
	std::queue<TestType>		queue_number;
	ft::queue<std::string>		ft_queue_string;
	std::queue<std::string>		queue_string;

	SECTION("Push back number") {
		ft_queue_number.push(42);
		queue_number.push(42);

		REQUIRE(queue_number.size() == ft_queue_number.size());
		REQUIRE(queue_number.front() == ft_queue_number.front());
		REQUIRE(queue_number.back() == ft_queue_number.back());

		ft_queue_number.pop();
		queue_number.pop();

		REQUIRE(queue_number.size() == ft_queue_number.size());
		REQUIRE(queue_number.empty() == ft_queue_number.empty());
	}

	SECTION("Push string") {
		ft_queue_string.push("Push String");
		queue_string.push("Push String");

		REQUIRE(queue_string.size() == ft_queue_string.size());
		REQUIRE(queue_string.front() == ft_queue_string.front());
		REQUIRE(queue_string.back() == ft_queue_string.back());

		ft_queue_string.pop();
		queue_string.pop();

		REQUIRE(queue_string.size() == ft_queue_string.size());
		REQUIRE(queue_number.empty() == ft_queue_number.empty());
	}
}

TEMPLATE_TEST_CASE_SIG("Push/pop many times", "[queue] [push]", ((typename T, int V), T, V), (int, 23)) {
	ft::queue<T> 				ft_queue_number;
	std::queue<T> 				queue_number;
	ft::queue<std::string>		ft_queue_string;
	std::queue<std::string>		queue_string;

	SECTION("Push back number") {
		for (int i = 0; i < V; ++i) {
			ft_queue_number.push(i + 100);
			queue_number.push(i + 100);
		}

		REQUIRE(queue_number.size() == ft_queue_number.size());
		REQUIRE(queue_number.back() == ft_queue_number.back());

		for (int i = 0; i < V / 2; ++i) {
			REQUIRE(queue_number.front() == ft_queue_number.front());
			ft_queue_number.pop();
			queue_number.pop();
		}

		REQUIRE(queue_number.size() == ft_queue_number.size());
		REQUIRE(queue_number.front() == ft_queue_number.front());
		REQUIRE(queue_number.back() == ft_queue_number.back());
	}

	SECTION("Push string") {
		for (int i = 0; i < V; ++i) {
			ft_queue_string.push("Test string " + std::to_string(i));
			queue_string.push("Test string " + std::to_string(i));
		}

		REQUIRE(queue_string.size() == ft_queue_string.size());
		REQUIRE(queue_string.back() == ft_queue_string.back());

		for (int i = 0; i < V / 2; ++i) {
			REQUIRE(queue_string.back() == ft_queue_string.back());
			ft_queue_string.pop();
			queue_string.pop();
		}

		REQUIRE(queue_string.size() == ft_queue_string.size());
		REQUIRE(queue_string.back() == ft_queue_string.back());
	}
}
