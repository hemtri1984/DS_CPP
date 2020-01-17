/**
 * Author: Hemant Tripathi
 */

#include<iostream>

using namespace std;

#define MAXSIZE 5

void rotateClockwise(int arr[][MAXSIZE], int start, int end);
void rotateAntiClockwise(int arr[][MAXSIZE], int start, int end);

int main() {
	bool isExit = false;
	if(MAXSIZE < 2) {
		cout << "Minimum 2D Array Size must be greater than 1"<<endl;
		return 0;
	}
	int arr[MAXSIZE][MAXSIZE];
	cout << "################# Program of 2D Matrix Rotation ################" << endl;
	while(1) {
		if(isExit)
			break;
		cout << "Enter your choice" << endl;
		cout << "1. Create 2D Matrix" << endl;
		cout << "2. Rotate 90 degree clockwise" << endl;
		cout << "3. Rotate 90 degree anticlockwise" << endl;
		cout << "4. Print 2D Matrix"<<endl;
		cout << "5. Exit"<<endl;

		int selection;
		cin >> selection;
		int temp;
		switch(selection) {
			case 1:
				cout << "Enter data into " << MAXSIZE<<"*"<<MAXSIZE<<" matrix"<<endl;
				for(int i=0; i < MAXSIZE; i++) {
					for(int j=0; j < MAXSIZE; j++) {
						cout << "Enter arr["<<i<<"]["<<j<<"] data:"<<endl;
						cin >> arr[i][j];
					}
				}
				cout << "Matrix filled successfully"<<endl;
				break;

			case 2:
				cout << "Rotating to 90 degree clockwise"<<endl;
				rotateClockwise(arr, 0, MAXSIZE-1);
				cout <<"Clockwise rotation done!"<<endl;
				break;

			case 3:
				cout << "Rotating to 90 degree anticlockwise"<<endl;
				rotateAntiClockwise(arr, 0, MAXSIZE-1);
				cout <<"AntiClockwise rotation done!"<<endl;
				break;

			case 4:
				cout << "Printing 2D matrix"<<endl;
				for(int i=0; i < MAXSIZE; i++) {
					for(int j=0; j < MAXSIZE; j++) {
						cout << "\t" << arr[i][j];
					}
					cout << endl;
				}
				break;

			case 5:
				isExit = true;
				break;
		}
	}
	cout << "Terminating the program"<<endl;
	return 0;
}

void rotateClockwise(int arr[][MAXSIZE], int start, int end) {
	int temp;
	int size = end-start;
	cout << "Size = "<<size<<"; start = "<<start<<"; end = "<<end<<endl;
	if(size < 1) {
		return;
	}
	for(int j=start; j < end; j++) {
		cout << "j = "<<j<<endl;
		temp = arr[start][j];
		cout << "Temp = "<<temp<<endl;
		arr[start][j] = arr[end-j+start][start];
		cout << "arr["<<start<<"]["<<j<<"] = "<<arr[start][j]<<endl;
		arr[end-j+start][start] = arr[end][end-j+start];
		cout<<"arr["<<end-j+start<<"]["<<start<<"] = "<<arr[end-j+start][start]<<endl;
		arr[end][end-j+start]=arr[j][end];
		cout<<"arr["<<end<<"]["<<end-j+start<<"] = "<<arr[end][end-j+start]<<endl;
		arr[j][end] = temp;
		cout<<"arr["<<j<<"]["<<end<<"] = "<<arr[j][end]<<endl;
	}
	rotateClockwise(arr, start+1, end-1);
}

void rotateAntiClockwise(int arr[][MAXSIZE], int start, int end) {
	int temp;
	int size = end-start;
	cout << "Size = "<<size<<"; start = "<<start<<"; end = "<<end<<endl;
        if(size < 1) {
                return;
        }
	for(int j=start; j < end; j++) {
		cout << "j = "<<j<<endl;
		temp = arr[start][j];
		cout << "Temp = "<<temp<<endl;
		arr[start][j] = arr[j][end];
		cout << "arr["<<start<<"]["<<j<<"] = "<<arr[start][j]<<endl;
		arr[j][end] = arr[end][end-j+start];
		cout<<"arr["<<j<<"]["<<end<<"] = "<<arr[j][end]<<endl;
		arr[end][end-j+start] = arr[end-j+start][start];
		cout<<"arr["<<end-j+start<<"]["<<start<<"] = "<<arr[end-j+start][start]<<endl;
		arr[end-j+start][start] = temp;
	}
	rotateAntiClockwise(arr, start+1, end-1);
}
