/**
 * Author: Hemant Tripathi
 */

#include <iostream>

using namespace std;

#define MAXHEAPSIZE 9

void heapify(int arr[], int totalNodes, int father);

int main() {
	int dataArray[MAXHEAPSIZE] = {25, 57, 48, 37, 12, 92, 86, 33, 40};
	
	//Heapify array (build heap tree)
        for(int i=MAXHEAPSIZE/2 -1; i >= 0; i--) {
                heapify(dataArray, MAXHEAPSIZE, i);
        }

        //Now one by one extract elements from top of heap
        for(int i = MAXHEAPSIZE-1; i >= 0; i--) {
                int tmp = dataArray[0];
                dataArray[0] = dataArray[i];
                dataArray[i] = tmp;

                //heapify the array again
                heapify(dataArray, i, 0);
        }

	cout << "####################### Result ########################";
	cout << "After successful heap sort, sorted arrays are:";
	for(int i=0; i < MAXHEAPSIZE; i++) {
		cout << "\t" << dataArray[i];
	}
	cout << endl;

	return 0;
}

void heapify(int arr[], int totalNodes, int father) {
	int largestNode = father;
	int leftChild = 2*father + 1; //left node = 2i+1
	int rightChild = 2*father +2; //right node = 2i+2

	cout << "Largest Node position: " << largestNode << "; Left Child position: " << leftChild << "; Right Child position: "<< rightChild << endl;
	cout << "Largest Node: " << arr[largestNode] << "; Left Child: " << arr[leftChild] << "; Right Child: " << arr[rightChild] << endl;


	//if left child is larger than father node
	if(leftChild < totalNodes && arr[leftChild] > arr[largestNode]) {
		cout << "left child is greater than father"<<endl;
		largestNode = leftChild;
	}

	//if right child is larger than father node
	if(rightChild < totalNodes && arr[rightChild] > arr[largestNode]) {
		cout << "Right child is greater than father" << endl;
		largestNode = rightChild;
	}

	cout << "Largest Node: " << largestNode << "; Father Node: " << father << endl;
	if(largestNode != father) {
		cout << "Swapping largest node and father node" << endl;
		//swap the largest node with the father node
		int tmp = arr[father];
		arr[father] = arr[largestNode];
		arr[largestNode] = tmp;

		cout << "Heapify total node: " << totalNodes << "; and largestNode: " << largestNode << " i.e. " << arr[largestNode] << endl;
		heapify(arr, totalNodes, largestNode);
	}
}
