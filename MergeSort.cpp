/**
 * Author: Hemant Tripathi
 */

#include<iostream>

using namespace std;

#define MAXSIZE 9

void mergeSort(int arr[], int lb, int ub);

int main() {
	cout << "Starting Merge Sort Program" << endl;

	int dataArray[MAXSIZE] = {25, 57, 48, 37, 12, 92, 86, 33, 10};
	
	mergeSort(dataArray, 0, MAXSIZE-1);
}

void mergeSort(int arr[], int lb, int ub) {
	if (arr[lb] == arr[ub]) {
		return;
	}

	int low1 = lb;
	int high1 = (lb+ub)/2;
	int low2 = high1+1;
	int high2 = ub;
	cout << "low1:" <<low1<<"; high1:"<<high1<<"; low2:"<<low2<<" high2:"<<high2<<endl;
	mergeSort(arr, low1, high1);
	mergeSort(arr, low2, high2);

	int totalLength = high2-low1+1;
	cout << "Total Length : " << totalLength <<endl;
	int tmpArr[totalLength];

	int i=low1;
	int j=low2;
	int count = 0;
	cout << "high1 = "<<high1<<"; high2 = "<<high2<<endl;
	for(; i<=high1 && j<=high2;) {
		cout << "i = "<<i<<"; j = "<<j<<endl;
		if(arr[i] > arr[j]) {
			cout<<"if>>"<<endl;
			cout << "tmpArr["<<count<<"] = arr["<<j<<"]"<<endl;
			tmpArr[count++] = arr[j++];
		} else {
			cout<<"else>>"<<endl;
			cout << "tmpArr["<<count<<"] = arr["<<i<<"]"<<endl;
			tmpArr[count++] = arr[i++];
		}
	}
	cout << "i = "<<i<<"; high1 = "<<high1<<endl;
	if(i<=high1) {
		cout << "i <= high1"<<endl;
		while(i <= high1) {
			cout<<"tmpArr["<<count<<"] = arr["<<i<<"]"<<endl;
			tmpArr[count++] = arr[i++];
		}
	}
	cout << "j = "<<j<<"; high2 = "<<high2<<endl;
	if(j <= high2) {
		cout << "j <= high2"<<endl;
		while(j <= high2) {
			cout << "tmpArr["<<count<<"] = arr["<<j<<"]"<<endl;
			tmpArr[count++] = arr[j++];
		}
	}
	//Now move all the sorted element from tmpArray to main Array
	for(int i=0; i < totalLength;i++) {
		arr[low1++] = tmpArr[i];
	}
	cout << "After next iteration, Array = ";
	for(int i=0; i < MAXSIZE; i++) {
		cout << "\t" << arr[i];
	}
	cout << endl;

}
