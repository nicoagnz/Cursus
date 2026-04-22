/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:45:58 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/04/22 11:45:59 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

using std::cout;
using std::endl;

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		cout << "A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "C" << endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		cout << "A" << endl;
		return ;
	}
	catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		cout << "B" << endl;
		return ;
	}
	catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		cout << "C" << endl;
		return ;
	}
	catch (...) {}

}
