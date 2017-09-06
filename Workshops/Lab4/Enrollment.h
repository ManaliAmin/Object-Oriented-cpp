#ifndef _ENROLLMENT_H_
#define _ENROLLMENT_H_
namespace ict{

	class Enrollment{
	private:
		char name_[31];
		char code_[11];
		int year_;
		int semester_;
		int slot_;
		bool enrolled_;
	public:
		bool isEnrolled() const;
		bool isValid()const;
		void setEmpty();
		void display(bool nameOnly = false)const;
		void set(const char* name, const char* code, int year, int semester, int time, bool enrolled = false);
		bool hasConflict(const Enrollment &other) const;
		Enrollment(const char* name, const char* code, int year, int semester, int time);
		Enrollment();
		void withdraw();
		int enrol(const Enrollment* enrollments, int size);
	};
}

#endif
