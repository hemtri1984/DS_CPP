/**
 * Author: Hemant Tripathi
 */

#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

struct Node* header = NULL;
int main() {
	cout << "Starting Linear Link List";
	bool isTerminated = false;
	while(1){
		if(isTerminated) {
			break;
		}
		cout << "Select and function for linear link list:" << endl;
		cout << "1. Add a node on beginning of list" << endl;
		cout << "2. Add a node in middle of the list" << endl;
		cout << "3. Add a node at the end of the list" << endl;
		cout << "4. Remove a node from the start of list" << endl;
		cout << "5. Remove a node from the middle of list" << endl;
		cout << "6. Remove a node from the end of the list" << endl;
		cout << "7. Show all nodes of the list"<<endl;
		cout << "8. Exit" << endl;

		int input;
		cout << "Enter the number of your choice:" << endl;
		cin >>input;

		if(input < 1 || input > 8) {
			cout << "Invalid input. Please choose between 1 to 8" << endl;
			continue;
		} else {
			struct Node* ptr;
			int inputData;
			switch(input) {
				case 1:
					ptr = (struct Node*)malloc(sizeof(struct Node));
					cout << "Enter the data into the new node" << endl;
					cin >> inputData;
					ptr->data = inputData;
					ptr->next = NULL;
					if (header == NULL) {
						cout << "No node found! Create first node of list" << endl;
						header = ptr;
						cout << "Created first (header) node of the list" << endl;
					} else {
						ptr->next = header;
						header = ptr;
						ptr = NULL;

						cout << "Successfully created a new node in the beginning of the LinkList" << endl;
					}
					break;

				case 2:
					struct Node* tmp;
					int position;
					ptr = (struct Node*)malloc(sizeof(struct Node));
					cout << "Enter the data into the new node" << endl;
					cin >> inputData;
					ptr->data = inputData;
					ptr->next = NULL;
					if (header == NULL) {
                                                cout << "No node found! Create first node of list" << endl;
                                                header = ptr;
                                                cout << "Created first (header) node of the list" << endl;
                                        } else {
						cout << "Enter the position of this node into list" << endl;
						cin >> position;
						if(position > 0) {
							bool indexOut = false;
							tmp = header;
							int counter = 0;
							while (counter < position-1) {
								tmp = tmp->next;
								counter++;
								if(tmp->next == NULL) {
									indexOut = true;
									break;
								}
							}
							if(indexOut) {
								cout << "IndexOutOfBoundError. Max list length = " << ++counter << endl;
							} else {
								ptr->next = tmp->next;
								tmp->next = ptr;
								tmp = NULL;

								cout << "Successfully added a new node at position " << ++counter << " of the link list" << endl;
							}
						} else {
							cout << "Please enter valid position" << endl;
						}
					}
					break;

				case 3:
                                        ptr = (struct Node*)malloc(sizeof(struct Node));
                                        cout << "Please enter the data into the new node" << endl;
                                        cin >> inputData;
                                        ptr->data = inputData;
                                        ptr->next = NULL;
                                        if (header == NULL) {
                                                cout << "No node created. Create first node of list" << endl;
                                                header = ptr;
                                                cout << "Created first (header) node of the list" << endl;
                                        } else {
                                                struct Node *tmp; //Node traverse through the link list
                                                tmp = header;
                                                while(tmp->next != NULL) {
                                                        tmp = tmp->next;
                                                }
                                                tmp->next = ptr;
                                                cout << "Successfully added new node at the end of list" << endl;
                                        }
					break;

				case 4:
					cout << "Removing the node from the beginning of the list" << endl;
					ptr = header;
					if(header->next != NULL) {
						header = header->next;
						ptr->next = NULL;
					} else {
						delete(header);
					}
					delete(ptr);
					cout << "Successfully removed first node of the list" << endl;
					break;

				case 5:
					int nodePosition;
					bool listFinished;
					listFinished = false;
					cout << "Enter the position of node your want to remove" << endl;
					cin >> nodePosition;
					if(nodePosition >= 0) {
						struct Node* ptr1;
						ptr = header;
						ptr1 = header->next;
						int counter = 0;
						while(counter < nodePosition-1) {
							ptr = ptr->next;
							ptr1=ptr1->next;
							if(ptr1->next == NULL) {
								listFinished = true;
								break;
							}
							counter++;
						}
						if(listFinished) {
							cout << "IndexOutOfBound! position is more than the size of list" << endl;
						} else {
							ptr->next = ptr1->next;
							ptr1->next = NULL;
							ptr = NULL;
							delete(ptr);
						}
					} else {
						cout << "Please enter valid input" << endl;
					}
					break;

				case 6:
					if(header != NULL) {
						if(header->next != NULL) {
							struct Node* ptr1;
							ptr = header;
							ptr1 = header->next;
							while(ptr1->next != NULL) {
								ptr = ptr->next;
								ptr1 = ptr1->next;
							}
							ptr->next = NULL;
							delete(ptr1);
						} else {
							delete(header);
						}
					} else {
						cout << "No list found! Please create a list first." << endl;
					}
					break;

				case 7:
					{
					cout << "Calculating all nodes of the link list" << endl;
					ptr = header;
					int counter = 0;
					cout << "Data " << ptr->data << " at position " << counter << endl;
					while(ptr->next != NULL) {
						ptr = ptr->next;
						cout << "Data " << ptr->data << " at position " << ++counter << endl;
					}
					}
					break;

				case 8:
					cout << "Terminating the program..." << endl;
					isTerminated = true;
					break;
			}
		}
	}

}
