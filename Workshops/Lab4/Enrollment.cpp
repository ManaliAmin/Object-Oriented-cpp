#include <iostream>
#include <cstring>
#include "Enrollment.h"
using namespace std;
namespace ict{

	Enrollment::Enrollment(){
		setEmpty();

	}
	Enrollment::Enrollment(const char* name, const char* code, int year, int semester, int time){
		set(name, code, year, semester, time, false);

	}

	void Enrollment::withdraw()
	{
		enrolled_ = false;
		//cout << "Student has been withdraw from the course:";
	}
	int Enrollment::enrol(const Enrollment* enrollments, int size){
		int ret = 0;
		for (int i = 0; i < size; i++)
		{
			if (hasConflict(enrollments[i])){
				ret = i + 1;
			}
		}
		if (ret == 0) { enrolled_ = true; }
		return ret;
	}

	bool Enrollment::hasConflict(const Enrollment &other) const{
		if (other.year_ != 0 && year_ != 0 && other.semester_ != 0 && other.slot_ != 0 && slot_ != 0){
			if (other.year_ == year_ && other.semester_ == semester_ && other.slot_ == slot_){
				return true;
			}
		}

		return false;

	}

	void Enrollment::set(const char* name, const char* code, int year, int semester, int time, bool enrolled){
		if (name != (char*)0 && name[0] && code != (char*)0 && code[0] && year >= 2015 && (semester >0 && semester < 4) && (time > 0 && time<6)) {
			strcpy(name_, name);

			strcpy(code_, code);

			year_ = year;
			semester_ = semester;
			slot_ = time;
			enrolled_ = enrolled;
		}
		else{
			setEmpty();
		}
	}


	bool Enrollment::isValid()const{
		return name_ && name_[0]; //return true if _name is not null and not empty
	}
	void Enrollment::setEmpty(){
		name_[0] = 0;
		code_[0] = 0;
		year_ = 0;
		semester_ = 0;
		slot_ = 0;
		enrolled_ = false;
	}
	bool Enrollment::isEnrolled() const{
		return enrolled_;
	}

	void Enrollment::display(bool nameOnly)const{
		if (isValid()){
			cout << name_;
			if (!nameOnly){
				cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
				cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
			}
		}
		else{
			cout << "Invalid enrollment!" << endl;
		}
	}
}
