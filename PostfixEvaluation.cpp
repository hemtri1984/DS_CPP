/**
 * Author: Hemant Tripathi
 */

//This is a program to calculate Postfix Expression and show the result.

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MAXSTACKSIZE 10
#define MAXEXPSIZE 30

class PostfixEvaluation {
	int top;
	
	public:
	char stack[MAXSTACKSIZE];

	PostfixEvaluation() {
		top = -1;
	}

	bool PushToStack(char op);
	int PopFromStack();
	bool IsOperand(char op);
	bool IsOperator(char op);
};

bool PostfixEvaluation::PushToStack(char op) {
	if(top >= MAXSTACKSIZE) {
		cout << "Stack Buffer Overflow."<<endl;
		return false;
	} else {
		stack[++top] = op;
		cout << "Element Added into stack at position "<<top<<endl;
	}
}

int PostfixEvaluation::PopFromStack() {
	if(top < 0){
		cout << "Stack is Empty. Pop operation aborted." << endl;
		return -1;
	} else {
		return stack[top--];
	}
}

bool PostfixEvaluation::IsOperand(char x) {
	if((int)x >= 48 && (int)x <= 57) {
		return true;
	} else {
		return false;
	}
}

bool PostfixEvaluation::IsOperator(char x) {
	if((int)x==36 || (int)x==94 || (int)x==43 || (int)x==45 || (int)x==42 || (int)x==47) {
		return true;
	} else {
		return false;
	}
}

int main() {
	class PostfixEvaluation postfixEvaluator;
	string input;
	char inputarr[MAXEXPSIZE];
	bool isValid = true;
	cout << "Enter any postfix expression to evaluate"<<endl;
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

	while (*ptr != '\0') {
		cout << "Next Character : " << *ptr << endl;
		if(postfixEvaluator.IsOperand(*ptr)) {//enter into stack
			postfixEvaluator.PushToStack(*ptr);
		}else if(postfixEvaluator.IsOperator(*ptr)) {//Evaluate the expression and push into stack
			int secondOperand = stoi(postfixEvaluator.PopFromStack()); //convert string to int
			int firstOperand = stoi(postfixEvaluator.PopFromStack());
			int result;
			//do the operation
			switch(*ptr) {
				case '$':
				case '^':
					result = pow(firstOperand, secondOperand);
					break;

				case '+':
					result = firstOperand + secondOperand;
					break;

				case '-':
					result = firstOperand - secondOperand;
					break;

				case '*':
					result = firstOperand * secondOperand;
					break;

				case '/':
					result = firstOperand/secondOperand;
					break;
			}
			postfixEvaluator.PushToStack(to_string(result));
		} else {//unidentified character. Skip the operation
			continue;
		}
		ptr++;
	}

	//Now Pop the last character from Stack and show it as a result.
	cout << "Evaluation Result = " << postfixEvaluator.PopFromStack() << endl;
}
