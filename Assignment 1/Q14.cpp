#include<iostream>
using namespace std;
int main(){
	int m, d, y;
	cout << "Enter Month: ";
	cin >> m;
	cout << "Enter Day: ";
	cin >> d;
	cout << "Enter Year (2-Digits): ";
	cin >> y;
	if(m * d == y){
		cout << "Result: MAGIC";
	}
	else{
		cout << "Result: NOT MAGIC";
	}
}
