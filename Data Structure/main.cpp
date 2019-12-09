#include <iostream>
#include <stack>
#include <chrono>
#include "Data.h"
#include "LUStack.h"
using namespace std;

constexpr int LOOP_COUNT = 10000000;
using T = int;
int main()
{
	LU::Stack<T> s;
	stack<T> stlS;
	std::cout << "========== My stack ==========" << std::endl;
	{
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 1; i <= LOOP_COUNT; i++) {
			s.push(T());
		}

		while (!s.empty()) {
			s.pop();
		}
		std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
	
		std::cout << "elapsed time: " << sec.count() << " seconds" << std::endl;
	}

	std::cout << "========== STL stack ==========" << std::endl;

	{
		std::chrono::system_clock::time_point start2 = std::chrono::system_clock::now();
		for (int i = 1; i <= LOOP_COUNT; i++) {
			stlS.push(T());
		}

		while (!stlS.empty()) {
			stlS.pop();
		}
		std::chrono::duration<double> sec2 = std::chrono::system_clock::now() - start2;

		std::cout << "elapsed time: " << sec2.count() << " seconds" << std::endl;
	}
	

	return 0;
}