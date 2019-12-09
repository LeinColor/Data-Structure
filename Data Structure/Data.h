#pragma once
#include <iostream>

class Data {
public:
	int a = 1;
	Data() {
	//	std::cout << "Default Constructor" << std::endl;
		for (int i = 1; i <= 100000; i++) {
			a *= 2;
		}
	}
};