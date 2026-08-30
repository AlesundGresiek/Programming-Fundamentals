#include<iostream>
using namespace std;
int main(){
	int n1 , n2;
	cout << "Enter First Number: ";
	cin >> n1;
	cout << "Enter Second Number: ";
	cin >> n2;
	if(n1 > n2){
		cout << n1 << " is Larger than " << n2;
	}
	else if(n1 < n2){
		cout << n2 << " is Larger than " << n1;
	}
	else{
		cout << "Both Numbers are Equal";
	}
}
