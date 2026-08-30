#include<iostream>
using namespace std;
double celsiusToFahrenheit(double celsius){
	double fahrenheit;
	fahrenheit = (celsius * (9.0/5.0)) + 32;
	return fahrenheit;
}
int main(){
	double celsius;
	cout << "Enter Temperature in Celsius: ";
	cin >> celsius;
	cout << "Tempterature in Fahrenheit is: " << celsiusToFahrenheit(celsius);
}
