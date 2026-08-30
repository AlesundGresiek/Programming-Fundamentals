#include<iostream>
using namespace std;

double calculateAverage(int array[], int size){
	double sum = 0;
	double avg;
	for(int i = 0; i < size; i++){
		sum += array[i];
	}
	avg = sum / size;
	return avg;
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
	cout << "Average Marks of all the Students are: " << calculateAverage(marks, n);
}
