#include <iostream>
#include <stack>
#include "LUStack.h"

int main()
{
	LU::Stack<int> s;
	int p = 1;
	s.push(p);
	s.push(2);
	s.push(3);

	while (!s.empty()) {
		std::cout << s.top() << " " << std::endl;
		s.pop();
	}
	return 0;
}