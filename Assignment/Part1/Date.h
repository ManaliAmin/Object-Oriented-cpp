

#ifndef ICT_DATE_H__
#define ICT_DATE_H__
#define NO_ERROR   0  
#define CIN_FAILED 1  
#define YEAR_ERROR 2
#define MON_ERROR  3  
#define DAY_ERROR  4  


#include <iostream>
namespace ict{


	class Date{
	private:
		int value()const;
		void errCode(int errorCode);


	public:
		int year_;
		int mon_;
		int day_;
		int readErrorCode_;
		int mdays()const;
		Date();
		Date(int year, int mon, int day);

		bool operator==(const Date& D)const;
		bool operator!=(const Date& D)const;
		bool operator<(const Date& D)const;
		bool operator>(const Date& D)const;
		bool operator<=(const Date& D)const;
		bool operator>=(const Date& D)const;

		int errCode();
		bool bad()const;
		void validate();
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;




	};
	//std::ostream& operator<< (std::ostream &out, const Date &D);
	//std::istream& operator>> (std::istream &in, Date &D);
	std::istream&  operator>>(std::istream& istr, Date& D);
	std::ostream&  operator<<(std::ostream& ostr, const Date& D);
}
#endif
