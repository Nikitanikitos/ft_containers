/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:31:40 by imicah            #+#    #+#             */
/*   Updated: 2020/11/01 13:43:11 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include "catch.hpp"

#include <map>
#include <iostream>
#include "map.hpp"

int 	main() {
	ft::map<int,int>	map;
	auto	it = map.begin();

	while (it != map.end())
		std::cout << it->first << std::endl;
	return (0);
}