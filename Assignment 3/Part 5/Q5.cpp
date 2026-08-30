#include<iostream>
using namespace std;

void combineNames(char fN[],char lN[],char mt[]){
	int lettersF = 0;
	int lettersL = 0;
	for(int i = 0 ; fN[i] != '\0'; i++){
		lettersF++;
	}
	for(int i = 0 ; lN[i] != '\0'; i++){
		lettersL++;
	}
	for(int i = 0; i < lettersF; i++){
		mt[i] = fN[i];
	}
	mt[lettersF] = ' ';
	for(int j = 0; j < lettersL; j++){
		mt[lettersF + 1 + j] = lN[j]; 
	}
	cout << "Full Name: " << mt;
}

int main(){
	char fN[100];
	char lN[100];
	char mt[100];
	cout << "Enter First Name: ";
	cin >> fN;
	cout << "Enter Last Name: ";
	cin >> lN;
	combineNames(fN, lN, mt);
}
