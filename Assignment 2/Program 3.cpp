#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

string item [8] = {"Rice 1 KG", "Sugar 1 KG", "Cooking Oil 1 Litre", "Milk Pack", "Tea Pack", "Flour 5 KG", "Eggs Dozen", "Detergent"};
int price [8] = {350, 180, 580, 220, 450, 950, 320, 600};

double grossBillVar = 0;
double salesTaxVar = 0;
double membershipDiscountVar = 0;
double billDiscountVar = 0;
double cardChargeVar = 0;

double finalBillVar = 0;

double enteredLoyaltyPoints;
double loyaltyPointsVar = 0;
double loyaltyValue;
double loyaltyBill;
double loyaltyRem;

int choice;
int loyaltyChoice;

string cart[100];
int cartPrice[100];
int count = 0;

string customerName;
string customerID;
int customerType;
int paymentMethod;

void registerCustomer(){
	cout << "Enter Your Name: ";
	getline(cin, customerName);
	cout << "Enter Your ID: ";
	cin >> customerID;
	cout << "Enter Customer Type: " << endl;
	cout << "1. Regular" << endl;
	cout << "2. Member" << endl;
	cin >> customerType;
	cout << "Enter Payment Method: " << endl;
	cout << "1. Cash" << endl;
	cout << "2. Card" << endl;
	cin >> paymentMethod;
}

void displayMainMenu(){
	cout << endl << endl << "\tMain Menu" << endl << endl;
	cout << "1. View Customer Details"  << endl;
	cout << "2. View Grocery Items" << endl; 
	cout << "3. Add Items to Cart" << endl;
	cout << "4. Display Cart" << endl;
	cout << "5. Calculate Bill" << endl;
	cout << "6. Exit" << endl;
}

void displayGroceryList(){
	cout << endl << "\t\tGrocery Menu" << endl << endl;
	cout << left << setw(27) << "Item No. " << left << setw(50) << "Grocery Item" << left << setw(100) << "Price" << endl;
	cout << endl;
	for(int i = 0; i < 8; i++){
		cout << left << setw(27) << i+1 << left << setw(50) << item[i] << left << setw(100) << price[i] << endl;

	}
}

void placeOrder(){
	int repChoice = 1;
	int itemChoice;
	while(repChoice == 1){
		cout << endl;
		cout << "Enter the item number of the item you would like to add to cart: ";
		cin >> itemChoice; // 5
		cout << endl << "Your Chose " << item [itemChoice - 1/*4*/] << " that costs " << price [itemChoice - 1] << endl;
		cart[count] = item[itemChoice - 1];
		cartPrice[count] = price[itemChoice - 1];
		count++;
		cout << endl << "Would you like to order something else? Press 1 for Yes, Anything else for No: ";
		cin >> repChoice;
	}
}

void displayCart(){
	cout << endl;
	cout << left << setw(27) << "" << left << setw(50) << "  Cart" << left << setw(100) << "" << endl;
	cout << endl;
	for(int i = 0; i <= count - 1; i++){
		cout << left << setw(27) << i+1 << left << setw(42) << cart[i] << left << setw(50) << cartPrice[i] << endl;
	}
}

double grossBill(){
	for(int i = 0; i <= count - 1; i++){
		grossBillVar += cartPrice[i];
	}
	cout << "Gross Bill:\t\t\t";
	return grossBillVar;
}

double salesTax(){
	for(int i = 0; i <= count - 1; i++){
		if(cartPrice[i] == 600){
			salesTaxVar += 0.1 * cartPrice[i];
		}
		else{
			salesTaxVar += 0.05 * cartPrice[i];
		}
	}
	cout << "Sales Tax:\t\t\t";
	return salesTaxVar;
}

double membershipDiscount(){
	if(customerType == 1){
		cout << "Membership Discount:\t\t";
		membershipDiscountVar = 0;
		return 0;
	}
	else{
		cout << "Membership Discount:\t\t";
		membershipDiscountVar = -1 * (grossBillVar * 0.07);
		return membershipDiscountVar;
	}
}

