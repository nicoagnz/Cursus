/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:45:53 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/04/22 11:45:54 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void){
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(NULL));
		seeded = true;
	}
	int r = std::rand() % 3;
	switch (r) {
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}
