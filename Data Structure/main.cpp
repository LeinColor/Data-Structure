#include <iostream>
#include <stack>
#include "LUStack.h"

int main()
{
	LU::Stack<int> s;

	for (int i = 1; i <= 500; i++) {
		s.push(i);
	}

	while (!s.empty()) {
		std::cout << s.top() << " " << std::endl;
		s.pop();
	}
	return 0;
}