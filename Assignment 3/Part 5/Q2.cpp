#include<iostream>
using namespace std;
int main(){
	int r, c;
	cout << "Enter Number of Rows: ";
	cin >> r;
	cout << "Enter Number of Columns: ";
	cin >> c;
	int arr[r][c];
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << "Enter Roll Number for Row " << i << " Column " << j << ": ";
			cin >> arr[i][j];
		}
	}
	int ur, uc;
	cout << "Enter index: " << endl;
	cout << "Enter Row: ";
	cin >> ur;
	cout << "Enter Column: ";
	cin >> uc;
	cout << endl << "Value at given index: " << arr[ur][uc];
}
