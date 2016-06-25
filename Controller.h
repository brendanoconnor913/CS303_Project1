#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <string>
#include <iostream>
#include "OrderedPoly.h"


using namespace std;

class Controller {
public:
	Controller() {}
	// Take user input string and return a polynomial
	OrderedPoly<int> createPoly(string polystring) {
		OrderedPoly<int> returnPoly;
		//Variables
		string poly2 = "~";
		unsigned int it = 0;
		string exp;
		string coe;
		int expint;
		int coeint;
		int polylength = polystring.length();
		//Remove spaces from poly string
		//poly3.erase(remove_if(poly3.begin(), poly3.end(), isspace), poly3.end());
		//Add '~' to beginning of poly string
		string poly777 = polystring.insert(0, poly2);
		string poly = poly777.insert(polystring.length(), "+");
		//Start of finding coe and exp
		for (it; it < poly.length() - 1; it++) {
			int	find = poly.find_first_of('x', it + 2);
			int find2 = poly.find_first_of('+', it + 2);
			int find3 = poly.find_first_of('-', it + 2);
			char a = poly[it + 2];// after current place
			char c = poly[it + 1];// current place
			char b = poly[it];// before current place

							  //special case no coefficient = 1 or -1 :::::::::::::::::: perfect
			if ((c == 'x' && b == '+') || (c == 'x' && b == '~')) {
				coe = '1';
				coeint = atoi(coe.c_str());
				cout << "coe = " << coe << endl;
				cout << "exp = " << exp << endl;
			}
			if (c == 'x' && b == '-') {
				coe = "-1";
				coeint = atoi(coe.c_str());
				cout << "coe = " << coe << endl;
				cout << "exp = " << exp << endl;
			}

			//Find coefficient with at the start of the string
			if (b == '~' && c != '-' && c != 'x') {

				// if place of x is less than the place of next + and next -
				if ((find < find2 && find < find3 && find != -1) || (find2 == -1 && find3 == -1 && find != -1) || ((find < find2 && find3 == -1 || find < find3 && find2 == -1) && find != -1)) {
					coe = poly.substr(it + 1, find - it - 1);
					coeint = atoi(coe.c_str());
					cout << "coe = " << coe << endl;
					cout << "exp = " << exp << endl;
				} // if place of + is less than the place of next x and next -
				else if ((find2 < find && find2 < find3 && find2 != -1) || (find == -1 && find3 == -1 && find2 != -1) || ((find2 < find && find3 == -1 || find2 < find3 && find == -1) && find2 != -1)) {
					coe = poly.substr(it + 1, find2 - it - 1);
					exp = '0';
					coeint = atoi(coe.c_str());
					expint = atoi(exp.c_str());
					returnPoly.insert(coeint, expint);
					cout << "exp = " << exp << endl;
					cout << "coe = " << coe << endl;
				}// if place of - less than place of next x and next +
				else if ((find3 < find2 && find3 < find && find3 != -1) || ((find2 == -1 && find == -1 && find3 != -1) || ((find3 < find && find2 == -1 || find3 < find2 && find == -1) && find3 != -1))) {
					coe = poly.substr(it + 1, find3 - it - 1);
					exp = '0';
					coeint = atoi(coe.c_str());
					expint = atoi(exp.c_str());
					returnPoly.insert(coeint, expint);
					cout << "exp = " << exp << endl;
					cout << "coe = " << coe << endl;
				}// if no place for x, +, or - are found::::::::::::one variable in string exception
				else if (find == -1 && find2 == -1 && find3 == -1) {
					coe = poly.substr(it + 1, find - it - 1);
					exp = "0";
					coeint = atoi(coe.c_str());
					expint = atoi(exp.c_str());
					returnPoly.insert(coeint, expint);
					cout << "exp = " << exp << endl;
					cout << "coe = " << coe << endl;
				}
			}
			// find coefficients in the middle of string
			if ((c == '-' && b != '^' && a != 'x') || (c == '+' && a != 'x')) {

				if (c == '-') {//if current character is -
							   // if place of x is less than the place of next + and next -
					if ((find < find2 && find < find3 && find != -1) || (find2 == -1 && find3 == -1 && find != -1) || ((find < find2 && find3 == -1 || find < find3 && find2 == -1) && find != -1)) {
						coe = poly.substr(it + 1, find - it - 1);
						coeint = atoi(coe.c_str());
						cout << "coe = " << coe << endl;
						cout << "exp = " << exp << endl;
					}// if place of + is less than the place of next x and next -
					else if ((find2 < find && find2 < find3 && find2 != -1) || (find == -1 && find3 == -1 && find2 != -1) || ((find2 < find && find3 == -1 || find2 < find3 && find == -1) && find2 != -1)) {
						coe = poly.substr(it + 1, find2 - it - 1);
						exp = '0';
						coeint = atoi(coe.c_str());
						expint = atoi(exp.c_str());
						returnPoly.insert(coeint, expint);
						cout << "exp = " << exp << endl;
						cout << "coe = " << coe << endl;
					}
					else if ((find3 < find2 && find3 < find && find3 != -1) || (find2 == -1 && find == -1 && find3 != -1) || ((find3 < find && find2 == -1 || find3 < find2 && find == -1) && find3 != -1)) {
						coe = poly.substr(it + 1, find3 - it - 1);
						exp = '0';
						coeint = atoi(coe.c_str());
						expint = atoi(exp.c_str());
						returnPoly.insert(coeint, expint);
						cout << "exp = " << exp << endl;
						cout << "coe = " << coe << endl;
					}// if no place for x, +, or - are found::::::::::::end of string exception
					else if (find == -1 && find2 == -1 && find3 == -1) {
						coe = poly.substr(it + 1, find - it - 1);
						exp = "0";
						coeint = atoi(coe.c_str());
						expint = atoi(exp.c_str());
						returnPoly.insert(coeint, expint);
						cout << "exp = " << exp << endl;
						cout << "coe = " << coe << endl;
					}
				}
				else if (c == '+') { // if current character is +
									 // if place of x is less than the place of next + and next -
					if ((find < find2 && find < find3 && find != -1) || (find2 == -1 && find3 == -1 && find != -1) || ((find < find2 && find3 == -1 || find < find3 && find2 == -1) && find != -1)) {
						coe = poly.substr(it + 2, find - it - 2);
						coeint = atoi(coe.c_str());
						cout << "coe = " << coe << endl;
						cout << "exp = " << exp << endl;
					}// if place of + is less than the place of next x and next -
					else if ((find2 < find && find2 < find3 && find2 != -1) || (find == -1 && find3 == -1 && find2 != -1) || ((find2 < find && find3 == -1 || find2 < find3 && find == -1) && find2 != -1)) {
						coe = poly.substr(it + 2, find2 - it - 2);
						exp = '0';
						coeint = atoi(coe.c_str());
						expint = atoi(exp.c_str());
						returnPoly.insert(coeint, expint);
						cout << "exp = " << exp << endl;
						cout << "coe = " << coe << endl;
					}// if place of - less than place of next x and next +
					else if ((find3 < find2 && find3 < find && find3 != -1) || (find2 == -1 && find == -1 && find3 != -1) || ((find3 < find && find2 == -1 || find3 < find2 && find == -1) && find3 != -1)) {
						coe = poly.substr(it + 2, find3 - it - 2);
						exp = '0';
						coeint = atoi(coe.c_str());
						expint = atoi(exp.c_str());
						returnPoly.insert(coeint, expint);
						cout << "exp = " << exp << endl;
						cout << "coe = " << coe << endl;
					}// if no place for x, +, or - are found::::::::::::end of string exception
					else if (find == -1 && find2 == -1 && find3 == -1) {
						coe = poly.substr(it + 2, find - it - 2);
						exp = "0";
						coeint = atoi(coe.c_str());
						expint = atoi(exp.c_str());
						returnPoly.insert(coeint, expint);
						cout << "exp = " << exp << endl;
						cout << "coe = " << coe << endl;
					}


				}
			}
			//Find exponent ::::::::::::::::::::::::::::: perfect
			if (b == '^') {

				if ((find3 < find2 && find3 != -1) || find2 == -1) { // find exp between ^ and -
					expint = atoi(exp.c_str());
					returnPoly.insert(coeint, expint);
					cout << "exp = " << exp << endl;
					cout << "coe = " << coe << endl;

				}
				else if (find3 == -1 || (find2 < find3 && find2 != -1)) {  // find exp between ^ and +
					exp = poly.substr(it + 1, find2 - it - 1);
					expint = atoi(exp.c_str());
					returnPoly.insert(coeint, expint);
					cout << "exp = " << exp << endl;
					cout << "coe = " << coe << endl;

				}

			}
			if (c == 'x' && a != '^') { //special case no ^
				exp = '1';
				expint = atoi(exp.c_str());
				returnPoly.insert(coeint, expint);
				cout << "exp = " << exp << endl;
				cout << "coe = " << coe << endl;

			}

		}


		//printOrderedPoly(returnPoly);
		return returnPoly;
	}
	
