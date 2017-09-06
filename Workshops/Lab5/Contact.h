#ifndef ICT_CONTACT_H_
#define ICT_CONTACT_H_
#include "PhoneNumber.h"
namespace ict{
	class Contact{
		char name_[41];
		PhoneNumber* phoneNumber_;
		int noPN_;
		void setEmpty();
	public:
		Contact();
		Contact(char* name, int phoneNumber);
		Contact(const Contact& C);
		~Contact();
		Contact& operator=(const Contact& C);
		void read();
		void display()const;
		bool isEmpty()const;
	};

}

#endif