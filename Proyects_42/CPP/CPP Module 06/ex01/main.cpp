/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 10:57:09 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/04/22 11:45:03 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.value = 42;

	Data *original = &data;

	uintptr_t raw = Serializer::serialize(original);

	Data *restored = Serializer::deserialize(raw);

	std::cout << "Original pointer:  " << original << std::endl;
	std::cout << "Serialized value:  " << raw << std::endl;
	std::cout << "Restored pointer:  " << restored << std::endl;

	if (original == restored)
		std::cout << "Pointers are equal ✅" << std::endl;
	else
		std::cout << "Pointers are NOT equal ❌" << std::endl;

	std::cout << "Original value:  " << original->value << std::endl;
	std::cout << "Restored value:  " << restored->value << std::endl;

	return 0;
}
