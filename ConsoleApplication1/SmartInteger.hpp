///////////////////////////////////////////////////////////////////////////////
// File Name:          SmartInteger.hpp
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
	// Overloads < to compare the right hand side of expression of smartInts
	bool operator<(SmartInteger rhs) const;
	// Same as the < operator but reversed to check if greater than rhs
	bool operator>(SmartInteger rhs) const;
	// Overloads <= to compare if left hand side is less than or equal to rhs
	// Uses the < overload
	bool operator<=(SmartInteger rhs) const;
	// Overloads <= to compare if left hand side is greater than or equal to rhs
	// Uses the > overload
	bool operator>=(SmartInteger rhs) const;
	// Overloads == to compare if lhs is equal to the rhs for smartInts
	bool operator==(SmartInteger rhs) const;
	// Overload of != operator, uses the == overload to save code
	bool operator!=(SmartInteger rhs) const;
	// Overloads << to automatically print out the .getValue of a smartInt
	friend std::ostream& operator << (std::ostream& os, const SmartInteger& rhs);
	// Overload of + operator, uses limits.h to help check for overflow
	// Throws a standard exception if overflow
	const SmartInteger operator+(SmartInteger rhs) const;
	// Overload of - operator, uses limits.h to help check for overflow
	// Throws a standard exception if overflow
	const SmartInteger operator-(SmartInteger rhs) const;
	// Overload of * operator, uses limits.h to help check for overflow
	// Throws a standard exception if overflow
	const SmartInteger operator*(SmartInteger rhs) const;
	// Overload of += operator, calls on the overloaded + operator to reuse code
	SmartInteger& operator+=(SmartInteger rhs);
	// Overload of -= operator, calls on the overloaded - operator to reuse code
	SmartInteger& operator-=(SmartInteger rhs);
	// Overload of *= operator, calls on the overloaded * operator to reuse code
	SmartInteger& operator*=(SmartInteger rhs);
	// Overload of negation operator, calls on the overloaded *= operator to reuse code
	SmartInteger operator-() const;
	// Overload of ++ operator (pre-increment), calls on the overloaded + operator to reuse code
	SmartInteger& operator++();
	// Overload of -- operator (pre-decrement), calls on the overloaded - operator to reuse code
	SmartInteger& operator--();
	// Overload of ++ operator (post-increment), calls on the overloaded + operator to reuse code
	SmartInteger operator++(int);
	// Overload of -- operator (post-decrement), calls on the overloaded - operator to reuse code
	SmartInteger operator--(int);

};
