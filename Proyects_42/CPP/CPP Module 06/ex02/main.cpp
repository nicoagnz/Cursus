/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:46:03 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/04/22 12:06:57 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "generate.hpp"
#include "identify.hpp"

using std::cout;
using std::endl;

int main() {
	std::srand(std::time(NULL));

	Base *obj = generate();

	cout << "Pointer identify: ";
	identify(obj);

	cout << "Reference identify: ";
	identify(*obj);

	delete obj;
	return 0;
}

