#include<iostream>
using namespace std;
int main(){
	int n;
	cout << "Enter Number of Letters in Word: ";
	cin >> n;
	char word[n];
	cout << "Enter Word: ";
	cin >> word;
	for(int i = n; i >= 0; i--){
		cout << word[i];
	}
}
