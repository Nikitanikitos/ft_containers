/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_constructor_tests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:51:47 by imicah            #+#    #+#             */
/*   Updated: 2020/10/29 12:15:38 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>
#include "../catch.hpp"

TEMPLATE_TEST_CASE_SIG( "Default Constructors in stack container", "[stack] [constructor]",
																((typename T, int V), T, V), (int, 10), (char, 20)) {
	SECTION("Create empty list") {
		ft::stack<T>		ft_stack;
		std::stack<T>		stack;

		REQUIRE(stack.empty() == ft_stack.empty());
		REQUIRE(stack.size() == ft_stack.size());
	}
}
