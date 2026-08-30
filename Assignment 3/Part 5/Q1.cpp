#include<iostream>
using namespace std;
int main(){
	int p, w;
	int sum = 0;
	cout << "Enter Number of Products: ";
	cin >> p;
	cout << "Enter Number of Weeks: ";
	cin >> w;
	int arr [p][w];
	for(int i = 0; i < w; i++){
		for(int j = 0; j < p; j++){
			cout << "Enter sales figure for Product Number " << j + 1 << " for Week " << i + 1 << ": ";
			cin >> arr[j][i];
		}
	}
	for(int i = 0; i < p; i++){
		for(int j = 0; j < w; j++){
			sum += arr[i][j];
		}
		cout << "Total for Product #" << i + 1 << ": " << sum << endl;
		sum = 0;
	}
	
}
