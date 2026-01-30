/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:59:10 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/01/29 10:54:01 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	int i = 0;

	if (n <= 0)
		return NULL;
	Zombie* horde = new Zombie[n];
	while (i < n)
	{
		horde[i].setName(name);
		i++;
	}
	return horde;
}
