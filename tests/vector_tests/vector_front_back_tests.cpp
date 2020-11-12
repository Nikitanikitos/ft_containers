/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_front_back_tests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:11:15 by imicah            #+#    #+#             */
/*   Updated: 2020/10/28 15:21:18 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../catch.hpp"
#include <vector>
#include "vector.hpp"

TEMPLATE_TEST_CASE_SIG("Front back vector", "[vector] [front] [back]", ((typename T, int V), T, V), (int, 21)) {
	ft::vector<T>		ft_vector;
	std::vector<T>		vector;

	for (int i = 0; i < V; ++i) {
		ft_vector.push_back(i);
		vector.push_back(i);
		REQUIRE(ft_vector.back() == vector.back());
		REQUIRE(ft_vector.front() == vector.front());
	}
}
