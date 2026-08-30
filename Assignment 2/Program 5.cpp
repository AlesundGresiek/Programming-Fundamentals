#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

string name;
string businessName;
int businessType;
int duration;

int choice;

string platform[3] = {"Instagram", "Facebook", "LinkedIn"};
int baseManagementCharge[3] = {15000, 12000, 20000};
int platformChoice;

string item [3] = {"Static Post", "Reel/Video Post", "Carousel Post"};
int price [3] = {1000, 2500, 1800};
string cart[100];
int cartPrice[100];
int count = 0;

double baseManagementChargeVar;

double postTotalVar = 0;

double grossBillVar = 0;

double advertisingBudget;
double agencyHandlingFeeVar;

double durationFeeVar;

double gstVar;

double discountVar;

double finalBillVar;

void registerCustomer(){
	cout << "Enter Your Name: ";
	getline(cin, name);
	cout << "Enter Your Business Name: ";
	cin >> businessName;
	cout << "Enter Business Type: " << endl;
	cout << "1. Small Business" << endl;
	cout << "2. Medium Business" << endl;
	cout << "3. Corporate Business" << endl;
	cin >> businessType;
	cout << "Enter Your Campaign Duration in Days: ";
	cin >> duration;
}

void displayMainMenu(){
	cout << endl << endl << "\tMain Menu" << endl << endl;
	cout << "1. View Client Details"  << endl;
	cout << "2. View Platforms" << endl;
	cout << "3. View Post Types" << endl;
	cout << "4. Select Post Types" << endl;
	cout << "5. View Selected Post Types" << endl;
	cout << "6. Calculate Bill" << endl;
	cout << "7. Exit" << endl;
}

void displayPlatforms(){
	cout << endl;
	cout << left << setw(27) << "" << left << setw(50) << "Platforms" << left << setw(100) << "" << endl;
	cout << endl;
	cout << left << setw(27) << "# " << left << setw(42) << "Platform" << left << setw(50) << "Base Management Charge" << endl;
	cout << endl;
	for(int i = 0; i < 3; i++){
		cout << left << setw(27) << i+1 << left << setw(42) << platform[i] << left << setw(50) << baseManagementCharge[i] << endl << endl;
	}
	cout << "Enter Your Choice: ";
	cin >> platformChoice;
}

double baseManagementChargeFunc(){
	baseManagementChargeVar = baseManagementCharge[platformChoice];
	cout << "Platform Management Charges:\t";
	return baseManagementChargeVar;
}

void displayPostTypes(){
	cout << left << setw(27) << "" << left << setw(50) << "Post Types" << left << setw(100) << "" << endl;
	cout << endl;
	cout << left << setw(27) << "Item No. " << left << setw(50) << "Post Type" << left << setw(100) << "Price" << endl;
	for(int i = 0; i < 3; i++){
		cout << left << setw(27) << i+1 << left << setw(50) << item[i] << left << setw(100) << price[i];
		cout << endl;
	}
}

void placeOrder(){
	int repChoice = 1;
	int itemChoice;
	while(repChoice == 1){
		cout << endl;
		cout << "Enter the item number of the Post Type you would like to add: ";
		cin >> itemChoice; // 5
		cout << endl << "Your Chose " << item [itemChoice - 1] << " that costs " << price [itemChoice - 1] << endl;
		cart[count] = item[itemChoice - 1];
		cartPrice[count] = price[itemChoice - 1];
		count++;
		cout << endl << "Would you like to add something else? Press 1 for Yes, Anything else for No: ";
		cin >> repChoice;
	}
}

void displayCart(){
	cout << endl;
	cout << left << setw(27) << "" << left << setw(50) << "Selected Features" << left << setw(100) << "" << endl;
	cout << endl;
	for(int i = 0; i <= count - 1; i++){
		cout << left << setw(27) << i+1 << left << setw(42) << cart[i] << left << setw(50) << cartPrice[i] << endl;
	}
}

