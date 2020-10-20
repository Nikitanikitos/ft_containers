/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:40:41 by imicah            #+#    #+#             */
/*   Updated: 2020/10/20 16:05:12 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "list/list.hpp"

int main() {
	ft::list<int>	qwe(4);
	std::list<int>::iterator 	q;
	ft::list<int>::iterator		it = qwe.begin();

	for (; it != qwe.end(); ++it) {
//		std::cout << *it << std::endl;
	}
	return (0);
}
