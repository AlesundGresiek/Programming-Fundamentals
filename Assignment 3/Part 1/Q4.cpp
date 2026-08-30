#include<iostream>
using namespace std;

double calculateVoltage(double current, double resistance){
	double voltage = current * resistance;
	return voltage;
}

int main(){
	double current, resistance;
	cout << "Enter Current: ";
	cin >> current;
	cout << "Enter Resistance: ";
	cin >> resistance;
	cout << "Voltage is: " << calculateVoltage(current, resistance);
}
