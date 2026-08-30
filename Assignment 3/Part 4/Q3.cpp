#include<iostream>
using namespace std;

double calculateArea(double side){
	return side * side;
}

double calculateArea(double length, double width){
	return length * width;
}

int main(){
	double side, length, width;
	cout << "Enter Side of a Square: ";
	cin >> side;
	cout << "Enter Length of a Rectangle: ";
	cin >> length;
	cout << "Enter Width of a Rectangle: ";
	cin >> width;
	cout << "Area of Square: " << calculateArea(side) << endl;
	cout << "Area of Rectangle: " << calculateArea(length, width);
}
