/**
 * Author: Hemant Tripathi
 */


#include <iostream>
using namespace std;

#define MAXSIZE 8

int main() {

	int dataArray[MAXSIZE] = {25,57,48,37,12,92,86,33};
	bool swapping = true;
	for(int i=0; i < MAXSIZE && swapping; i++) {
		swapping = false;
		for(int j=0; j < MAXSIZE-i-1; j++) {
			if(dataArray[j] > dataArray[j+1]) { //swap the data
				dataArray[j] = dataArray[j] + dataArray[j+1];
				dataArray[j+1] = dataArray[j] - dataArray[j+1];
				dataArray[j] = dataArray[j] - dataArray[j+1];
				swapping = true;
			}
		}
		cout << "After " << i+1 << " iteration: ";
		for(int x=0; x < MAXSIZE; x++) {
			cout << "\t" << dataArray[x];
		}
		cout << endl;
	}
	cout << "Bubble sorting executed successfully >>>>>>>>>>>" << endl;
	for(int i=0; i < MAXSIZE; i++) {
		cout << "\t" << dataArray[i];
	}
	cout << endl;
}
