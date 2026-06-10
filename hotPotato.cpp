#include <iostream>
#include <vector> 
#include <string> 
using namespace std;

//Constants for prices(unchangeable, read-only), w3schools.com link: https://www.w3schools.com/cpp/cpp_variables_constants.asp
const double smallPrice = 5.0;
const double mediumPrice = 8.50;
const double largePrice = 10.25;
const double cheesePrice = 1.00;
const double butterPrice = 0.40;
const double garlicButterPrice = 0.50;
const double beansPrice = 0.75;
const double currySaucePrice = 1.20;
const double mushroomsPrice = 0.80;
const double onionsPrice = 0.40;
const double extraCheesePrice = 1.50;
const double saladBoxPrice = 1.50;
const double hotDogPrice = 4.00;
const double fizzyDrinkPrice = 1.20;
const double bottleWaterPrice = 0.80;
const double teaPrice = 1.00;
const double coffeePrice = 1.20;

double balance = 0.0; // w3schools.com link: https://www.w3schools.com/cpp/ref_keyword_double.asp

void displayMainMenu() //w3schools.com link: https://www.w3schools.com/cpp/cpp_functions.asp
{
	cout << "------------------------------" << endl; 
	cout << "Hot Potato" << endl;
	cout << "------------------------------" << endl;
	cout << "MAIN MENU" << endl;
	cout << " 1. Add Credits (current credits = " << balance << ")" << endl;
	cout << " 2. New Order" << endl;
	cout << " 0. Exit" << endl;
	cout << "Please enter a number: ";
}

void displaySizeMenu() //w3schools.com link: https://www.w3schools.com/cpp/cpp_functions.asp
{
	cout << "NEW ORDER - Select Size [Current Balance = " << balance <<" credits]" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << " 1. Small [5.0 credits]" << endl;
	cout << " 2. Medium [8.50 credits]" << endl;
	cout << " 3. Large [10.25 credits]" << endl;
	cout << " 0. Return to Main Menu" << endl;
	cout << "........................................" << endl;
	cout << "Please enter a number: ";
}

void displayToppingsMenu(double currentPrice) // w3schools.com link: https://www.w3schools.com/cpp/cpp_function_param.asp
{
	cout << "You have selected a medium baked potato." << endl;
	cout << "Your current price is "<< currentPrice << " credits. " << endl;
	cout << "Please choose from the following toppings: " << endl;
	cout << " 1. Cheese           [1.00 credits]" << endl;
	cout << " 2. Butter           [0.40 credits]" << endl;
	cout << " 3. Garlic Butter    [0.50 credits]" << endl;
	cout << " 4. Beans            [0.75 credits]" << endl;
	cout << " 5. Curry Sauce      [1.20 credits]" << endl;
	cout << " 6. Mushrooms        [0.80 credits]" << endl;
	cout << " 7. Onions           [0.40 credits]" << endl;
	cout << " 8. Extra Cheese     [1.50 credits]" << endl;
	cout << " 0. Return to Main Menu" << endl; // click 0 after choosing any of the options above to continue.
	cout << "........................................" << endl;
	cout << "Please enter a number: ";
}

void displayExtrasMenu(double currentPrice) // w3schools.com link: https://www.w3schools.com/cpp/cpp_function_param.asp
{
	cout << "Your current price is: " << currentPrice << " credits. " << endl;
	cout << "Would you like to order anything from the Extra's menu?" << endl;
	cout << "Please input 'Y' for yes and 'N' for no: ";
	char choice;
	cin >> choice;
	while (true)
	{
		cin >> choice;
		if (choice == 'Y' || choice == 'y') break;
		if (choice == 'N' || choice == 'n') return;
		cout << "Invalid input. Please input 'Y' for yes and 'N' for no: ";
	}
	cout << "........................................" << endl;
	cout << "Please choose from the following extra's:" << endl;
	cout << " 1. Salad Box              [1.50 credits]" << endl;
	cout << " 2. Hot Dog                [4.00 credits]" << endl;
	cout << " 3. Can of Fizzy Drink     [1.20 credits]" << endl;
	cout << " 4. Bottle of Water        [0.80 credits]" << endl;
	cout << " 5. Tea                    [1.00 credits]" << endl;
	cout << " 6. Coffee                 [1.20 credits]" << endl;
	cout << " 0. Return to Main Menu" << endl; // click 0 after choosing any of the options given above.
	cout << "........................................" << endl;
	cout << "Please enter a number: ";
}

