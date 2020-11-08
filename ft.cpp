/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:31:40 by imicah            #+#    #+#             */
/*   Updated: 2020/11/06 22:08:38 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include "catch.hpp"

#include <map>
#include <iostream>
#include <map.hpp>
#include "vector.hpp"
#include "list.hpp"

int 	main() {
	ft::list<int>	qwe;

	for (int i = 0; i < 6; ++i) {
		if (i % 2)
			qwe.push_back(i);
		else
			qwe.push_back(-i);
	}
	qwe.sort();
	return (0);
}
