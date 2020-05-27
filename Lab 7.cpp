#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	cout << setiosflags(ios_base::fixed);									//Do Not Use E Notation
	cout << setiosflags(ios_base::showpoint);								//Always Show Decimal Point
	cout << setprecision(2);										//Rounded To 2 Decimal Places

	int numberOfemployees;
	char selection;
	double hours, weeklyTotalwithTax, weeklyTotal;

	string input;
	string employeeFirstname;
	string employeeLastname;
	bool hasEmployee; 

	const float salaryTaxreductions = .33;										//Const for tax reductiosn on salary workers
	const float taxReductions = .28;									//Const for tax reductions from per hour workers
	
	const float counterStaffpay = 10.50;								//Pay for all workers
	const float kitchenCookspay = 15.75;
	const float dishwashersPay = 10.50;
	const float managersPay = 48000;

	hours = 0;															//Initializations 
	

	cout << "Do you have an employee to pay?" << endl;
	cin >> input;
	if (input == "Yes") {
		hasEmployee = true;
		do {
			weeklyTotal = '0';
			cout << "Employee first name: " << endl;
			cin >> employeeFirstname;
			cout << "Employee last name: " << endl;
			cin >> employeeLastname;
			cout << "What is their role here?" << endl << endl << "A. Counter Staff" << endl << "B. Kitchen Cook" << endl << "C. Dishwasher" << endl << "D. Manager" << endl << endl << "Please choose an option: ";
			cin >> selection;
		
			if (selection != 'A' && selection != 'B' && selection != 'C' && selection != 'D') {								//Edgecase to account for wrong characters inputed
				cout << "Error: Please choose one of the options above." << endl << "(Make sure your letter is capitilized)" << endl;
				cout << "What is their role here?" << endl << endl << "A. Counter Staff" << endl << "B. Kitchen Cook" << endl << "C. Dishwasher" << endl << "D. Manager" << endl << endl << "Please choose an option: ";
				cin >> selection;
			}
			if (selection == 'D') {
				weeklyTotalwithTax = (managersPay / 52);								//52 is for the number of weeks in a year
				weeklyTotal = (weeklyTotalwithTax - (weeklyTotalwithTax * salaryTaxreductions));
			}
			else {
				cout << "Enter number of hours worked: " << endl;
				cin >> hours;
			}
			if (hours < 0) {
				cout << "Error: must not be less than 0" << endl;
			}
			if (selection == 'A') {
				weeklyTotalwithTax = (counterStaffpay * hours);
				weeklyTotal = (weeklyTotalwithTax - (weeklyTotalwithTax * taxReductions));
			}
			if (selection == 'B') {
				weeklyTotalwithTax = (kitchenCookspay * hours);
				weeklyTotal = (weeklyTotalwithTax - (weeklyTotalwithTax * taxReductions));
			}
			if (selection == 'C') {
				weeklyTotalwithTax = (dishwashersPay * hours);
				weeklyTotal = (weeklyTotalwithTax - (weeklyTotalwithTax * taxReductions));
			}
			cout << endl << employeeFirstname << " " << employeeLastname << " earned $" << weeklyTotal << " this week." << endl << endl << endl;


			cout << "Do you have another employee? " << endl;
			cin >> input;
		} while (hasEmployee = true);
		
	}
	else
	{
		cout << "Thank you" << endl;
	}
	return 0;

}

