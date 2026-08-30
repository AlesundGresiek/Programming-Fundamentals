#include<iostream>
using namespace std;
int main(){
	int r, c;
	int sum = 0;
	cout << "Enter Number of Columns: ";
	cin >> c;
	cout << "Enter Number of Rows: ";
	cin >> r;
	int arr[r][c];
	for(int i = 0; i < r; i++){
		for(int j = 0 ; j < c; j++){
			cout << "Enter Value for Row " << i + 1 << " Column " << j + 1 << ": ";
			cin >> arr[i][j];
		}
	}
	cout << endl;
	for(int i = 0; i < r; i++){
		for(int j = 0 ; j < c; j++){
			sum += arr[i][j];
		}
	}
	int el1 = arr[0][0];
	sum = sum - el1;
	int dif = el1 - sum;
	cout << "Difference: " << dif;
}
