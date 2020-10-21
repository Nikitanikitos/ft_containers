/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:40:41 by imicah            #+#    #+#             */
/*   Updated: 2020/10/21 15:56:05 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "list/list.hpp"

int main() {

	ft::list<int>		list;
//	ft::list<char>::iterator	begin = list.begin();
//	ft::list<char>::iterator	end = list.end();
//
	ft::list<int>		list_2;

	list.push_back(2);
	list.push_back(6);

//	list.push_front()
	list_2 = list;
	return (0);
}
