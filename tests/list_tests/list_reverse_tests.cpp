/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse_tests.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:45:03 by imicah            #+#    #+#             */
/*   Updated: 2020/10/25 15:48:18 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include "../catch.hpp"

TEMPLATE_TEST_CASE_SIG("Reverse lists with size = V", "[list] [swap]", ((typename T, int V), T, V), (int, 13)) {
	ft::list<T>							ft_list;
	std::list<T>						list;
	typename ft::list<T>::iterator		ft_it;
	typename std::list<T>::iterator		it;

	for (int i = 0; i < V; ++i) {
		ft_list.push_back(i);
		list.push_back(i);
	}

	it = list.begin();
	for (ft_it = ft_list.begin(); ft_it != ft_list.end(); ++ft_it) {
		REQUIRE(*ft_it == *it);
		++it;
	}
}
