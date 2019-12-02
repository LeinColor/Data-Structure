#include "LUStack.hpp"

namespace LU {
	template<typename T>
	Stack<T>::Stack() : data(new T[10]), capacity(10), index(static_cast<size_t>(-1))
	{}

	template<typename T>
	Stack<T>::~Stack() {
		delete[] capacity;
	}

	template<typename T>
	void Stack<T>::push(T&& value) {
		if (capacity <= index) {
			capacity *= 2;
			T* temp = new T[capacity];

			for (size_t i = 0; i < index; i++) {
				temp[i] = data[i];
			}

			delete[] data;
			data = temp;
		}

		data[index++] = value;
	}

	template<typename T>
	void Stack<T>::pop() {
		index--;
	}

	template<typename T>
	[[nodiscard]]
	bool Stack<T>::empty() const {
		// a type of index is size_t, so negative integer occurs underflow
		// static_cast<size_t>(-1) check underflow, it means max number in size_t type
		return index == static_cast<size_t>(-1);
	}

	template<typename T>
	T Stack<T>::top() const {
		return T[index];
	}

	template<typename T>
	size_t Stack<T>::size() const {
		return (empty() == static_cast<size_t>(-1)) ? 0 : index + 1;
	}
}