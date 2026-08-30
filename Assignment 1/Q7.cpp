#include<iostream>
using namespace std;
int main(){
	int n1, n2, n3, first, second, third;
	cout << "Enter First Runner's Time: ";
	cin >> n1;
	cout << "Enter Second Runner's Time: ";
	cin >> n2;
	cout << "Enter Third Runner's Time: ";
	cin >> n3;
	if(n1 > n2){
		if(n1 > n3){
			first = n1;
			if(n2 > n3){
				second = n2;
				third = n3;
			}
			else{
				second = n3;
				third = n2;
			}
		}
		else{
			second = n1;
			first = n3;
			third = n2;
		}
	}
	else{
		if(n2 > n3){
			first = n2;
			if(n1 > n3){
				second = n1;
				third = n3;
			}
			else{
				second = n3;
				third = n1;
			}
		}
		else{
			second = n2;
			first = n3;
			third = n1; 
		}
	}
	cout << "First Place: " << first << endl;
	cout << "Second Place: " << second << endl;
	cout << "Third Place: " << third << endl;
}
