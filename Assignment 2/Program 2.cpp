#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

string userName;
string phoneNumber;
double dineTake = 0;
int noOfPeople;

int choice;

double foodBill = 0;
double gst;
double serviceCharge;
double bill = 0;

string item [8] = {"Chicken Burger", "Zinger Burger", "Pizza Small", "Pizza Large", "Chicken Biryani", "BBQ Platter", "Fries\t", "Cold Drink"};
int price [8] = {450, 550, 900, 1800, 350, 1200, 250, 120};

void registerCustomer(){
	cout << "Enter Your Name: ";
	getline(cin, userName);
	cout << "Enter Your Phone Number: ";
	cin >> phoneNumber;
	cout << "Press 1 or Dine in, Anything Else for Take Away: ";
	cin >> dineTake;
	cout << "Enter Number of People: ";
	cin >> noOfPeople;
}

void displayMainMenu(){
	cout << endl << "\t\tMain Menu" << endl << endl;
	cout << "1. View Food Menu" << endl; 
	cout << "2. Place Order" << endl;
	cout << "3. Calculate Bill" << endl;
	cout << "4. View Customer Details"  << endl;
	cout << "5. Exit" << endl;
}

void displayFoodMenu(){
	cout << endl << "\t\tFood Menu" << endl << endl;
	cout << "Item No." << "\t" << "Item" << "\t\t\t" << "Price" << endl;
	for(int i = 0; i < 8; i++){
		cout << i+1 << "\t\t" << item[i] << "\t\t" << price[i] << endl;
	}
}

void placeOrder(){
	int repChoice = 1;
	int itemChoice;
	while(repChoice == 1){
		cout << "Enter the item number of the item you want: ";
		cin >> itemChoice;
		cout << endl << "Your Chose " << item [itemChoice - 1] << " that costs " << price [itemChoice - 1] << endl;
		cout << endl << "Would you like to order something else? Press 1 for Yes, Anything Else for No: ";
		cin >> repChoice;
		foodBill += price[itemChoice - 1];
	}
	
	
	cout << "Food Bill: " << foodBill;
}

double serviceChargeFunc(){
	if(dineTake == 1){
		serviceCharge = foodBill * 0.1;
	}
	else{
		serviceCharge = foodBill * 0.05;
	}
	return serviceCharge;
}

double gstFunc(){
	gst = foodBill * 0.16;
	return gst;
}

void preDiscBill(){
	bill = foodBill + gst + serviceCharge;
}

double disc(double &bill){
    double discount = 0;
    if(bill > 3000 && bill < 5000){
        discount = bill * 0.05;
    }
    else if(bill > 5000 && bill < 10000){
        discount = bill * 0.10;
    }
    else if(bill > 10000){
        discount = bill * 0.15;
    }
    bill -= discount;
    cout << left << setw(27) << "\tDiscount: " << discount << endl;
    return bill;
}

double deliveryCharge(){
		if (bill > 5000){
			return 0;
		}
		else
		return 200;
}

void displayCustomerDetails(){
	cout << "\t\t Customer Details" << endl << endl;
	cout << left << setw(27) << "\tCustomer Name: " << userName << endl;
    cout << left << setw(27) << "\tPhone Number: " << phoneNumber << endl;
    
	if(dineTake == 1){
	cout << left << setw(27) << "\tOrder Type: " << "Dine-In" << endl;
	}
	else{
		cout << left << setw(27) << "\tOrder Type: " << "Take Away" << endl;
	}
	
    cout << left << setw(27) << "\tNumber of People: " << noOfPeople << endl;
}



int main (){
	cout << "\t\tResturant Bill" << endl << endl;
	registerCustomer();
	do{
		displayMainMenu();
		cin >> choice;
		
		switch(choice){
			case 1:
				displayFoodMenu();
				break;
				
			case 2:
				placeOrder();
				break;
				
			case 3:
				gst = gstFunc();
				serviceCharge = serviceChargeFunc();
				preDiscBill();
				cout << left << setw(27) << "\t\tBill Calculation " << endl << endl;
				cout << left << setw(27) << "\tFood Bill: " << foodBill << endl;
				cout << left << setw(27) << "\tService Charges: " << serviceCharge << endl;
				cout << left << setw(27) << "\tGST: " << gst << endl;
				disc(bill);
				cout << left << setw(27) << "\tBill: " << bill << endl;
				cout << left << setw(27) << "\tDelivery Charges: " << deliveryCharge() << endl;
				cout << left << setw(27) << "\tFinal Payable Bill: " << deliveryCharge() + bill << endl;
				break;
				
			case 4:
				displayCustomerDetails();
				break;
				
			case 5:
				cout << "Have a nice Meal :)";
				return 0;
				break;
				
			default:
				cout << "Invalid Input :(";
				break;
		}
	}
	while(choice != 5);
}
