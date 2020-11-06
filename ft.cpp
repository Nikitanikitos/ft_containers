/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:31:40 by imicah            #+#    #+#             */
/*   Updated: 2020/11/06 13:40:43 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include "catch.hpp"

#include <map>
#include <iostream>
#include <map.hpp>

int 	main() {
	ft::map<int,int>	map;
	ft::map<int,int>::iterator	it = map.begin();

	map[3] = 5;
	while (it != map.end())
		std::cout << it->first << std::endl;
	return (0);
}
