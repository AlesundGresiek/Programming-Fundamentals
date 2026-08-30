#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int roll;
	string name;
	float marks;
	int count = 0;
	
	ifstream inFile("students.txt");
	
	if (!inFile)
	{
	    cout << "Error opening file.";
	    return 1;
	}
	
	cout << "Roll\tName\tMarks" << endl;
	
	while (inFile >> roll >> name >> marks)
	{
	    cout << roll << "\t"
	         << name << "\t"
	         << marks << endl;
	
	    count++;
	}
	
	inFile.close();
	
	cout << "\nTotal Records = " << count;
	
	return 0;
}
