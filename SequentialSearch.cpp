/**
 * Author: Hemant Tripathi
 */

#include<iostream>

using namespace std;

#define MAXSIZE 8

int main() {
	int dataArray[] = {25, 57, 48, 37, 25, 92, 86, 33};

	cout << "Enter and element to search" << endl;
	int element;
	cin >> element;

	bool elementFound = false;
	int index = -1;
	for(int i=0; i<MAXSIZE; i++) {
		if(dataArray[i] == element) {
			elementFound = true;
			index = i;
			break;
		}
	}

	if(elementFound) {
		cout << "Element found at index: " << index << endl;
	} else {
		cout << "Element not found!"<<endl;
	}
}