double billDiscount(){
	if(grossBillVar < 5000){
		cout << "Bill Discount:\t\t\t";
		billDiscountVar = 0;
		return billDiscountVar;
	}
	else if(grossBillVar >= 5000 && grossBillVar <= 10000){
		cout << "Bill Discount:\t\t";
		billDiscountVar = -1 * (grossBillVar * 0.05);
		return billDiscountVar;
	}
	else{
		cout << "Bill Discount:\t\t";
		billDiscountVar = -1 * (grossBillVar * 0.1);
		return billDiscountVar;
	}
}

double cardCharge(){
	if(paymentMethod == 1){
		cout << "Card Charge:\t\t\t";
		cardChargeVar = 0;
		return cardChargeVar;
	}
	else{
		cout << "Card Charge:\t\t\t";
		cardChargeVar = grossBillVar * 0.02;
		return cardChargeVar;
	}
}

double finalBill(){
	cout << endl << "Final Bill:\t\t\t";
	finalBillVar = cardChargeVar + billDiscountVar + membershipDiscountVar + salesTaxVar + grossBillVar;
	return finalBillVar;
}

double loyaltyPoints(){
	loyaltyPointsVar = enteredLoyaltyPoints + (finalBillVar / 100);
	cout << "Updated Loyalty Points:\t\t";
	return loyaltyPointsVar;
	
}

double redeem(){
	if(loyaltyChoice == 1){
		cout << "How many loyalty point would you like to redeem?: ";
		cin >> loyaltyValue;
		cout << endl;
		loyaltyBill = finalBillVar - loyaltyValue;
		loyaltyRem = loyaltyPointsVar - loyaltyValue;
		cout << "Loyalty Points Balance:\t\t\t" << loyaltyRem;
		cout << endl;
		cout << "Final Bill after redeeming " << loyaltyValue << " points:\t";
		return loyaltyBill;
	}
}

void displayCustomerDetails(){
	cout << "\t Customer Details" << endl << endl;
	cout << left << setw(27) << "Customer Name: " << customerName << endl;
    cout << left << setw(27) << "Customer ID: " << customerID << endl;
    
	if(customerType == 1){
	cout << left << setw(27) << "Customer Type: " << "Regular" << endl;
	}
	else{
		cout << left << setw(27) << "Customer Type: " << "Member" << endl;
	}
	
	if(paymentMethod == 1){
	cout << left << setw(27) << "Payment Method: " << "Cash" << endl;
	}
	else{
		cout << left << setw(27) << "Payment Method: " << "Card" << endl;
	}
}

int main (){
	cout << "\t\tGrocery Mart Bill" << endl << endl;
	registerCustomer();
	do{
		displayMainMenu();
		cin >> choice;
		
		switch(choice){
			case 1:
				displayCustomerDetails();
				break;
				
			case 2:
				displayGroceryList();
				break;
				
			case 3:
				placeOrder();
				break;
					
			case 4:
				displayCart();
				break;
				
			case 5:
				cout << "\t\tBill Calculation" << endl << endl;
				cout << "Enter Your Loyalty Points:\t";
				cin >> enteredLoyaltyPoints;
				cout << endl;
				cout << grossBill() << endl;
				cout << salesTax() << endl;
				cout << membershipDiscount() << endl;
				cout << billDiscount() << endl;
				cout << cardCharge() << endl;
				cout << finalBill() << endl;
				cout << loyaltyPoints();
				cout << endl;
				cout << endl;
				cout << "Would You Like to Redeem your Loyalty Points? Enter 1 for Yes, Anything else for No: ";
				cin >> loyaltyChoice;
				cout << redeem();
				break;
					
			case 6:
				cout << "Thank you for shopping :)";
				return 0;
				break;
				
			default:
				cout << "Invalid Input :(";
				break;
		}
	}
	while(choice != 6);
}
