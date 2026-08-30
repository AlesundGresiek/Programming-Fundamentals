#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
	int searchRoll, roll;
	string name;
	float marks, newMarks;
	bool found = false;
	
	fstream file("students.txt", ios::in | ios::out);
	
	if (!file)
	{
	    cout << "Error opening file.";
	    return 1;
	}
	
	cout << "Enter Roll Number to update: ";
	cin >> searchRoll;
	
	cout << "Enter New Marks: ";
	cin >> newMarks;
	
	while (file >> roll >> name >> marks)
	{
	    if (roll == searchRoll)
	    {
	        streampos pos = file.tellg();
	        pos -= 7;
	        file.seekp(pos);
	
	        file << setw(6) << left << newMarks;
	
	        found = true;
	        break;
	    }
	}
	
	file.close();
	
	if (found)
	    cout << "Record Updated Successfully.";
	else
	    cout << "Roll Number Not Found.";
	
	return 0;
}
