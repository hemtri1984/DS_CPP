/**
* Author: Hemant Tripathi
*/

//This program will convert infix notation to postfix
//Condition: All numbers must be positive

#include <iostream>

using namespace std;

#define MAXSTACKSIZE 10
#define MAXEXPSIZE 30

class StackOperator {
	int top;
	public:
	string postfix;
	char stack[MAXSTACKSIZE];

	StackOperator() {
		top = -1;
		postfix = "";
	}

	int PushToOpStack(char op);
	int PushToPostfix(char op);
	int PopFromOpStack();
	bool Precedence(char op1, char op2); //This will check if op1 precendence is greater than op2 or not
	bool IsOperand(char x);
	bool IsOpStackEmpty();
};

int StackOperator::PushToOpStack(char op) {
	if(top < MAXSTACKSIZE) {//Stack has space, insert the operator
		cout << "Inserted operator into OpStack at positon: " << top << endl;
		//If op is ),}or], then pop all the elements to Postfix until ( will not meet
		if(op == (char)41) {
			cout << "Operator = )";
			while(1) {
				op = PopFromOpStack();
				if(op >= 0) {
					if(op == (char)40) {
						break;
					} else {
						PushToPostfix(op);
					}
				} else {
					return -1;
				}
			}
			return 1;
		} else {
			stack[++top] = op;
			cout << "Operator = " << op << endl;
			//Now check the precedence of top operator vs below operator
			if(top > 0) {
				cout << "Checking operator precedence with " << stack[top-1] << endl;
				bool isLowOrEqual = Precedence(stack[top], stack[top-1]);
				if(isLowOrEqual) {//True, Pop the top and top-1, push top-1 into Postfix and push top back into OpStack, so that top will always be top
					cout << "Lower Precedence" << endl;
					int topElement = PopFromOpStack();
					if(topElement >= 0) {
						PushToPostfix(PopFromOpStack());
						cout << "Pushing back top element to OpStack: " << (char)topElement << endl;
						PushToOpStack((char)topElement);
					} else {
						cout << "Cannot perform operation. OpStack is emptty!"<<endl;
						return -1;
					}
				} else {
					cout << "Higher Precedence"<<endl;
					return 1;
				}
			} else {
				cout << "Only one operator in stack at top: " << stack[top] << endl;
				return 1;
			}
		}
	} else { //show warning message of stack overflow
		cout << "Operator Buffer Overflow. Cannot perform this operation" << endl;
		return -1;
	}
}

int StackOperator::PushToPostfix(char op) {
	postfix = postfix + op;
	cout << "Postfix String : " << postfix << endl;
}

int StackOperator::PopFromOpStack() {
	if(top >=0) {
		cout << "Popping operator: "<< stack[top];
		return stack[top--];
	} else {
		cout << "Operator stack is empty" << endl;
		return -1;
	}
}

bool StackOperator::Precedence(char op1, char op2) {
	cout << "Checking precedence for "<<op1<<" and " << op2<<endl;
	if((int)op1 == 40 || (int)op2 == 40  || (int)op1 == 36 || (int)op1 == 94) {
		return false;
	} else if(((int)op1 == 42 || (int)op1 == 47) && ((int)op2 == 36 || (int)op2 == 94 || (int)op2 == 42 || (int)op2 == 47)) {
		return true;
	} else if(((int)op1 == 43 || (int)op1 == 45) && ((int)op2 == 36 || (int)op2 == 94 || (int)op2 == 42 || (int)op2 == 47 || (int)op1 == 43 || (int)op1 == 45)) {
		return true;
	} else {
		return false;
	}
}

bool StackOperator::IsOperand(char x) {
	if(((int)x >= 48 && (int)x <= 57) || ((int)x >= 65 && (int)x <= 90) || ((int)x >= 97 && (int)x <= 122)) {
		return true;
	} else {
		return false;
	}
}

bool StackOperator::IsOpStackEmpty() {
	if(top >= 0) {
		return false;
	} else {
		return true;
	}
}


int main() {
	class StackOperator stackOperator;
	string input;
	char inputarr[50];
	bool isValid = true;
	cout << "Enter any expression to convert to postfix:" << endl;
	cin >> input;

	char *ptr;
	int counter = 0;

	for(auto x:input) {
		if(x == '\0') {
			break;
		}
		inputarr[counter++] = x;
	}
	inputarr[counter] = '\0';

	ptr = inputarr;

	while(*ptr != '\0') {
		cout << "next character: "<<*ptr << endl;
		bool isOperand = stackOperator.IsOperand(*ptr);
		if(isOperand > 0) {//Operand
			cout << "This is and operand. Send to Postfix String." << endl;
			stackOperator.PushToPostfix(*ptr);
		} else { //Operator
			cout << "This is an Operator. Send to Operator Stack." << endl;
			int result = stackOperator.PushToOpStack(*ptr);
			if(result <= 0) {//some error occured. Stop the process
				isValid = false;
				break;
			}
		}
		ptr++;
	}
	if(isValid) {//Append stack operators into postfix string
		cout << "==============================================="<<endl;
		while(!stackOperator.IsOpStackEmpty()) {
			char nextChar = (char)stackOperator.PopFromOpStack();
			cout << "Making Postfix. Next Popped character : " << nextChar << endl;
			stackOperator.postfix += nextChar;
		}
	}

	cout << "Postfix value: " << stackOperator.postfix << endl;

}
