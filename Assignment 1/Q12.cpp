#include<iostream>
using namespace std;
int main(){
	int ai, y;
	cout << "Enter your Annual Income: ";
	cin >> ai;
	cout << "Enter the number of years at your current job: ";
	cin >> y;
	if(y > 5 && ai >= 3500000){
		cout << "You Qualify for the Loan";
	}
	else{
		cout << "You DONT Qualify for the Loan";
	}
}
