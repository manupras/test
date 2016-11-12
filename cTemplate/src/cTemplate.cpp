//============================================================================
// Name        : cTemplate.cpp
// Author      : Manu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <class T>
class calcu {
private:
	T obj1, obj2;
public:
	void setVar(T a, T b) {
		obj1 = a;
		obj2 = b;
	}
	T sum() {
		return obj1+obj2;
	}
};

int main() {
	cout << "cTemplate" << endl; // prints cTemplate

	calcu<int> inst1;
	inst1.setVar(10,20);
	cout<<inst1.sum()<<endl;
	return 0;
}
