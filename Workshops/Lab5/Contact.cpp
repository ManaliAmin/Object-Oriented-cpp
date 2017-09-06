#include <cstring>
#include <iostream>
#include "Contact.h"
using namespace std;

namespace ict{

	Contact::Contact()
	{
		setEmpty();
	}
	Contact::Contact(char* name, int phoneNumber)
	{
		phoneNumber_ = new PhoneNumber[phoneNumber];
		strncpy_s(name_, name, 40);
		name_[40] = (char)0;
		noPN_ = phoneNumber;
	}
	Contact::~Contact()
	{
		delete[] phoneNumber_;
	}
	Contact::Contact(const Contact& C)
	{

		name_[40] = C.name_[40];
		phoneNumber_ = new PhoneNumber[C.noPN_];
		noPN_ = C.noPN_;
		for (int i = 0; i < noPN_; i++)
		{
			phoneNumber_[i] = C.phoneNumber_[i];
		}
	}

	Contact& Contact::operator=(const Contact& C)
	{
		if (this != &C)
		{
			delete[] phoneNumber_;
			name_[40] = C.name_[40];
			phoneNumber_ = new PhoneNumber[C.noPN_];
			noPN_ = C.noPN_;

			for (int i = 0; i < noPN_; i++)
			{
				phoneNumber_[i] = C.phoneNumber_[i];
			}
		}
		return *this;
	}


	void Contact::display()const{
		if (phoneNumber_ != nullptr)
		{
			//display the name and go to new line
			cout << name_ << endl;
			//cout << endl;
			// loop through elements of _pn up to _noPN and display them one by one
			for (int i = 0; i < noPN_; i++)
			{
				//cout << "HI" << endl;
				phoneNumber_[i].display();
			}

			cout << "----------------------------------------" << endl;
			// draw a 40 char line using '-' and go to new line
		}

	}

	void Contact::read(){
		cout << "Contact Name: ";
		cin.getline(name_, 41, '\n');
		cout << "Please enter " << noPN_ << " phone numbers: " << endl;
		for (int i = 0; i < noPN_; i++){
			cout << i + 1 << ": ";
			phoneNumber_[i].read();
		}
	}



	bool Contact::isEmpty()const{
		//return phoneNumber_ == (PhoneNumber*)0;  // tu zero nakhe etle nullptr 
		if (name_[0] == 0 && noPN_ == 0 && phoneNumber_ == nullptr){
			return true;

		}
		else{
			return false;
		}
	}
	void Contact::setEmpty(){
		name_[0] = 0;
		noPN_ = 0;
		phoneNumber_ = nullptr;// 
	}
}