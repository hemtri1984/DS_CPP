/**
 * Author: Hemant Tripathi
 */

#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int> adj[], int i, int j);

int main() {
	bool isExit = false;
	int totalVertex;
	cout << "Enter the size of graph (i.e. total vertices)" << endl;
	cin >> totalVertex;
	vector<int> adj[totalVertex];
	while(1) {
		if(isExit) {
			break;
		}
		cout << "Select an option:"<<endl;
		cout << "1. Add two vertex" << endl;
		cout << "2. Delete any vertex" << endl;
		cout << "3. Show graph" << endl;
		cout << "4. Exit" << endl;

		int option;
		cin >> option;

		switch(option) {
			case 1:
				int i,j;
				cout << "Enter first vertex number between 0 to "<<totalVertex-1<<endl;
				cin >> i;
				if(i < 0 || i >= totalVertex) {
					cout << "Vertex is out of range"<<endl;
					break;
				}
				cout << "Enter second vertex number between 0 to "<<totalVertex-1<<endl;
				cin >> j;
				if(j < 0 || j >= totalVertex) {
					cout << "Vertex is out of range" << endl;
					break;
				}
				addEdge(adj, i, j);
				break;

			case 2:

				break;

			case 3:
				cout << "Generating all routes of graph" << endl;
				for(int i=0; i<totalVertex; i++) {
					cout << "Adjacency List of vertex "<<i<<endl<<"Head";
					for(auto j:adj[i]) {
						cout << " -> " << j;
					}
					cout << endl;
				}
				break;

			case 4:
				cout << "Terminating program" << endl;
				isExit = true;
				break;
		}
	}
}

void addEdge(vector<int> adj[], int i, int j) {
	adj[i].push_back(j);
	adj[j].push_back(i);

	cout << "Vertex " << i << " and Vertex " << j << " joined together!";
}
