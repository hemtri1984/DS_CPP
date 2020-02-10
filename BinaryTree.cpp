/**
 * Author: Hemant Tripathi
 */

#include <iostream>

using namespace std;

struct NodePtr {
	int info;
	struct NodePtr *left, *right;
};

NodePtr* insertOp(struct NodePtr* ptr, int info);
bool isLeft(struct NodePtr* ptr);
bool isRight(struct NodePtr* ptr);
void showInorder(struct NodePtr* ptr);
void showPreorder(struct NodePtr* ptr);
void showPostorder(struct NodePtr* ptr);
NodePtr* searchBST(struct NodePtr* ptr, int data);
int getBSTHeight(struct NodePtr* ptr);

int main() {
	cout << "#########Program to create and traversal through binary tree##########" << endl;
	bool isExit = false;
	struct NodePtr* tree = NULL;
	while(1) {
		if(isExit) {
			cout << "Terminating the program" << endl;
			break;
		}
		cout << "Select your option..." << endl;
		cout << "1. Insert an element into the tree" << endl;
		cout << "2. Show all the elements of the tree" << endl;
		cout << "3. Preorder Traversal to all nodes" << endl;
		cout << "4. Inorder Traversal to all nodes" << endl;
		cout << "5. Postorder Traversal to all nodes" << endl;
		cout << "6. Search an element in BST" << endl;
		cout << "7. Find Hight of BST" << endl;
		cout << "8. Exit" << endl;

		cout << "Enter your choice" << endl;
		int choice;
		cin >> choice;

		if(choice < 1 || choice > 8) {
			cout << "Invalid input. Please choose between 1 to 7" << endl;
			continue;
		}

		switch(choice) {
			case 1:
				cout << "Enter an element to insert into the tree" << endl;
				int data;
				cin >> data;
				tree = insertOp(tree, data);
				break;

			case 2:
			case 4:
				cout << "Printing tree nodes in Inorder form"<<endl;
				if(tree != NULL) {
					//By default it will show an inorder form.
					if(isLeft(tree)) {
						showInorder(tree->left);
					}
					cout << "\t" << tree->info;
					if(isRight(tree)) {
						showInorder(tree->right);
					}
				} else {
					cout << "No Tree structure found!"<<endl;
				}
				cout << endl;
				break;

			case 3:
				cout << "Printing tree nodes in Preorder form" <<endl;
				if(tree != NULL) {
					cout << "\t" << tree->info;
					if(isLeft(tree)) {
						showPreorder(tree->left);
					}
					
					if(isRight(tree)) {
						showPreorder(tree->right);
					}
				} else {
					cout << "No tree structure found!"<<endl;
				}
				cout << endl;
				break;

			case 5:
				cout << "Printing tree nodes in Postorder form"<<endl;
				if(tree != NULL) {
					if(isLeft(tree)) {
						showPostorder(tree->left);
					}
					if(isRight(tree)) {
						showPostorder(tree->right);
					}

					cout << "\t" << tree->info;
				} else {
					cout << "No tree structure found!" << endl;
				}
				cout << endl;
				break;

			case 6:
				cout << "Enter the element you want to search in BST"<<endl;
				int element;
				cin >> element;
				NodePtr* searchElement;
				searchElement = searchBST(tree, element);
				if(searchElement != NULL) {
					cout << "Search element found!"<<endl;
				} else {
					cout << "Element not found!"<<endl;
				}
				break;

			case 7:
				cout << "Finding height of Binary Search Tree" << endl;
				int height;
				height =  getBSTHeight(tree);
				cout << "Height of tree : "<<height<<endl;
				break;

			case 8:
				isExit = true;
				break;

		}
	}
}


NodePtr* insertOp(struct NodePtr* tree, int info) {
	if(tree == NULL) {
		cout << "Tree not found! Create a new tree" << endl;
		tree = (struct NodePtr*)malloc(sizeof(struct NodePtr));
		tree->info = info;
		tree->left = NULL;
		tree->right = NULL;
	} else {
		cout << "Tree found! Adding new node into tree" << endl;
		if(info >= tree->info) {
			cout << "info = " << info << " is greater or equals to the parent node " << tree->info << " hence moving to right of the tree" << endl;
			tree->right = insertOp(tree->right, info);
		}else {
			cout << "info = " << info << " is less than the parent node "<< tree->info << " hence moving to left of the tree"<<endl;
			tree->left = insertOp(tree->left, info);
		}
	}
	return tree;

}

bool isLeft(struct NodePtr* ptr) {
	if(ptr->left != NULL) {
		return true;
	} else {
		return false;
	}
}

bool isRight(struct NodePtr* ptr) {
	if(ptr->right != NULL) {
		return true;
	} else {
		return false;
	}
}

void showInorder(struct NodePtr* ptr) {
	if(isLeft(ptr)) {
		showInorder(ptr->left);
	}
	cout << "\t" << ptr->info;
	if(isRight(ptr)) {
                showInorder(ptr->right);
        }
}

void showPreorder(struct NodePtr* ptr) {
	cout << "\t" << ptr->info;
	if(isLeft(ptr)) {
                showPreorder(ptr->left);
        }
        if(isRight(ptr)) {
                showPreorder(ptr->right);
        } 

}

void showPostorder(struct NodePtr* ptr) {
	if(isLeft(ptr)) {
                showPostorder(ptr->left);
        }
        if(isRight(ptr)) {
                showPostorder(ptr->right);
        }
	cout << "\t" << ptr->info;

}

NodePtr* searchBST(struct NodePtr* tree, int data) {
	if(tree == NULL) {
		return tree;
	} else {
		struct NodePtr* ptr;
		ptr = tree;
		while(ptr != NULL && data != ptr->info) {
			ptr = (data < ptr->info)?ptr = ptr->left : ptr=ptr->right;
		}
		return ptr;
	}
}

int getBSTHeight(struct NodePtr* ptr) {
	if(ptr == NULL) return -1;
	int leftHeight, rightHeight;
	leftHeight = getBSTHeight(ptr->left);
	rightHeight = getBSTHeight(ptr->right);
	return (leftHeight > rightHeight)?leftHeight+1:rightHeight+1;
}