double postTotal(){
	for(int i = 0; i <= count - 1; i++){
		postTotalVar += cartPrice[i];
	}
	cout << "Post Design Cost:\t\t";
	return postTotalVar;
}

double grossBill(){
	grossBillVar = postTotalVar + baseManagementChargeVar;
	return grossBillVar;
}

double agencyHandlingFee(){
	cout << "Enter Your Advertising Budget:\t";
	cin >> advertisingBudget;
	if(advertisingBudget < 50000){
		cout << "Handling Fee:\t\t\t";
		agencyHandlingFeeVar = 0.05 * grossBillVar;
		return agencyHandlingFeeVar;
	}
	else if(advertisingBudget >= 50000 && advertisingBudget <= 100000){
		cout << "Handling Fee:\t\t\t";
		agencyHandlingFeeVar = grossBillVar * 0.08;
		return agencyHandlingFeeVar;
	}
	else{
		cout << "Handling Fee:\t\t\t";
		agencyHandlingFeeVar = grossBillVar * 0.1;
		return agencyHandlingFeeVar;
	}
}

double durationFee(){
	if(duration > 30){
		durationFeeVar = (duration - 30) * 500;
		cout << "Extra Duration Charges: \t";
		return durationFeeVar;
	}
	else{
		durationFeeVar = 0;
		cout << "Extra Duration Charges: \t";
		return durationFeeVar;
	}
}

double gst(){
	gstVar = grossBillVar * 0.16;
	cout << "GST: \t\t\t\t";
	return gstVar;
}

double discount(){
	switch(businessType){
		case 1:
			discountVar = -1 * (grossBillVar * 0.05);
			cout << "Discount: \t\t\t";
			return discountVar;
			break;
			
		case 2:
			discountVar = -1 * (grossBillVar * 0.08);
			cout << "Discount: \t\t\t";
			return discountVar;
			break;
			
		case 3:
			discountVar = -1 * (grossBillVar * 0.1);
			cout << "Discount: \t\t\t";
			return discountVar;
			break;
	}
}

double finalBill(){
	finalBillVar = grossBillVar + discountVar + gstVar + durationFeeVar + agencyHandlingFeeVar;
	cout << "Final Campaign Bill: \t\t";
	return finalBillVar; 
}

void displayCustomerDetails(){
	cout << "\t Client Details" << endl << endl;
	cout << left << setw(27) << "Name: " << name << endl;
    cout << left << setw(27) << "Business Name: " << businessName << endl;
    
	if(businessType == 1){
	cout << left << setw(27) << "Business Type: " << "Small Business" << endl;
	}
	else if(businessType == 2){
		cout << left << setw(27) << "Business Type: " << "Medium Business" << endl;
	}
	else if(businessType == 3){
		cout << left << setw(27) << "Business Type: " << "Corporate Business" << endl;
	}
	cout << left << setw(27) << "Campaign Duration in Days: " << duration << endl;
}



int main (){
	cout << "\t\tSocial Media Campaign Bill" << endl << endl;
	registerCustomer();
	do{
		displayMainMenu();
		cin >> choice;
		
		switch(choice){

			case 1:
				displayCustomerDetails();
				break;

			case 2:
				displayPlatforms();
				break;
				
			case 3:
				displayPostTypes();
				break;
				
			case 4:
				placeOrder();
				break;
								
			case 5:
				displayCart();
				break;
				
			case 6:
				cout << "\t\tBill Calculation" << endl << endl;
				cout << baseManagementChargeFunc() << endl;
				cout << postTotal() << endl;
				cout << "Gross Bill:\t\t\t" << grossBill() << endl;
				cout << agencyHandlingFee() << endl;
				cout << durationFee() << endl;
				cout << gst() << endl;
				cout << discount() << endl;
				cout << finalBill() << endl;
				break;
				
			case 7:
				return 0;
				break;
				
			default:
				cout << "Invalid Input :(";
				break;
		}
	}
	while(choice != 7);
}
