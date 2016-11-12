/*
 * test.cpp
 *
 *  Created on: 06-Nov-2016
 *      Author: Manuprasad
 */

#include <test.h>

test::test(){
	num = 0;
}

test::test(int A){
	num = A;
}

test test::operator +(test t){
	test temp;
	temp.num = num + t.num;
	return temp;
}



