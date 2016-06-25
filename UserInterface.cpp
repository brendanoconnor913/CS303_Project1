
#include "UserInterface.h"

using namespace std;

// output menu options
void UserInterface::outputMenu() {
	cout << endl << "Welcome to PolyAdder please choose an option from the menu below:"
		<< endl << "1. Enter first polynomial"
		<< endl << "2. View first polynomial"
		<< endl << "3. Enter second polynomial"
		<< endl << "4. View second polynomial"
		<< endl << "5. Calculate sum of polynomials"
		<< endl << "6. Clear entered polynomials"
		<< endl << "7. Exit" << endl;
}

// get user input from menu and call appropriate functions
// only handles numerical input
bool UserInterface::getMenuInput() {
	string poly;
	string choice;

	while (true) {
		cout << "What will be your choice: ";
		cin >> choice;
		switch (stoi(choice)) {
		case 1:
			poly = getPolynomial();
			cntrl.setpoly1(poly);
			return true;
		case 2:
			cntrl.printPoly1();
			return true;
		case 3:
			poly = getPolynomial();
			cntrl.setpoly2(poly);
			return true;
		case 4:
			cntrl.printPoly2();
			return true;
		case 5:
			if (cntrl.addPolys()) {
				cntrl.printResult();
			}
			else {
				cout << "Both polynomials must be define." << endl;
			}
			return true;
		case 6:
			cntrl.clearPolys();
			return true;
		case 7:
			return false;
		default:
			cout << "Invalid input, try again" << endl;
			continue;
		}
	}
}

// ui to get user polynomial string to pass to controller
string UserInterface::getPolynomial() {
	string out;
	cout << endl << endl
		<< "Using the following example as a model, "
		<< "please enter a polynomial (ex. 2x^4-3x^2+x^1-6)"
		<< endl << ": ";
	cin.ignore();
	getline(cin, out);
	return out;
}