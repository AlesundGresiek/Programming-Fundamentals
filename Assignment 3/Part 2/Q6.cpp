#include<iostream>
using namespace std;
int main(){
	char word[5];
	cout << "Enter 5 Letters: ";
	for(int i = 0; i < 5; i++){
		cin >> word[i];
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 4; j++){
			if(word[j] > word[j + 1]){
				char temp = word[j + 1];
				word[j + 1] = word[j];
				word[j] = temp;
			}
		}
	}
	cout << "Sorted: ";
	for(int i = 0; i < 5; i++){
		cout << word[i];
	}
}
