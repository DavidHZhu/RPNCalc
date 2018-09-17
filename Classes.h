// Stack Class Header for RPN
// If not defined previously:

#ifndef CLASSES_H 
#define CLASSES_H
#include <iostream>
using namespace std;
// Stack class:
class Stack{
	
	protected: 
		float data[20];
		int top;
	public:
		Stack();
		void push(float f);
		float pop();
		float getTop();
		float dataStack(int i);
		float topPos();
		bool isValid();
		bool isEmpty();		
		~Stack(){}
};

// Derived classes:
class Operator : public Stack {
	
	public:
		void clear();
		int add();
		int sub();
		int mul();
		int div();
		int exp();
		int root();	
	
};

#endif
