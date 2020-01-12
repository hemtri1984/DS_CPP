/**
 * Author: Hemant Tripathi
 */

#include<iostream>

using namespace std;

#define MAXSIZE 8

int main() {
	cout << "Starting program for Shell Sort" << endl;

	int dataArray[] = {25, 57, 48, 37, 12, 92, 86, 33};

	for(int gap = MAXSIZE/2; gap>0; gap = gap/2) {
		cout << "Gap Size = "<<gap<<endl;
		for(int i=gap; i < MAXSIZE; i++) {
			int tmp = dataArray[i];
			cout << "i = " << i << "; temp value = " << tmp << endl;
			int j;
			for (j=i; j >= gap && dataArray[j-gap] > tmp; j -=gap) {
				dataArray[j] = dataArray[j-gap];
			}
			dataArray[j] = tmp;
		}

		cout << "After next iteration, Array is: ";
		for(int x=0; x < MAXSIZE; x++) {
			cout << "\t" << dataArray[x];
		}
		cout << endl;
	}

	cout << "################ Result #######################" << endl;
	cout << "Shell Sorting done. Final Result: ";
	for(int i=0; i < MAXSIZE; i++) {
		cout << "\t" << dataArray[i];
	}
	cout << endl;
}
