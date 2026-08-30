#include<iostream>
using namespace std;
int main(){
	int n;
	cout << "Enter Number of Letters in Word: ";
	cin >> n;
	char word[n];
	cout << "Enter Word: ";
	cin >> word;
	for(int i = 0; i < n; i++){
		cout << word[i] << endl;
	}
}
