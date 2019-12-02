#include <iostream>
#include "LUStack.hpp"

int main()
{
	LU::Stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);

	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
	return 0;
}