#include<iostream>
using namespace std;
int main(){
	int temp;
	cout << "Enter Temperature: ";
	cin >> temp;
	if ( temp > -50 && temp < 150 ){
		cout << "The Number is Valid";
	}
}
