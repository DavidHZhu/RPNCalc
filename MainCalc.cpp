/***********************************************************************************************************************
 *	Name:   David Zhu                                                        
 *	Course: ICS4U                                                              
 *	Date: March 24th, 2017	                   		                          
 *	                                                                          
 *	Purpose: Reverse Polish Notation Calculator		      				 	 
 *	                                                                         
 *	Usage: 	Performs basic calculator functions in post-fix, using stacks and
 *			classes.														 *
 *			Process:														 *
 *			1. Takes input, adds onto stack - repeat						 
 *			2. On an operator, call function to perform method; returns 0	 
 *				on successful and push(pop) answer onto stack, returns 		 
 *				specific error otherwise									 
 *			3. Print out answer with getTop()								 
 *			4. (Graphics) With GUI, have user inputs added to seperate box	 
 *				displaying the stack. Message box for Stack clear or errors	 
 *	       														    		     
 *	                                                                         
 *	Revision History:	- Header and definition finished. 					 
 *				operations work, added check isValid for 2 elements  
 *				the stack.											 
 *				- Changed bool methods to int, clearer errors			 
 *				- Fixed Negative numbers.								 
 *				- Added GUI.txt										 
 *				- Formatting Changes				                   	   
 *	                                                                         
 *	Known Issues: edit printStack, not efficient						     
 *	                                                                           
 *************************************************************************************************************************/
 
 #include <iostream>
 #include <fstream>
 #include <cctype>
 #include <iomanip>
 #include <windows.h>
 #include <locale>
 #include <stdlib.h>
 #include "Classes.h"
 using namespace std;
 
 // Prototypes
 void operation(char input[], Operator& RPN);
 void printAns(int validAns, Operator& RPN);
 void printStack(int validAns, Operator& RPN);
 bool printGUI();
 void gotoxy(short x, short y);
 
 // Main Program
 int main(){
 	
 	// Instantiate RPN
 	Operator RPN;
	
	// Create graphics
	if (!printGUI())
		cerr << "GUI.txt was not found: check directory ";
	
		
 	// User Input
	char input[8];
	
	// Take input 
	while (input[0] != 'n'){
		gotoxy(10,3);
		cin >> input;
		gotoxy(10,3);
		cout << "       ";
		// Exits program with return value 0
		if (input[0] == 'n'){
			gotoxy(1,20);
			break;
		}
		operation(input, RPN);
	}
	
	return 0;
}
	

// Function that determines operation when called
void operation(char input[], Operator &RPN){
	
	// Check if operation is successfull, errors
	int validAns; 
	
	// Determines operation, if the input is not a digit
	 if (!isdigit(input[0])){
		switch(input[0]){
			
			// Clear stack
			case 'c':
				RPN.clear();
				system("CLS");
				printGUI();
				validAns = 1;
				break;
				
			// Addition
			case '+':
				validAns = RPN.add();
				break;
				
			// Subtraction	
			case '-':	
				// Checks if its a negative number
				if (!isdigit(input[1])){
					validAns = RPN.sub();
				} else {
					validAns = 0;
					RPN.push(atof(input));	
				}
				break;	
					
			// Multiplication	
			case '*':	
				validAns = RPN.mul();
				break;
			
			// Division
			case '/':
				validAns = RPN.div();
				break;
			
			// Raise to power	
			case '^':
				validAns = RPN.exp();
				break;
			
			// Square root	
			case 'r': 		
				validAns = RPN.root();
				break;
				
			// If input is neither operator	nor number
			default:
				validAns = 2;
		}
	 }
	 
	 // If input is a number:
	 else {
	 	
		 // Converts array into float, and places on stack
		 RPN.push(atof(input));
		 
		 // No operation, puts on stack since input is a number
		 validAns = 0;
	 }
 	
 	// Prints Answer to screen
   	 printAns(validAns, RPN);
	 //printStack(validAns, RPN);
 	
 }

// Prints out various error responses or answer (top of stack):
void printAns(int validAns, Operator &RPN){
	
	// Switch for Output
	switch(validAns){
		case 0:
	 		gotoxy(10,7);
			cout << RPN.getTop() << "     " << setw(8) << endl;
			
		//	printStack(validAns, RPN);
			break;
		case 1:
			gotoxy(24,18);
			cout << "Stack Cleared                 		 " << endl;
			break;
		case -1:
			gotoxy(24,18);	
			cout << "Error: Not Enough Operands             " << endl;
			break;
		case -2:
			gotoxy(24,18);
			cout << "Error: Divide by Zero                 " << endl;
			break;
		case -3:
			gotoxy(24,18);
			cout << "Error: Square Root of Negative          " << endl;
			break;
		default:
			gotoxy(24,18);
			cout << "Error: Invalid Operator                 " << endl;
	}
	
}

// Formatting; prints out numbers into stack: REQUIRES EDITING
void printStack(int validAns, Operator& RPN){
	

 	for (int i = 0; i < RPN.topPos(); i++){
 		gotoxy(7,7+i);
 		cout << RPN.dataStack(i) << endl;
	 }
 	
 }

// Moves output/input:
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Default GUI:
bool printGUI() {
	ifstream fin;
	fin.open("GUI.txt"); 
	
	if (!fin.is_open()){
		return false;
	}
	else {
		cout << fin.rdbuf();
		fin.close();
		return true;
	}
}
