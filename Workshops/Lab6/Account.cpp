#include <cstring>
#include "Account.h"
#include "iomanip"
using namespace std;

namespace ict {

	void Account::display(bool gotoNewline)const {
		cout << (name_[0] ? name_ : "No Name") << ": $" << setprecision(2) << fixed << balance_;
		if (gotoNewline) cout << endl;
	}


	Account::Account() {
		name_[0] = 0;
		balance_ = 0;
	}
	Account::Account(double balance) {
		name_[0] = 0;
		balance_ = balance;
	}
	Account::Account(const char name[], double balance) {
		strcpy(name_, name);
		balance_ = balance;
	}
	Account operator + (const Account& amt, const Account& A) {
		return Account(amt.balance() + A.balance());
	}
	Account & Account::operator += (const Account &amt) {
		balance_ += amt.balance_;
		return *this;
	}
	double operator += (double& amt, const Account& A) {
		amt += A.balance();
		return amt;
	}
	Account & Account::operator = (const char newname[40]) {
		strncpy(name_, newname, 41);
		return *this;
	}
	
	ostream& operator<<(ostream& os, const Account& a) {
		a.display(false);
		return os;
	}

	

	

}