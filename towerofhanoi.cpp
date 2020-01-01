/**
 * Author Hemant Tripathi
 */

#include <iostream>
using namespace std;

void htower(int n, char from, char to, char aux);

int main() {
	int disks;
	cout << "Enter the number of disks you want to iterate?" << endl;
	cin >> disks;

	htower(disks, 'A', 'B', 'C');

	return 0;
}

void htower(int n, char from, char to, char aux) {
	if(n==1) {
		cout << "Move Disk 1 from Tower " << from << " to Tower " << to << endl;
		return;
	}
	htower(n-1, from, aux, to);
	cout << "Move Disk " << n << " From Tower " << from << " to Tower " << to << endl;
	htower(n-1, aux, to, from);
}
