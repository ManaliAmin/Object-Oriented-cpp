// OOP244 Workshop 5: Classes with resources 
// File: PhoneNumber.cpp
// Version: 1.0
// Date: 2015/10/13
// Author: Fardad Soleimanloo
/////////////////////////////////////////////
#ifndef ICT_PHONENUMBER_H_
#define ICT_PHONENUMBER_H_
namespace ict{
	class PhoneNumber{
		int area_;
		int number_;
		char *type_;
		void setEmpty();
		bool isValid(int area, int number, const char* type)const;
		bool allocateAndCopy(int area, int number, const char* str);
	public:
		PhoneNumber();
		PhoneNumber(const PhoneNumber& cp);
		PhoneNumber& operator=(const PhoneNumber& ro);
		// No need
		//    PhoneNumber(int area, int number , const char* type="Home");
		~PhoneNumber();
		// Performs a fool-proof entry of phone number form console
		void read();
		// displays the phone number and goes to new line
		void display(bool goToNewLine = true)const;
		bool isEmpty()const;
	};
}
#endif