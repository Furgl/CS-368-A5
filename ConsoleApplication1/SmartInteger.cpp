#include "SmartInteger.hpp"
#include <iostream>
#include <limits.h>

SmartInteger::SmartInteger() {
	this->num = 0;
}

SmartInteger::SmartInteger(int num) {
	this->num = num;
}

int SmartInteger::getValue() const {
	return num;
}

//Overloads << to automatically print out the .getValue of a smartInt
std::ostream& operator << (std::ostream& os, const SmartInteger& rhs) {
	os << rhs.getValue();
	return os;
}

//Overloads < to compare the right hand side of expression of smartInts
//with the left hand side (THIS->). Similar to sample code from week 9
bool SmartInteger::operator<(SmartInteger rhs) const{
	if (this->num < rhs.getValue())
		return true;
	else
		return false;
}

//Same as the < operator but reversed to check if greater than rhs
bool SmartInteger::operator>(SmartInteger rhs) const{
	if (this->num > rhs.getValue())
		return true;
	else
		return false;
}

//Overloads <= to compare if left hand side is less than or equal to rhs
//Uses the < overload
bool SmartInteger::operator<=(SmartInteger rhs) const{
	if (this->num == rhs.getValue())
		return true;
	else
		return (*this < rhs);
}

//Overloads <= to compare if left hand side is greater than or equal to rhs
//Uses the > overload
bool SmartInteger::operator>=(SmartInteger rhs) const{
	if (this->num == rhs.getValue())
		return true;
	else
		return (*this > rhs);
}

//Overloads == to compare if lhs is equal to the rhs for smartInts
bool SmartInteger::operator==(SmartInteger rhs) const{
	if (this->num == rhs.getValue())
		return true;
	else
		return false;
}

//Overload of != operator, uses the == overload to save code
bool SmartInteger::operator!=(SmartInteger rhs) const{
	return !(*this == rhs);
}


//Overload of + operator, uses limits.h to help check for overflow
//Throws a standard exception if overflow
SmartInteger SmartInteger::operator+(SmartInteger rhs) {

	SmartInteger sum;

	if ((rhs.getValue() > 0) && (this->getValue() > INT_MAX - rhs.getValue()))
		throw std::exception();

	else if ((rhs.getValue() < 0) && (this->getValue() < INT_MIN - rhs.getValue()))
		throw std::exception();
	
	else
		sum.num = rhs.getValue() + this->getValue();

	return sum;
}


//Overload of += operator, calls on the overloaded + operator to reuse code
SmartInteger SmartInteger::operator+=(SmartInteger rhs) {
	*this = *this + rhs;
	return *this;
}