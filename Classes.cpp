// CPP file for Stack class definitions
#include <iostream>
#include <stdlib.h>
#include "Classes.h"
#include <math.h>
#define PI 3.14159265
using namespace std;

// Initialize stack as empty:
Stack::Stack(){
	
	//empty stack, starts at -1:
	top = -1;
	
	for (int i = 0; i < 20; i++) {
		data[i] = 0;
	}
	
}

// Adds float operand to stack:
void Stack::push(float f){
	
	// increments the position of top:
	top++;
	data[top] = f;
	
}

// Remove top of stack:
float Stack::pop(){
	
	return data[top--];	
	
}

// Position of top:
float Stack::topPos(){
	
	return top;
	
}

// Returns numbers inside stack

float Stack::dataStack(int i){
	
	return data[i];

}

// Returns top of stack:
float Stack::getTop() {
	
	return data[top];
	
}

// Checks Stack for at least two elements and returns:
bool Stack::isValid(){
	
	return (top > 0);
	
	
}

// Checks if Stack is empty
bool Stack::isEmpty(){
	
	return (top == -1);
	
}


//*****************************************************************************************************************
// Calculator definitions: First checks if stack exists, then pushes answer onto stack and returns if successfull

/* Errors
	Return 0 = Success, is Valid
	Return -1 = Empty Stack or Not enough items on the stacks
	Return -2 = Divide by 0
	Return -3 = Negative Root
	Return 1 = Clear Stack
*/

// Clear method:
void Operator::clear(){
	
	top = -1;
	for (int i = 0; i < 20; i++) {
		data[i] = 0;
	}	
	
	
}

// Add method:
int Operator::add(){
	
	if (isValid()){
		push(pop() + pop());
		return 0;
	} else {
		return -1;
	}
	
}

// Subtraction method:
int Operator::sub(){
	
	// Re-arrange to make sure order of numbers is correct; non-communitive property 
	if (isValid()){
		float subtractor = pop();
		float subtrahend = pop();
		push(subtrahend - subtractor);
		return 0;
	} else {
		return -1;  
	}
	
}

// Multiplication method:
int Operator::mul(){
	
	if (isValid()){
		push(pop() * pop());
		return 0;
	} else {
		return -1;
	}
	
}

// Division method: non-communitive property
int Operator::div(){
	
	if (isValid()){
		float divisor = pop();
		float dividend = pop();
		// Checks for divide by 0:	
		if (divisor != 0){
			push(dividend / divisor);
			return 0;
		} else if (divisor == 0){
			return -2;
		}
	} else {
		return -1;
	}
	
}


// Raise to power method:
int Operator::exp(){
	
	if (isValid()){
		float exponent = pop();
		float base = pop();
		push(pow(base, exponent));
		return 0;
	} else {
		return -1;
	}
		
}

// SquareRoot method:
int Operator::root(){
	
	if (getTop() < 0){
		return -3;
	} else if (isEmpty()){
		return -1;
	} else {
		push(sqrt(pop()));
		return 0;
	}
	
}
