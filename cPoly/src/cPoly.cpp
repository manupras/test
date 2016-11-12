//============================================================================
// Name        : cPoly.cpp
// Author      : Manu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class AutoMobile {

public:
	virtual void describe()=0;

	virtual ~AutoMobile() {

	}
};

class car : public AutoMobile {

public:
	void describe(){
		cout<<"This is car"<<endl;
	}

};

class bike:public AutoMobile {
public:
	void describe(){
		cout<<"This is bike"<<endl;
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!


	AutoMobile *auto1 = new car;
	AutoMobile *auto2 = new bike;

	auto1->describe();
	auto2->describe();
	return 0;
}
