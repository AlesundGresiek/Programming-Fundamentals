#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int roll;
	string name;
	float marks;
	
	ofstream outFile("students.txt");
	
	if (!outFile)
	{
	    cout << "File could not be created.";
	    return 1;
	}
	
	for (int i = 1; i <= 5; i++)
	{
	    cout << "Enter Roll Number: ";
	    cin >> roll;
	
	    cout << "Enter Name: ";
	    cin >> name;
	
	    cout << "Enter Marks: ";
	    cin >> marks;
	
	    outFile << roll << " "
	            << name << " "
	            << marks << endl;
	}
	
	outFile.close();
	
	cout << "Records saved successfully.";
	
	return 0;
}
