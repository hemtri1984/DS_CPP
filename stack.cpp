//This is a Stack program in CPP
#include <iostream>
using namespace std;

#define MAXSTACKSIZE 10

class Stack {
	int top;
	public:
	int mystack[MAXSTACKSIZE];

	Stack(){
		top = -1;
	}

	bool Push(int x);
	bool Pop();
	void Peek();
	void Display();
};

bool Stack::Push(int x) {
	if(top >= MAXSTACKSIZE-1) {
		cout << "Stack is full" << endl;
		cout << "Top = " << top << endl;
		return false;
	} else {
		cout << "Inserting element "<<x<<" into stack" << endl;
		mystack[++top] = x;
		cout << "insert at position = "<< top << endl;
		return true;
	}
}

bool Stack::Pop() {
	if(top < 0) {
		cout << "Stack is empty. Cannot popped" << endl;
		return false;
	} else {
		cout << "Popped item is : " << mystack[top--] << endl;
		return true;
	}
}

void Stack::Peek() {
	if(top < 0) {
		cout << "Empty Stack, no peek element"  << endl;
	} else {
		cout << "Peek Element is: " << mystack[top] << endl;
	}
}

void Stack::Display() {
	if(top < 0) {
		cout << "Empty Stack, no element to display" << endl;
	} else {
		for(int i=0; i < top+1; i++) {
			cout << "  " << mystack[i];
		}
	}
	cout << endl;
}

int main() {
	int option;
	bool exit = false;

	class Stack stack;
	
	while(1) {
		if(exit) {
			break;
		}
		
		cout << "Select an options:" << endl;
		cout << "1. Push an element" << endl;
		cout << "2. POP and element\n";
		cout << "3. Peek element\n";
		cout << "4. Display Stack\n";
		cout << "5. Exit\n";

		cin >> option; //Input user selection

		switch(option) {
			case 1:
				int number;
				cout << "Please enter a number to push into stack";
				cin >> number;
				stack.Push(number);
			break;
			
			case 2:
			cout << "Popping and element from stack";
			stack.Pop();
			break;
			
			case 3:
			cout << "Peek element is: ";
			stack.Peek();
			break;
			
			case 4:
			cout << "The stack status is: ";
			stack.Display();
			break;
			
			case 5:
			exit = true;
			cout << "Exiting from the program";
			break;
		}

	}
}
