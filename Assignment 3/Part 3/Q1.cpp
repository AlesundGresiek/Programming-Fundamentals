#include<iostream>
using namespace std;

int countEvenNumbers(int array[], int size){
	int countE = 0;
	for(int i = 0; i < size; i++){
		if(array[i] % 2 == 0){
			countE++;
		}
	}
	return countE;
}

int countOddNumbers(int array[], int size){
	int countO = 0;
	for(int i = 0; i < size; i++){
		if(array[i] % 2 != 0){
			countO++;
		}
	}
	return countO;
}

int main(){
	int size;
	cout << "Enter Size of Array: ";
	cin >> size;
	int array[size];
	for(int i = 0; i < size; i++){
		cout << "Enter #" << i + 1 << ": ";
		cin >> array[i];
	}
	cout << "Number of Even Numbers in the Array: " << countEvenNumbers(array, size) << endl;
	cout << "Number of Odd Numbers in the Array: " << countOddNumbers(array, size);
}
