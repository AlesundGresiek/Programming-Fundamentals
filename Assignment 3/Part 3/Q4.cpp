#include<iostream>
using namespace std;

double calculateStrikeRate(int runs, int balls){
	return (static_cast<double>(runs)/balls) * 100;
}

int main(){
	int runs, balls;
	cout << "Enter Runs: ";
	cin >> runs;
	cout << "Enter Balls: ";
	cin >> balls;
	cout << "Strike Rate: " << calculateStrikeRate(runs, balls);
}
