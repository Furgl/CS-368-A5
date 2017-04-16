#include "SmartInteger.hpp"

#include <iostream>

using namespace std;

int main() {
    std::cout << "Constructing n1 and n2..." << std::endl;
    SmartInteger n1(3);
    SmartInteger n2;
    std::cout << "n1.getValue() should be 3: " << n1.getValue() << std::endl;
    std::cout << "n2.getValue() should be 0: " << n2.getValue() << std::endl;
    std::cout << std::endl;

    // No need to implement custom copy assignment operator - this should just work
    std::cout << "Changing value of n2..." << std::endl;
    n2 = 3;
    std::cout << "n2.getValue() should be 3: " << n2.getValue() << std::endl;
    std::cout << std::endl;

    // No need to implement custom copy constructor - this should just work
    std::cout << "Constructing n3..." << std::endl;
    SmartInteger n3(n2);
    std::cout << "n3.getValue() should be 3: " << n3.getValue() << std::endl;

    // Add more code here!

	//test for the << operator
	cout << "Test of << OPERATOR, Value should be 3: " << n1 << endl;

	//test for the < and > operator
	cout << "Test of < & >, OPERATOR: ";
	SmartInteger n4(7); 

	if (n1 < n4) // 3 < 7
		cout << "Correct --- ";
	else
		cout << "Incorrect --- ";

	if (n4 > n1) // 7 > 3
		cout << "Correct" << endl;
	else
		cout << "Incorrect" << endl;

	
	//Test of the <=, Checks the corner case where they are equal
	//You can just switch the signs to check  >= but didnt wanna rewrite tests

	cout << "Test of <= Operators: ";
		if (n1 <= n3) // 3 <= 3
			cout << "CORRECT --- ";
		else
			cout << "INCORRECT --- ";

		if (n1 <= n4) // 3 <= 7
			cout << "CORRECT --- " << endl;
		else
			cout << "INCORRECT --- " << endl;


	//Test of the == and != operators
		cout << "Test of the == and != operators: ";
			if (n1 == n3) // 3 == 3
				cout << "CORRECT --- ";
			else
				cout << "INCORRECT --- ";

			if (n1 != n4) // 3 != 7
				cout << "CORRECT" << endl;
			else
				cout << "INCORRECT" << endl;

		
	//Test of addition (+ and +=) operator
			cout << "Test of the + operator, Value should be 10: ";
				cout << (n1 + n4);

				cout << "Test of the += operator, Value should be 14: ";

				n4 += n4;
				cout << n4;



			//MAKE SURE WE REMOVE THIS BEFORE SUBMISSION
			std::cin.get();

    return 0;
}
