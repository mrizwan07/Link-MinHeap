#include <iostream>
#ifndef STACK_H
#define STACK_H
template <typename T>
class Stack
{
	T* stack;
	int size;
	int top;
public:
	Stack(int s = 10)
	{
		size = s;
		stack = new T[size];
		top = -1;
	}
	~Stack()
	{
		if (stack)
		{
			delete[] stack;
			stack = nullptr;
		}
	}
	void push(T val)
	{
		if (isFull())
		{
			reSize();
		}
		stack[++top] = val;
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "Stack is empty";
		}
		else
		{
			--top;
		}
	}
	int topIndex()
	{
		return top;
	}
	T topValue()
	{
		return stack[top];
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void reSize()
	{
		int newSize = size * 2; 
		T* newStack = new T[newSize]; 
		for (int i = 0; i <= top; ++i) // Copying elements from the old stack to the new stack
		{
			newStack[i] = stack[i];
		}
		delete[] stack;
		stack = newStack; 
		size = newSize; 
	}

	bool isFull()
	{
		if (top == size - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
#endif // !1