#include<iostream>
using namespace std;
int main(){
	char pass1[100];
	char pass2[100];
	bool pass = true;
	cout << "Enter Your Password: ";
	cin >> pass1;
	cout << "Confirm Password: ";
	cin >> pass2;
	for(int i = 0; i < 100; i++){
		if(pass1[i] != pass2[i]){
			cout << "The two passwords don't match";
			pass = false;
			break;
		}
		if (pass1[i] == '\0' && pass2[i] == '\0') {
            break;
        }
	}
	if(pass){
		cout << "Login Successful";
	}
}
