#include<iostream>
using namespace std;
int main(){
	int choice;
	cout << "Press 1 for Area of a Circle" << endl;
	cout << "Press 2 for Area of a Rectangle" << endl;
	cout << "Press 3 for Area of a Triangle" << endl;
	cout << "Enter Your Choice: " << endl;
	cin >> choice;
	switch(choice){
		case 1:
			double rad;
			cout << "Enter Radius: ";
			cin >> rad;
			cout << "Area of Circle is: " << rad * rad * 3.14159;
			break;
		case 2:
			double l, w;
			cout << "Enter Length: ";
			cin >> l;
			cout << "Enter Width: ";
			cin >> w;
			cout << "Area of Rectangle is: " << l*w;
			break;
		case 3:
			double b, h;
			cout << "Enter Base: ";
			cin >> b;
			cout << "Enter Height: ";
			cin >> h;
			cout << "Area of Triangle is: " << b*h*0.5;
	}
}
