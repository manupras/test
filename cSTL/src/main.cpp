/*
 * main.cpp
 *
 *  Created on: 10-Nov-2016
 *      Author: Manuprasad
 */

#include <iostream>
#include <cSTL.h>
using namespace std;

int main() {
	test t1(10);
	t1.vNum.push_back(20);
	t1.vNum.push_back(30);

	for (vector<int>::iterator it = t1.vNum.begin(); it < t1.vNum.end(); it++)
		cout << ' ' << *it << endl;
	return 0;
}

