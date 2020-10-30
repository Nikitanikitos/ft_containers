/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:31:40 by imicah            #+#    #+#             */
/*   Updated: 2020/10/30 19:03:57 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include "catch.hpp"
#include "map.hpp"

int 	main() {
	ft::map<int, int>	map;
	ft::map<int, int>::iterator 	it;

	it.operator->();
	map.insert(std::make_pair(13, 42));
	map.insert(std::make_pair(6, 42));
	map.insert(std::make_pair(2, 42));
	map.insert(std::make_pair(42, 42));
	map.insert(std::make_pair(21, 42));

	return (0);
}