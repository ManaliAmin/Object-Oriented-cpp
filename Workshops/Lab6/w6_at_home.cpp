// OOP244 Workshop 6: operators
// File: w6_at_home.cpp
// Version: 1.0
// Date: 10/24/2016
// Author: Manali Amin
// Description:w6_at_home
// This file tests At-Home section of your workshop
/////////////////////////////////////////////

#include <iostream>
#include "Account.h"
using namespace ict;
using namespace std;
void displayABC(const Account& A,
	const Account& B,
	const Account& C){
	cout << "A: " << A << endl << "B: " << B << endl
		<< "C: " << C << endl << "--------" << endl;
}
int main(){
	Account A;
	Account B("Saving", 10000.99);
	Account C("Checking", 100.99);
	Account* AC[3] = { &A, &B, &C };
	double balance = 0;
	displayABC(A, B, C);
	A = B + C;
	displayABC(A, B, C);
	A = "Joint";
	displayABC(A, B, C);
	A = B += C;
	displayABC(A, B, C);
	A = B += C += 100.01;
	displayABC(A, B, C);
	for (int i = 0; i < 3; i++){
		//cout << "abc " << endl;
		cout << i + 1 << "- " << (balance +=*AC[i]) << endl;
	}
	cout << "Total Balance: " << balance << endl;
	return 0;
}

/*
(Your output should exactly match the following)

A : No Name : $0.00
B : Saving : $10000.99
C : Checking : $100.99
--------
A : No Name : $10101.98
B : Saving : $10000.99
C : Checking : $100.99
--------
A : Joint : $10101.98
B : Saving : $10000.99
C : Checking : $100.99
--------
A : Saving : $10101.98
B : Saving : $10101.98
C : Checking : $100.99
--------
A : Saving : $10302.98
B : Saving : $10302.98
C : Checking : $201.00
--------
1 - 10302.98
2 - 20605.96
3 - 20806.96
Total Balance : 20806.96
*/