/*
 * main.cpp
 *
 *  Created on: 06-Nov-2016
 *      Author: Manuprasad
 */
#include <iostream>
#include <test.h>
using namespace std;

int main() {
	test t1(20);
	test t2(30);
	test t3;

	t3 = t1 + t2;

	cout << t3.num <<endl;
	return 0;
}


