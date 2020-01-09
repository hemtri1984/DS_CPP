/**
 * Author: Hemant Tripathi
 */

#include <iostream>
using namespace std;

#define MAXSIZE 8

int main() {
	cout << "############## Program for Selection Sort ##################"<<endl;
	cout << "Ascending Selection Sort"<<endl;

	int dataArray[MAXSIZE] = {25, 57, 48, 37, 12, 92, 86, 33};

	for( int i=0; i < MAXSIZE-1;i++) {
		int minIndex = i;
		for(int j=i+1; j < MAXSIZE; j++) {
			if(dataArray[minIndex] > dataArray[j]) {//jth position element is smaller
				minIndex = j;
			}
		}
		//swap minIndex with i th element
		int tmp = dataArray[i];
		dataArray[i] = dataArray[minIndex];
		dataArray[minIndex] = tmp;

		cout << "After next iteration array is: ";
		for(int x=0; x < MAXSIZE; x++) {
			cout << "\t" << dataArray[x];
		}
		cout <<endl;
	}

	cout << endl << endl;
	cout << "######### Result ###############"<<endl;
	cout << "After ascending selection sort operation, sorted array is: "<<endl;
	for(int i=0; i < MAXSIZE; i++) {
		cout << "\t" << dataArray[i];
	}
	cout <<endl;
}
