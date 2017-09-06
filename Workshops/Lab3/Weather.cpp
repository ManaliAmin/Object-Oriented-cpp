// OOP244 Workshop ??: ??????????
// File ???????
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name    			 Date    	Reason
// Manali Amin    03/10/2016	w3_at_home
///////////////////////////////////////////////////////////

/*Weather.cpp*/
//  includes go here
#include "Weather.h"
#include<string.h>
#include<iostream>
#include<iomanip>
// ict namespace
using namespace std;
using namespace ict;
// set
void Weather::set(const char*dt, double ht, double lt)
{
	strcpy(m_date, dt);
	high_temp = ht;
	low_temp = lt;
}

// display
void Weather::display() const
{
	//cout<<date<<"_______"<<high_temp<<"____"<<low_temp<<endl; 
	cout << setprecision(1) << fixed;
	cout << setfill('_') << left << setw(10) << m_date << right << setw(6) << high_temp << setw(6) << low_temp << endl;
}
double Weather::low() const{
	return low_temp;
}
 const char *Weather::date() const{
	 return m_date;
}