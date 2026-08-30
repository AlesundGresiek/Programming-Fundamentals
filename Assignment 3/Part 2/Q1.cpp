#include<iostream>
using namespace std;

double calculate2ndLowest(int array[], int size){
	double lowest = array[0];
	double low2 = array[1];
	if (low2 < lowest){
    	double temp = lowest;
    	lowest = low2;
    	low2 = temp;
	}
	for(int i = 2; i < size; i++){
    	if (array[i] < lowest) {
        	low2 = lowest;
        	lowest = array[i];
    	}
    	else if (array[i] < low2 && array[i] != lowest){
        	low2 = array[i];
    	}
	}
	return low2;
}

double calculate2ndHighest(int array[], int size){
	double highest = array[0];
	double hi2 = array[1];
	if (hi2 < highest){
    	double temp = highest;
    	highest = hi2;
    	hi2 = temp;
	}
	for(int i = 2; i < size; i++){
    	if (array[i] > highest) {
        	hi2 = highest;
        	highest = array[i];
    	}
    	else if (array[i] > hi2 && array[i] != highest){
        	hi2 = array[i];
    	}
	}
	return hi2;
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
	cout << "2nd Lowest Marks of all the Students are: " << calculate2ndLowest(marks, n) << endl;
	cout << "2nd Highest Marks of all the Students are: " << calculate2ndHighest(marks, n);
}
