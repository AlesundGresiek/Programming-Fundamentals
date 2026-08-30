#include<iostream>
using namespace std;
int main(){
	double m, w;
	cout << "Enter Mass: ";
	cin >> m;
	if(m > 1000){
		cout << "Object is too Heavy ";
	}
	else if(m < 10){
		cout << "Object is too Light ";
	}
	else{
		w = m * 9.8;
		cout << "The Object's Weight in Kilograms is: " << w;
	}
}
