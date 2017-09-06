#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__

#include <iostream>

namespace ict {
	class Account {
		char name_[41];
		double balance_;
	public:

		void display(bool gotoNewline = true)const;

		Account();
		Account(double balance);
		Account(const char name[], double balance = 0.0);
		//Account operator+(const Account& A);
		//Account operator+=(const Account& c);
		Account & operator += (const Account &amt);
		Account & operator = (const char name[40]);
		double balance() const { return balance_; }

	};

	std::ostream& operator<<(std::ostream& os, const Account& a);
	Account operator + (const Account &amt, const Account &A);
	double operator += (double& amt, const Account& A);
}

#endif