#pragma once
#include <cassert>

namespace LU {
	template<typename T>
	class Stack {
	public:
		// default constructor
		Stack();

		// default destructor
		~Stack();

		// stack implements
		void push(const T& value);
		void pop();
		[[nodiscard]] bool empty() const;
		T top() const;
		size_t size() const;

		void print() const {
			std::cout << capacity << " " << index << std::endl;
		}

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

		const size_t MAX_CAPACITY = static_cast<size_t>(-1);
	};

	template<typename T>
	inline Stack<T>::Stack() : data(new T[10]), capacity(10), index(static_cast<size_t>(-1))
	{}

	template<typename T>
	inline Stack<T>::~Stack() 
	{
		if (data != nullptr)
			delete[] data;
	}

	template<typename T>
	inline void Stack<T>::push(const T& value)
	{
		if (index != MAX_CAPACITY && capacity <= index + 1) {
			capacity *= 2;
			T* temp = new T[capacity];

			for (size_t i = 0; i < index; i++) {
				temp[i] = data[i];
			}

			delete[] data;
			data = temp;
		}

		data[++index] = value;
	}

	template<typename T>
	inline void Stack<T>::pop()
	{
		index--;
	}

	template<typename T>
	inline bool Stack<T>::empty() const
	{
		// a type of index is size_t, so negative integer occurs underflow
		// static_cast<size_t>(-1) check underflow, it means max number in size_t type
		return index == MAX_CAPACITY;
	}

	template<typename T>
	inline T Stack<T>::top() const
	{
		assert(index != MAX_CAPACITY);
		return data[index];
	}

	template<typename T>
	inline size_t Stack<T>::size() const
	{
		return empty() ? 0 : index + 1;
	}

}