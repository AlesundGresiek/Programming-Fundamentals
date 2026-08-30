#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

string userName;
string email;
string city;
int customerType;
int paymentMethod;

string item [8] = {"T-Shirt", "Jeans", "Shoes", "Watch", "Hand Bag", "Headphones", "Mobile Cover", "Perfume"};
int price [8] = {1200, 3500, 5000, 2500, 4200, 3000, 700, 2800};

int choice;

string cart[100];
int cartPrice[100];
int count = 0;

double deliveryChargeVar = 0;

double GSTVar = 0;
double productTotalVar = 0;

double customerDiscountVar = 0;

double orderValueDiscountVar = 0;

double cardChargeVar = 0;

double finalBillVar = 0;

void registerCustomer(){
	cout << "Enter Your Username: ";
	getline(cin, userName);
	cout << "Enter Your Email Address: ";
	cin >> email;
	cout << "Enter Your City: ";
	cin >> city;
	cout << "Enter Customer Type: " << endl;
	cout << "1. New Customer" << endl;
	cout << "2. Returning Customer" << endl;
	cin >> customerType;
	cout << "Enter Payment Method: " << endl;
	cout << "1. Cash on Delivery" << endl;
	cout << "2. Debit or Credit Card" << endl;
	cin >> paymentMethod;
}

void displayCustomerDetails(){
	cout << "\t Customer Details" << endl << endl;
	cout << left << setw(27) << "Username: " << userName << endl;
    cout << left << setw(27) << "Email: " << email << endl;
    cout << left << setw(27) << "City: " << city << endl;
    
	if(customerType == 1){
	cout << left << setw(27) << "Customer Type: " << "New" << endl;
	}
	else{
		cout << left << setw(27) << "Customer Type: " << "Returning" << endl;
	}
	
	if(paymentMethod == 1){
	cout << left << setw(27) << "Payment Method: " << "Cash on Delivery" << endl;
	}
	else{
		cout << left << setw(27) << "Payment Method: " << "Debit/Credit Card" << endl;
	}
}

void displayProductList(){
	cout << endl << "\t\tProduct List" << endl << endl;
	cout << left << setw(27) << "Item No. " << left << setw(50) << "Grocery Item" << left << setw(100) << "Price" << endl;
	cout << endl;
	for(int i = 0; i < 8; i++){
		cout << left << setw(27) << i+1 << left << setw(50) << item[i] << left << setw(100) << price[i] << endl;

	}
}

void displayMainMenu(){
	cout << endl << endl << "\tMain Menu" << endl << endl;
	cout << "1. View User Details"  << endl;
	cout << "2. View Products List" << endl; 
	cout << "3. Add Products to Cart" << endl;
	cout << "4. Display Cart" << endl;
	cout << "5. Calculate Bill" << endl;
	cout << "6. Exit" << endl;
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

double productTotal(){
	for(int i = 0; i <= count - 1; i++){
		productTotalVar += cartPrice[i];
	}
	cout << "Product Total:\t\t\t";
	return productTotalVar;
}

double deliveryCharge(){
	if(city == "Lahore" || city == "lahore" || city == "Islamabad" || city == "islamabad" || city == "Karachi" || city == "karachi"){
		cout << "Delivery Charges:\t\t";
		deliveryChargeVar = 250;
		return deliveryChargeVar;
	}
	else{
		cout << "Delivery Charges:\t\t";
		deliveryChargeVar = 500;
		return deliveryChargeVar;
	}
}

double GST(){
	cout << "GST:\t\t\t\t";
	GSTVar = 0.17 * productTotalVar;
	return productTotalVar;
}

double customerDiscount(){
	if(customerType == 1){
		cout << "Customer Discount:\t\t";
		customerDiscountVar = -1 * (0.05 * productTotalVar);
		return customerDiscountVar;
	}
	else{
		cout << "Customer Discount:\t\t";
		customerDiscountVar = -1 * (0.1 * productTotalVar);
		return customerDiscountVar;
	}
}

double orderValueDiscount(){
	if(productTotalVar < 5000){
		cout << "Order Value Discount:\t\t\t";
		orderValueDiscountVar = 0;
		return orderValueDiscountVar;
	}
	else if(productTotalVar >= 5000 && productTotalVar <= 10000){
		cout << "Order Value Discount:\t\t";
		orderValueDiscountVar = -1 * (productTotalVar * 0.05);
		return orderValueDiscountVar;
	}
	else{
		cout << "Order Value Discount:\t\t";
		orderValueDiscountVar = -1 * (productTotalVar * 0.12);
		return orderValueDiscountVar;
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
		cardChargeVar = productTotalVar * 0.025;
		return cardChargeVar;
	}
}

double finalBill(){
	finalBillVar = cardChargeVar + orderValueDiscountVar + customerDiscountVar + GSTVar + deliveryChargeVar + productTotalVar;
	cout << endl << "Final Bill:\t\t\t";
	return finalBillVar;
}



int main (){
	cout << "\t\tOnline Shopping Bill" << endl << endl;
	registerCustomer();
	do{
		displayMainMenu();		
		cin >> choice;
		
		switch(choice){
			case 1:
				displayCustomerDetails();
				break;

			case 2:
				displayProductList();
				break;
				
			case 3:
				placeOrder();
				break;
								
			case 4:
				displayCart();
				break;

			case 5:
				cout << "\t\tBill Calculation" << endl << endl;
				cout << productTotal() << endl;
				cout << GST() << endl;
				cout << deliveryCharge() << endl;
				cout << customerDiscount() << endl;
				cout << orderValueDiscount() << endl;
				cout << cardCharge() << endl;
				cout << finalBill() << endl;
				cout << endl;
				cout << endl;
				break;
			
			case 6:
				cout << "Thank your for shopping :)";
				return 0;
				break;
				
			default:
				cout << "Invalid Input :(";
				break;
		}
	}
	while(choice != 6);
}