	// Add the two polys stored in control variables
	// returns false if operation fails
	bool addPolys() { // notify user if either poly not defined
		if (poly1.size() == 0 || poly2.size() == 0) {
			return false;
		}

		// insert each poly into result poly (poly insert function handles addition)
		OrderedPoly<int>::const_piterator itr = poly1.begin();
		for (itr; itr != poly1.end(); itr++) {
			sum.insert(*itr, itr.getCo());
		}
		itr = poly2.begin();
		for (itr; itr != poly2.end(); itr++) {
			sum.insert(*itr, itr.getCo());
		}
		return true;
	}
	
	// Output the poly to user
	void printOrderedPoly(const OrderedPoly<int>& f) {
		OrderedPoly<int>::const_piterator iter = f.begin();
		while (iter != f.end()) {
			if ((f.getLeadDegree() != *iter) && (iter.getCo()>0))
				cout << "+";
			if (*iter == 0) {
				cout << iter.getCo();
				++iter;
			}
			else {
				if (iter.getCo() != 1) {
					cout << iter.getCo();
				}
				cout << "x";
				if ((*iter != 1)) {
					cout << "^" << *iter;
				}
				++iter;
			}
		}
		cout << endl << endl;
	}

	// remove all the terms in both stored polys
	void clearPolys() {
		poly1.emptyPoly();
		poly2.emptyPoly();
	}
	// output the first poly
	void printPoly1() {
		printOrderedPoly(poly1);
	}
	// output the second poly
	void printPoly2() {
		printOrderedPoly(poly2);
	}
	// output sum of poly1 and poly2
	void printResult() {
		printOrderedPoly(sum);
	}
	// function for UI to call to create first poly
	// and store it in poly1 variable
	void setpoly1(string source) {
		poly1.emptyPoly();
		poly1 = createPoly(source);
	}
	// function for UI to call to create second poly
	// and store it in poly2 variable
	void setpoly2(string source) {
		poly2.emptyPoly();
		poly2 = createPoly(source);
	}
	
private:
	OrderedPoly<int> poly1;
	OrderedPoly<int> poly2;
	OrderedPoly<int> sum;
};
#endif