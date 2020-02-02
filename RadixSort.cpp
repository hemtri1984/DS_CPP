/*
 * Author: Hemant Tripathi
 */

#include<iostream>

using namespace std;

#define MAXSIZE 8

int getMax(int arr[]);
void radixSort(int arr[], int exp);

int main() {
	int arr[MAXSIZE] = {25, 57, 48, 37, 12, 92, 86, 33};
	cout << "Finding highest number of array"<<endl;
	int maxNum = getMax(arr);
	cout << "Highest number of array = "<<maxNum<<endl;
	cout << "Now call the total passes for sorting (i.e. total digits)"<<endl;
	int count = 1;
	for(int exp=1; maxNum/exp > 0; exp*=10) {
		cout << "Pass "<<count++<<endl;
		radixSort(arr, exp);
	}
	return 0;
}

int getMax(int arr[]) {
	int maxNum = arr[0];
	for(int i=1; i < MAXSIZE; i++) {
		if(arr[i] > maxNum) {
			maxNum = arr[i];
		}
	}
	return maxNum;
}

void radixSort(int arr[], int exp) {
	int count[10] = {0,0,0,0,0,0,0,0,0,0}; //This will contains the frequencies of each items place values into the array.
	for(int i=0; i<MAXSIZE; i++) {
		count[(arr[i]/exp)%10]++;
	}

	cout << "Frequencies of each items for exp = "<<exp<<" is" <<endl;
	for(int i=0; i < 10; i++) {
		cout << count[i] << " ";
	}
	cout << endl;
	cout << "Now finding cumulative frequencies "<<endl;
	for(int i=1; i < 10; i++) {
		count[i] += count[i-1];
	}
	cout << "Cumulative frequencies are: "<<endl;
	for(int i=0; i < 10; i++) {
		cout << count[i] << " ";
	}
	cout << endl;
	cout << "Now set the items to its place according to the cumulative frequency"<<endl;
	int output[MAXSIZE];
	for(int i=MAXSIZE-1; i>=0; i--) {
		output[count[(arr[i]/exp)%10]-1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}
	//copy output item into the array
	for(int i=0; i<MAXSIZE;i++) {
		arr[i] = output[i];
	}
	cout<<"After iteration, sorted array is: "<<endl;
	for(int i=0; i < MAXSIZE; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
