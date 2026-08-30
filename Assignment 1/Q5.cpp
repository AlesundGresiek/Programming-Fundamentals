#include<iostream>
using namespace std;
int main(){
	double a, b;
	cout << "Enter Numerator: ";
	cin >> a;
	cout << "Enter Denominator: ";
	cin >> b;
	if(b != 0){
		cout << "Quotient: " << a / b;
	}
	else{
		cout << "Divison by zero is not possible";
	}
}
