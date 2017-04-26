#include "Vector.hpp"

#include <iostream>

using namespace std;

void printVector(const Vector<int> &v) {

	for (int i = 0; i < v.size(); i++) {

		cout << v[i] << ", ";
	}
	cout << endl;
}

int main() {
	
	Vector<int> v1;
	v1.pushBack(1);
	v1.pushBack(2);
	v1.pushBack(3);
	printVector(v1);

	cout << "SELF ASSIGNMENT TEST" << endl;
	v1 = v1;


	Vector<int> v2;
	v2 = v1;
	printVector(v2);
	v2[0] = 4;
	printVector(v2);
	printVector(v1);

	v1.pushBack(4);
	v1.pushBack(5);
	printVector(v1);
	int *i1 = v1.begin();

	cout << *i1 << endl;

	v1.popBack();
	printVector(v1);

	v1.erase(i1+1);
	printVector(v1);

	cin.get();

	return 0;
}
