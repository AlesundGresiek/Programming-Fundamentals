#include<iostream>
using namespace std;
int main(){
	double a = 10;
	double b = 10;
	a += 0.2;
	if(a > b){
		cout << a << " is Larger than " << b;
	}
	else if(a < b){
		cout << b << " is Larger than " << a;
	}
	else{
		cout << "Both Numbers are Equal";
	}
}
