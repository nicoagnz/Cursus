#pragma once

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int value){
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::exception();
	
	return it;
}
