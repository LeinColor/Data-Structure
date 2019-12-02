#pragma once

namespace LU {
	template<typename T>
	class Stack {
	public:
		// default constructor
		Stack();

		// default destructor
		~Stack();

		// stack implements
		void push(T&& value);
		void pop();
		[[nodiscard]] bool empty() const;
		T top() const;
		size_t size() const;

		/*
		bool operator==(const LUStack<T>& lhs, const LUStack<T>& rhs);
		bool operator!=(const LUStack<T>& lhs, const LUStack<T>& rhs);
		bool operator<(const LUStack<T>& lhs, const LUStack<T>& rhs);
		bool operator<=(const LUStack<T>& lhs, const LUStack<T>& rhs);
		bool operator>(const LUStack<T>& lhs, const LUStack<T>& rhs);
		bool operator>=(const LUStack<T>& lhs, const LUStack<T>& rhs);
		*/

	private:
		// to allocate memory for specified type T
		T* data;

		// capacity is maximum count to store data in stack
		size_t capacity;

		// index is the pointer to indicate data
		size_t index;
	};

}