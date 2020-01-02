/**
 * Author: Hemant Tripathi
 */

#include <iostream>

using namespace std;

#define MAXQSIZE 5

class CircularQueue {
	int front, rare;

	public:
	int cqueue[MAXQSIZE];

	CircularQueue() {
		front = rare = MAXQSIZE - 1;
	}

	bool insertOp(int element);
	bool removeOp();
	int getFirstElement();
	int getFirstElementPosition();
	int getLastElement();
	int getLastElementPosition();
	bool isEmpty();
	bool isOverflow();
	void showElements();
	int totalCount();

};

bool CircularQueue::insertOp(int element) {
	if(isOverflow()) {
		cout << "Queue is overflow! Cannot insert.";
		return false;
	}
	if(rare == MAXQSIZE-1 && (front != 0)) {
		rare = 0;
	} else {
		rare++;
	}
	cqueue[rare] = element;
	cout << "element " << element << " inserted at position " << rare << endl;
	return true;
}

bool CircularQueue::removeOp() {
	if(isEmpty()) {
		cout << "cqueue is empty" << endl;
		return false;
	}
	if(front == MAXQSIZE-1) {
		front = 0;
	} else {
		front++;
	}
	cout << "popped item " << cqueue[front] << " from the queue" << endl;
	return true;
}

int CircularQueue::getFirstElement() {
	if(isEmpty()) {
		cout << "Empty Queue!" << endl;
		return -1;
	} 
	if(front == MAXQSIZE-1) {
		return cqueue[0];
	} else {
		return cqueue[front+1];
	}
}

int CircularQueue::getFirstElementPosition() {
	if(isEmpty()) {
		return -1;
	}
	if(front == MAXQSIZE-1) {
		return 0;
	} else {
		return front+1;
	}
}

int CircularQueue::getLastElement() {
	if(isEmpty()) {
		cout << "Empty Queue!" << endl;
		return -1;
	} 
	
	return cqueue[rare];
}

int CircularQueue::getLastElementPosition() {
	if(isEmpty()) {
		return -1;
	}
	return rare;
}

bool CircularQueue::isEmpty() {
	if(front == rare) {
		return true;
	} else {
		return false;
	}
}

bool CircularQueue::isOverflow() {
	if((front-rare == 1) || (rare-front == MAXQSIZE-1)) {
		return true;
	} else {
		return false;
	}
}

void CircularQueue::showElements() {
	if(rare < front) {
		for (int i = front+1; i < MAXQSIZE; i++) {
			cout << "Element " << cqueue[i] << " at position " << i << endl;
		}
		for (int i = 0; i <= rare; i++) {
			cout << "Element " << cqueue[i] << " at position " << i << endl;
		}
	} else if(front < rare) {
		for(int i = front+1; i <= rare; i++) {
			cout << "Element " << cqueue[i] << " at position " << i << endl;
		}
	} else {
		cout << "No Element Found! Empty stack.";
	}
}

int CircularQueue::totalCount() {
	if(rare < front) {
		return MAXQSIZE - front + rare;
	} else if(front < rare) {
		return rare - front;
	} else {
		return 0;
	}
}


int main() {
	class CircularQueue cQueue;
	bool exit = false;
	cout << "########## Starting Circular Queue Operation ###########";
	while(1) {
		if(exit) {
                        cout << "Aborting the program" << endl;
                        break;
                }
		cout << "Select an Option: " << endl;
		cout << "1. Insert An Element" << endl;
		cout << "2. Remove and Element" << endl;
		cout << "3. Get First Element of Queue" << endl;
		cout << "4. Get First Element Position in Queue" << endl;
		cout << "5. Get Last Element of Queue" << endl;
		cout << "6. Get Last Element Position in Queue" << endl;
		cout << "7. Get Total Number of Element In Queue" << endl;
		cout << "8. Show all element of queue" << endl;
		cout << "9. Exit" << endl;

		int choice = -1;
		cin >> choice;

		switch(choice) {
			case 1:
				int element;
				cout << "Please enter an element to insert into the queue" << endl;
				cin >> element;
				cQueue.insertOp(element);
				break;

			case 2:
				cQueue.removeOp();
				break;

			case 3:
				int firstElement; 
				firstElement = cQueue.getFirstElement();
				if(firstElement >= 0) {
					cout << "First Element of Queue is: " << firstElement << endl;
				} else {
					cout << "No Element Found!" << endl;
				}
				break;

			case 4:
				cout << "First Element Position is: "<< cQueue.getFirstElementPosition() << endl;
				break;

			case 5:
				int lastElement;
				lastElement = cQueue.getLastElement();
				if(lastElement >= 0) {
					cout << "Last Element of Queue is: " << lastElement << endl;
				} else {
					cout << "No Element Found!" << endl;
				}
				break;

			case 6:
				cout << "Last Element Position is: " << cQueue.getLastElementPosition() << endl;
				break;

			case 7:
				if(cQueue.isEmpty()) {
					cout << "Empty Queue! Zero Element found!" << endl;
				} else {
					cout << "Total Element in Queue = " << cQueue.totalCount() << endl;
				}
				break;

			case 8:
				if(cQueue.isEmpty()) {
					cout << "No Element found in the queue" << endl;
				} else {
					cQueue.showElements();
				}
				break;

			case 9:
				exit = true;
				break;
		}
	}
	return 0;
}
