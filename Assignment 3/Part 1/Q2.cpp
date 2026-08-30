#include<iostream>
using namespace std;

double calculateLowest(int array[], int size){
	double lowest = array[1];
	for(int i = 0; i < size; i++){
		if(lowest > array[i]){
			lowest = array[i];
		}
	}
	return lowest;
}

double calculateHighest(int array[], int size){
	double highest = array[1];
	for(int i = 0; i < size; i++){
		if(highest < array[i]){
			highest = array[i];
		}
	}
	return highest;
}

int main(){
	int n;
	cout << "Enter Number of Students: ";
	cin >> n;
	int marks [n];
	for(int i = 0; i < n; i++){
		cout << "Enter Marks of Student #" << i + 1 << ": ";
		cin >> marks[i];
	}
	cout << "Lowest Marks of all the Students are: " << calculateLowest(marks, n) << endl;
	cout << "Highest Marks of all the Students are: " << calculateHighest(marks, n);
}
