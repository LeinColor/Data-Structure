#pragma once

template<typename T>
class LUStack {
public:
	// default constructor
	LUStack(int _size) : size(_size) {}
	
	// destory
	~LUStack() {}

	// stack implements
	void push(T element);
	void pop();
	T top() const;
	size_t getSize() const;

private:
	size_t size;
	size_t capacity;
	size_t index;
};