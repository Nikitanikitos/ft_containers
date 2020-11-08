/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_pop_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:57:44 by imicah            #+#    #+#             */
/*   Updated: 2020/10/29 12:15:40 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>
#include "../catch.hpp"

TEMPLATE_TEST_CASE("Push pop stack", "[stack] [push]", int, float) {
	ft::stack<TestType>			ft_stack_number;
	std::stack<TestType>		stack_number;
	ft::stack<std::string>		ft_list_string;
	std::stack<std::string>		list_string;

	SECTION("Push back number") {
		ft_stack_number.push(42);
		stack_number.push(42);

		REQUIRE(stack_number.size() == ft_stack_number.size());
		REQUIRE(stack_number.top() == ft_stack_number.top());

		ft_stack_number.pop();
		stack_number.pop();

		REQUIRE(stack_number.size() == ft_stack_number.size());
		REQUIRE(stack_number.empty() == ft_stack_number.empty());
	}

	SECTION("Push back string") {
		ft_list_string.push("Push Back String");
		list_string.push("Push Back String");

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(list_string.top() == ft_list_string.top());

		ft_list_string.pop();
		list_string.pop();

		REQUIRE(list_string.size() == ft_list_string.size());
		REQUIRE(stack_number.empty() == ft_stack_number.empty());
	}
}

TEMPLATE_TEST_CASE_SIG("Push stack", "[stack] [push]", ((typename T, int V), T, V), (int, 23)) {
	ft::stack<T> 				ft_stack_number;
	std::stack<T> 				stack_number;
	ft::stack<std::string>		ft_stack_string;
	std::stack<std::string>		stack_string;

	SECTION("Push back number") {
		for (int i = 0; i < V; ++i) {
			ft_stack_number.push(i + 100);
			stack_number.push(i + 100);
		}

		REQUIRE(stack_number.size() == ft_stack_number.size());
		REQUIRE(stack_number.top() == ft_stack_number.top());

		for (int i = 0; i < V / 2; ++i) {
			ft_stack_number.pop();
			stack_number.pop();
		}

		REQUIRE(stack_number.size() == ft_stack_number.size());
		REQUIRE(stack_number.top() == ft_stack_number.top());
	}

	SECTION("Push back string") {
		for (int i = 0; i < V; ++i) {
			ft_stack_string.push("Test string " + std::to_string(i));
			stack_string.push("Test string " + std::to_string(i));
		}

		REQUIRE(stack_string.size() == ft_stack_string.size());
		REQUIRE(stack_string.top() == ft_stack_string.top());

		for (int i = 0; i < V / 2; ++i) {
			ft_stack_string.pop();
			stack_string.pop();
		}

		REQUIRE(stack_string.size() == ft_stack_string.size());
		REQUIRE(stack_string.top() == ft_stack_string.top());
	}
}
