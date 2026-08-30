#include<iostream>
using namespace std;

double getBowlingAverage(int runsConceeded, int wicketsTaken){
	double avg;
	if(wicketsTaken == 0){
		return 0.0;
	}
	else{
		avg = static_cast<double>(runsConceeded)/ wicketsTaken;
		return avg;
	}
}

int main(){
	int runs, wickets;
	cout << "Enter Runs Conceeded: ";
	cin >> runs;
	cout << "Enter Wickets Taken: ";
	cin >> wickets;
	cout << "Bowling Average: " << getBowlingAverage(runs, wickets);
}
