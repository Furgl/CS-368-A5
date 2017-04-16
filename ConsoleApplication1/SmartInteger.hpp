#pragma once
#include <iostream>
#include <limits.h>

class SmartInteger {

private:
	int num;

public:

	SmartInteger();

	SmartInteger(int);

	int getValue() const;

	bool operator<(SmartInteger rhs) const;

	bool operator>(SmartInteger rhs) const;

	bool operator<=(SmartInteger rhs) const;

	bool operator>=(SmartInteger rhs) const;

	bool operator==(SmartInteger rhs) const;

	bool operator!=(SmartInteger rhs) const;

	friend std::ostream& operator << (std::ostream& os, const SmartInteger& rhs);

	SmartInteger operator+(SmartInteger rhs);
	SmartInteger operator+=(SmartInteger rhs);

};
