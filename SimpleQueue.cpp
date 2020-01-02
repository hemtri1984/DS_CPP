/**
 * Author: Hemant Tripathi
 */

#include <iostream>

using namespace std;

#define MAXQUEUESIZE 10

class Queue {
	int front, rear;

	public:
	int myqueue[MAXQUEUESIZE];

	Queue() {
		front = 0;
		rear = -1;
	}

	bool insertOp(int element);
	bool removeOp();
	int getFirstElement();
	int getLastElement();
	bool isEmpty();
	bool isOverflow();
	void showElements();
	int totalCount();
};

bool Queue::insertOp(int element) {
	if(isOverflow()) {
		cout << "Queue is overflow. Cannot insert any element" << endl;
		return false;
	} else {
		myqueue[++rear] = element;
		cout << "Inserted element " << element << " into queue, at position "<< rear << endl;
		return true;
	}
}

bool Queue::removeOp() {
	if(isEmpty()) {
		cout << "Empty Queue" << endl;
		return false;
	} else {
		int poppedElement = myqueue[front++];
		cout << "Element " << poppedElement << " is popped from position << " << front << endl;
		return true;
	}
}

int Queue::getFirstElement() {
	if(isEmpty()) {
		cout << "Empty Queue" << endl;
		return -1;
	} else {
		return myqueue[front];
	}
}

int Queue::getLastElement() {
	if(isEmpty()) {
		cout << "Empty Queue" << endl;
		return -1;
	} else {
		return myqueue[rear];
	}
}

bool Queue::isEmpty() {
	if(rear < front) {
		return true;
	} else {
		return false;
	}
}

bool Queue::isOverflow() {
	if(rear < MAXQUEUESIZE-1) {
		return false;
	} else {
		return true;
	}
}

void Queue::showElements() {
	if(isEmpty()) {
		cout << "Empty Queue" << endl;
	} else {
		for(int i=front; i <= rear; i++) {
			cout << "Element: " << myqueue[i] << "; Position: " << i << endl;
		}
	}
}

int Queue::totalCount() {
	return rear - front + 1;
}


int main() {
	class Queue queue;
	bool exit = false;
	cout << "########## Starting Simple Queue Operation #############" << endl;
	while(1) {
		if(exit) {
			cout << "Aborting the program" << endl;
			break;
		}
		cout << "Select an option:" << endl;
		cout << "1. Insert an element" << endl;
		cout << "2. Remove an element" << endl;
		cout << "3. Get First Element of Queue" << endl;
		cout << "4. Get Last Element of Queue" << endl;
		cout << "5. Show All Element of Queue" << endl;
		cout << "6. Exit"<<endl;

		int choice = -1;
		cin >> choice;
	
		switch(choice) {
			case 1:
				int element;
				cout << "Please enter a number to insert into the queue" << endl;
				cin >> element;
				queue.insertOp(element);
			break;

			case 2:
			{
				bool result = queue.removeOp();
				if(result) {
					cout << "Element removed from queue successfully!" << endl;
				} else {
					cout << "Cannot remove element from queue!" << endl;
				}
			}
			break;
			
			case 3:
			{
				int firstElement = queue.getFirstElement();
				if(firstElement >= 0) {
					cout << "First Element of Queue is: " << firstElement << endl;
				}
			}
			break;	

			case 4:
			{
				int lastElement = queue.getLastElement();
				if(lastElement >= 0) {
					cout << "Last Element of Queue is: " << lastElement << endl;
				}
			}
			break;

			case 5:
			queue.showElements();
			break;

			case 6:
			exit = true;
			break;
		}
	}
}
