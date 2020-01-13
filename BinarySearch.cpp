/**
 * Author: Hemant Tripathi
 */


#include<iostream>

using namespace std;

#define MAXSIZE 10

int binarySearch(int arr[], int data, int startIndex, int endIndex);

int main() {
	cout << "Starting Binary Search program" << endl;
	cout << "Considering array is already in sorted ascending order" << endl;

	int dataArray[] = {1,2,3,4,5,6,7,8,9,10};

	int search;
	cout << "Enter the element you want to search"<<endl;
	cin >> search;

	int index = binarySearch(dataArray, search, 0, MAXSIZE-1);
	if(index < 0) {
		cout << "data not found!"<<endl;
	}else {
		cout << "data found at index: "<<index<< endl;
	}
}

int binarySearch(int arr[], int data, int startIndex, int endIndex) {
	int middle = (startIndex+endIndex)/2;
	cout << "StartIndex: "<<startIndex<<"; EndIndex: "<<endIndex<<"; Middle Index: "<<middle<<endl;
	if(arr[middle] == data) {
		return middle;
	}
	if(middle == startIndex && middle == endIndex) {
		return -1;
	}
	if(data < arr[middle]) {
		binarySearch(arr, data, startIndex, middle);
	} else {
		binarySearch(arr, data, middle+1, endIndex);
	}
}
