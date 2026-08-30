#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int choice;

string customerName;
string customerID;
int customerTypeChoice;
string customerType;

int unitsConsumed;
int tvChoice;

float preTotal;

void registerCustomer(){
	cout << "Enter Your Name: ";
	getline(cin, customerName);
	cout << "Enter Your ID: ";
	cin >> customerID;
	cout << endl << endl;
	cout << "Enter Your Type of Connection: " << endl;
	cout << "1. Domestic" << endl;
	cout << "2. Commercial" << endl;
	cin >> customerTypeChoice;
	if(customerTypeChoice == 1){
    	customerType = "Domestic";
	}
	else{
		customerType = "Commercial";
	}
	cout << "Enter Units Consumed: ";
	cin >> unitsConsumed;
}

void displayMenu(){
	cout << endl << "\t\t Menu" << endl << endl;
	cout << "1. Calculate Bill" << endl; 
	cout << "2. Apply for New Electricity Connection" << endl;
	cout << "3. View Customer Details"  << endl;
	cout << "4. Exit" << endl;
}

double consumptionCharges(){
	double charge;
	double unitRate[8] = {12.21, 14.53, 31.51, 38.41, 41.62, 43.04, 44.18, 49.10};
	if(unitsConsumed < 100){
		charge = unitRate[0] * unitsConsumed;
	}
	
	else if(unitsConsumed < 200){
		charge = unitRate[1] * unitsConsumed;
	}
	
	else if(unitsConsumed < 300){
		charge = unitRate[2] * unitsConsumed;
	}
	
	else if(unitsConsumed < 400){
		charge = unitRate[3] * unitsConsumed;
	}
	
	else if(unitsConsumed < 500){
		charge = unitRate[4] * unitsConsumed;
	}
	
	else if(unitsConsumed < 600){
		charge = unitRate[5] * unitsConsumed;
	}
	
	else if(unitsConsumed < 700){
		charge = unitRate[6] * unitsConsumed;
	}
	
	else{
		charge = unitRate[7] * unitsConsumed;
	}
	
	return charge;
}

double GST(double preTotal){
	double charge = preTotal * 0.18;
	return charge;
}

double incomeTax(double preTotal){
	double charge = 0;
	if(customerType == "Domestic"){
		charge = preTotal * 0.1;
	}
	else{
		charge = preTotal * 0.15;
	}
	return charge;
}

double electricalDuty(){
	double charge = consumptionCharges() * 0.15;
	return charge;
}

double tvFee(){
	double charge = 0;
	if(tvChoice == 1){
		charge = 35;
	}
	return charge;
}

double additionalCharges(){
	double charge;
	charge = electricalDuty() + tvFee();
	return charge;
}

double fixedCharges(){
	double charge;
	double fixedRate[5] = {200, 400, 600, 800, 1000};
	if(unitsConsumed < 300){
		charge = 0;
	}
	
	else if(unitsConsumed < 400){
		charge = fixedRate[0];
	}
	
	else if(unitsConsumed < 500){
		charge = fixedRate[1];
	}
	
	else if(unitsConsumed < 600){
		charge = fixedRate[2];
	}
	
	else if(unitsConsumed < 700){
		charge = fixedRate[3];
	}

	else{
		charge = fixedRate[4];
	}
	
	return charge;

}

double finalBill(){
	double total = 0;
	
	total = GST(preTotal) + preTotal + incomeTax(preTotal);
	return total;
}

double newConnectionCharges(){
	double meterCost, meterCableCost, securityCost, additionalCharges, newCustomerTypeChoice, noOfMeter, properConnection,newTypeValue;
	double newTotal = 0;
	cout << "Enter Meter Cost: ";
	cin >> meterCost;
	cout << "Enter Meter Cable Cost: ";
	cin >> meterCableCost;
	cout << "Enter Security Cost: ";
	cin >> securityCost;
	cout << "Enter Your Type of New Connection: " << endl;
	cout << "1. Domestic" << endl;
	cout << "2. Commercial" << endl;
	cin >> newCustomerTypeChoice;
	if(newCustomerTypeChoice == 1){
		newTypeValue = 2500;
	}
	else{
		newTypeValue = 35000;
	}
	cout << "Is this your First or Second Meter?: ";
	cin >> noOfMeter;
	additionalCharges = noOfMeter * newTypeValue;
	cout << "Would you like a Proper Connection? Press 1 for Yes, 2 for No: ";
	cin >> properConnection;
	if(properConnection == 1){
		newTotal += 250000;
	}
	
	newTotal = newTotal + meterCost + meterCableCost + securityCost + additionalCharges;
	
	cout << endl << "Total Cost of New Connection: " << newTotal;
	
	return newTotal;
	
}

void displayCustomerDetails(){
	cout << "\t\t Customer Details" << endl << endl;
	cout << left << setw(27) << "\tCustomer Name: " << customerName << endl;
    cout << left << setw(27) << "\tCustomer ID: " << customerID << endl;
    cout << left << setw(27) << "\tConnection Type: " << customerType << endl;
}

int main(){
	cout << "\t\tLESCO ELECTRICITY BILL" << endl << endl;
	registerCustomer();
	do{
		displayMenu();
		cin >> choice;

		switch (choice){
			case 1:
				cout << "Have you a TV? 1 for Yes, 2 for No: ";
				cin >> tvChoice;
				cout << endl << left << setw(27) << "\t\tBill Calculation" << endl << endl;
				cout << left << setw(27) << "\tConsumption Charges: " << consumptionCharges() << endl;
				cout << left << setw(27) << "\tElectrical Duty Charges: " << electricalDuty() << endl;
				cout << left << setw(27) << "\tFixed Charges: " << fixedCharges() << endl;
				cout << left << setw(27) << "\tMeter Rent Charges: " << 250 << endl;
				if(tvChoice == 1){
					cout << left << setw(27) << "\tTV Charges: " << 35 << endl;
				}
				preTotal = fixedCharges() + additionalCharges() + consumptionCharges() + 250;
				cout << left << setw(27) << "\tGST Charges: " << GST(preTotal) << endl;
				cout << left << setw(27) << "\tIncome Tax Charges: " << incomeTax(preTotal) << endl << endl;
				cout << left << setw(27) << "\tTotal Payable Bill: " << finalBill() << endl;
				break;
				
			case 2:
				newConnectionCharges();
				break;
				
			case 3:
				displayCustomerDetails();
				break;
				
			case 4:
				return 0;
				break;
				
			default:
				cout << "Invalid Input :(";
				break;
		}
	}
	while(choice != 4);
}
