#pragma once
#include <iostream>

class SmartInteger {

private:
	int num;

public:

	SmartInteger();

	SmartInteger(int);

	int getValue();

	bool SmartInteger::operator<(SmartInteger s1);

	bool SmartInteger::operator>(SmartInteger s1);

	bool SmartInteger::operator<=(SmartInteger s1);

	bool SmartInteger::operator>=(SmartInteger s1);

	bool SmartInteger::operator==(SmartInteger s1);

	bool SmartInteger::operator!=(SmartInteger s1);


	friend std::ostream& operator << (std::ostream& os, SmartInteger& si);

};
