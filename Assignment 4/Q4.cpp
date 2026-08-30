#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main(){
	int searchRoll, roll;
	string name;
	float marks;
	bool found = false;
	
	ifstream inFile("students.txt");
	ofstream tempFile("temp.txt");
	
	if (!inFile || !tempFile)
	{
	    cout << "Error Opening Files.";
	    return 1;
	}
	
	cout << "Enter Roll Number to Delete: ";
	cin >> searchRoll;
	
	while (inFile >> roll >> name >> marks)
	{
	    if (roll == searchRoll)
	    {
	        found = true;
	        continue;
	    }
	
	    tempFile << roll << " "
	             << name << " "
	             << marks << endl;
	}
	
	inFile.close();
	tempFile.close();
	
	remove("students.txt");
	rename("temp.txt", "students.txt");
	
	if (found)
	    cout << "Record Deleted Successfully.";
	else
	    cout << "Roll Number Not Found.";
	
	return 0;
}
