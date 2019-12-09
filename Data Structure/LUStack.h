#pragma once
#include <cassert>

namespace LU {
	template<typename T, typename Container = std::allocator<T>>
	class Stack {
	public:
		using value_type			= T;
		using pointer				= T*;
		using const_pointer			= const T*;
		using void_pointer			= void*;
		using const_void_pointer	= const void*;
		using size_type				= std::size_t;
		using difference_type		= std::ptrdiff_t;

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

		static constexpr size_t MAX_CAPACITY = static_cast<size_t>(-1);
		static constexpr size_t INITIAL_CAPACITY = 10;
		static constexpr double EXPAND_FACTOR = 1.5;
	};

	template<typename T>
	inline Stack<T>::Stack() : capacity(INITIAL_CAPACITY), index(static_cast<size_t>(-1))
	{
		data = static_cast<T*>(operator new(sizeof(T) * INITIAL_CAPACITY));
	}

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
			capacity = static_cast<double>(capacity) * EXPAND_FACTOR;
			T* temp = static_cast<T*>(operator new(sizeof(T) * capacity));

			for (size_t i = 0; i < index + 1; i++) {
				temp[i] = std::move(data[i]);
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