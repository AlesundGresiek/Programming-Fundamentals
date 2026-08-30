#include<iostream>
using namespace std;

int calculateSum(int marks[], int size){
	int sum = 0;
	for(int i = 0; i < size; i++){
		sum += marks[i];
	}
	return sum;
}

int main(){
	int size;
	cout << "Enter Number of Students: ";
	cin >> size;
	int marks[size];
	for(int i = 0; i < size; i++){
		cout << "Enter Marks of Student #" << i + 1 << ": ";
		cin >> marks[i];
	}
	cout << "Sum of Marks of all Students is: " << calculateSum(marks, size);
}
