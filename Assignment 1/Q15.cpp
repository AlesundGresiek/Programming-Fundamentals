#include<iostream>
using namespace std;
int main(){
	double value, com;
	cout << "Enter Value in Sales: ";
	cin >> value;
	if(value > 15000){
		com = 0.20;
	}
	else if(value <= 10000){
		com = 0.10;
	}
	else if(value <= 15000 && value >= 10000){
		com = 0.15;
	}
	cout << "Commision is: " << com;
}