double selectSize()
{
	int choice;
	cin >> choice;
	switch (choice) // w3schools.com link: https://www.w3schools.com/cpp/cpp_switch.asp 
	{
	case 1: return smallPrice;
	case 2: return mediumPrice; 
	case 3: return largePrice;
	default: return 0.0; // w3schools.com link: https://www.w3schools.com/cpp/cpp_switch.asp
	}
}

double selectToppings()
{
	vector<double> toppingsPrices = { cheesePrice, butterPrice, garlicButterPrice, beansPrice, currySaucePrice, mushroomsPrice, onionsPrice, extraCheesePrice }; // w3schools.com link: https://www.w3schools.com/cpp/cpp_vectors.asp
	int choice;
	double total = 0.0;
	while (true)
	{
		cin >> choice;
		if (choice == 0) break;
		if (choice >= 1 && choice <= 8) total += toppingsPrices[choice - 1];
	}
	return total;
}

double selectExtras()
{
	vector<double> extrasPrices = { saladBoxPrice, hotDogPrice, fizzyDrinkPrice, bottleWaterPrice, teaPrice, coffeePrice }; //w3schools.com link: https://www.w3schools.com/cpp/cpp_vectors.asp
	int choice;
	double total = 0.0;
	while (true)
	{
		cin >> choice;
		if (choice == 0) break; // break = breaking/ending a loop
		if (choice >= 1 && choice <= 6) total += extrasPrices[choice - 1];
	}
	return total;
}

void addCredits() //w3schools.com link: https://www.w3schools.com/cpp/cpp_functions.asp
{
	cout << "Please enter the amount of credits you would like to add to your balance: ";
	double credits;
	cin >> credits;
	balance += credits;
	cout << "----------------------------------------" << endl;
	cout << "Your new balance = " << balance << " credits. " << endl;
}

int main() 
{
	int menuChoice;
	while (true) {
		displayMainMenu();
		cin >> menuChoice;
		if (menuChoice == 0) break;
		switch (menuChoice) { //w3schools.com link: https://www.w3schools.com/cpp/cpp_switch.asp
		case 1: { // w3schools.com link: https://www.w3schools.com/cpp/cpp_switch.asp
			addCredits();
			break;
		}
		case 2: { // w3schools.com link: https://www.w3schools.com/cpp/cpp_switch.asp
			double sizePrice = 0.0, toppingsPrice = 0.0, extrasPrice = 0.0, totalPrice = 0.0;
			displaySizeMenu();
			sizePrice = selectSize();
			if (sizePrice == 0.0) break;
			displayToppingsMenu(sizePrice);
			toppingsPrice = selectToppings();
			displayExtrasMenu(sizePrice + toppingsPrice);
			extrasPrice = selectExtras();
			totalPrice = sizePrice + toppingsPrice + extrasPrice;
			if (totalPrice > balance) {
				cout << "Available Balance:    " << balance << " credits " << endl;
				cout << "OrderPrice:           " << totalPrice << " credits " << endl;
				cout << "----------------------------------------" << endl;
				cout << "You have insufficient credits available. You need " << totalPrice - balance << " credits. " << endl;
				cout << "Would you like to add more credits to your balance?" << endl;
				cout << "Please enter 'Y' for yes and 'N' for no: ";
				char choice;
				cin >> choice;
				if (choice == 'Y' || choice == 'y') {
					addCredits();
				}
				cout << "Would you like to continue processing your order?" << endl;
				cout << "Please input 'Y' for yes and 'N' for no: ";
				cin >> choice;
				if (choice == 'N' || choice == 'n') break;
			}
			balance -= totalPrice; // Assignment operator links: cppreference.com - https://en.cppreference.com/w/c/language/operator_assignment || w3schools.com - https://www.w3schools.com/cpp/cpp_operators_assignment.asp
			cout << "----------------------------------------" << endl;
			cout << "Available Balance:    " << balance << " credits. " << endl;
			cout << "Order price:          " << totalPrice << " credits. " << endl;
			cout << "----------------------------------------" << endl;
			cout << "Your new Balance  = " << balance << " credits. " << endl;
			cout << "----------------------------------------" << endl;
			cout << "Thank you for your order!" << endl;
			cout << "Would you like to place another order?" << endl;
			cout << "Please input 'Y' for yes and 'N' for no: ";
			int choice = 'N'; // w3schools.com link: https://www.w3schools.com/cpp/ref_keyword_int.asp
			cin >> choice;
			if (choice == 'N' || choice == 'n') return 0;
			break;
		}
		}
		cout << "Thank you for your order!" << endl;
		cout << "Goodbye!" << endl;
		return 0;
	}
}

/* 
 * Copyright © 2026 Osasere H. Ero. All rights reserved.
 * Proprietary and confidential. Unauthorized copying of this file, via any medium, is strictly prohibited.
 */
