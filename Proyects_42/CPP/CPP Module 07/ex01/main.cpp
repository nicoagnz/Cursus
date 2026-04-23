#include "iter.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void increment(int &x){
	x++;
}

void printInt(const int &x){
	cout << x << " ";
}

template <typename T>
void printGeneric(const T &x){
	cout << x << " ";
}

void toUpper(string &strs){
	size_t len = 0;
	while (len < strs.size()){
		strs[len] = std::toupper(strs[len]);
		len++;
	}
}

int main(void){
	int arr[] = {1, 2, 3, 4};
	int len = 4;

	iter(arr, len, increment);

	cout << "After increment: ";
	iter(arr, len, printInt);
	cout << endl;

	cout << "Print whit template: ";
	iter(arr, len, printGeneric<int>);
	cout << endl;

	string strs[] = {"hello", "wordl"};
	int len2 = 2;

	iter(strs, len2, toUpper);
	cout << "Upper strings: ";
	iter(strs, len2, printGeneric<string>);
	cout << endl;

	const int constArr[] = {41, 42, 43, 44};

	cout << "Const array: ";
	iter(constArr, 4, printInt);
	cout << endl;

	return 0;
}