#include "SmartInteger.hpp"

#include <iostream>

using namespace std;

int main() {
	cout << "Constructing n1 and n2..." << endl;
	SmartInteger n1(3);
	SmartInteger n2;
	cout << "n1.getValue() should be 3: " << n1.getValue() << endl;
	cout << "n2.getValue() should be 0: " << n2.getValue() << endl;
	cout << endl;

	//  No need to implement custom copy assignment operator - this should just work
	cout << "Changing value of n2..." << endl;
	n2 = 3;
	cout << "n2.getValue() should be 3: " << n2.getValue() << endl;
	cout << endl;

	//  No need to implement custom copy constructor - this should just work
	cout << "Constructing n3..." << endl;
	SmartInteger n3(n2);
	cout << "n3.getValue() should be 3: " << n3.getValue() << endl;

	//  Add more code here!

	// test for the << operator
	cout << "Test of << OPERATOR, value should be 3: " << n1 << endl;

	// test for the < and > operator
	cout << "Test of < & >, OPERATOR: ";
	SmartInteger n4(7);

	if (n1 < n4) //  3 < 7
		cout << "Correct --- ";
	else
		cout << "Incorrect --- ";

	if (n4 > n1) //  7 > 3
		cout << "Correct" << endl;
	else
		cout << "Incorrect" << endl;


	// Test of the <=, Checks the corner case where they are equal
	// You can just switch the signs to check  >= but didnt wanna rewrite tests

	cout << "Test of <= Operators: ";
	if (n1 <= n3) //  3 <= 3
		cout << "CORRECT --- ";
	else
		cout << "INCORRECT --- ";

	if (n1 <= n4) //  3 <= 7
		cout << "CORRECT --- " << endl;
	else
		cout << "INCORRECT --- " << endl;


	// Test of the == and != operators
	cout << "Test of the == and != operators: ";
	if (n1 == n3) //  3 == 3
		cout << "CORRECT --- ";
	else
		cout << "INCORRECT --- ";

	if (n1 != n4) //  3 != 7
		cout << "CORRECT" << endl;
	else
		cout << "INCORRECT" << endl;


	// Test of addition (+ and +=) operators
	cout << "Test of the + operator, value should be 10: ";
	cout << (n1 + n4) << endl;
	cout << "Test of the += operator, value should be 14: ";
	n4 += n4;
	cout << n4 << endl;

	// Test of subtraction (- and -=) operators
	cout << "Test of the - operator, value should be -11: ";
	cout << (n1 - n4) << endl;
	cout << "Test of the -= operator, value should be 11: ";
	n4 -= n1;
	cout << n4 << endl;

	// Test of multiplication (* and *=) operators
	cout << "Test of the * operator, value should be 33: ";
	cout << (n1 * n4) << endl;
	cout << "Test of the *= operator, value should be 33: ";
	n4 *= n1;
	cout << n4 << endl;

	// Test of negation operator
	cout << "Test of the negation operator, value should be 33, -33, 33: ";
	cout << n4 << ", " << -n4 << ", " << n4 << endl;

	// Test of ++ and -- operators (pre)
	cout << "Test of the ++ operator (pre-increment), values should be 4 and 4: ";
	cout << ++n1 << ", " << n1 << endl;
	cout << "Test of the -- operator (pre-decrement), value should be 3 and 3: ";
	cout << --n1 << ", " << n1 << endl;

	// Test of ++ and -- operators (post)
	cout << "Test of the ++ operator (post-increment), values should be 3 and 4: ";
	cout << n1++ << ", " << n1 << endl;
	cout << "Test of the -- operator (post-decrement), value should be 4 and 3: ";
	cout << n1-- << ", " << n1 << endl;

	// main.cpp won't be turned in, so we don't need to worry about removing this
	cin.get();

	return 0;
}
