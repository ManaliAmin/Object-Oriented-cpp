#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"



namespace sict {

	void  AccountNumber::name(const char name[]) {

		strcpy_s(_name, name);
	}
	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber) {
		//cout << "Account num is " << bankCode << "-" << branchCode << "-" << accountNumber;


		_bankCode = bankCode;
		_branchCode = branchCode;
		_accountNumber = accountNumber;

		//_validAccNumber = false;
		if ((bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE) && (branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE) && (accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO)) {
			_validAccNumber = true;
		}
		else{
			_validAccNumber = false;
		}

	}
	bool AccountNumber::isValid() const {

		return _validAccNumber;  // check krava su krvanu che ? vachvu padse vachi ne kav

	}
	void AccountNumber::displayNumber() const{
		cout << "Account number: " << _bankCode << "-"
			<< _branchCode << "-" << _accountNumber;

	}
	void AccountNumber::displayName() const{
		cout << "Name: " << _name;
	}
	void AccountNumber::display() const {

		if (isValid()){
			displayName();
			cout << " ,";
			displayNumber();
		}
		else
			cout << _name << " does not have a valid account number." << endl;
	}
	void AccountNumber::display(bool display_name) const{
		if (display_name == false)
			displayNumber();

	}
	void AccountNumber::display(bool display_name, bool display_number) const{
		//cout << "HI";
		//displayName();
		if (display_name == true && display_number == false){
			displayName();

		}
	}


}
