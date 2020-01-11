/**
 * Author: Hemant Tripathi
 */

#include<iostream>

using namespace std;

#define MAXSIZE 8

int main() {
	cout << "Starting Insertion Sort program" << endl;

	int dataArray[] = {25, 57, 48, 37, 12, 92, 86, 33};

	for (int i=1; i<MAXSIZE; i++) {
		for(int j=i; j > 0; j--) {
			if(dataArray[j] < dataArray[j-1]) {
				//Swap the data of i and j position
				int tmp = dataArray[j];
				dataArray[j] = dataArray[j-1];
				dataArray[j-1] = tmp;
			} else {
				break;
			}
		}
		cout << "After next iteration, array : ";
		for(int x=0; x < MAXSIZE; x++) {
			cout << "\t" << dataArray[x];
		}
		cout << endl;
	}
	cout << "############## Result ###################"<<endl;
	cout << "After Insertion Sort operation, sorted array is: ";
	for(int i=0; i < MAXSIZE; i++) {
		cout << "\t" << dataArray[i];
	}
	cout << endl;
}
