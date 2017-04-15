#include "SmartInteger.hpp"
#include <iostream>

SmartInteger::SmartInteger() {
	this->num = 0;
}

SmartInteger::SmartInteger(int num) {
	this->num = num;
}

int SmartInteger::getValue() {
	return num;
}

//Overloads << to automatically print out the .getValue of a smartInt
std::ostream& operator << (std::ostream& os, SmartInteger& si) {
	os << si.getValue();
	return os;
}

//Overloads < to compare the right hand side of expression of smartInts
//with the left hand side (THIS->). Similar to sample code from week 9
bool SmartInteger::operator<(SmartInteger rhs) {
	if (this->num < rhs.getValue())
		return true;
	else
		return false;
}

//Same as the < operator but reversed to check if greater than rhs
bool SmartInteger::operator>(SmartInteger rhs) {
	if (this->num > rhs.getValue())
		return true;
	else
		return false;
}

//Overloads <= to compare if left hand side is less than or equal to rhs
//Uses the < overload
bool SmartInteger::operator<=(SmartInteger rhs) {
	if (this->num == rhs.getValue())
		return true;
	else
		return (*this < rhs);
}

//Overloads <= to compare if left hand side is greater than or equal to rhs
//Uses the > overload
bool SmartInteger::operator>=(SmartInteger rhs) {
	if (this->num == rhs.getValue())
		return true;
	else
		return (*this > rhs);
}

//Overloads == to compare if lhs is equal to the rhs for smartInts
bool SmartInteger::operator==(SmartInteger rhs) {
	if (this->num == rhs.getValue())
		return true;
	else
		return false;
}

//Overload of != operator, uses the == overload to save code
bool SmartInteger::operator!=(SmartInteger rhs) {
	return !(*this == rhs);
}