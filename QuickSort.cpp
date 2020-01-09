/**
 * Author: Hemant Tripathi
 */

#include <iostream>
using namespace std;

#define MAXSIZE 8

void quickSort(int x[], int lb, int ub);

int main() {
	int dataArray[MAXSIZE] = {25, 57, 48, 37, 12, 92, 86, 33};
	quickSort(dataArray, 0, MAXSIZE-1);

	cout << endl << endl;
	cout << "############################ Result ##############################" << endl;
	cout << "After quicksort Operation > Array: ";
	for(int i=0; i < MAXSIZE; i++) {
		cout << "\t" << dataArray[i];
	}
	cout <<endl;

}

void quickSort(int x[], int lb, int ub) {
	int a = x[lb];
        int up = ub;
        int down = lb;

        while(down < up) {
                while(x[down] <= a && down < ub) {
                        down++;
                }
          	while(x[up] > a) {
	                up--;
        	}
       		if(down < up) {
               		//swap the elements of up and down positions
                      	int temp = x[down];
                	x[down] = x[up];
       	        	x[up] = temp;
               	}
       	}
	x[lb] = x[up];
       	x[up] = a;

	cout << "After next iteration > Array:";
	for(int i=0; i < MAXSIZE; i++) {
                cout << "\t" << x[i];
        }
        cout <<endl;

	if(up > lb) {
		quickSort(x, lb, up-1);
	}
	if(down < ub) {
		quickSort(x, up+1, ub);
	}
}
