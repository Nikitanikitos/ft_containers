/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_constructor_tests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:17:46 by imicah            #+#    #+#             */
/*   Updated: 2020/10/29 12:17:46 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.hpp"
#include <queue>
#include "catch.hpp"

TEMPLATE_TEST_CASE_SIG( "Default Constructors in queue container", "[queue] [constructor]",
																((typename T, int V), T, V), (int, 10), (char, 20)) {
	SECTION("Create empty queue") {
		ft::queue<T>		ft_queue;
		std::queue<T>		queue;

		REQUIRE(queue.empty() == ft_queue.empty());
		REQUIRE(queue.size() == ft_queue.size());
	}
}
