#include<iostream>
using namespace std;
int main(){
	int r, c;
	cout << "Enter Number of Rows: ";
	cin >> r;
	cout << "Enter Number of Columns: ";
	cin >> c;
	int rollNo[r][c];
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << "Enter Roll Number for Row " << i + 1 << " Column " << j + 1 << ": ";
			cin >> rollNo[i][j];
		}
	}
	cout << endl;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << rollNo[i][j] << " ";
		}
		cout << endl;
	}
}
