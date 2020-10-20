/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:40:41 by imicah            #+#    #+#             */
/*   Updated: 2020/10/20 17:20:55 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "list/list.hpp"

int main() {
	ft::list<int>	qwe(10);
	std::list<int>::iterator 	q;
	ft::list<int>::iterator		it = qwe.begin();
	ft::list<int>::reverse_iterator	reverse_it = qwe.rbegin();

	for (; it != qwe.end(); it++) {
		std::cout << "ky" << std::endl;
	}
	++reverse_it;
	for (; reverse_it != qwe.rend(); reverse_it++) {

	}
	return (0);
}
