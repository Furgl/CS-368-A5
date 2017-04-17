///////////////////////////////////////////////////////////////////////////////
// File Name:          SmartInteger.cpp
//
// Author:             Jacob Pollard & Jason Waner
// CS email:           jpollard2@wisc.edu & jwaner@wisc.edu
//
// Description:        An Integer-like object that detects integer overflows
//
// Sources:            stackoverflow
// URL(s) of sources:  http://stackoverflow.com
//                                   
///////////////////////////////////////////////////////////////////////////////

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

// Overloads << to automatically print out the .getValue of a smartInt
std::ostream& operator << (std::ostream& os, const SmartInteger& rhs) {
	os << rhs.getValue();
	return os;
}

// Overloads < to compare the right hand side of expression of smartInts
bool SmartInteger::operator<(SmartInteger rhs) const {
	return this->num < rhs.getValue();
}

// Same as the < operator but reversed to check if greater than rhs
bool SmartInteger::operator>(SmartInteger rhs) const {
	return this->num > rhs.getValue();
}

// Overloads <= to compare if left hand side is less than or equal to rhs
// Uses the < overload
bool SmartInteger::operator<=(SmartInteger rhs) const {
	if (this->num == rhs.getValue())
		return true;
	else
		return (*this < rhs);
}

// Overloads <= to compare if left hand side is greater than or equal to rhs
// Uses the > overload
bool SmartInteger::operator>=(SmartInteger rhs) const {
	if (this->num == rhs.getValue())
		return true;
	else
		return (*this > rhs);
}

// Overloads == to compare if lhs is equal to the rhs for smartInts
bool SmartInteger::operator==(SmartInteger rhs) const {
	return this->num == rhs.getValue();
}

// Overload of != operator, uses the == overload to save code
bool SmartInteger::operator!=(SmartInteger rhs) const {
	return !(*this == rhs);
}

// Overload of + operator, uses limits.h to help check for overflow
// Throws a standard exception if overflow
const SmartInteger SmartInteger::operator+(SmartInteger rhs) const {

	SmartInteger sum;

	if (rhs.getValue() > 0 && this->getValue() > INT_MAX - rhs.getValue())
		throw std::exception();
	else if (rhs.getValue() < 0 && this->getValue() < INT_MIN - rhs.getValue())
		throw std::exception();
	else
		sum.num = this->getValue() + rhs.getValue();

	return sum;
}

// Overload of - operator, uses limits.h to help check for overflow
// Throws a standard exception if overflow
const SmartInteger SmartInteger::operator-(SmartInteger rhs)  const {

	SmartInteger difference;

	if (rhs.getValue() < 0 && this->getValue() > INT_MAX + rhs.getValue())
		throw std::exception();
	else if (rhs.getValue() > 0 && this->getValue() < INT_MIN + rhs.getValue())
		throw std::exception();
	else
		difference.num = this->getValue() - rhs.getValue();

	return difference;
}

// Overload of * operator, uses limits.h to help check for overflow
// Throws a standard exception if overflow
const SmartInteger SmartInteger::operator*(SmartInteger rhs)  const {

	SmartInteger product;

	if (this->getValue() == -1 && rhs.getValue() == INT_MIN)
		throw std::exception();
	else if (rhs.getValue() == -1 && this->getValue() == INT_MIN)
		throw std::exception();
	// both positive
	else if (rhs.getValue() != -1 && this->getValue() > 0 && rhs.getValue() > 0 && this->getValue() > INT_MAX / rhs.getValue())
		throw std::exception();
	// both negative
	else if (rhs.getValue() != -1 && this->getValue() < 0 && rhs.getValue() < 0 && this->getValue() > INT_MAX / abs(rhs.getValue()))
		throw std::exception();
	// one positive, one negative
	else if (rhs.getValue() != -1 && abs(this->getValue()) > INT_MAX / abs(rhs.getValue())) 
		throw std::exception();
	else
		product.num = this->getValue() * rhs.getValue();

	return product;
}

// Overload of += operator, calls on the overloaded + operator to reuse code
SmartInteger& SmartInteger::operator+=(SmartInteger rhs) {
	*this = *this + rhs;
	return *this;
}

// Overload of -= operator, calls on the overloaded - operator to reuse code
SmartInteger& SmartInteger::operator-=(SmartInteger rhs) {
	*this = *this - rhs;
	return *this;
}

// Overload of *= operator, calls on the overloaded * operator to reuse code
SmartInteger& SmartInteger::operator*=(SmartInteger rhs) {
	*this = *this * rhs;
	return *this;
}

// Overload of negation operator, calls on the overloaded *= operator to reuse code
SmartInteger SmartInteger::operator-() const {
	return SmartInteger(this->getValue()) *= -1;
}

// Overload of ++ operator (pre-increment), calls on the overloaded + operator to reuse code
SmartInteger& SmartInteger::operator++() {
	*this = *this + 1;
	return *this;
}

// Overload of -- operator (pre-decrement), calls on the overloaded - operator to reuse code
SmartInteger& SmartInteger::operator--() {
	*this = *this - 1;
	return *this;
}

// Overload of ++ operator (post-increment), calls on the overloaded + operator to reuse code
SmartInteger SmartInteger::operator++(int) {
	SmartInteger copy = SmartInteger(this->getValue());
	*this = *this + 1;
	return copy;
}

// Overload of -- operator (post-decrement), calls on the overloaded - operator to reuse code
SmartInteger SmartInteger::operator--(int) {
	SmartInteger copy = SmartInteger(this->getValue());
	*this = *this - 1;
	return copy;
}
