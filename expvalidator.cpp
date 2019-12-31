/**
* Author: Hemant Tripathi
*/

#include <iostream>
using namespace std;

#define MAXSIZE 20

class Expression {
	int top;
	public:
	char expression[MAXSIZE];

	Expression() {
		top = -1;
	}

	bool Push(char x);
	bool Pop(char x);
	char GetTop();
	bool IsEmpty();
};

bool Expression::Push(char x) {
	if(top >= MAXSIZE) {
		cout << "Buffer Full Error" << endl;
		return false;
	} else {
		cout << "Entering element into stack : " << x << endl;
		expression[++top] = x;
		return true;
	}
}


bool Expression::Pop(char x) {
	cout << "Top Value = " << top << endl;
	cout << "Popping item = "<<x<<endl;
	if(top < 0) {
		cout << "Stack is Empty" << endl;
		return false;
	} else {
		char poppeditem = expression[top];
		if((x == ')' && poppeditem == '(') || (x == '}' && poppeditem == '{') || (x == ']' && poppeditem == '[')) {
			//Pop an item
			top--;
			return true;
		} else {
			return false;
		}
	}
}


char Expression::GetTop() {
	if(top < 0) {
		return 'x';
	} else {
		return expression[top];
	}
}

bool Expression::IsEmpty() {
	if(top < 0) {
		return true;
	} else {
		return false;
	}
}


int main() {
	class Expression expression;
	string input;
	char inputarr[50];
	bool isValid = true;
	cout << "Write an expression to validate" << endl;
	cin >> input;

	char *ptr;

	int counter = 0;
	for(auto x: input) {
		if(x == '\0')
			break;
		inputarr[counter++] = x;
	}
	inputarr[counter] = '\0';

	ptr = inputarr;

	while(*ptr != '\0') {
		cout << "next character: "<<*ptr << endl;
		if(*ptr == '(' || *ptr == '{' || *ptr == '[') {
			//push the character into stack
			bool isPushed = expression.Push(*ptr);
			if(!isPushed) {
				isValid = false;
				cout << "Buffer Stack overflow. Cannot enter any more items";
			}
		}

		if(*ptr == ')' || *ptr == '}' || *ptr == ']') {
			//pop the item
			bool result = expression.Pop(*ptr);
			cout << "Popped Result: "<< result << endl;
			if(result != 1) {
				isValid = false;
			}
		}
		ptr++;
	}
	
	cout << "isValid = " << isValid << endl;
	if(isValid == 1 && expression.IsEmpty() == 1) {
		cout << "valid expression!" << endl;
	} else {
		cout << "Invalid expression!" << endl;
	}
}
