#pragma once

template <typename T>
void iter(T *array, int len, void (*func)(T &)){
	int i = 0;
	while (i < len)
		func(array[i++]);
}

template <typename T>
void iter(const T *array, int len, void (*func)(const T &)){
	int i = 0;
	while (i < len)
		func(array[i++]);
}
