// OOP244 Workshop 3: Dynamic Memory
// File	w3_at_home.cpp
// Version 1.0
// Date	: 03/10/2016
// Author	: Manali Amin
// Description : w3_at_home
///////////////////////////////////////////////////////////


#include <iostream>
#include <cstring>
#include <string>

#include "Weather.h"
using namespace std;
using namespace ict;
double findLow(const char* date, const Weather* data, int dataSize);
int main(){
	int i; //  loop counter
	int n; //the count of days worth of weather
	// create the weather pointer here
	Weather *weather;
	cout << "Weather Data\n";
	cout << "=====================" << endl;
	cout << "Days of Weather: ";
	cin >> n;
	cin.ignore();
	// allocate dynamic memory here
	weather = new Weather[n];
	for (i = 0; i < n; i++){
		char date_description[7];
		double high;
		double low;
		cout << "Enter date: ";
		cin >> date_description;
		cout << "Enter high: ";
		cin >> high;
		cout << "Enter low : ";
		cin >> low;
		weather[i].set(date_description, high, low);
		// ... add code to accept user input for
		//weather

	}
	cout << endl
		<< "Weather report:" << endl
		<< "Date        high  low" << endl
		<< "======================" << endl;

	for (i = 0; i < n; i++){
		weather[i].display();
	}

	char query[7];
	cout << endl << "Enter the date you are looking for: ";
	cin >> query;
	    
	double low = findLow(query, weather, n);
	cout << "Low temperature: " << low << endl;
	            
	delete[] weather;
	return 0;

}
double findLow(const char* date, const Weather* data, int dataSize){  
	 
	const char* a;
	double lo = 0;
	for (int i = 0; i < dataSize; i++){

		a = data[i].date(); 
		if (strcmp(a, date) == 0){
			lo = data[i].low();
		}
	}
	if (lo != 0){
		return lo;
	}
	else{
		return 0.0;  
	}
	

	
	

}