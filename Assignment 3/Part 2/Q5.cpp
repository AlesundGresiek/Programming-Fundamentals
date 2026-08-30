#include<iostream>
using namespace std;
int countVowels(char word[]){
	int count = 0;
	for(int i = 0; word[i] != '\0'; i++){
		if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U'){
			count++;
		}
	}
	return count;
}
int main(){
	int size;
	cout << "Enter Size of Your Word: ";
	cin >> size;
	char word[size];
	cout << "Enter Your Word: ";
	for(int i = 0; i < size; i++){
		cin >> word[i];
	}
	cout << "Number of Vowels in this word: " << countVowels(word);
}
