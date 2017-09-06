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
// Name				     Date	    Reason
// Manali amin    	03/10/2016 	   w3_at_home
///////////////////////////////////////////////////////////

// compilation safegaurds
namespace ict{
	class Weather {
		char m_date[6 + 1];
		double high_temp;
		double low_temp;
	public:
		void set(const char*dt, double ht, double lt);
		void display() const;
		const char* date() const;
		double low() const;
	};

}
/*Weather.h*/
// ict namespace


